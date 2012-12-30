/*
 * Copyright (C) 2011 Nicki, Assenovgrad, Bulgaria.
 *
 * See the LICENSE file for terms of use.
 */


#include "jsonutils.h"

cppcms::json::value JsonUtils::getJsonElement(std::string tag, MapString& paramsMap)
{
  cppcms::json::value element;
  cppcms::json::value params;
  for(MapString::iterator p = paramsMap.begin(); p != paramsMap.end(); p++)
  {
    params.at(p->first, p->second);
  }
  element.at("tag", tag);
  element.at("params", params);
  return element;
}

cppcms::json::value JsonUtils::getJsonElement(std::string tag, cppcms::json::array& params)
{
  cppcms::json::value element;
  element.at("tag", tag);
  element.at("params", params);
  return element;
}

cppcms::json::value JsonUtils::getJsonElements(MapString& paramsMap)
{
  cppcms::json::value params;
  for(MapString::iterator p = paramsMap.begin(); p != paramsMap.end(); p++)
  {
    params.at(p->first, p->second);
  }
  return params;
}
