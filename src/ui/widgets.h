#ifndef TG_CUI_WIDGETS_H_
#define TG_CUI_WIDGETS_H_

#include <string>
#include <vector>

#include "interact.h"
#include "view.h"

namespace ui {

class ListEvent {
 public:
  ListEvent(std::size_t pos) : selected_position(pos) {}

  std::size_t get_selected_position() const { return selected_position; }

 private:
  const std::size_t selected_position;
};

class List : public virtual View, public virtual Interactable<List, ListEvent> {
 public:
  virtual void Draw(Window& canvas) const override;

  virtual void MouseInteract(std::size_t x, std::size_t y) override;

  virtual void KeyboardInteract(int key) override;

  virtual void AddItem(View* view);

  const View* GetItem(std::size_t pos) { return items[pos]; }

  const View* RemoveItem(std::size_t pos);

  std::size_t Size() const { return items.size(); }

 protected:
  std::vector<View*> items;
};

class DialogsListItem : public View {
 public:
  DialogsListItem() {}

  DialogsListItem(const std::string& title,
                  const std::string& content,
                  bool unread)
      : title(title), content(content), unread(unread) {}

  virtual void Draw(Window& canvas) const override;

  virtual void MouseInteract(std::size_t x, std::size_t y) override;

  virtual void KeyboardInteract(int key) override;

  bool is_unread() const { return unread; }

  void set_unread(bool value) { unread = value; }

  const std::string& get_title() const { return title; }

  const std::string& get_content() const { return content; }

 private:
  std::string title;
  std::string content;
  bool unread = false;
};

}  // namespace ui

#endif  // TG_CUI_WIDGETS_H_
