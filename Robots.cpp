#include <iostream>
#define DEFAULT 0


class Robot { //just made this challenge using a Class for educational purposes.

public:
    int Position[2];

void North(int Mov){

    Position[1] += Mov;
}

void East(int Mov){

    Position[0] += Mov;
}

void South(int Mov){

    Position[1] -= Mov;
}

void West(int Mov){

    Position[0] -= Mov;
}

void Coordinates(void){

    std::cout << "(" << Position[0] << "," << Position[1] << ")" << std::endl;

}

void TrackRobot(int N, int E, int S, int W){

        North(N);
        East(E);
        South(S);
        West(W);

        Coordinates();

}


};



int main(void){

        Robot Myrobot;


        Myrobot.TrackRobot(-10, 20, 10, DEFAULT); //Example to show it works, it's an easy challenge.

}
