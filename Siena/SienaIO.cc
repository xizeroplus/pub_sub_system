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
// $Id: SienaIO.cc,v 1.2 2002/11/22 17:52:34 carzanig Exp $
// 
#include "include/sienaconf.h"

#include <cctype>
#include <iostream>
#include <string>

using namespace std;

#include "include/Siena.h"
#include "include/SienaIO.h"

static const char * PE_literal = "expecting literal value";
static const char * PE_operator = "expecting operator";
static const char * PE_lparen = "expecting `{'";
static const char * PE_anamerparen = "expecting attribute name or `}'";
static const char * PE_equal = "excpecting `='";
static const char * PE_pub = "expecting keyword `pub'";
static const char * PE_pubid = "expecting keyword `pubid'";
static const char * PE_uri = "expecting keyword `uri'";
static const char * PE_subsize = "expecting keyword `subsize'";
static const char * PE_senp = "expecting keyword `senp'";
static const char * PE_pattern = "expecting keyword `pattern'";
static const char * PE_sub = "expecting keyword `sub' or `}'";
static const char * PE_lowValue = "expecting keyword `lowValue'";
static const char * PE_highValue = "expecting keyword `highValue'";
static const char * PE_subatt = "expecting keyword `subatt'";
static const char * PE_pubatt = "expecting keyword `pubatt'";
static const char * PE_pubValue = "expecting keyword `PE_pubValue'";
static const char * PE_pubsize = "expecting keyword `PE_pubsize'";

static const char * Kwd_req = "req";
static const char * Kwd_pub = "pub";
static const char * Kwd_sub = "sub";
static const char * Kwd_any = "any";
static const char * Kwd_null = "null";
static const char * Kwd_true = "true";
static const char * Kwd_false = "false";
static const char * Kwd_lparen = "{";
static const char * Kwd_rparen = "}";

static const char * Kwd_op_sf = "*<";
static const char * Kwd_op_pf = ">*";
static const char * Kwd_op_lt = "<";
static const char * Kwd_op_gt = ">";
static const char * Kwd_op_le = "<=";
static const char * Kwd_op_ge = ">=";
static const char * Kwd_op_eq = "=";
static const char * Kwd_op_ne = "!=";
static const char * Kwd_op_ss = "*";
static const char * Kwd_op_xx = "any";

#ifdef HAVE_CXX_NAMESPACE
namespace Siena {
#endif

ostream &		operator << (ostream &os, const Pub &pub)
{
	os << Kwd_pub << ' ' << Kwd_lparen << ' ';
	os << pub.tp.sec << ' ' << pub.tp.ns << ' ';
	os << pub.pub_id << ' ' << pub.size << ' ';
	for (int i=0; i<pub.size; ++i)
		os << pub.pairs[i].att << ' ' << pub.pairs[i].value << ' ';
	os <<  Kwd_rparen << endl;
	return os;
}

ostream &		operator << (ostream &os, const purePub &pub)
{
	os << Kwd_pub << ' ' << Kwd_lparen << ' ';
	os << pub.pub_id << ' ' << pub.size << ' ';
	for (int i=0; i<pub.size; ++i)
		os << pub.pairs[i].att << ' ' << pub.pairs[i].value << ' ';
	os <<  Kwd_rparen << endl;
	return os;
}

ostream &		operator << (ostream &os, const IntervalSub &sub)
{
	os << Kwd_sub << ' ' <<  Kwd_lparen << ' ';
	string uri = sub.uri;
	os << uri << ' ' << sub.size << ' ';
	for (int i=0; i<sub.size; ++i)
		os << sub.constraints[i].att << ' ' << sub.constraints[i].lowValue << ' ' << sub.constraints[i].highValue << ' ';
	return os << Kwd_rparen << endl;
}

ostream & operator << (ostream & os, const Request &r)
{
	os << Kwd_req << ' ' << Kwd_lparen << ' ' << r.type << ' ' << Kwd_rparen << endl;
	return os;
}


istream &		operator >> (istream &is, Pub &pub)
{
	pub.pairs.clear();
	pub.pairs.shrink_to_fit();

	string type, lpren, rpren;

	is >> type;
	if (type != "pub") return is;
	is >> lpren >> pub.tp.sec >> pub.tp.ns >> pub.pub_id >> pub.size;

	for (int i=0; i<pub.size; ++i)
	{
		Pair p;
		is >> p.att >> p.value;
		pub.pairs.push_back(p);
	}

	is >> rpren;

	if (rpren!="}") throw ParseError(PE_pubsize);
	else return is;
}

istream &		operator >> (istream &is, purePub &pub)
{
	pub.pairs.clear();
	pub.pairs.shrink_to_fit();

	string type, lpren, rpren;

	is >> type >> lpren >> pub.pub_id >> pub.size;

	for (int i=0; i<pub.size; ++i)
	{
		Pair p;
		is >> p.att >> p.value;
		pub.pairs.push_back(p);
	}

	is >> rpren;

	if (rpren!="}") throw ParseError(PE_pubsize);
	else return is;
}


istream &		operator >> (istream &is, IntervalSub &sub)
{
	sub.constraints.clear();
	sub.constraints.shrink_to_fit();

	string type, lpren, rpren;

	is >> type;

	if (type != "sub") return is;

	is >> lpren >> sub.uri >> sub.size;

	for (int i=0; i<sub.size; ++i)
	{
		IntervalCnt c;
		is >> c.att >> c.lowValue >> c.highValue;
		sub.constraints.push_back(c);
	}

	is >> rpren;

	if (rpren!="}") throw ParseError(PE_subsize);
	else return is;
}


istream & operator >> (istream &is, Request &r)
{
	string type, lpren, rpren;

	is >> type;
    if (type != "req") return is;
    is >> lpren >> r.type >> rpren;

	if (rpren!="}")
        throw ParseError(rpren.c_str());
	else return is;
}


string encode(Request &r, Pub &pub)
{
    ostringstream os;
    os << r << pub;
    return os.str();
}
string encode(Request &r, IntervalSub &sub){
    ostringstream os;
    os << r << sub;
    return os.str();
}

void decode(string & str, Request &r, Pub &pub){
    istringstream is(str);
    is >> r >> pub;
}

void decode(string & str, Request &r, IntervalSub &sub){
	istringstream is(str);
    is >> r >> sub;
}

void decode(istringstream &is, Request &r)
{
	is >> r;
}
void decode(istringstream &is, Pub &p)
{
	is >> p;
}
void decode(istringstream &is, IntervalSub &s)
{
	is >> s;
}


#ifdef HAVE_CXX_NAMESPACE
} // namespace Siena
#endif

