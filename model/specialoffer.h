/*
 * Copyright (C) 2011 Nicki, Bulgaria.
 *
 * See the LICENSE file for terms of use.
*/


#ifndef SPECIALOFFER_H
#define SPECIALOFFER_H

#include "defines.h"

class SpecialOffer
{
public:
	std::string name;
	std::string description;
	std::string shortDescription;
	time_t startDate;
	time_t endDate;
	double discount;
	double price;
	dbo::ptr<Product> product;

	template<class Action> 
	void persist(Action& a)
	{
		dbo::field(a, name, "name");
		dbo::field(a, description, "description");
		dbo::field(a, shortDescription, "shortDescription");
		dbo::field(a, startDate, "startDate");
		dbo::field(a, endDate, "endDate");
		dbo::field(a, discount, "discount");
		dbo::field(a, price, "price");
		dbo::belongsTo(a, product, "product");
	}
};

DBO_EXTERN_TEMPLATES(SpecialOffer);

#endif // SPECIALOFFER_H
