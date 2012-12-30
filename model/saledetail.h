/*
 * Copyright (C) 2011 Nicki, Bulgaria.
 *
 * See the LICENSE file for terms of use.
*/


#ifndef SALEDETAIL_H
#define SALEDETAIL_H

#include "defines.h"

class SaleDetail
{
public:
	dbo::ptr<Sale> sale;
	dbo::ptr<Product> product;
	double price;
	double quantty;
	double discount;
	double total;
	
	template<class Action> 
	void persist(Action& a)
	{
		dbo::belongsTo(a, sale, "sale");
		dbo::belongsTo(a, product, "product");
		dbo::field(a, price, "price");
		dbo::field(a, quantty, "quantty");
		dbo::field(a, discount, "discount");
		dbo::field(a, total, "total");
	}

};

DBO_EXTERN_TEMPLATES(SaleDetail);

#endif // SALEDETAIL_H
