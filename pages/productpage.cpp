/*
 * Copyright (C) 2011 Nicki, Bulgaria.
 *
 * See the LICENSE file for terms of use.
*/


#include "productpage.h"
#include "../model/defines.h"
#include "Wt/Dbo/Impl"
#include "../utils/jsonutils.h"

ProductPage::ProductPage(DataSession* session, FormGenerator* generator) 
: BasePage(session, generator)
//, service_(session)
{
	service_.setSession(session);
}

ProductPage::~ProductPage()
{

}

cppcms::json::value ProductPage::grid_data()
{
	cppcms::json::value val;
	cppcms::json::array arr;
	std::stringstream st;
	int page = 0;
	int perpage = 0;
	std::string sortby = "";
	generator_->getRequestParam("perpage") >> perpage;
	generator_->getRequestParam("page") >> page;
	generator_->getRequestParam("sortby") >> sortby;

	dbo::Transaction transaction(*session_);

	Products products = session_->find<Product>().offset((page-1)*perpage).limit(perpage);
	int total = session_->query<int>("select count(*) from product");
	

	for	(Products::const_iterator i = products.begin(); i != products.end(); ++i){
		cppcms::json::value valData;
		st.str("");
		st << i->id();
		valData.at("id", st.str());
		st.str("");
		st << (*i)->name;
		valData.at("name", st.str());
		st.str("");
		st << (*i)->description;
		valData.at("description", st.str());
		if((*i)->category){
			st.str("");
			st << (*i)->category->name;
			valData.at("category", st.str());
		}
		if((*i)->collection){
			st.str("");
			st << (*i)->collection->name;
			valData.at("collection", st.str());
		}
		arr.push_back(valData);
	}

	transaction.commit();

	val.at("page", page);
	val.at("total", total);
	val.at("data", arr);

	return val;
}

cppcms::json::value ProductPage::grid()
{
	cppcms::json::value val;
	cppcms::json::array columns;
	cppcms::json::value column;
	column.at("header", "Id");
	column.at("dataIndex", "id");
	column.at("dataType", "number");
//	column.at("hidden", "true");
	column.at("width", 100);
	columns.push_back(column);
	column.at("header", "Name");
	column.at("dataIndex", "name");
	column.at("dataType", "string");
	column.at("width", 100);
	columns.push_back(column);
	column.at("header", "Description");
	column.at("dataIndex", "description");
	column.at("dataType", "string");
	column.at("width", 200);
	columns.push_back(column);
	column.at("header", "Category");
	column.at("dataIndex", "category");
	column.at("dataType", "string");
	column.at("width", 100);
	columns.push_back(column);
	column.at("header", "Collection");
	column.at("dataIndex", "collection");
	column.at("dataType", "string");
	column.at("width", 100);
	columns.push_back(column);
	val.at("width", 600);
	val.at("height", 330);
	val.at("columns", columns);
	return val;
}

cppcms::json::value ProductPage::filter()
{
	MapString mapParams;
	///fields
	cppcms::json::value val;
	cppcms::json::array form_arr;
	///Name
	mapParams.insert(PairString("type", "text"));
	mapParams.insert(PairString("value", "test"));
	mapParams.insert(PairString("class", "required"));
	mapParams.insert(PairString("name", "name"));
	mapParams.insert(PairString("title", "Name"));
	form_arr.push_back(JsonUtils::getJsonElement("input", mapParams));
	///email
	mapParams.clear();
	mapParams.insert(PairString("type", "text"));
	mapParams.insert(PairString("value", ""));
	mapParams.insert(PairString("class", "required validate-email"));
	mapParams.insert(PairString("name", "email"));
	mapParams.insert(PairString("title", "Email"));
	form_arr.push_back(JsonUtils::getJsonElement("input", mapParams));
	///Phone
	mapParams.clear();
	mapParams.insert(PairString("type", "text"));
	mapParams.insert(PairString("class", "required"));
	mapParams.insert(PairString("name", "phone"));
	mapParams.insert(PairString("title", "Phone"));
	form_arr.push_back(JsonUtils::getJsonElement("input", mapParams));
	///Url
	mapParams.clear();
	mapParams.insert(PairString("type", "text"));
	mapParams.insert(PairString("class", "required"));
	mapParams.insert(PairString("name", "url"));
	mapParams.insert(PairString("title", "Website / blog"));
	form_arr.push_back(JsonUtils::getJsonElement("input", mapParams));
	///Message
	mapParams.clear();
	mapParams.insert(PairString("class", "required"));
	mapParams.insert(PairString("name", "message"));
	mapParams.insert(PairString("title", "Message"));
	mapParams.insert(PairString("id", "myMessage"));
	mapParams.insert(PairString("rows", "5"));
	mapParams.insert(PairString("cols", "30"));
	form_arr.push_back(JsonUtils::getJsonElement("textarea", mapParams));
	mapParams.clear();
	///Newsletter
	cppcms::json::array radiogroup;
	mapParams.insert(PairString("text", "Would you like to <something>?"));
	radiogroup.push_back(JsonUtils::getJsonElement("label", mapParams));
	///Newsletter yes
	mapParams.clear();
	mapParams.insert(PairString("type", "radio"));
	mapParams.insert(PairString("name", "newsletter"));
	mapParams.insert(PairString("id", "news_y"));
	radiogroup.push_back(JsonUtils::getJsonElement("input", mapParams));
	mapParams.clear();
	mapParams.insert(PairString("text", "Yes"));
	mapParams.insert(PairString("for", "news_y"));
	radiogroup.push_back(JsonUtils::getJsonElement("label", mapParams));
	///Newsletter no
	mapParams.clear();
	mapParams.insert(PairString("type", "radio"));
	mapParams.insert(PairString("class", "validate-one-required"));
	mapParams.insert(PairString("name", "newsletter"));
	mapParams.insert(PairString("id", "news_n"));
	radiogroup.push_back(JsonUtils::getJsonElement("input", mapParams));
	mapParams.clear();
	mapParams.insert(PairString("text", "No"));
	mapParams.insert(PairString("for", "news_n"));
	radiogroup.push_back(JsonUtils::getJsonElement("label", mapParams));
	///Newsletter group
	form_arr.push_back(JsonUtils::getJsonElement("group", radiogroup));

	///buttons
	cppcms::json::array form_buttons;
	///Apply
	mapParams.clear();
	mapParams.insert(PairString("type", "button"));
	mapParams.insert(PairString("value", "Apply"));
	form_buttons.push_back(JsonUtils::getJsonElement("filterButton", mapParams));
	///Reset
	mapParams.clear();
	mapParams.insert(PairString("type", "reset"));
	mapParams.insert(PairString("value", "Reset"));
	form_buttons.push_back(JsonUtils::getJsonElement("input", mapParams));

	///structure
	val.at("fieldset", "Products filter");
	val.at("data", form_arr);
	val.at("buttons", form_buttons);
	return val;
}

cppcms::json::value ProductPage::filterpost()
{
	cppcms::json::value val;
	std::string name = "";
	generator_->getRequestParam("name") >> name;
	val.at("postname", name);
	return val;
}

cppcms::json::value ProductPage::form()
{
	dbo::Transaction transaction(*session_);

	int id;
	generator_->getRequestParam("id") >> id;
	dbo::ptr<Product> product = session_->find<Product>().where("id = ?").bind(id);

	MapString mapParams;
	///fields
	cppcms::json::value val;
	cppcms::json::array form_arr;
	cppcms::json::value data;
	
	///id
	mapParams.insert(PairString("type", "hidden"));
//	mapParams.insert(PairString("value", JsonUtils::toString<int>(id)));
	mapParams.insert(PairString("name", "id"));
	form_arr.push_back(JsonUtils::getJsonElement("input", mapParams));
	data.at("id", id);
	///Name
	mapParams.clear();
	mapParams.insert(PairString("type", "text"));
//	if(product) mapParams.insert(PairString("value", product->name));
	mapParams.insert(PairString("class", "required"));
	mapParams.insert(PairString("name", "name"));
	mapParams.insert(PairString("title", "Name"));
	form_arr.push_back(JsonUtils::getJsonElement("input", mapParams));
	if(product) data.at("name", product->name);

	///email
	mapParams.clear();
	mapParams.insert(PairString("type", "text"));
//	if(product) mapParams.insert(PairString("value", product->description));
	mapParams.insert(PairString("class", "required validate-email"));
	mapParams.insert(PairString("name", "email"));
	mapParams.insert(PairString("title", "Email"));
	form_arr.push_back(JsonUtils::getJsonElement("input", mapParams));
	if(product) data.at("email", product->description);
	///Phone
	mapParams.clear();
	mapParams.insert(PairString("type", "text"));
	mapParams.insert(PairString("class", "required"));
	mapParams.insert(PairString("name", "phone"));
	mapParams.insert(PairString("title", "Phone"));
	form_arr.push_back(JsonUtils::getJsonElement("input", mapParams));
	///Url
	mapParams.clear();
	mapParams.insert(PairString("type", "text"));
	mapParams.insert(PairString("class", "required"));
	mapParams.insert(PairString("name", "url"));
	mapParams.insert(PairString("title", "Website / blog"));
	form_arr.push_back(JsonUtils::getJsonElement("input", mapParams));
	///Message
	mapParams.clear();
	mapParams.insert(PairString("class", "required"));
	mapParams.insert(PairString("name", "message"));
	mapParams.insert(PairString("title", "Message"));
	mapParams.insert(PairString("id", "myMessage"));
	mapParams.insert(PairString("rows", "5"));
	mapParams.insert(PairString("cols", "30"));
	form_arr.push_back(JsonUtils::getJsonElement("textarea", mapParams));
	///Select
	mapParams.clear();
	mapParams.insert(PairString("class", "required"));
	mapParams.insert(PairString("name", "choose"));
	mapParams.insert(PairString("title", "Choose"));
	mapParams.insert(PairString("id", "myChoose"));
	cppcms::json::value select = JsonUtils::getJsonElement("select", mapParams);
	cppcms::json::array options;
	mapParams.clear();
	mapParams.insert(PairString("value", "1"));
	mapParams.insert(PairString("text", "Option1"));
	options.push_back(JsonUtils::getJsonElement("option", mapParams));
	mapParams.clear();
	mapParams.insert(PairString("value", "2"));
	mapParams.insert(PairString("text", "Option2"));
	options.push_back(JsonUtils::getJsonElement("option", mapParams));
	mapParams.clear();
	mapParams.insert(PairString("value", "3"));
	mapParams.insert(PairString("text", "Option3"));
	options.push_back(JsonUtils::getJsonElement("option", mapParams));
	select.at("options", options);
	form_arr.push_back(select);
	data.at("choose", "3");
	mapParams.clear();
	///Newsletter
	cppcms::json::array radiogroup;
	mapParams.insert(PairString("text", "Would you like to <something>?"));
	radiogroup.push_back(JsonUtils::getJsonElement("label", mapParams));
	///Newsletter yes
	mapParams.clear();
	mapParams.insert(PairString("type", "radio"));
	mapParams.insert(PairString("name", "newsletter"));
	mapParams.insert(PairString("id", "news_y"));
	radiogroup.push_back(JsonUtils::getJsonElement("input", mapParams));
	mapParams.clear();
	mapParams.insert(PairString("text", "Yes"));
	mapParams.insert(PairString("for", "news_y"));
	radiogroup.push_back(JsonUtils::getJsonElement("label", mapParams));
	///Newsletter no
	mapParams.clear();
	mapParams.insert(PairString("type", "radio"));
	mapParams.insert(PairString("class", "validate-one-required"));
	mapParams.insert(PairString("name", "newsletter"));
	mapParams.insert(PairString("id", "news_n"));
	radiogroup.push_back(JsonUtils::getJsonElement("input", mapParams));
	mapParams.clear();
	mapParams.insert(PairString("text", "No"));
	mapParams.insert(PairString("for", "news_n"));
	radiogroup.push_back(JsonUtils::getJsonElement("label", mapParams));
	///Newsletter group
	form_arr.push_back(JsonUtils::getJsonElement("group", radiogroup));

	transaction.commit();

	///buttons
	cppcms::json::array form_buttons;
	///Send
	mapParams.clear();
	mapParams.insert(PairString("type", "submit"));
	mapParams.insert(PairString("event", "close"));
	mapParams.insert(PairString("value", "Send"));
	form_buttons.push_back(JsonUtils::getJsonElement("input", mapParams));
	///Reset
	mapParams.clear();
	mapParams.insert(PairString("type", "reset"));
	mapParams.insert(PairString("value", "Reset"));
	form_buttons.push_back(JsonUtils::getJsonElement("input", mapParams));
	///Cancel
	mapParams.clear();
	mapParams.insert(PairString("type", "button"));
	mapParams.insert(PairString("event", "close"));
	mapParams.insert(PairString("value", "Cancel"));
	form_buttons.push_back(JsonUtils::getJsonElement("input", mapParams));

	///structure
	val.at("fieldset", "Product");
	val.at("structure", form_arr);
	val.at("data", data);
	val.at("buttons", form_buttons);
	return val;
}

cppcms::json::value ProductPage::formpost()
{
	cppcms::json::value val;
	int id;
	std::string name, description;
	
	generator_->getRequestParam("id") >> id;
	generator_->getRequestParam("name") >> name;
	generator_->getRequestParam("email") >> description;
	
	dbo::Transaction transaction(*session_);

	dbo::ptr<Product> product;
	if(id > 0){
		product = session_->find<Product>().where("id = ?").bind(id);
	}
	else{
		product = session_->add(new Product());
	}
	product.modify()->name = name;
	product.modify()->description = description;
	
	transaction.commit();
	
	val.at("result", "success");
	return val;
}

cppcms::json::value ProductPage::del()
{
	cppcms::json::value val;
	int id;
	std::string name, description;
	
	generator_->getRequestParam("id") >> id;
	
	dbo::Transaction transaction(*session_);

	session_->execute("delete from product where id = ?").bind(id);
	
	transaction.commit();
	
	val.at("result", "success");
	return val;
}
