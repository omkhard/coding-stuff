#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

/*
Author:
    Om Khard

Design: 
    Making an application which :
    1. Takes arguments from CLI as name and age and appends that to a
    file like a db. 
    (Write to a file named output.txt)
    Using 'fstream' library 
*/



class DesignApplication{
    private:
        char* name;
        int age;
    public:
    //Constructor
        DesignApplication(char* a,int b):name(a),age(b){}
    //Methods
        char* getName(){
            return name;
        }
        int getAge(){
            return age;
        }
        void updateDB(){
            ofstream myfile;
        // this 'ios::app' parameter is used to append data.
            myfile.open("./output.txt",std::ios::app);
            myfile<<"Name: "<<name<<" Age:"<<age<<endl;
            myfile.close();
        }
};

int main(int argc, char* argv[]){
    DesignApplication d(argv[1],atoi(argv[2]));
    std::cout<<"Name: "<<d.getName()<<endl<<"Age: "<<d.getAge();
    d.updateDB();
    return 0;
}