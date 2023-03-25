#![allow(non_snake_case)] /*Stupid warning. This is the most ridiculous warning i ever seen on a compiler. I'm going to add
                          #![allow(non_snake_case)] to my rust files like i add <stdio.h> to a C file. */
                            
/*this program sums the digit of the number passed from command line and returns even or odd based on the sum.
 
                            https://edabit.com/challenge/r6TSNwkLZ2DgsoKiH  */                           
                            
use std::env;

fn main(){

	let args: Vec<String> = env::args().collect(); //(int argc, char *argv[]) basically
	let number = args[1].parse::<i32>().unwrap(); //args[1] is parsed from string to i32
	OddishEven(number);




}

fn OddishEven(mut num: i32) -> i32 {

	
	let mut vec_ = Vec::new(); //vector to store all digits

	while num > 0 {

	let digit = num % 10;
	vec_.push(digit);
	num /= 10;

	}

	let sum: i32 = vec_.iter().sum(); //iterates over the elements in vec_ and add them to sum.

	if sum % 2 == 1{ //case of sum is odd.

		println!("Oddish!");
		return 1;

	}

	else{ //case of sum is even.

		println!("Even!");
		return 0;

	}
	
}
