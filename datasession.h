/*

 Copyright (C) 2011 Nicki, Bulgaria.

 See the LICENSE file for terms of use.

*/

#ifndef DATASESSION_H
#define DATASESSION_H
#include <string>
#include <Wt/Dbo/backend/Sqlite3>
#include <Wt/Dbo/Session>

namespace dbo = Wt::Dbo;

class DataSession : public dbo::Session
{
public:
  DataSession();
  
private:
  void initialize();

  dbo::backend::Sqlite3 connection_;

};

#endif // DATASESSION_H
