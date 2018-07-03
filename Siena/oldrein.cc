#include "include/oldrein.h"
/*
void oldRein::insert(Sub sub)
{
    for (int i = 0; i < sub.size; i++)
    {
        Cnt cnt = sub.constraints[i];
        Combo c;
        c.val = cnt.value;
        c.uri = sub.uri;
        if (cnt.op == 0)        // ==
        {
            data[cnt.att][0][c.val / buckStep].push_back(c);
            data[cnt.att][1][c.val / buckStep].push_back(c);
        }
        else if (cnt.op == 1)   // >=
            data[cnt.att][0][c.val / buckStep].push_back(c);
        else                    // >=
            data[cnt.att][1][c.val / buckStep].push_back(c);
    }
}
 */

void oldRein::insert(IntervalSub &sub)
{
    for (int i = 0; i < sub.size; i++)
    {
        IntervalCnt cnt = sub.constraints[i];
        Combo c;
        c.val = cnt.lowValue;
        c.index_id = LvURI.size();
        data[cnt.att][0][c.val / buckStep].push_back(c);
        c.val = cnt.highValue;
        data[cnt.att][1][c.val / buckStep].push_back(c);
    }
    LvURI.push_back(sub.uri);
}

void oldRein::match(const Pub &pub, string  myuri, ThreadPool<pair<string,Pub> > & pool)
{
    bool bitset[LvURI.size()];
    memset(bitset,0,sizeof(bitset));

    for (int i = 0; i < pub.size; i++)
    {
        //Timer t0;
        int value = pub.pairs[i].value, att = pub.pairs[i].att, buck = value / buckStep;
        vector<Combo> &data_0 = data[att][0][buck];
        //pretime += t0.elapsed_nano()/1000000.0;

        //Timer t1;
        int data_0_size = data_0.size();
        for (int k = 0; k < data_0_size; k++)
            if (data_0[k].val > value)
                bitset[data_0[k].index_id] = true;
        //searchtime += t1.elapsed_nano()/1000000.0;

        //Timer t2;
        for (int j = buck + 1; j < bucks; j++){
            vector<Combo> &data_1 = data[att][0][j];
            int data_1_size = data_1.size();
            for (int k = 0; k < data_1_size; k++)
                bitset[data_1[k].index_id] = true;
        }
        //travesetime += t2.elapsed_nano()/1000000.0;

        //Timer t3;
        vector<Combo> &data_2 = data[att][1][buck];
        int data_2_size = data_2.size();
        for (int k = 0; k < data_2_size; k++)
            if (data_2[k].val < value)
                bitset[data_2[k].index_id] = true;
        //searchtime += t3.elapsed_nano()/1000000.0;

        //Timer t4;
        for (int j = buck - 1; j >= 0; j--)
        {
            vector<Combo> &data_3 = data[att][1][j];
            int data_3_size = data_3.size();
            for (int k = 0; k < data_3_size; k++)
                bitset[data_3[k].index_id] = true;
        }
        //travesetime += t4.elapsed_nano()/1000000.0;

    }

    //Timer t5;
    int b = LvURI.size();
    for (int i = 0; i < b; i++)
        if (!bitset[i]){
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

            Sender * master = Sender::create_sender(LvURI[i]);
            //cout << "bad" << record.first << endl;
            Pub p = pub;
            try{
                Request r;
                r[SENP::Method] = SENP::PUB;
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
    //tagtime += t5.elapsed_nano()/1000000.0;
/*
    f0 << pretime << "\n";
    f1 << searchtime << "\n";
    f2 << travesetime << "\n";
    f3 << tagtime << "\n";
    f0.close();
    f1.close();
    f2.close();
*/
}
