use std::io;

fn main() {
    let mut input = String::new();

    println!("Enter your input:");

    // this will give a warning because read_line might return an error
    // io::stdin().read_line(&mut input);
    // do this to handle it:
    // io::stdin().read_line(&mut input).expect("Read error!");
    // but more readable as:
    io::stdin()
        .read_line(&mut input)
        .expect("Read error!");

    let input = input.trim();

    println!("{input}");
}
