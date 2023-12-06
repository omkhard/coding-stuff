#include <bits/stdc++.h>
using namespace std;
//int NUM_OF_PEEPS=0; iski jaroorat ni h GLOBAL_VARIABLES are not much secure
class Elevator{
private:
  int totalPeeps,floor;
  string elevatorDirection;
public:
  int stopAt;
  Elevator(int startNumofPeeps,string direction,int floorElev,int stopat); // Constructor declared
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
      if(floor == 5){
        elevatorDirection = "down";
      }
      if(floor == 0){
        elevatorDirection = "up";
      }
      if(floor == stopAt){
        stopElevator();
        return ;
      }
    }
  }
  int stopElevator(){
    return 1;// start from here (pending ...)
  }
  string detectDirection(){
    return elevatorDirection;
  }
};
// defined variables names should be different
Elevator::Elevator(int startNumofPeeps,string direction,int floorElev,int stopat){
  totalPeeps = startNumofPeeps;
  elevatorDirection = direction;
  floor = floorElev;
  stopAt = stopat;
}
int main(){
  int count=0;
  string dir;
  Elevator elv(2,"up",2,3);
  elv.startElevator();
  count = elv.displayPeepsCount();
  dir = elv.detectDirection();
  std::cout<<count<<" Direction: "<<dir<<endl;
  return 0;
}
