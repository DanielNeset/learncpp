struct Surface {
    width: f64,
    length: f64,
}

//impl Surface {
//    fn area(self: &Self) -> f64 {
//        return self.width * self.length;
//    }
//}
// Creating a interface / trait

trait GeometricQuantities {
    fn area(self: &Self) -> f64;
}

impl GeometricQuantities for Surface {
    fn area(self: &Self) -> f64 {
        return self.width * self.length;
    }
}

struct ColoredSurface {
    surface: Surface,
    red: f64,
    green: f64,
    blue: f64,
}

//impl ColoredSurface {
//    fn area(self: &Self) -> f64 {
//        return self.surface.area();
//    }
//}

impl GeometricQuantities for ColoredSurface {
    fn area(self: &Self) -> f64 {
        return self.surface.area();
    }
}

fn main() {
    let surface = Surface {
        width: 2.0,
        length: 3.0,
    };
    println!("{}", surface.width);
    println!("{}", surface.area());

    let colored_surface = ColoredSurface {
        surface: Surface {
            width: 2.0,
            length: 3.0,
        },
        red: 1.2,
        green: 2.0,
        blue: 1.0,
    };
    println!("{}", colored_surface.surface.width);
    println!("{}", colored_surface.blue);
    println!("{}", colored_surface.area());
}
