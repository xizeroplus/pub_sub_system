//
// Created by mg2015started on 18-3-26.
//

#ifndef SIENA_THREADPOOL_H
#define SIENA_THREADPOOL_H
#include "concurrentQueue.h"

#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

#define MIN_THREADS 5


template<class Type>
class ThreadPool {
    ThreadPool& operator=(const ThreadPool&) = delete;

    ThreadPool(const ThreadPool& other) = delete;

public:
    ThreadPool()
    {
        _shutdown = false;
    }
    void initialize(int32_t threads);

    virtual ~ThreadPool();

    void Submit(Type record);
    void writeLog(int id, double interval1,double interval2, double interval3);
    void hand(Type & record);

private:

private:
    mutable std::mutex _mutex;
    bool _shutdown;
    int32_t _threads;
    //std::function<void(Type& record)> _handler;
    std::vector <std::thread> _workers;
    ConcurrentQueue <Type> _tasks;
};


template<class Type>
void ThreadPool<Type>::initialize(int32_t threads)
{
    _shutdown = false;
    _threads = threads;
    if (_threads < MIN_THREADS)
        _threads = MIN_THREADS;

    for (int32_t i = 0; i < _threads; ++i)
        _workers.emplace_back(
                [this] {
                    while (!_shutdown) {
                        Type record;
                        _tasks.Pop(record, true);
                        hand(record);
                    }
                }
        );

}

template<class Type>
void ThreadPool<Type>::hand(Type &record)
{
    Pub pub = record.second;
    struct timespec tv;
    clock_gettime(CLOCK_REALTIME, &tv);
    double time_interval = (tv.tv_sec - pub.tp.sec)*1000 + (tv.tv_nsec - pub.tp.ns)/1000000.0;

    string destination = record.first;

    Sender * master = Sender::create_sender(destination);
    //cout << "bad" << record.first << endl;
    try{
        Request r;
        r[SENP::Method] = SENP::PUB;
        //r[SENP::Publisher] = myuri;
        string packet = encode(r, pub);
        master->send(packet.data(), packet.size());
    }
    catch (exception &ex) {
        cout << ex.what() << endl;
        cout << "matching" << endl;
    }
    delete(master);
    clock_gettime(CLOCK_REALTIME, &tv);
    double time_interval_2 = (tv.tv_sec - pub.tp.sec)*1000 + (tv.tv_nsec - pub.tp.ns)/1000000.0;
    thread t(&ThreadPool<Type>::writeLog,this,pub.pub_id, time_interval,time_interval_2,time_interval_2-time_interval);
    t.detach();
}

template<class Type>
void ThreadPool<Type>::writeLog(int id, double interval1,double interval2, double interval3)
{
    std::lock_guard <std::mutex> lock(_mutex);
    ofstream filestream;
    filestream.open("sendthreadLog.txt",ios::app);
    filestream<< id << '\t' << interval1 << '\t' << interval2 << '\t' << interval3 << endl;
    filestream.close();
}

template<class Type>
ThreadPool<Type>::~ThreadPool() {
    for (std::thread &worker: _workers)
        worker.join();
}


template<class Type>
void ThreadPool<Type>::Submit(Type record) {
    _tasks.Push(record);
}
#endif //SIENA_THREADPOOL_H
