#include "model.h"
#include "authorization.h"

void Model::auth(std::string token) {
  authorizable->auth(token);
}

Model::Model()
    : authorizable(std::make_unique<Authorization>(Authorization())) {}

Model::Model(std::unique_ptr<Authorizable> authorizable)
    : authorizable(std::move(authorizable)){};