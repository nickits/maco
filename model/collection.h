/*

 Copyright (C) 2011 Nicki, Bulgaria.

 See the LICENSE file for terms of use.

*/

#ifndef COLLECTION_H
#define COLLECTION_H

#include "defines.h"

class Collection
{
public:
  std::string name;
  std::string description;
  Products products;
  
  template<class Action> 
  void persist(Action& a)
  {
    dbo::field(a, name, "name");
    dbo::field(a, description, "description");
    dbo::hasMany(a, products, dbo::ManyToOne, "collection");
  }

};

DBO_EXTERN_TEMPLATES(Collection);

#endif // COLLECTION_H
