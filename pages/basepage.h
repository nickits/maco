/*
 * Copyright (C) 2011 Nicki, Bulgaria.
 *
 * See the LICENSE file for terms of use.
*/


#ifndef BASEPAGE_H
#define BASEPAGE_H

#include <cppcms/json.h>
#include "../utils/jsonutils.h"
#include "../utils/formgenerator.h"

class BasePage
{

protected:
	DataSession* session_;
	FormGenerator* generator_;
public:
	BasePage(DataSession* session, FormGenerator* generator);
	virtual ~BasePage();

	virtual cppcms::json::value grid();
	virtual cppcms::json::value grid_data();
	virtual cppcms::json::value form();  
	virtual cppcms::json::value formpost();
	virtual cppcms::json::value filter();  
	virtual cppcms::json::value filterpost();
	virtual cppcms::json::value del();
};

#endif // BASEPAGE_H
