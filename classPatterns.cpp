#include <bits/stdc++.h>
using namespace std;
// for public and private Data
class Patterns{
private:
  string privateData="127.0.0.1"; // Initialising private variable with a secret value
  // private variables are more secure to use in OOP

public:
  string publicData;

  string returnPublicData(){
    return publicData;
  }

  string returnPrivateData(){
    return privateData;
  }
  void display(){
    std::cout<<"Inherited display"<<endl;
  }
};

class Security: Patterns{
private:
  string privateData="private IP";
public:

  void securityData(){
    display(); // Inherited Function
    std::cout<<"SecurityData:"<<privateData;
  }

};
int main(){
  string pbcdata,pvtdata;
  Patterns ptrn;
  ptrn.publicData = "172.a.b.c";
  pbcdata = ptrn.returnPublicData();
  pvtdata = ptrn.returnPrivateData();
  std::cout<<"PrivateData:"<<pvtdata<<", PublicData:"<<pbcdata<<endl;

  Security scr;
  scr.securityData();
  return 1;
}
