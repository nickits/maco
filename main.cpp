/*

 Copyright (C) 2011 Nicki, Bulgaria.

 See the LICENSE file for terms of use.

*/

#include "main.h"
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/http_request.h>
#include <cppcms/url_dispatcher.h>
#include <bits/stl_multimap.h>
#include <iostream>
#include <sstream>
#include "model/defines.h"
#include "utils/formgenerator.h"

Main::Main(cppcms::service& srv): application(srv)
{
    dispatcher().assign("/submit", &Main::submit, this);
    dispatcher().assign("/grid/(\\w+)", &Main::grid, this, 1);
    dispatcher().assign("/griddata/(\\w+)", &Main::griddata, this, 1);
    dispatcher().assign("/filterinit/(\\w+)", &Main::filterinit, this, 1);
    dispatcher().assign("/filterpost/(\\w+)", &Main::filterpost, this, 1);
    dispatcher().assign("/form/(\\w+)", &Main::form, this, 1);
    dispatcher().assign("/forminit/(\\w+)/(\\d+)", &Main::forminit, this, 1, 2);
    dispatcher().assign("/formpost/(\\w+)", &Main::formpost, this, 1);
    dispatcher().assign("/delete/(\\w+)/(\\d+)", &Main::del, this, 1, 2);
    dispatcher().assign("/(\\w+)", &Main::admin, this, 1);
}

void Main::main(std::string str)
{
  cppcms::application::main(str);
}
    
void Main::admin(std::string arg)
{
    message_admin_.entity = arg;
	
    session().load();
    int i = 0;
    std::string stri = session().get("iii", "0");
    std::stringstream ss;
    ss.str(stri);
    ss >> i;
    std::cout << i++ << std::endl;
    std::stringstream si;
    si << i;
    std::cout << si.str() << std::endl;
    session().set("iii", si.str());
    std::cout << session().get("iii", "0") << std::endl;
    session().save();
    std::cout << session().age() << std::endl;
    std::cout << session().expiration() << std::endl;

    render("skinback", "admin", message_admin_);
}

void Main::grid(std::string arg)
{
	MapString mapParams;
	getRequestData(mapParams);
	FormGenerator generator(arg, mapParams, session_);
	response().out() << generator.grid();
}

void Main::griddata(std::string arg)
{
	MapString mapParams;
	getRequestData(mapParams);
	FormGenerator generator(arg, mapParams, session_);
	response().out() << generator.grid_data();
}

void Main::filterinit(std::string arg)
{
	MapString mapParams;
	getRequestData(mapParams);
	FormGenerator generator(arg, mapParams, session_);
	response().out() << generator.filter();
}

void Main::filterpost(std::string arg)
{
	MapString mapParams;
	getRequestData(mapParams);
	FormGenerator generator(arg, mapParams, session_);
	response().out() << generator.filterpost();
}

void Main::getRequestData(MapString& mapParams)
{
	cppcms::http::request::form_type req = request().post_or_get();
	for(cppcms::http::request::form_type::iterator i = req.begin(); i != req.end(); ++i){
		mapParams.insert(PairString(i->first, i->second));
	}
}

void Main::admin()
{
}

void Main::form(std::string arg)
{
}

void Main::formpost(std::string arg)
{
	MapString mapParams;
	getRequestData(mapParams);
	FormGenerator generator(arg, mapParams, session_);
	response().out() << generator.formpost();
}

void Main::forminit(std::string arg, std::string id)
{
	MapString mapParams;
	getRequestData(mapParams);
	mapParams.insert(PairString("id", id));
	FormGenerator generator(arg, mapParams, session_);
	response().out() << generator.form();
}

void Main::del(std::string arg, std::string id)
{
	MapString mapParams;
	getRequestData(mapParams);
	mapParams.insert(PairString("id", id));
	FormGenerator generator(arg, mapParams, session_);
	response().out() << generator.del();
}

void Main::submit()
{
  response().out() << "submit";
}
  
int main(int argc,char ** argv)
{
    try {
        cppcms::service srv(argc,argv);
        srv.applications_pool().mount(cppcms::applications_factory<Main>());
        srv.run();
    }
    catch(std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }
}
