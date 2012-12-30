/*

 Copyright (C) 2011 Nicki, Bulgaria.

 See the LICENSE file for terms of use.

*/

#ifndef CLIENT_H
#define CLIENT_H

#include "defines.h"

enum ClientType{
	Business,
	Individual
};

class Client
{
public:
	std::string userName;
	std::string password;
	ClientType type;
	std::string name;
	std::string lastName;
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
	double discount;
	OwnerProducts ownerProducts;
	Sales salles;
	Sales buyes;
	
  template<class Action> 
  void persist(Action& a)
  {
	dbo::field(a, userName, "userName");
	dbo::field(a, password, "password");
	dbo::field(a, type, "type");
	dbo::field(a, name, "name");
	dbo::field(a, lastName, "lastName");
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
	dbo::field(a, discount, "discount");
	dbo::hasMany(a, ownerProducts, dbo::ManyToOne, "client");
	dbo::hasMany(a, buyes, dbo::ManyToOne, "client");
	dbo::hasMany(a, salles, dbo::ManyToOne, "saller");
  }
};

DBO_EXTERN_TEMPLATES(Client);

#endif // CLIENT_H
