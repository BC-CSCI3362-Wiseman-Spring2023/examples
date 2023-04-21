fn main() {
    let val = 0;

    if val < 0 {
        println!("negative!");
    } else if val == 0 {
        println!("zero!");
    } else {
        println!("positive!");
    }

    let val2 = if val > 5 { 1 } else { -1 };
    println!("val2={val2}");
}
