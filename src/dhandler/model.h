#ifndef TG_CUI_MODEL_H
#define TG_CUI_MODEL_H

#include <memory>

#include "interfaces/authorizable.h"

class Model : public Authorizable {
 public:
  Model();
  Model(std::unique_ptr<Authorizable> authorizable);
  void auth(std::string token) override;

 private:
  std::unique_ptr<Authorizable> authorizable;
};

#endif  // TG_CUI_MODEL_H
