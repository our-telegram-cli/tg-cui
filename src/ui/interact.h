#ifndef TG_CUI_INTERACT_H_
#define TG_CUI_INTERACT_H_

#include <cstddef>

class InteractEvent {
 public:
  InteractEvent(const std::size_t x, const std::size_t y) : x(x), y(y){};

  std::size_t get_x() const { return x; }

  std::size_t get_y() const { return y; }

 private:
  const std::size_t x, y;
};

class InteractListener {
 public:
  virtual void OnInteract(const InteractEvent& event) = 0;
};

class Interactable {
 public:
  void SetInteractListener(InteractListener* listener) {
    this->listener = listener;
  }

 protected:
  InteractListener* listener = nullptr;
};

#endif  // TG_CUI_INTERACT_H_
