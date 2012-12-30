/*

 Copyright (C) 2011 Nicki, Bulgaria.

 See the LICENSE file for terms of use.

*/

#ifndef VIDEO_H
#define VIDEO_H

#include "defines.h"

class Video
{
public:
  std::string name;
  std::string description;
  std::string url;
  dbo::ptr<Product> product;
  
  template<class Action> 
  void persist(Action& a)
  {
    dbo::field(a, name, "name");
    dbo::field(a, description, "description");	
    dbo::field(a, url, "url");
    dbo::belongsTo(a, product, "product");
  }
};

DBO_EXTERN_TEMPLATES(Video);

#endif // VIDEO_H
