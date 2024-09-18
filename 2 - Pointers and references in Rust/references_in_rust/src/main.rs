fn main() {
    let mut value = 2;
    // Note that &mut i32 (reference) is used instead of *mut i32 (pointer)
    // : &mut i32 is not needed.
    let value_ref: &mut i32 = &mut value;

    // Changes the value to 4
    *value_ref = 4;
    // Cant print out the value then the reference, since it is borrowed. Will get a error.
    println!("{}", *value_ref);
    println!("{}", value_ref);
    println!("{}", value);

    // Another example:

    // Create a dynamic array.
    let mut vec = vec![1, 2, 3];
    println!("{:?}", vec);

    //Reference to the first element in vec
    let element_ref = &mut vec[0];
    println!("{}", element_ref);

    vec.clear();

    // Cannot borrow mutable vec more then once!
    //println!("{}", element_ref);
    println!("{:?}", vec);
}
