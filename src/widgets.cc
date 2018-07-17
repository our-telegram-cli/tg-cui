
#include "widgets.h"

namespace ui {

void List::Draw() const {}

void List::MouseInteract(std::size_t x, std::size_t y) {
  View::MouseInteract(x, y);
}

void List::KeyboardInteract(int key) {}

void List::AddItem(const View* view) {
  items.push_back(view);
}

const View* List::RemoveItem(std::size_t pos) {
  const View* item = items[pos];
  items.erase(items.begin() + pos);
  return item;
}

void DialogsListItem::Draw() const {}

void InputField::Draw() const {}

void InputField::MouseInteract(std::size_t x, std::size_t y) {
  View::MouseInteract(x, y);
}

void InputField::KeyboardInteract(int key) {}

const std::string& InputField::GetText() const {
  return input;
}

void InputField::SetText(const std::string& str) {
  input = str;
}

void InputField::ClearText() {
  SetText("");
}

}  // namespace ui
