fn main() {
    // create a Vec<i32> vector
    let vals = vec![2, 4, 8, 16];
    print_vec(&vals);

    let mut vals2: Vec<i32> = Vec::new();
    vals2.push(2);
    vals2.push(4);
    vals2.push(8);
    vals2.push(16);

    // loop over vals2 vector, getting a mutable reference
    // to each element so that we can change the element
    for val in &mut vals2 {
        // have to deference the reference with *
        *val = *val * 2;
    }

    // remove() removes an element by index, by 
    // shifting every subsequent element down
    vals2.remove(0);
    print_vec(&vals2);

    // swap_remove() is more efficient than remove()
    // but doesn't maintain ordering of the vec
    vals2.swap_remove(0);
    print_vec(&vals2);
}

fn print_vec(v: &Vec<i32>) {
    for val in v {
        print!("{val} ");
    }
    println!();
}
