#include <iostream>
#include <string.h>

using namespace std;

class DesignApplication{
    private:
        int privA ,privB;
    public:
        DesignApplication(int a,int b):privA(a),privB(b){}
        int performAddition(){
            return privA+privB;
        }
};

int main(int argc, char* argv[]){
    DesignApplication d(atoi(argv[1]),atoi(argv[2]));
    std::cout<<"HERES your pretty values "<<d.performAddition()<<endl;
}