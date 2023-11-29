#include <bits/stdc++.h>
using namespace std;
//int NUM_OF_PEEPS=0; iski jaroorat ni h GLOBAL_VARIABLES are not much secure
class Elevator{
private:
  int totalPeeps,floor;
  string elevatorDirection;
public:
  Elevator(int startNumofPeeps,string direction,int floor); // Constructor declared
  void inElevator(int num){
    totalPeeps = num+totalPeeps;
  }
  void outElevator(int num){
    if(num > totalPeeps){
      std::cout<<"CAN'T EXIT !!! THEY ARENT THIS many in ELEVATOR"<<endl;
      return;
    }
    totalPeeps = totalPeeps - num;
  }
  int displayPeepsCount(){
    // Maximum Capacity of Elevator 20 peeps
    if(totalPeeps > 20){
      std::cout<<"WARNING: ELEVATOR capacity reached!!!"<<endl;
    }
    return totalPeeps;
  }
  void startElevator(){// this function will occur every time someone getsIn (pending...)
    while(1){
      if(elevatorDirection=="up"){
        std::cout<<"GOING UP::"<<endl;
        floor = floor + 1;
        sleep(2); // in 2 seconds it will reach other floor

      }
      if(elevatorDirection=="down"){
        std::cout<<"GOING DOWN::"<<endl;
        floor = floor - 1;
        sleep(2); // in 2 sec it reach other down floors
      }
    }
  }
  string detectDirection(){
    return elevatorDirection;
  }
};
Elevator::Elevator(int startNumofPeeps,string direction,int floor){
  totalPeeps = startNumofPeeps;
  elevatorDirection = direction;
}
int main(){
  int count=0;
  string dir;
  Elevator elv(2,"up",0);
  elv.startElevator();
  elv.inElevator(2);
  elv.outElevator(1);
  elv.inElevator(2);
  count = elv.displayPeepsCount();
  dir = elv.detectDirection();
  std::cout<<count<<" Direction: "<<dir<<endl;
  return 0;
}
