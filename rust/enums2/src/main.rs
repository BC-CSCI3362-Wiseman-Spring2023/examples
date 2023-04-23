use std::io;
use std::io::Write;
use std::process::exit;

fn main() {
    let x = get_number("Enter x: ");
    let y = get_number("Enter y: ");

    let z = match safe_division(x, y) {
        Some(answer) => answer,
        None => {
            println!("Can't divide by zero!");
            exit(1);
        },
    };

    println!("{x}/{y} = {z}");
}

fn safe_division(top: i32, bottom: i32) -> Option<f64> {
    if bottom != 0 {
        Some(f64::from(top)/f64::from(bottom))
    } else {
        None
    }
}

fn get_number(prompt: &str) -> i32 {
    let input = get_line(prompt);

    let num: i32 = match input.parse() {
        Ok(num) => num,
        Err(_) => {
            println!("{input} is not a number!");
            exit(1);
        },
    };
    num
}

fn get_line(prompt: &str) -> String {
    let mut input = String::new();

    print!("{prompt}");
    // output is line-buffered, so flush output
    // flush() returns an Result b/c there might be an I/O error,
    // but we can have it panic if the error occurs
    io::stdout().flush().expect("flush failed!");


    // read_line() returns a Result enum
    match io::stdin().read_line(&mut input) {
        Err(err) => {
            println!("I/O error: {err}");
            exit(1);
        },
        Ok(_) => (),
    }

    let input = input.trim();
    String::from(input)
}
