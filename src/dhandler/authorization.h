//
// Created by dimonchik0036 on 07.07.18.
//

#ifndef TG_CUI_AUTH_H
#define TG_CUI_AUTH_H

#include "interfaces/authorizable.h"

class Authorization : public Authorizable {
 public:
  void auth(std::string token) override;
};

#endif  // TG_CUI_AUTH_H
