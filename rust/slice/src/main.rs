fn main() {
    // s1 is a &str
    let s1 = "hello there";

    // String::from() convert &str to a String
    let s2 = String::from("hello there");

    print_line(&s2); 
    println!("{s1}");

    // this line will cause a compiler error
    //print_line(s1); 
    
    let slice1 = &s1[0..5];

    // omitting the end of the ranges goes to the end of the string
    let slice2 = &s2[6..];

    println!("{slice1}");
    println!("{slice2}");
}

fn print_line(s: &String) {
    println!("{s}");
}
