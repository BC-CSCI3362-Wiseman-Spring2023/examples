fn main() {
    let x = 6;
    let y = 7;

    let z = do_stuff(x, y);
    println!("z={z}");

    let (val1, val2) = other_stuff(z);
    println!("val1={val1},val2={val2}");
}

fn do_stuff(a: i32, b: i32) -> i32 {
    // could do this:
    // return a * b;
    // but this is the idiomatic rust way:
    a * b
}

fn other_stuff(num: i32) -> (i32, i32) {
    let d = num - 2;
    (d / 10, d % 10)
}
