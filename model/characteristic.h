/*
 * Copyright (C) 2011 Nicki, Bulgaria.
 *
 * See the LICENSE file for terms of use.
*/


#ifndef CHARACTERISTIC_H
#define CHARACTERISTIC_H

#include "defines.h"

class Characteristic
{
public:
	std::string name;
	std::string description;
	std::string shortDescription;
	dbo::ptr<Category> category;
	ProductCharacteristics productCharacteristics;

	template<class Action> 
	void persist(Action& a)
	{
		dbo::field(a, name, "name");
		dbo::field(a, description, "description");
		dbo::field(a, shortDescription, "shortDescription");
		dbo::belongsTo(a, category, "category");
		dbo::hasMany(a, productCharacteristics, dbo::ManyToOne, "characteristic");
	}
};

DBO_EXTERN_TEMPLATES(Characteristic);

#endif // CHARACTERISTIC_H
