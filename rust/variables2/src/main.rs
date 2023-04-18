fn main() {
    let val = 1;
    println!("val={val}");

    let val = val + 1;
    println!("val={val}");

    {
        let val = val + 1;
        println!("val={val}");
    }

    println!("val={val}");
}
