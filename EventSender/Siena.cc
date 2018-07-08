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
// $Id: Siena.cc,v 1.2 2002/11/22 17:52:34 carzanig Exp $
//
#include "include/sienaconf.h"

#include <cstdio>

#include <iostream>
#include <string>

using namespace std;

#include "include/Siena.h"

#ifdef HAVE_CXX_NAMESPACE
namespace Siena {
#endif

#if defined(NO_INLINE)
#define inline
#include <siena/Siena.icc>
#endif

const char * Siena::Version = SIENAVERSION;

const string SienaTypeDescription[] = {
    "null",
    "string",
    "integer",
    "boolean",
    "data",
    "float",
    "binary"
};

const string SienaOperatorDescription[] = {
    "unknown operator",
    "equal",
    "suffix",
    "prefix",
    "less than",
    "greater than",
    "less equal",
    "greater equal",
    "any value",
    "not equal",
    "contains"
};


bool is_suffix(const string &x, const string &y)
{
    // true iff y is a suffix of x, e.g.:
    // x = "pippotto"
    // y = "otto"
    //
    string::const_reverse_iterator xri = x.rbegin();
    string::const_reverse_iterator yri = y.rbegin();
    while(yri != y.rend()) {
	if (xri == x.rend() || *xri != *yri) return false;
	++xri;
	++yri;
    }
    return true;
}

bool is_prefix(const string &x, const string &y)
{
    // true iff y is a prefix of x, e.g.:
    // x = "testolina"
    // y = "test"
    //
    string::const_iterator xi = x.begin();
    string::const_iterator yi = y.begin();
    while(yi != y.end()) {
	if (xi == x.end() || *xi != *yi) return false;
	++xi;
	++yi;
    }
    return true;
}

bool is_substr(const string &x, const string &y)
{
    // true iff y is a substring of x, e.g.:
    // x = "software"
    // y = "war"
    //
    return x.find(y) != x.npos;
}

/** semantics of attribute constraints: applies an operator to two values.

    This function implements some minimal type-conversion (or type
    compatibility). In practice, it only considers integers as
    doubles.  Actually, I'm not even sure the extended semantics would
    make sense, e.g., would it be reasonable to write: <code>int x =
    12; string y = "30"</code>; and then ask <code>x &lt; y</code> ?
    What's the right answer to this?  We still need to specify these
    details */


//
// Exceptions
//
const char * SienaException::what() const throw() {
    static const string _descr = "unknown Siena exception";
    return _descr.c_str();
}

const char * EventModelException::what() const throw() {
    static const string _descr = "event model exception";
    return _descr.c_str();
}

const char * BadType::what() const throw() {
    static const string _descr = "bad type";
    return _descr.c_str();
}

ostream & BadType::printout(ostream &os) const {
    return os << what() << ": " << SienaTypeDescription[type];
}

const char * BadOperator::what() const throw() {
    static const string _descr = "bad operator";
    return _descr.c_str();
}

ostream & BadOperator::printout(ostream &os) const {
    return os << what() << ": " << SienaOperatorDescription[op];
}

#ifdef HAVE_CXX_NAMESPACE
} // namespace Siena
#endif

