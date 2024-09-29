use std::alloc::{alloc, dealloc, Layout};

fn main() {
    // Type of value to be created in the heap
    let layout = Layout::new::<i32>();
    unsafe {
        // Create memory range for an integer in the heap
        let ptr = alloc(layout);

        // Store the value 42 on the heap
        *ptr = 42;

        println!("{}", *ptr); // Outputs: 42
        println!("{:p}", ptr); // Outputs the address of the value in the heap

        dealloc(ptr, layout); // Free the memory ptr points to.
    }

    // Smart pointers:

    // Store the value 42 in the heap
    let ptr = Box::new(42);

    println!("{}", *ptr); // Outputs: 42
    println!("{:p}", ptr); // Outputs the address of the value in the heap
                           // The memory ptr points to is freed at end of scope
}
