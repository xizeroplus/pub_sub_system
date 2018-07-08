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
// $Id: Siena.h,v 1.2 2002/11/22 17:52:34 carzanig Exp $
// 
#ifndef _Siena_h
#define _Siena_h

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <exception>
#include "data_structure.h"

using namespace std;

#ifdef HAVE_CXX_NAMESPACE
namespace Siena {
#endif
class Siena;
class Notifiable;

class Siena {
 public:
    /** @memo Version identifier for the Siena interface */
    static const char * Version;
    virtual void	publish(Pub &pub)				= 0;
    virtual void	subscribe(IntervalSub &sub)	= 0;
    //virtual void	subscribe(const Pattern &p, Notifiable *n)	= 0;
    //virtual void	unsubscribe(const Filter &f, Notifiable *n)	= 0;
    //virtual void	unsubscribe(const Pattern &p, Notifiable *n)	= 0;
    //virtual void	disconnect(Notifiable *)			= 0;
};

class Notifiable {
 public:
    virtual void	notify(Pub &pub)				= 0;
};

enum SienaType {
    Siena_null		= 0,
    /** string */
    Siena_string	= 1,
    /** signed integer number  */
    Siena_integer	= 2,
    /** boolean value */
    Siena_bool		= 3,
    /** time/date (<b><em>not yet implemented!</em></b>) */
    Siena_date		= 4,
    /** floating point number */
    Siena_double 	= 5,
    /** binary object (<b><em>not yet implemented!</em></b>) */
    Siena_binary	= 6
};

extern const string	SienaTypeDescription[];



enum SienaOperator {
    Siena_eq		= 1,
    Siena_sf		= 2,
    Siena_pf		= 3,
    Siena_lt		= 4,
    Siena_gt		= 5,
    Siena_le		= 6,
    Siena_ge		= 7,
    Siena_xx		= 8,
    Siena_ne		= 9,
    Siena_ss		= 10
};

extern const string	SienaOperatorDescription[];


/** generic exception */
class SienaException: public exception {
    /** C-style string representation of what went wrong */
    virtual const char *	what() const throw();
public:
    virtual ~SienaException() throw() {};
};

/** exception: service unavailable */
class ServiceUnavailable: public exception {
    /** C-style string representation of what went wrong */
    virtual const char *	what() const throw();
public:
    virtual ~ServiceUnavailable() throw() {};
};

/** model exception */
class EventModelException: public SienaException {
    /** C-style string representation of what went wrong */
    virtual const char *	what() const throw();
public:
    virtual ~EventModelException() throw() {};
};

/** exception: attribute type mismatch */
class BadType: public EventModelException {
public:
    virtual ~BadType() throw() {};
 public:
    /** wrong type */
    SienaType			type;

				BadType(SienaType);

    /** C-style string representation of what went wrong */
    virtual const char *	what() const throw();
    virtual ostream &		printout(ostream &)		const;
};

/** exception operator mismatch */
class BadOperator: virtual public EventModelException {
public:
    virtual ~BadOperator() throw() {};
public:
    /** wrong operator */
    SienaOperator		op;

				BadOperator(SienaOperator);

    /** C-style string representation of what went wrong */
    virtual const char *	what() const throw();
    virtual ostream &		printout(ostream &)		const;
};

#ifndef NO_INLINE
#include "Siena.icc"
#endif

#ifdef HAVE_CXX_NAMESPACE
};
#endif

#endif
