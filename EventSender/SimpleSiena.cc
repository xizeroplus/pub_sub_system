// -*- C++ -*-
//
//  This file is part of Siena, a wide-area event notification system.
//  See http://www.cs.colorado.edu/serl/dot/siena.html
//
//  Author: Antonio Carzaniga <carzanig@cs.colorado.edu>
//  See the file AUTHORS for full details. 
//
//  Copyright (C) 1998-1999 University of Colorado
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307,
//  USA, or send email to serl@cs.colorado.edu.
//
//
// $Id: SimpleSiena.cc,v 1.3 2002/11/22 17:52:34 carzanig Exp $
// 
#include "include/sienaconf.h"

#include <sstream>
#include <iostream>
#include <fstream>
#include "include/Siena.h"
#include "include/SienaIO.h"
#include "include/SimpleSiena.h"
#include "include/SENP.h"

#ifdef HAVE_CXX_NAMESPACE
namespace Siena {
#endif

//
// A simple client-side Siena service
//

SimpleSiena::SimpleSiena(const string & uri): server(uri) {
    master = Sender::create_sender(uri);
}

SimpleSiena::~SimpleSiena() 
{
    if (myuri != NULL) delete(myuri);
}

void SimpleSiena::set_receiver(Receiver * r) {
    receiver = r;
}

Receiver * SimpleSiena::get_receiver() {
    return receiver;
}

void SimpleSiena::publish(Pub &pub)
{
    Request r;
    r[SENP::Method] = SENP::PUB;
    string packet = encode(r, pub);
    master->send(packet.data(), packet.size());
}

Notifiable * get_party_from_string(const string &s)
{
    //
    // dirty hack! I have to do this because unfortunately, my
    // implementation of the C++ stream library doesn't have
    // istream::operator>>(void * &) (which is part of the standard!)
    // Anyway it is rather safe to assume that a pointer can be stored
    // in an unsigned long long
    //
    union {
	unsigned long long ul;
	Notifiable * n;
    };
    istringstream is(s);
    is >> ul;
    return n;
}

string put_party_into_string(Notifiable *party)
{
    //
    // dirty hack! See explanation above.
    //
    union {
	unsigned long long ul;
	Notifiable * n;
    };
    n = party;
    ostringstream os;
    os << ul;
    return os.str();
}

void SimpleSiena::subscribe(IntervalSub &sub)
{

    Request r;

    r[SENP::Method] = SENP::SUB;
    r[SENP::Subscriber] = sub.uri;
    string packet = encode(r, sub);
    master->send(packet.data(), packet.size());
}

void SimpleSiena::exit_loop()
{
    in_loop=false;
}

void SimpleSiena::main_loop()
{
    int SENP_MAXPACKETLEN = 102400;
    if (receiver == NULL) exit(-1);
    char pktbuf[102400];
    ssize_t pktsize;

    Pub pub;
    Request r;

    ofstream ot;
    ot.open("receiveTime.txt");
    if (!ot) {
        cerr << "can't open outtime file " << endl;
        exit(1);
    }

    struct timespec tv;

    in_loop = true;
    while(in_loop) {
        pktsize = receiver->receive(pktbuf, SENP_MAXPACKETLEN);
        if (pktsize < 0) exit(-1);
        string str = string(pktbuf, pktsize);
        decode(str,r, pub);
	Request::iterator method_i = r.find(SENP::Method);
	if (method_i == r.end() || (*method_i).second.type()!=Siena_string) {
	    cout << SENP::RE_BadRequest << flush;
	} else if ((*method_i).second.string_value() == SENP::PUB) {
        struct timespec tv;
        clock_gettime(CLOCK_REALTIME, &tv);
        double time_interval = (tv.tv_sec - pub.tp.sec)*1000 + (tv.tv_nsec - pub.tp.ns)/1000000.0;
        thread t(&SimpleSiena::recordTime,this,pub.pub_id,time_interval);
        t.detach();
	}
    }
}



#ifdef HAVE_CXX_NAMESPACE
}; // namespace Siena
#endif


