use std::io;

fn main() {
    let msg = get_line();

    // s in the function is now just borrowing msg
    print_line(&msg); 

    // this will work now
    print_line(&msg); 
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

fn print_line(s: &String) {
    let s = s.trim();
    println!("{s}");
}
