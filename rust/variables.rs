fn main() {
    {
        let x; // declare "x"
        x = 42; // assign 42 to "x"
    }

    {
        let x = 42;
    }

    {
        let x: i32; // `i32` is a signed 32-bit integer
        x = 42;
        // there's i8, i16, i32, i64, i128
        // also u8, u16, u32, u64, u128 for unsigned
    }

    {
        let x: i32 = 42;
    }

    {
        let x;
        // foobar(x); // error: borrow of possibly-uninitialized variable: `x`
        x = 42;
    }

    {
        // this does *nothing* because 42 is a constant
        let _ = 42;

        // this calls `get_thing` but throws away its result
        // let _ = get_thing();
    }

    {
        // we may use `_x` eventually, but our code is a work-in-progress
        // and we just wanted to get rid of a compiler warning for now.
        let _x = 42;
    }

    {
        let x = 13;
        let x = x + 3;
        // using `x` after that line only refers to the second `x`,
        // the first `x` no longer exists.
    }

    {
        let pair = ('a', 17);
        pair.0; // this is 'a'
        pair.1; // this is 17
    }

    {
        let pair: (char, i32) = ('a', 17);
    }

    {
        let (some_char, some_int) = ('a', 17);
        // now, `some_char` is 'a', and `some_int` is 17
    }

    {
        // let (left, right) = slice.split_at(middle);
    }

    {
        let x = vec![1, 2, 3, 4, 5, 6, 7, 8]
            .iter()
            .map(|x| x + 3)
            .fold(0, |x, y| x + y);
    }

    {
        let x = "out";
        {
            // this is a different `x`
            let x = "in";
            println!("{}", x);
        }
        println!("{}", x);
    }

    {
        // this:
        // let x = 42;

        // is equivalent to this:
        let x = { 42 };
    }

    {
        let x = {
            let y = 1; // first statement
            let z = 2; // second statement
            y + z // this is the *tail* - what the whole block will evaluate to
        };
        println!("{}", x)
    }

    {
        greet();
        println!("{}", fair_dice_roll());
        println!("{}", fair_dice_roll2());
    }

    {
        let least = std::cmp::min(3, 8); // this is 3
        println!("{}", least); // this is 3);
    }

    {
        use std::cmp::min;

        let least = min(7, 1); // this is 1
        println!("{}", least); // this is 3);
    }

    {
        // this works:
        use std::cmp::max;
        use std::cmp::min;

        // this also works:
        // use std::cmp::{max, min};

        // this also works!
        // use std::{cmp::max, cmp::min};

        // this brings `min` and `max` in scope, and many other things
        // use std::cmp::*;
    }

    {
        // let x = "amos".len(); // this is 4
        // let x = str::len("amos"); // this is also 4
    }

    {
        // `Vec` is a regular struct, not a primitive type
        // let v = Vec::new();

        // this is exactly the same code, but with the *full* path to `Vec`
        // let v = std::vec::Vec::new();
    }

    {
        struct Vec2 {
            x: f64, // 64-bit floating point, aka "double precision"
            y: f64,
        }

        let v1 = Vec2 { x: 1.0, y: 3.0 };
        let v2 = Vec2 { y: 2.0, x: 4.0 };
        // the order does not matter, only the names do

        let v3 = Vec2 { x: 14.0, ..v2 };

        /*
        This is called “struct update syntax”, can only happen in last position, and cannot be followed by a comma.

        Note that the rest of the fields can mean all the fields:
        */
        let v4 = Vec2 { ..v3 };
    }

    {
        struct Vec2 {
            x: f64, // 64-bit floating point, aka "double precision"
            y: f64,
        }

        let v = Vec2 { x: 3.0, y: 6.0 };
        let Vec2 { x, y } = v;
        // `x` is now 3.0, `y` is now `6.0`

        let Vec2 { x, .. } = v;
        // this throws away `v.y`
    }

    {
        // let patterns can be used as conditions in if:

        struct Number {
            odd: bool,
            value: i32,
        }

        fn test() {
            let one = Number {
                odd: true,
                value: 1,
            };
            let two = Number {
                odd: false,
                value: 2,
            };
            print_number(one);
            print_number(two);
        }

        fn print_number(n: Number) {
            if let Number { odd: true, value } = n {
                println!("Odd number: {}", value);
            } else if let Number { odd: false, value } = n {
                println!("Even number: {}", value);
            }
        }

        test();

        // this prints:
        // Odd number: 1
        // Even number: 2
    }

    {
        // let patterns can be used as conditions in if:

        struct Number {
            odd: bool,
            value: i32,
        }

        fn test() {
            let one = Number {
                odd: true,
                value: 1,
            };
            let two = Number {
                odd: false,
                value: 2,
            };
            print_number(one);
            print_number(two);
        }

        // fn print_number(n: Number) {
        //     match n {
        //         Number { odd: true, value } => println!("Odd number: {}", value),
        //         Number { odd: false, value } => println!("Even number: {}", value),
        //     }
        // }

        // // A match has to be exhaustive: at least one arm needs to match.
        // fn print_number(n: Number) {
        //     match n {
        //         Number { value: 1, .. } => println!("One"),
        //         Number { value: 2, .. } => println!("Two"),
        //         Number { value, .. } => println!("{}", value),
        //         // if that last arm didn't exist, we would get a compile-time error
        //     }
        // }

        // If that's hard, _ can be used as a “catch-all” pattern:

        fn print_number(n: Number) {
            match n.value {
                1 => println!("One"),
                2 => println!("Two"),
                _ => println!("{}", n.value),
            }
        }

        // this prints the same as before

        test();

        // this prints:
        // Odd number: 1
        // Even number: 2
    }

    {
        struct Number {
            odd: bool,
            value: i32,
        }

        impl Number {
            fn is_strictly_positive(self) -> bool {
                self.value > 0
            }
        }

        fn test() {
            let minus_two = Number {
                odd: false,
                value: -2,
            };
            println!("positive? {}", minus_two.is_strictly_positive());
            // this prints "positive? false"
        }

        test();
    }

    {
        // Variable bindings are immutable by default, which means their interior can't be mutated:

        struct Number {
            odd: bool,
            value: i32,
        }

        // fn test() {
        //     let n = Number {
        //         odd: true,
        //         value: 17,
        //     };
        //     n.odd = false; // error: cannot assign to `n.odd`,
        //                    // as `n` is not declared to be mutable
        // }

        // test();

        // fn test2() {
        //     let n = Number {
        //         odd: true,
        //         value: 17,
        //     };
        //     n = Number {
        //         odd: false,
        //         value: 22,
        //     }; // error: cannot assign twice to immutable variable `n`
        // }

        fn test() {
            let mut n = Number {
                odd: true,
                value: 17,
            };
            n.value = 19; // all good
        }
    }
}

fn greet() {
    println!("Hi there!");
}

fn fair_dice_roll() -> i32 {
    4
}

fn fair_dice_roll2() -> i32 {
    let feeling_lucky = true;

    // if feeling_lucky {
    //     6
    // } else {
    //     4
    // }
    match feeling_lucky {
        true => 6,
        false => 4,
    }
}
