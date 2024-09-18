fn main() {
    // Create a 32-bit (4 byte) integer (i32 type in Rust)
    // The mut (mutable) keyword makes a value alterable (non-constant)
    // In C and C++ variables are non-const (mut) by default, while in Rust the variables are const.
    let mut value = 2;

    let ptr: *mut i32 = &mut value;
    unsafe {
        // Changes value to 4. This statement must be in a unsafe block.
        *ptr = 4;
        println!("{}", *ptr);
    }
    println!("{}", value)
}
