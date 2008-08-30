/*
 *
 *  D-Bus++ - C++ bindings for D-Bus
 *
 *  Copyright (C) 2005-2007  Paolo Durante <shackan@gmail.com>
 *
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */


#ifndef __DBUSXX_ECORE_INTEGRATION_H
#define __DBUSXX_ECORE_INTEGRATION_H

#include <Ecore.h>

#include "api.h"
#include "dispatcher.h"
#include "Ecore.h"

namespace DBus {

namespace Ecore {

class BusDispatcher;

class DXXAPI BusTimeout : public Timeout
{
private:

	BusTimeout( Timeout::Internal*/*, GMainContext* */);

	~BusTimeout();

	void toggle();

	static int timeout_handler( void* );

	void _enable();

	void _disable();

private:
  Ecore_Timer *_etimer;
	//GSource* _source;
	//GMainContext* _ctx;

friend class BusDispatcher;
};

class DXXAPI BusWatch : public Watch
{
private:

	BusWatch( Watch::Internal*/*, GMainContext* */);

	~BusWatch();

	void toggle();

	static int watch_handler_read ( void*, Ecore_Fd_Handler *fdh);
    
  static int watch_handler_error ( void*, Ecore_Fd_Handler *fdh);

	void _enable();

	void _disable();

private:
  //GSource* _source;
	//GMainContext* _ctx;
  Ecore_Fd_Handler *fd_handler_read;
  Ecore_Fd_Handler *fd_handler_error;

friend class BusDispatcher;
};

class DXXAPI BusDispatcher : public Dispatcher
{
public:
	BusDispatcher() /*: _ctx(NULL) */{}

	void attach(/* GMainContext* */);

	void enter() {}

	void leave() {}

	Timeout* add_timeout( Timeout::Internal* );

	void rem_timeout( Timeout* );

	Watch* add_watch( Watch::Internal* );

	void rem_watch( Watch* );

private:

	//GMainContext* _ctx;
};

} /* namespace Ecore */

} /* namespace DBus */

#endif//__DBUSXX_ECORE_INTEGRATION_H
