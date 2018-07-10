#ifndef OLD_REIN_H
#define OLD_REIN_H
#include<vector>
#include <cstring>
#include "generator.h"
#include "chrono_time.h"
#include "util.h"
#include "data_structure.h"
#include "Siena.h"
#include "data_structure.h"
#include "SienaIO.h"
#include "SENP.h"
#include <map>
#include "Siena.h"
#include "data_structure.h"
#include "SienaIO.h"
#include "SENP.h"
#include "threadPool.h"
#include <thread>
#include <functional>
#include "SienaIO.h"

using namespace std;

const int OLD_MAX_SUBS = 2000001;
const int OLD_MAX_ATTS = 101;
const int OLD_MAX_BUCKS = 1000;

class oldRein{
    int valDom, buckStep, bucks;
    vector<Combo> data[OLD_MAX_ATTS][2][OLD_MAX_BUCKS];    // 0:left parenthesis, 1:right parenthesis
    bool bits[OLD_MAX_SUBS];
    bool skipped[OLD_MAX_ATTS];
    attAndCount attsCounts[OLD_MAX_ATTS];
    vector<string> LvURI;
    int matchsubs;
    mutable std::mutex _mutex;
public:
    void initialize(int _valDom, int buck_num)
    {
        valDom = _valDom; buckStep = (valDom - 1) / buck_num + 1; bucks = (valDom - 1) / buckStep + 1;
    }
    //void insert(Sub &sub);
    void insert(IntervalSub &sub);
    //int64_t match(const Pub &pub, int &matchSubs, const vector<IntervalSub> &subList);
    
    //void select_skipped_atts(const vector<IntervalSub> &subList, int atts, double falsePositive);
    //int64_t approx_match(const Pub &pub, int &matchSubs, const vector<IntervalSub> &subList);

    void match(const Pub &pub, string myuri, ThreadPool<pair<string,Pub> > & pool);
    void recordTime(int id, double time_interval)
    {
        std::lock_guard <std::mutex> lock(_mutex);
        ofstream fileStream;
        fileStream.open("reinlog.txt",ios::app);
        fileStream<< id << '\t' << time_interval << endl;
        fileStream.close();
    };
};

#endif //REIN_REIN_H
