fn main() {
    let mut counter = 1;

    println!("loop:");
    loop {
        println!("{counter}");
        counter += 1;
        if counter == 10 {
            break;
        }
    }
    println!("end loop");

    counter = 1;
    println!("while loop:");
    while counter < 10 {
        println!("{counter}");
        counter += 1;
    }
    println!("end while loop");

    println!("for loop:");
    for counter in 1..10 {
        println!("{counter}");
    }
    println!("end for loop");

    println!("for loop over array:") ;
    let vals = [5, 4, 3, 2, 1];
    for val in vals {
        println!("{val}");
    }
    println!("end for loop over array");
}
