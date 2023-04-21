fn main() {
    let i: u32 = 0;
    println!("i={i}");

    let x = 1.1234;
    let y: f32 = 1.4321;
    println!("x={},y={}", x, y);

    // this line would be a compiler error:
    //let j: u32 = -1;

    let mut a = [1, 1, 2, 3, 5];

    a[0] = 0;
    println!("a[0]={}", a[0]);

    // this line would be a compiler error:
    //a[5] = 0;
    
    // use [type; len] to set the type for the elements
    let b: [u32; 5] = [0,0,0,0,0];
    // use array:? to pretty print an array
    println!("b={b:?}");

    // use [val; len] to repeat val len times
    let c = [1; 4];
    println!("c={c:?}");
}
