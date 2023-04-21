fn main() {
    let x = 4;
    let y = x;

    // no error here
    // x and y each own a copy of 4
    println!("x={x}");
    println!("y={y}");
}
