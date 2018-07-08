//
// Created by mg2015started on 18-3-17.
//


#include <iostream>
#include <fstream>
#include <exception>

using namespace std;
//
// this gives you access to the Siena headers (and to the Siena namespace)
//
#include "include/siena.h"
#include "include/generator.h"
SimpleSiena * S;

//
// here's a simple interested party
//

void print_usage(const char *programname)
{
    cerr << "Usage: " << programname << " [options...]\n\
options:\n\
\t-port number\n\
\t-connect URI\n\
" << endl;

    exit(-1);
}

int main (int argc, char *argv[])
{

    string host = "udp://192.168.101.36:7001/";
    string h = "192.168.101.36";
    int port=7001;

    string server = "udp://192.168.101.34:1969";

    cout << "begin" << endl;
    int subs;           // Number of subscriptions.
    int pubs;           // Number of publications.
    int attDom;           // Total number of attributes, i.e. dimensions.
    int k;           // Number of constraints(predicates) in one sub.
    int m;              // Number of constraints in one pub.
    int valDom;         // Cardinality of values.
    int subAttDis;         // The distribution of attributes in subs and pubs. 0:uniform distribution | 1:Zipf distribution
    int subValDis;         // The distribution of values in subs and pubs. 0:uniform
    int pubAttDis;         // The distribution of attributes in subs and pubs. 0:uniform distribution | 1:Zipf distribution
    int pubValDis;         // The distribution of values in subs and pubs. 0:uniform
    double subAttalpha;       // Parameter for Zipf distribution.
    double pubAttalpha;
    double subValalpha;
    double pubValalpha;
    double width;       // Width of a predicate.
    double equalRatio;
    int old_buck_num;
    int new_buck_num;

    ifstream parafile;
    parafile.open(string("./paras/paras_1")+string(".txt"));
    parafile >> subs >> pubs >> k >> m >> subAttDis >> subValDis >> pubAttDis >> pubValDis >> attDom >> valDom >> subAttalpha >>subValalpha >>  pubAttalpha >> pubValalpha >> width >> equalRatio >> old_buck_num >> new_buck_num;
    parafile.close();

    //m = atts;           // Note that Rein requires m == atts.

    // Initiate generator
    intervalGenerator gen(subs, pubs, k, m, subAttDis, subValDis, pubAttDis, pubValDis, attDom, valDom, subAttalpha ,subValalpha ,pubAttalpha, pubValalpha, width, equalRatio, host);
    gen.GenSubList();
    cout << "gen datalist finished" << endl;

    S = new SimpleSiena(server);
    UDPReceiver *r = new UDPReceiver(port, h.c_str());// create receiver for

    S->set_receiver(r);






    for (int i=1; i< argc; ++i) {	// parses command-line parameters
        if (strcmp(argv[i], "-port")==0) {
            if (++i < argc) {
                port = atoi(argv[i]);
            } else {
                print_usage(argv[0]);
            }
        } else if (strcmp(argv[i], "-connect")==0) {
            if (++i < argc) {
                host = argv[i];
            } else {
                print_usage(argv[0]);
            }
        }
        else {
            print_usage(argv[0]);
        }
    }


    ifstream fileStream;
    fileStream.open("subList.txt");

    IntervalSub sub;
    while (fileStream>>sub)
    {
        //cout << sub.uri << endl;
        S->subscribe(sub);
    }
    cout << "End" << endl;
    fileStream.close();
    S->main_loop();		// enter the loop... waiting for notifications
    //delete(S);
}
