/*
 * Copyright (C) 2011 Nicki, Assenovgrad, Bulgaria.
 *
 * See the LICENSE file for terms of use.
 */

#ifndef JSONUTILS_H
#define JSONUTILS_H

#include <map>
#include <string>
#include <cppcms/json.h>
#include <sstream>

typedef std::map<std::string, std::string> MapString;
typedef std::pair<std::string, std::string> PairString;

class JsonUtils
{
public:
	static cppcms::json::value getJsonElement(std::string tag, MapString& paramsMap);
	static cppcms::json::value getJsonElement(std::string tag, cppcms::json::array& params);
	static cppcms::json::value getJsonElements(MapString& paramsMap);
	template<typename T> static std::string toString(T value){
		std::stringstream st;
		st << value;
		return st.str();
	}
};

#endif // JSONUTILS_H
