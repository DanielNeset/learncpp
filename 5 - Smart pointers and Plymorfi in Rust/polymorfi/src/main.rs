use std::any::Any;

struct Surface {
    width: f64, // f64 corresponds to double in Rust
    length: f64,
}

trait GeometricQuantities {
    // Self is a reference to the calling Surface instance
    fn area(self: &Self) -> f64;
    fn string(self: &Self) -> String;
}

impl GeometricQuantities for Surface {
    // All functions in the trait GeometricQuantities must be implemented here, and only functions in GeometricQuantities can be implemented.

    fn area(self: &Self) -> f64 {
        return self.width * self.length;
    }

    fn string(&self) -> String {
        return format!(
            "length: {}, width {}, area {}.",
            self.length,
            self.width,
            self.area()
        );
    }
}

struct ColoredSurface {
    surface: Surface,
    red: f64,
    green: f64,
    blue: f64,
}

impl GeometricQuantities for ColoredSurface {
    // All functions in the trait GeometricQuantities must be implemented here, and only functions in GeometricQuantities can be implemented.

    fn area(self: &Self) -> f64 {
        return self.surface.area();
    }

    fn string(&self) -> String {
        return format!(
            "{}, color: ({}, {}, {})",
            self.surface.string(),
            self.red,
            self.green,
            self.blue
        );
    }
}

fn main() {
    let mut surfaces = Vec::<Box<dyn Any>>::new();

    surfaces.push(Box::new(Surface {
        width: 2.0,
        length: 3.0,
    }));

    surfaces.push(Box::new(ColoredSurface {
        surface: Surface {
            width: 2.0,
            length: 3.0,
        },
        red: 0.0,
        green: 0.0,
        blue: 1.0,
    }));

    for surface in &surfaces {
        // If surface is of type Surface:
        if let Some(surface) = surface.downcast_ref::<Surface>() {
            println!("{}", surface.width);
            println!("{}", surface.area());
            println!("{}", surface.string());
        } else if let Some(colored_surface) = surface.downcast_ref::<ColoredSurface>() {
            println!("{}", colored_surface.surface.width);
            println!("{}", colored_surface.area());
            println!("{}", colored_surface.string());

            println!("{}", colored_surface.blue);
        }
    }
}
