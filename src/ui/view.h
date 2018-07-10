#ifndef TG_CUI_VIEW_H_
#define TG_CUI_VIEW_H_

#include <cstddef>

namespace ui {

class Window {};

class View {
 public:
  virtual void Draw(Window& canvas) const = 0;

  virtual void MouseInteract(std::size_t x, std::size_t y) = 0;

  virtual void KeyboardInteract(int key) = 0;

  virtual void SetBounds(std::size_t x,
                         std::size_t y,
                         std::size_t width,
                         std::size_t height) {
    this->x = x;
    this->y = y;
    SetSize(width, height);
  }

  virtual void SetSize(std::size_t width, std::size_t height) {
    this->width = width;
    this->height = height;
  }

  size_t get_x() const { return x; }

  size_t get_y() const { return y; }

  size_t get_width() const { return width; }

  size_t get_height() const { return height; }

 private:
  size_t x, y;
  size_t width, height;
};

class Panel : public Window {};

}  // namespace ui

#endif  // TG_CUI_VIEW_H_
