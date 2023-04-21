fn main() {
    let x = 10;
    println!("x = {x}");

    // this will generate a compiler warning as y never changes
    let y = 15;
    println!("y = {y}");

    let mut z = 20;
    z = z + 5;
    println!("z = {z}");

    // this line would generate a compiler error
    x = x + 1; 
}
