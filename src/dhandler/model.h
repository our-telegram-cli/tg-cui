#ifndef TG_CUI_MODEL_H_
#define TG_CUI_MODEL_H_

#include <memory>

#include "interfaces/authorizable.h"

class Model : public Authorizable {
 public:
  Model();
  Model(std::unique_ptr<Authorizable> authorizable);
  void auth(std::string token) override;
  virtual ~Model() = default;

 private:
  std::unique_ptr<Authorizable> authorizable;
};

#endif  // TG_CUI_MODEL_H_
