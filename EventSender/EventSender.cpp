//
// Created by mg2015started on 18-3-17.
//
#include "include/siena.h"
#include "include/generator.h"
#include <unistd.h>
#include <fstream>
#include <time.h>
#include <iostream>
#include <exception>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


using namespace std;

SimpleSiena * S;

void print_usage(const char *programname)
{
    cerr << "Usage: " << programname << " [options...]\n\
options:\n\
\t-connect URI\n\
" << endl;

    exit(-1);
}

int main (int argc, char *argv[])
{
    string host = "udp://127.0.0.1:7001/";
    string server = "udp://127.0.0.1:1969";
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
    gen.GenPubList();
    cout << "gen datalist finished" << endl;

    S = new SimpleSiena(server);

    for (int i=1; i< argc; ++i) {	// parses command-line parameters
        if (strcmp(argv[i], "-connect")==0) {
            if (++i < argc) {
                server = argv[i];
            } else {
                print_usage(argv[0]);
            }
        } else {
            print_usage(argv[0]);
        }
    }

    Request r;

    iostream *s = NULL;
    bool quiet = false;

    if (argc > 1 && string(argv[1])==string("-quiet"))
        quiet = true;

    ifstream fileStream;
    ofstream o;
    fileStream.open("pubList.txt");
    struct timespec tv;

    Pub pub;
    while(fileStream >> pub)
    {
        sleep(1);
        clock_gettime(CLOCK_REALTIME, &tv);
        pub.tp.sec = tv.tv_sec;
        pub.tp.ns = tv.tv_nsec;
        if ((pub.pub_id+1)%500==0) cout << pub << endl;
        S->publish(pub);
    }

    cout << "c1" << endl;
    //delete(S);
    cout << "c2" << endl;
    return 0;
}
