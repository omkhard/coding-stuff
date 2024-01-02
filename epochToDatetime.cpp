/*
Q . Converting the epoch timestamp to datetime timestamp

Earlier thought of creating a calendar function doing from scratch , it would be larger
so optimised it using preimplimented functions and libraries .

Author: om khard
*/
#include <bits/stdc++.h>
using namespace std;
// these function are unused and would be implimented on for a larger solution
double secondsToMinutes(int sec){
   return ((double)sec/60);
}
double minutesToHours(double min){
  return (min/60);
}
double hoursToDays(double hrs){
  return (hrs/24);
}
double calculateDaysFromEpoch(int epoch){
  return hoursToDays(minutesToHours(secondsToMinutes(epoch)));
}
// Doing with Premimplimented library time.h
struct tm* getDateTimeFromEpoch(time_t epoch){
  struct tm* timeinfo;
  timeinfo = localtime(&epoch);
  return timeinfo;
}

string formatDateTime(struct tm* timeinfo){
  char buf[80];
  strftime(buf,sizeof(buf),"%Y-%m-%d %H:%M:%S",timeinfo);
  string formatedDateTime = buf;
  return formatedDateTime;
}

int main(){
  int epoch = 1000; //seconds
  // epoch starts from 1-Jan-1970
  double days = calculateDaysFromEpoch(epoch);
  std::cout<<days<<" days from epoch"<<endl;
  time_t timefromEpoch = (time_t)epoch;
  struct tm* timeinfo= getDateTimeFromEpoch(timefromEpoch);
  string format = formatDateTime(timeinfo);
  std::cout<<"Datetime(epoch:"<<epoch<<"):"<<format;
  return 1;
}
