#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;
 int main(){
   
    map<string,int,greater<>> word;
    word["Shashwat"] = 27;
    word["Deepthi"] = 14;
    word.insert(make_pair("Aman",23));
    word["Poojitha"] = 4;
    for(auto i :  word) cout<< i.first << " " << i.second << endl;
    return 0;
 }