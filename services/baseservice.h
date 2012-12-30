/*
 * Copyright (C) 2011 Nicki, Bulgaria.
 *
 * See the LICENSE file for terms of use.
*/


#ifndef BASESERVICE_H
#define BASESERVICE_H
#include "../utils/jsonutils.h"
#include "../model/defines.h"
#include "../datasession.h"

template <class T>
class BaseService
{
protected:
	DataSession* session_;
public:
	BaseService();
	BaseService(DataSession* session);

	virtual void setSession(DataSession* session);
	virtual T get(MapAny& params) = 0;
	virtual dbo::collection<dbo::ptr<T> > listAll() = 0;
	virtual dbo::collection<dbo::ptr<T> > list(MapAny& params) = 0;
	virtual void save(T& entity) = 0;
};

#include "baseservice.cpp"

#endif // BASESERVICE_H
