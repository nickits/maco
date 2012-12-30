/*
 Copyright (C) 2011 Nicki, Bulgaria.

 See the LICENSE file for terms of use.
*/

#include "formgenerator.h"
#include "../pages/basepage.h"
#include "../pages/productpage.h"

FormGenerator::FormGenerator()
{
	page = 0;
}

FormGenerator::FormGenerator(std::string& entity, MapString& params, DataSession& session)
{
	params_ = &params;
	page = 0;
	if(entity.compare("products") == 0){
		page = new ProductPage(&session, this);
	}
	else{
		page = new BasePage(&session, this);
	}
}

FormGenerator::~FormGenerator()
{
	if(page) delete page;
}

//use for all entities
//----------------------
cppcms::json::value FormGenerator::form()
{
	return page->form();
}

cppcms::json::value FormGenerator::formpost()
{
	return page->formpost();
}

cppcms::json::value FormGenerator::grid()
{
	return page->grid();
}

cppcms::json::value FormGenerator::grid_data()
{
	return page->grid_data();
}

cppcms::json::value FormGenerator::filter()
{
	return page->filter();
}

cppcms::json::value FormGenerator::filterpost()
{
	return page->filterpost();
}

cppcms::json::value FormGenerator::del()
{
	return page->del();
}

//----------------------

std::istringstream& FormGenerator::getRequestParam(std::string param)
{
  ssParam_.clear();
  ssParam_.str((*params_)[param]);
  //ssParam.imbue(context().locale());
  return ssParam_;
}
