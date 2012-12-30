/*

 Copyright (C) 2011 Nicki, Bulgaria.

 See the LICENSE file for terms of use.

*/

#ifndef OWNERPRODUCT_H
#define OWNERPRODUCT_H

#include "defines.h"

class OwnerProduct
{
public:
	dbo::ptr<Client> client;
	dbo::ptr<Product> product;
	double quantity;
	double price;
  
  template<class Action> 
  void persist(Action& a)
  {
    dbo::belongsTo(a, product, "product");
    dbo::belongsTo(a, client, "client");
    dbo::field(a, quantity, "quantity");
    dbo::field(a, price, "price");
  }
};

DBO_EXTERN_TEMPLATES(OwnerProduct);

#endif // OWNERPRODUCT_H
