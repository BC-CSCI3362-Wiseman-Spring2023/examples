use std::io;

fn main() {
    let mut input = String::new();

    println!("Enter your input:");

    io::stdin()
        .read_line(&mut input)
        .expect("Read error!");

    let another_ref = input;
    // after here, the input variable is no longer valid

    println!("{another_ref}");

    // this line will generate a compiler error:
    //println!("{input}");
    
    let a_copy = another_ref.clone();
    println!("{a_copy}");
    println!("{another_ref}");
}
