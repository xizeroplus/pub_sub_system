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
// $Id: SienaIO.h,v 1.2 2002/11/22 17:52:35 carzanig Exp $
//
#ifndef _SienaIO_h
#define _SienaIO_h

#include <iostream>

#include "Siena.h"
#include <stdio.h>
#include "data_structure.h"
#include <sstream>

#ifdef HAVE_CXX_NAMESPACE
namespace Siena {
#endif

ostream &		operator << (ostream &, const IntervalSub &);
ostream &		operator << (ostream &, const Pub &);
ostream &		operator << (ostream &, const Request &);

istream &		operator >> (istream &, IntervalSub &);
istream &		operator >> (istream &, Pub &);
istream &		operator >> (istream &, Request &);

stringstream &		operator << (stringstream &, const IntervalSub &);
stringstream &		operator << (stringstream &, const Pub &);
stringstream &		operator << (stringstream &, const Request &);

stringstream &		operator >> (stringstream &, IntervalSub &);
stringstream &		operator >> (stringstream &, Pub &);
stringstream &		operator >> (stringstream &, Request &);

string encode(Request &r, Pub &p);
string encode(Request &r, IntervalSub &s);

void decode(string & str, Request &r, Pub &p);
void decode(string & str, Request &r, IntervalSub &s);

void decode(string & str, Request &);

class ParseError: virtual public exception {
    const char * _what;
public:
    ParseError(const char *s): _what(s) {};

    virtual const char *	what() const throw() { return _what; };
};

#ifdef HAVE_CXX_NAMESPACE
}; // namespace Siena
#endif

#endif
