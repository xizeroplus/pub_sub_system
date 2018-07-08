#ifndef _DATA_STRUCTURE_H
#define _DATA_STRUCTURE_H
#include<string>
#include<vector>

#ifdef HAVE_CXX_NAMESPACE
namespace Siena {
#endif

using namespace std;

class tmpoint{
public:
    int sec = 0;
    int ns = 0;
};

class Cnt{
public:
    int att;
    int value;
    int op;     //  op==0 -> "="  op==1 -> ">="  op==2 -> "<="
};

class IntervalCnt{
public:
    int att;
    int lowValue, highValue;
};

class Sub {
public:
    string uri;
    int size; 								//number of predicates
    vector<Cnt> constraints;				//list of constraints
};

class IntervalSub{
public:
    string uri;
    int size;
    vector<IntervalCnt> constraints;
};

class ConElement {
public:
    int att;
    int val;
    string uri;
};

class Combo{
public:
    int index_id;
    int val;
};

class IntervalCombo{
public:
    int lowValue, highValue;
    string uri;
};

class Pair{
public:
    int att;
    int value;
};

class purePub
{
public:
    int pub_id;
    int size;
    vector<Pair> pairs;
};

class Pub{
public:
    tmpoint tp;
    int pub_id;
    int size;
    vector<Pair> pairs;
};

class Request
{
public:
    int type;
    //0:sub ; 1:pub;
};

#ifdef HAVE_CXX_NAMESPACE
}; // namespace Siena
#endif

#endif //_DATA_STRUCTURE_H
