/*
 * Copyright (C) 2011 Nicki, Bulgaria.
 *
 * See the LICENSE file for terms of use.
*/


#ifndef PRODUCTCHARACTERISTIC_H
#define PRODUCTCHARACTERISTIC_H

#include "defines.h"

class ProductCharacteristic
{
public:
	dbo::ptr<Product> product;
	dbo::ptr<Characteristic> characteristic;
	double quantity;
	double priceCorrection;
  
  template<class Action> 
  void persist(Action& a)
  {
    dbo::belongsTo(a, product, "product");
    dbo::belongsTo(a, characteristic, "characteristic");
    dbo::field(a, quantity, "quantity");
    dbo::field(a, priceCorrection, "priceCorrection");
  }
};

DBO_EXTERN_TEMPLATES(ProductCharacteristic);

#endif // PRODUCTCHARACTERISTIC_H
