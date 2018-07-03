//
// Created by mg2015started on 18-1-25.
//

#ifndef SIENASERVER_0_3_2_NEWSERVER_H
#define SIENASERVER_0_3_2_NEWSERVER_H
#include "rein.h"
#include "oldrein.h"
#include <iostream>
#include <set>
#include <map>

#include "Siena.h"
#include "data_structure.h"
#include "SienaIO.h"
#include "SENP.h"
#include "threadPool.h"
#include "concurrentQueue.h"

class EventServer {
    friend class Rein;
    friend class oldRein;
public:
    static const string Version;
    //
    // This is the interface of the Event Server
    // these functions should not throw exceptions, i.e., they should
    // deal with exceptions themselves.
    //
    void		publish(Request &r, Pub &pub);
    void		subscribe(Request &r, IntervalSub &sub);
    //void		unsubscribe(Request &r, Filter &f);
    //void		connect_peer(Request &);

    void		shutdown();
    void		set_receiver(Receiver *);
    //
    // initialize takes the URI of the first peer connection as a
    // parameter, I'm not sure this is the right thing to do. I will
    // probably change this.
    //
    void		initialize(const string &my_uri,
                           const string &peer_uri);
    void		initialize(const string &my_uri, int _valDom, int k, int buck_num);
    Receiver * receiver;
private:
    oldRein rein;
    vector<string> neighbors;
    string myuri;
    ThreadPool<pair<string,Pub> > pool;
    //URI subscriber;

};


#endif //SIENASERVER_0_3_2_NEWSERVER_H
