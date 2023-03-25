//The same program as the Robots.cpp, but written in rust


const DEFAULT: i32 = 0;

struct Robot {
	
	positions: [i32; 2],


	}

impl Robot {

	fn north(&mut self, mov: i32){

		self.positions[1] += mov;
	
	}

	fn east(&mut self, mov: i32){

		self.positions[0] += mov;

	}

	fn south(&mut self, mov: i32){

		self.positions[1] -= mov;
	}

	fn west(&mut self, mov: i32){

		self.positions[0] -= mov;

	}

	fn coordinates(&self){

		println!("({},{})", self.positions[0], self.positions[1]);
	}

	fn track_robot(&mut self, n: i32, e: i32, s: i32, w: i32){

		self.north(n);
		self.east(e);
		self.south(s);
		self.west(w);
		self.coordinates();

	}


}


fn main(){

	let mut myrobot = Robot{ 
				positions: [0,0] };
	
	myrobot.track_robot(-10, 20, 10, DEFAULT);


}



