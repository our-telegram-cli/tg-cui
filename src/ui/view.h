#ifndef TG_CUI_VIEW_H_
#define TG_CUI_VIEW_H_

#include <cstddef>
#include <vector>

namespace ui {

class View;

class Window {
 public:
  bool AddView(View* view);

  bool RemoveView(const View* view);

  bool ContainsView(const View* view) const;

  bool FocusAt(View* view);

 private:
  std::vector<View*> views;  // TODO - replace to set
  View* focus = nullptr;
};

class View {
 public:
  View(Window& win) : window(win) {}

  virtual void Draw() const = 0;

  virtual void MouseInteract(std::size_t x, std::size_t y) { SetFocused(true); }

  virtual void KeyboardInteract(int key) {}

  virtual void SetFocused(bool focused);

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

  std::size_t get_x() const { return x; }

  std::size_t get_y() const { return y; }

  std::size_t get_width() const { return width; }

  std::size_t get_height() const { return height; }

  virtual ~View();

 protected:
  std::size_t x = 0, y = 0;
  std::size_t width = 1, height = 1;

  Window& window;
};

class Panel : public Window {};

}  // namespace ui

#endif  // TG_CUI_VIEW_H_
