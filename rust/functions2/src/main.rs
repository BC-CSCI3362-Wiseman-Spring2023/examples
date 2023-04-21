use std::io;

fn main() {
    let msg = get_line();

    // this will move ownership to s in the function
    print_line(msg); 

    // that means that this line would cause a compiler error:
    //print_line(msg); 
}

fn get_line() -> String {
    let mut input = String::new();

    println!("Enter your input:");

    io::stdin()
        .read_line(&mut input)
        .expect("Read error!");

    // this will move ownership to msg, so the value
    // won't be dropped after the function ends
    input
}

fn print_line(s: String) {
    let s = s.trim();
    println!("{s}");
}
