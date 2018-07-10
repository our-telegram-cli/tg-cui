#ifndef TG_CUI_VIEW_H_
#define TG_CUI_VIEW_H_

#include <cstddef>
#include <vector>

namespace ui {

class View;

/**
 * Window, contains Views.
 */
class Window {
 public:
  /**
   * Attaches View to display.
   *
   * @param view View.
   *
   * @return {@code false} if View already attached to this org another Window.
   */
  bool AddView(View* view);

  /**
   * Deattaches View and destruct it.
   *
   * @param view View.
   *
   * @return {@code false} if View didn't attached to this Window.
   */
  bool RemoveView(const View* view);

  /**
   * Checks for the presence of an attached View.
   *
   * @param view View.
   *
   * @return {@code true} if View at this Window.
   */
  bool ContainsView(const View* view) const;

  /**
   * Sets the focus to the specified View.
   * All key presses will be transmitted to the focused View.
   *
   * @param view View.
   *
   * @return {@code true} if View attached to Window at set focused.
   */
  bool FocusAt(View* view);

 private:
  std::vector<View*> views;  // TODO - replace to set
  View* focus = nullptr;
};

/**
 * View, can be drawn at Window and can contain another Views.
 * Also can accept mouse clicks and keyboard.
 */
class View {
 public:
  /**
   * @param win Root Window.
   */
  View(Window& win) : window(win) {}

  /**
   * Raises the drawing of the View on the root Window.
   */
  virtual void Draw() const = 0;

  /**
   * Processes a mouse click on a View.
   * Default implementation sets focus on this View.
   *
   * @param x X position relative to the position of the View.
   * @param y Y position relative to the position of the View.
   */
  virtual void MouseInteract(std::size_t x, std::size_t y) { SetFocused(true); }

  /**
   * Processes key press to a focused View.
   *
   * @param key Presses key code.
   */
  virtual void KeyboardInteract(int key) {}

  /**
   * Sets focus status on this View.
   *
   * @param focused Focus or remove focus on this View.
   */
  virtual void SetFocused(bool focused);

  /**
   * Sets bounds of View at Window.
   *
   * @param x X position on Window.
   * @param y Y position on Window.
   * @param width Width on Window.
   * @param height Height on Window.
   */
  virtual void SetBounds(std::size_t x,
                         std::size_t y,
                         std::size_t width,
                         std::size_t height) {
    this->x = x;
    this->y = y;
    SetSize(width, height);
  }

  /**
   * Sets sizes of View at Window.
   *
   * @param width Width on Window.
   * @param height Height on Window.
   */
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
