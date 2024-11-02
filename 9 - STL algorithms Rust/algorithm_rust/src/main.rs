fn main() {
    let numbers = vec![0, 1, 2, 3, 4, 5];

    // Reverse the order of the list
    for e in numbers.iter().rev() {
        println!("{}", e)
    }

    println!();

    // Find all whole numbers and square it
    for e in numbers.iter().filter(|e| (*e % 2) == 0).map(|e| e * e) {
        println!("{}", e)
    }
}
