#include <bits/stdc++.h>
using namespace std;


void substr(string str,int start, vector<string> &ans,string res){
    if(str[start] =='\0'){
        ans.push_back(res);
        // res= "";
        return;
    }
    substr(str,start+1,ans,res);
    res = res + str[start];
    substr(str,start+1,ans,res);
}
int main(){
    string str = "367";
    vector <string> ans;
    string res = "";
    substr(str,0,ans,res);
    for(auto g : ans) cout << g << endl; 
}
