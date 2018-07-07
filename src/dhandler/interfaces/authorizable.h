//
// Created by dimonchik0036 on 07.07.18.
//

#ifndef TG_CUI_AUTHORIZABLE_H
#define TG_CUI_AUTHORIZABLE_H

#include <string>

class Authorizable {
 public:
  virtual void auth(std::string token) = 0;
};

#endif //TG_CUI_AUTHORIZABLE_H
