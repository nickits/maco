/*
 * Copyright (C) 2011 Nicki, Bulgaria.
 *
 * See the LICENSE file for terms of use.
*/


#ifndef SALE_H
#define SALE_H

#include "defines.h"

enum SaleStatus{
	SaleQuery,
	SaleOrder,
 	SaleDispatch,
	SaleInProgress,
	SaleDelivered	
};

class Sale
{
public:
	dbo::ptr<Client> client;
	dbo::ptr<Client> saller;
	dbo::ptr<Payment> payment;
	dbo::ptr<Shop> shop;
	time_t orderDate;
	time_t saleDate;
	SaleStatus status;
	double discount;
	double total;
	SaleDetails details;
	
	template<class Action> 
	void persist(Action& a)
	{
		dbo::belongsTo(a, saller, "saller");
		dbo::belongsTo(a, client, "client");
		dbo::belongsTo(a, shop, "shop");
		dbo::belongsTo(a, payment, "payment");
		dbo::field(a, orderDate, "orderDate");
		dbo::field(a, saleDate, "saleDate");
		dbo::field(a, status, "status");
		dbo::field(a, discount, "discount");
		dbo::field(a, total, "total");
		dbo::hasMany(a, details, dbo::ManyToOne, "sale");
	}

};

DBO_EXTERN_TEMPLATES(Sale);

#endif // SALE_H
