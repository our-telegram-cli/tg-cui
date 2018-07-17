
#include "view.h"

namespace ui {

bool Window::AddView(View* view) {
  views.push_back(view);
  return true;
}

bool Window::RemoveView(const View* view) {
  return false;
}

bool Window::ContainsView(const View* view) const {
  return false;
}

bool Window::FocusAt(View* view) {
  if (view != nullptr && !ContainsView(view))
    return false;
  focus = view;
  return true;
}

void View::SetFocused(bool focused) {
  if (focused)
    window.FocusAt(this);
  else
    window.FocusAt(nullptr);
}

}  // namespace ui
