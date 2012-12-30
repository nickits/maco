/*
 * Copyright (C) 2011 Nicki, Bulgaria.
 *
 * See the LICENSE file for terms of use.
*/


#ifndef PRODUCTPAGE_H
#define PRODUCTPAGE_H
#include "basepage.h"
#include "../services/productsservice.h"

class ProductPage : public BasePage
{
private:
	ProductsService service_;
public:
	ProductPage(DataSession* session, FormGenerator* generator);
	virtual ~ProductPage();

	virtual cppcms::json::value grid();
	virtual cppcms::json::value grid_data();
	virtual cppcms::json::value form();  
	virtual cppcms::json::value formpost();
	virtual cppcms::json::value filter();  
	virtual cppcms::json::value filterpost();
	virtual cppcms::json::value del();
};

#endif // PRODUCTPAGE_H
