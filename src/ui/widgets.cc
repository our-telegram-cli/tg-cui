
#include "widgets.h"

namespace ui {

void List::Draw(Window& canvas) const {}

void List::MouseInteract(std::size_t x, std::size_t y) {}

void List::KeyboardInteract(int key) {}

void List::AddItem(View* view) {
  items.push_back(view);
}

const View* List::RemoveItem(std::size_t pos) {
  const View* item = items[pos];
  items.erase(items.begin() + pos);
  return item;
}

void DialogsListItem::Draw(Window& canvas) const {}

void DialogsListItem::MouseInteract(std::size_t x, std::size_t y) {}

void DialogsListItem::KeyboardInteract(int key) {}

}  // namespace ui
