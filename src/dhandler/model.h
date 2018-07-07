#ifndef TG_CUI_MODEL_H
#define TG_CUI_MODEL_H

#include "interfaces/authorizable.h"

class Model : public Authorizable {
 public:
  void auth() override;
 private:
  Authorizable authorizable;
};

#endif  // TG_CUI_MODEL_H
