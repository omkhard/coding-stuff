#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;

int countOfNumbers(int number,vector<int> varr){
    int size = varr.size();
    int count =0;
    for(int i=0;i<size;i++){
        if(number == varr[i])
            count++;
    }
    return count;
}

int countOfStrings(string s,vector<string> sarr){
    int size = sarr.size();
    int count=0;
    for(int i=0;i<size;i++){if(s == sarr[i]){count++;}}
    return count;
}