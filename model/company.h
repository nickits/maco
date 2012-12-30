/*
 * Copyright (C) 2011 Nicki, Bulgaria.
 *
 * See the LICENSE file for terms of use.
*/


#ifndef COMPANY_H
#define COMPANY_H

#include "defines.h"

class Company
{
public:
	std::string name;
	std::string identityNumber;
	std::string country;
	std::string town;
	std::string zipCode;
	std::string address;
	std::string phone;
	std::string fax;
	std::string webSite;
	std::string email;
	std::string contactPerson;
	Shops shops;

	template<class Action> 
	void persist(Action& a)
	{
		dbo::field(a, name, "name");
		dbo::field(a, identityNumber, "identityNumber");
		dbo::field(a, country, "country");
		dbo::field(a, town, "town");
		dbo::field(a, zipCode, "zipCode");
		dbo::field(a, address, "address");
		dbo::field(a, phone, "phone");
		dbo::field(a, fax, "fax");
		dbo::field(a, webSite, "webSite");
		dbo::field(a, email, "email");
		dbo::field(a, contactPerson, "contactPerson");
		dbo::hasMany(a, shops, dbo::ManyToOne, "company");
	}

};

DBO_EXTERN_TEMPLATES(Company);

#endif // COMPANY_H
