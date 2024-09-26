#include <gtkmm.h>
#include <string>

class Window : public Gtk::Window {
public:
  Gtk::VBox vbox;
  Gtk::Label labelFirstName;
  Gtk::Entry entryFirstName;
  Gtk::Label labelLastName;
  Gtk::Entry entryLastName;
  Gtk::Button button;
  Gtk::Label label;

  Window() {
    set_title("Øving 4");
    set_default_size(400, 200);

    button.set_label("Combine names");
    button.set_sensitive(false);
    labelFirstName.set_label("First name");
    labelLastName.set_label("Last name");

    vbox.pack_start(labelFirstName);
    vbox.pack_start(entryFirstName);
    vbox.pack_start(labelLastName);
    vbox.pack_start(entryLastName);
    vbox.pack_start(button);
    vbox.pack_start(label);

    add(vbox);
    show_all();

    entryFirstName.signal_changed().connect([this]() {
      on_entry_changed();
    });

    on_entry_changed();
    entryLastName.signal_changed().connect([this]() {
      on_entry_changed();
    });

    button.signal_clicked().connect([this]() {
      std::string labelString = entryFirstName.get_text() + " " + entryLastName.get_text();
      label.set_text("Names combined: " + labelString);
    });
  }

private:
  void on_entry_changed() {
    button.set_sensitive(!entryFirstName.get_text().empty() && !entryLastName.get_text().empty());
  }
};

int main() {
  Gtk::Main gtk_main;
  Window window;
  gtk_main.run(window);
}
