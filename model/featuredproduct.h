/*
 * Copyright (C) 2011 Nicki, Bulgaria.
 *
 * See the LICENSE file for terms of use.
*/


#ifndef FEATUREDPRODUCT_H
#define FEATUREDPRODUCT_H

#include "defines.h"

class FeaturedProduct
{
public:
	std::string name;
	std::string description;
	std::string shortDescription;
	dbo::ptr<Product> product;

	template<class Action> 
	void persist(Action& a)
	{
		dbo::field(a, name, "name");
		dbo::field(a, description, "description");
		dbo::field(a, shortDescription, "shortDescription");
		dbo::belongsTo(a, product, "product");
	}
};

DBO_EXTERN_TEMPLATES(FeaturedProduct);

#endif // FEATUREDPRODUCT_H
