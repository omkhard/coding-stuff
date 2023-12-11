#include <bits/stdc++.h>
using namespace std;
//int NUM_OF_PEEPS=0;
/*
This Elevator system is still a statically designed Elevator System
which takes few use inputs and perform the opertations of Going 'UP/DOWN'
preparing it like , first man leaves first and second leaves second

problems:

onces stoped , can't be started again
USING FIFO algorithm , has to do many modifications
*/
class Elevator{
private:
  int totalPeeps,startAt,last_peep_floor;
  string elevatorDirection;
  bool changeDirection=false;
public:
  int stopAt;
  int secondStart = startAt;
  vector<int> secondStartAt;
  Elevator(int startNumofPeeps,string direction,int startat,int stopat ,int lastPeepAt); // Constructor declared
  void inElevator(int num){
    totalPeeps = num+totalPeeps;
  }
  void outElevator(int num){
    if(num > totalPeeps){
      std::cout<<"CAN'T EXIT !!! THERE ARENT THIS many in ELEVATOR"<<endl;
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

      if(elevatorDirection=="up" and changeDirection){
        std::cout<<"GOING UP::"<<endl;
        startAt = startAt + 1;
        sleep(2); // in 2 seconds it will reach other floor
      }
      if(elevatorDirection=="down" and changeDirection){
        std::cout<<"GOING DOWN::"<<startAt<<endl;
        startAt = startAt - 1;
        sleep(2); // in 2 sec it reach other down floors
      }
      if(startAt == 6 or last_peep_floor < secondStart){
        elevatorDirection = "down"; // it will go till 5th floor
        changeDirection = true;
      }
      if(startAt == -1 or last_peep_floor > secondStart){
        elevatorDirection = "up"; // it will go till 0(ground) floor
        changeDirection = true;

      }
      if(startAt == last_peep_floor){
        std::cout<<"LAST PEEP GOING OUT at "<<last_peep_floor<<":"<<endl;
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
Elevator::Elevator(int startNumofPeeps,string direction,int startat,int stopat,int lastPeepAt){
  totalPeeps = startNumofPeeps;
  elevatorDirection = direction;
  startAt = startat;
  stopAt = stopat;
  last_peep_floor = lastPeepAt;
}
int main(){
  int count=0,startAt,stop_at,init_peeps=2,last_peep_at;
  string dir;
  std::cout<<"Enter ElevAT:";
  std::cin>>startAt;
  std::cout<<"Enter StopAT:";
  std::cin>>stop_at;
  std::cout<<"Enter DirectionOfGoing(String):";
  std::cin>>dir;
  std::cout<<"Last peep leaving AT:";
  std::cin>>last_peep_at;
  Elevator elv(init_peeps,dir,startAt,stop_at,last_peep_at);
  elv.startElevator();
  count = elv.displayPeepsCount();
  dir = elv.detectDirection();
  std::cout<<count<<" Direction: "<<dir<<endl;
  return 0;
}
