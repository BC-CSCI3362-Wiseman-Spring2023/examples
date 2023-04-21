use std::io;

fn main() {
    let mut msg = get_line();
    let msg2 = get_line();

    // mutable refernce here since msg will be changed
    append_str(&mut msg, msg2);

    print_line(&msg); 

    let ref1 = &mut msg;

    // this would be a compiler error:
    //msg.push_str("again");
    
    print_line(ref1); 
}

fn get_line() -> String {
    let mut input = String::new();

    println!("Enter your input:");

    io::stdin()
        .read_line(&mut input)
        .expect("Read error!");

    let input = input.trim();
    String::from(input)
}

fn append_str(s: &mut String, append: String) {
    // push_str's parameter is a reference
    s.push_str(" ");
    s.push_str(&append);
}

fn print_line(s: &String) {
    println!("{s}");
}
