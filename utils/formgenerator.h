/*
 Copyright (C) 2011 Nicki, Bulgaria.

 See the LICENSE file for terms of use.
*/

#ifndef FORMGENERATOR_H
#define FORMGENERATOR_H

#include "jsonutils.h"
#include <sstream>
#include "../datasession.h"

class BasePage;
class FormGenerator
{
private:
  MapString* params_;
  std::istringstream ssParam_;
  BasePage* page;
  
public:
	FormGenerator();
	FormGenerator(std::string& entity, MapString& params, DataSession& session);
	virtual ~FormGenerator();
	
	cppcms::json::value grid();
	cppcms::json::value grid_data();
	cppcms::json::value filter();  
	cppcms::json::value filterpost();  
	cppcms::json::value form();  
	cppcms::json::value formpost();  
	cppcms::json::value del();
	std::istringstream& getRequestParam(std::string param);
};

#endif // FORMGENERATOR_H
