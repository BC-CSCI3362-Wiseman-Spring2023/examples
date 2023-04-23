enum Animal {
    Cat,
    Dog,
    Cow,
    Snake,
}

fn noise(animal: Animal) -> String {
    match animal {
        Animal::Cat => String::from("meow"),
        Animal::Dog => String::from("woof"),
        Animal::Cow => String::from("moo"),
        Animal::Snake => String::from("hiss"),
    }
}

fn main() {
    let pet = Animal::Cat;
    let sound = noise(pet);
    println!("My pet goes {sound}");
}
