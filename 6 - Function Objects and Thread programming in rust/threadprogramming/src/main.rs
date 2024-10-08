use std::collections::HashMap;
use std::sync::{Arc, Mutex};
use std::{thread, time};

fn main() {
    // Arc is similar to shared_ptr in c++
    // Mutex: Data and mutex combined, where the data cannot be access without locking the mutex
    let results = Arc::new(Mutex::new(HashMap::<String, String>::new()));

    let results_copy = results.clone();
    let url = "https://www.ntnu.no/".to_string();
    let t1 = thread::spawn(move || {
        //Simulate getting the result from the url with a time delay
        thread::sleep(time::Duration::from_secs(1));

        // Access the data by locking the mutex object
        let mut lock = results_copy.lock().unwrap();
        (*lock).insert(url, "Welcome to NTNU".to_string());

        //The mutex object is unlocked at the end of the scope
    });

    let results_copy = results.clone();
    let url = "https://www.mit.edu/".to_string();
    let t2 = thread::spawn(move || {
        thread::sleep(time::Duration::from_secs(1));
        let mut lock = results_copy.lock().unwrap();
        (*lock).insert(url, "Welcome to MIT".to_string());
    });

    // Handle the results
    t1.join().unwrap_or_else(|e| {
        println!("Thread 1 panicked: {:?}", e);
    });
    t2.join().unwrap_or_else(|e| {
        println!("Thread 2 panicked: {:?}", e);
    });

    // Cannot access data without calling lock(); even though locking is unnecessary.
    let lock = results.lock().unwrap();
    println!("{}", (*lock)["https://www.ntnu.no/"]);
    println!("{}", (*lock)["https://www.mit.edu/"]);
}
