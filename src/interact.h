#ifndef TG_CUI_INTERACT_H_
#define TG_CUI_INTERACT_H_

#include <cstddef>

#include "view.h"

namespace ui {

/**
 * Interaction event with Interactable.
 * V is Interactable element type.
 * D is Event data type.
 */
template <typename V, typename D>
class InteractEvent {
 public:
  InteractEvent(const V& view, const D& event) : view(view), event(event){};

  const V& get_view() const { return view; }

  const D& get_data() const { return event; }

 private:
  const D& event;
  const V& view;
};

/**
 * Interaction event listener.
 * V is Interactable element type.
 * D is Event data type.
 */
template <typename V, typename D>
class InteractListener {
 public:
  virtual void OnInteract(const InteractEvent<V, D>& event) = 0;
};

/**
 * Interactable element.
 * V is Interactable element type.
 * D is Event data type.
 */
template <typename V, typename D>
class Interactable {
 public:
  void SetInteractListener(InteractListener<V, D>* listener) {
    this->listener = listener;
  }

 protected:
  InteractListener<V, D>* listener = nullptr;
};

}  // namespace ui

#endif  // TG_CUI_INTERACT_H_
