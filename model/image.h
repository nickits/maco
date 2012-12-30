/*

 Copyright (C) 2011 Nicki, Bulgaria.

 See the LICENSE file for terms of use.

*/

#ifndef IMAGE_H
#define IMAGE_H

#include "defines.h"

class Image
{
public:
  std::string name;
  std::string description;
  std::string url;
  std::string urlThumb;
  std::string urlSmall;
  std::string urlMedium;
  dbo::ptr<Product> product;
  
  template<class Action> 
  void persist(Action& a)
  {
    dbo::field(a, name, "name");
    dbo::field(a, description, "description");	
    dbo::field(a, url, "url");
    dbo::field(a, urlThumb, "urlThumb");
    dbo::field(a, urlSmall, "urlSmall");
    dbo::field(a, urlMedium, "urlMedium");
    dbo::belongsTo(a, product, "product");
  }
};

DBO_EXTERN_TEMPLATES(Image);

#endif // IMAGE_H
