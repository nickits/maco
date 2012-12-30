/*
 * Copyright (C) 2011 Nicki, Bulgaria.
 *
 * See the LICENSE file for terms of use.
*/


#include "basepage.h"

BasePage::BasePage(DataSession* session, FormGenerator* generator)
{
	session_ = session;
	generator_ = generator;
}

BasePage::~BasePage()
{

}

cppcms::json::value BasePage::grid_data()
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
  
  for(int i = 0; i < perpage; i++){
    cppcms::json::value valData;
    int index = (page-1)*10 + i + 1;
    st.str("");
    st << "name" << index;
    valData.at("name", st.str());
    st.str("");
    st << "description" << index;
    valData.at("description", st.str());
    st.str("");
    st << "category" << index;
    valData.at("category", st.str());
    st.str("");
    st << "collection" << index;
    valData.at("collection", st.str());
    arr.push_back(valData);
  }
  
  val.at("page", page);
  val.at("total", 48);
  val.at("data", arr);
  return val;
}

cppcms::json::value BasePage::grid()
{
  cppcms::json::value val;
  cppcms::json::array columns;
  cppcms::json::value column;
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

cppcms::json::value BasePage::filter()
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
	mapParams.insert(PairString("type", "submit"));
	mapParams.insert(PairString("value", "Apply"));
	form_buttons.push_back(JsonUtils::getJsonElement("input", mapParams));
	///Reset
	mapParams.clear();
	mapParams.insert(PairString("type", "reset"));
	mapParams.insert(PairString("value", "Reset"));
	form_buttons.push_back(JsonUtils::getJsonElement("input", mapParams));

	///structure
	val.at("fieldset", "Product");
	val.at("data", form_arr);
	val.at("buttons", form_buttons);
	return val;
}

cppcms::json::value BasePage::filterpost()
{
	cppcms::json::value val;
	std::string name = "";
	generator_->getRequestParam("name") >> name;
	val.at("postname", name);
	return val;
}

cppcms::json::value BasePage::form()
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
	///Send
	mapParams.clear();
	mapParams.insert(PairString("type", "submit"));
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
	mapParams.insert(PairString("value", "Cancel"));
	form_buttons.push_back(JsonUtils::getJsonElement("input", mapParams));

	///structure
	val.at("fieldset", "Product");
	val.at("data", form_arr);
	val.at("buttons", form_buttons);
	return val;
}

cppcms::json::value BasePage::formpost()
{
	cppcms::json::value val;
	std::string name = "";
	generator_->getRequestParam("name") >> name;
	val.at("postname", name);
	return val;
}

cppcms::json::value BasePage::del()
{
	cppcms::json::value val;
	val.at("result", "success");
	return val;
}

