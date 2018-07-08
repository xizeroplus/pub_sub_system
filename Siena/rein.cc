#include "include/rein.h"


void Rein::insert(IntervalSub &sub)
{
    int s_index = sub.size -1;
    int c_id = LvURI[s_index].size();
    int buckStep = LvBuckStep[s_index];
    for (int i = 0; i < sub.size; i++)
    {
        IntervalCnt cnt = sub.constraints[i];
        Combo c;
        c.val = cnt.lowValue;
        c.index_id = c_id;
        data[s_index][cnt.att][0][c.val / buckStep].push_back(c);
        c.val = cnt.highValue;
        data[s_index][cnt.att][1][c.val / buckStep].push_back(c);
    }
    LvURI[s_index].push_back(sub.uri);
}

void Rein::match(const Pub &pub, string  myuri, ThreadPool<pair<string,Pub> > & pool)
{
    //ofstream fileStream;
    //fileStream.open("detail.txt", ios::app);
    //fileStream << endl;
    Timer t;
    bool bitset[Dom][LvURI[0].size()*2];
    memset(bitset, 0, sizeof(bitset));
    //cout << "begin match " << pub.pub_id << endl;
    for (int siIndex=0; siIndex<Dom && siIndex<pub.size; ++siIndex)
    {
        bool *kbitset = bitset[siIndex];
        for (int i = 0; i < pub.size; i++)
        {
            //Timer t0;
            int value = pub.pairs[i].value, att = pub.pairs[i].att, buck = value / LvBuckStep[siIndex];
            int bucks = LvBuck[siIndex];
            vector<Combo> &data_0 = data[siIndex][att][0][buck];
            //pretime += t0.elapsed_nano()/1000000.0;

            //Timer t1;
            int data_0_size = data_0.size();
            for (int k = 0; k < data_0_size; k++)
                if (data_0[k].val > value)
                    kbitset[data_0[k].index_id] = true;

            //searchtime += t1.elapsed_nano()/1000000.0;

            //Timer t2;
            for (int j = buck + 1; j < bucks; j++){
                vector<Combo> &data_1 = data[siIndex][att][0][j];
                //if (data_1.empty()) break;
                int data_1_size = data_1.size();
                for (int k = 0; k < data_1_size; k++)
                    kbitset[data_1[k].index_id] = true;
            }
            //travesetime += t2.elapsed_nano()/1000000.0;

            //Timer t3;
            vector<Combo> &data_2 = data[siIndex][att][1][buck];
            int data_2_size = data_2.size();
            for (int k = 0; k < data_2_size; k++)
                if (data_2[k].val < value)
                    kbitset[data_2[k].index_id] = true;
            //searchtime += t3.elapsed_nano()/1000000.0;

            //Timer t4;
            for (int j = buck - 1; j >= 0; j--){
                vector<Combo> &data_3 = data[siIndex][att][1][j];
                //if (data_3.empty()) break;
                int data_3_size = data_3.size();
                for (int k = 0; k < data_3_size; k++)
                    kbitset[data_3[k].index_id] = true;
            }
            //travesetime += t4.elapsed_nano()/1000000.0;
        }

        //Timer t5;
        vector<string> &_Lv = LvURI[siIndex];
        int b = _Lv.size();
        for (int i=0; i<b; ++i)
        {
            if(!kbitset[i]){
                //cout << pub.pub_id << endl;
                /*
                struct timespec tv;
                clock_gettime(CLOCK_REALTIME, &tv);
                double time_interval = (tv.tv_sec - pub.tp.sec)*1000 + (tv.tv_nsec - pub.tp.ns)/1000000.0;

                pool.Submit(make_pair(_Lv[i], pub));

                thread t(&Rein::recordTime,this,pub.pub_id,time_interval);
                t.detach();
                */

                struct timespec tv;
                clock_gettime(CLOCK_REALTIME, &tv);
                double time_interval = (tv.tv_sec - pub.tp.sec)*1000 + (tv.tv_nsec - pub.tp.ns)/1000000.0;

                ofstream fileStream;
                fileStream.open("reinlog.txt",ios::app);
                fileStream<< pub.pub_id << '\t' << time_interval << endl;

                Sender * master = Sender::create_sender(_Lv[i]);
                //cout << "bad" << record.first << endl;
                Pub p = pub;
                try{
                    Request r;
                    r.type = 1;
                    //r[SENP::Publisher] = myuri;
                    string packet = encode(r, p);
                    master->send(packet.data(), packet.size());
                }
                catch (exception &ex) {
                    cout << ex.what() << endl;
                    cout << "matching" << endl;
                }
                delete(master);

            }

        }

        //tagtime += t5.elapsed_nano()/1000000.0;
    }

}
