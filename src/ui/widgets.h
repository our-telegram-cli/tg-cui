#ifndef TG_CUI_WIDGETS_H_
#define TG_CUI_WIDGETS_H_

#include <string>
#include <vector>

#include "interact.h"
#include "view.h"

namespace ui {

/**
 * Interaction event at List.
 */
class ListEvent {
 public:
  ListEvent(std::size_t pos) : selected_position(pos) {}

  std::size_t get_selected_position() const { return selected_position; }

 private:
  const std::size_t selected_position;
};

/**
 * Vertical List of Views.
 */
class List : public View, public Interactable<List, ListEvent> {
 public:
  virtual void Draw() const override;

  virtual void MouseInteract(std::size_t x, std::size_t y) override;

  virtual void KeyboardInteract(int key) override;

  virtual void AddItem(const View* view);

  const View* GetItem(std::size_t pos) const { return items[pos]; }

  const View* RemoveItem(std::size_t pos);

  std::size_t Size() const { return items.size(); }

 protected:
  std::vector<const View*> items;
};

/**
 * Dialog in chats list.
 */
class DialogsListItem : public View {
 public:
  DialogsListItem(Window& win) : View(win) {}

  DialogsListItem(Window& win,
                  const std::string& title,
                  const std::string& content,
                  bool unread)
      : View(win), title(title), content(content), unread(unread) {}

  virtual void Draw() const override;

  bool is_unread() const { return unread; }

  void set_unread(bool value) { unread = value; }

  const std::string& get_title() const { return title; }

  const std::string& get_content() const { return content; }

 private:
  std::string title;
  std::string content;
  bool unread = false;
};

/**
 * Interaction event of Input Field.
 */
class InputFieldEvent {
 public:
  InputFieldEvent(const std::string& input) : input(input) {}

  const std::string& get_input() { return input; }

 private:
  const std::string& input;
};

/**
 * Text input field.
 */
class InputField : public View,
                   public Interactable<InputField, InputFieldEvent> {
 public:
  using View::View;

  virtual void Draw() const override;

  virtual void MouseInteract(std::size_t x, std::size_t y) override;

  virtual void KeyboardInteract(int key) override;

  const std::string& GetText() const;

  void SetText(const std::string& str);

  void ClearText();

 private:
  std::string input;  // TODO - replace to input buffer
};

}  // namespace ui

#endif  // TG_CUI_WIDGETS_H_
