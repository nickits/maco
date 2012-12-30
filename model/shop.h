/*
 * Copyright (C) 2011 Nicki, Bulgaria.
 *
 * See the LICENSE file for terms of use.
*/


#ifndef SHOP_H
#define SHOP_H

#include "defines.h"

enum ShopType{
	Store,
	WebSite
};

class Shop
{
public:
	std::string name;
	ShopType type;
	std::string url;
	std::string country;
	std::string town;
	std::string zipCode;
	std::string address;
	std::string phone;
	std::string fax;
	std::string webSite;
	std::string email;
	std::string contactPerson;
	dbo::ptr<Company> company;
	Sales sales;

	template<class Action> 
	void persist(Action& a)
	{
		dbo::field(a, name, "name");
		dbo::field(a, type, "type");
		dbo::field(a, url, "url");
		dbo::field(a, country, "country");
		dbo::field(a, town, "town");
		dbo::field(a, zipCode, "zipCode");
		dbo::field(a, address, "address");
		dbo::field(a, phone, "phone");
		dbo::field(a, fax, "fax");
		dbo::field(a, webSite, "webSite");
		dbo::field(a, email, "email");
		dbo::field(a, contactPerson, "contactPerson");
		dbo::belongsTo(a, company, "company");
		dbo::hasMany(a, sales, dbo::ManyToOne, "shop");
	}
};

DBO_EXTERN_TEMPLATES(Shop);

#endif // SHOP_H
