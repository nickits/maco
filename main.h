/*

 Copyright (C) 2011 Nicki, Bulgaria.

 See the LICENSE file for terms of use.

*/

#ifndef MAIN_H
#define MAIN_H
#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include "datasession.h"
#include "utils/jsonutils.h"
#include "view/admin.h"

typedef std::pair<std::string, std::string> PairString;

class Main : public cppcms::application
{
public:
  Main(cppcms::service& srv);
  
  virtual void main(std::string str);
  void index();
  void admin(std::string arg);
  void admin();
  void formpost(std::string arg);
  void forminit(std::string arg, std::string id);
  void form(std::string arg);
  void submit();
  void grid(std::string arg);
  void griddata(std::string arg);
  void filterpost(std::string arg);
  void filterinit(std::string arg);
  void del(std::string arg, std::string id);
  
private:
  void getRequestData(MapString& params);
  
  DataSession session_;
  back::admin message_admin_;
  std::string selCategory;
  std::string selCollection;
};

#endif // MAIN_H
