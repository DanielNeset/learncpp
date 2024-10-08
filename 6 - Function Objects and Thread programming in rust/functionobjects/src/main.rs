trait Drawable {
    fn draw(self: &Self) -> ();
}

struct Image {
    file: String,
}

impl Drawable for Image {
    fn draw(&self) {
        println!("Draw image from file: {}", self.file);
    }
}

struct Button {
    label: String,
    on_click: Box<dyn Fn() -> ()>,
}

impl Drawable for Button {
    fn draw(&self) {
        println!("Draw button labeled: {}", self.label);
        println!("This happens when the button is clicked:");
        (self.on_click)();
    }
}

struct Window {
    widgets: Vec<Box<dyn Drawable>>,
}

impl Window {
    fn show(self: &Self) {
        for widget in &self.widgets {
            widget.draw();
        }
    }
}

fn main() {
    let mut window = Window {
        widgets: Vec::new(),
    };

    window.widgets.push(Box::new(Image {
        file: String::from("image.png"),
    }));

    // In Rust one can make an function Object Fn() -> () and anonymous with || {}
    window.widgets.push(Box::new(Button {
        label: String::from("Click me!"),
        on_click: Box::new(|| {
            println!("Button was pressed!");
        }),
    }));

    window.show();
}
