/*
 * Copyright (C) 2011 Nicki, Assenovgrad, Bulgaria.
 *
 * See the LICENSE file for terms of use.
 */

#include "baseservice.h"

//template <class T>
// BaseService<T>::BaseService(DataSession* session)
// {
// 	session_ = session;
// }

template <class T>
BaseService<T>::BaseService()
{

}

template <class T>
BaseService<T>::BaseService(DataSession* session)
{
	session_ = session;
}

template <class T>
void BaseService<T>::setSession(DataSession* session)
{
	session_ = session;
}
