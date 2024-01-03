/*
 * Simple Programming Question (A)
 * Q: To Get the Max. Frequently Occured string in a vector or array of string.
 *
 * Author: om khard
 * Implimented using set and maps
 * */
#include <bits/stdc++.h>
using namespace std;
int main(){
    // defining variables
    int n,count,max=0;
    string s,mostfreq;
    set<string> ss;
    vector<string> vs;
    map<string,int> mvs;
    std::cin>>n;
    // storing strings in a vector format
    for(int i=0;i<n;i++){
        std::cin>>s;
        vs.push_back(s);
    }
    // getting set of the strings from the vector
    for(string st:vs){
        ss.insert(st);
    }
    // getting the frequency of each of the strings and creating a map for comparing
    for(string sst:ss){
        count=0;
        for(int i=0;i<n;i++){
            if(strcmp(sst.c_str(),vs[i].c_str())==0){ // string to char string conversion
                count+=1;
            }
        }
        mvs.insert({sst,count});
    }
    // element of the set as a key and comparing there values and getting the max valued key
    for(auto it=mvs.cbegin();it!=mvs.cend();++it){
        if(it ->second > max){
            max = it ->second;
            mostfreq = it ->first;
        }
    }
    // print the mostFrequent element/string.
    std::cout<<"MostFrequentString:"<<mostfreq<<endl;
    vs.clear();
    return 1;

}
