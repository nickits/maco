/*
 * Copyright (C) 2011 Nicki, Assenovgrad, Bulgaria.
 *
 * See the LICENSE file for terms of use.
 */

#include "productsservice.h"

ProductsService::ProductsService(): BaseService< Product >()
{

}

ProductsService::ProductsService(DataSession* session) : BaseService< Product >(session)
{

}

Product ProductsService::get(MapAny& params)
{
	//return BaseService< Product >::get(params);
}
Products ProductsService::list(MapAny& params)
{
}

Products ProductsService::listAll()
{

}
void ProductsService::save(Product& entity)
{
	//BaseService< Product >::save(entity);
}
