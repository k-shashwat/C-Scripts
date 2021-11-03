#include <bits/stdc++.h>
using namespace std;

string minWindow(string A, string B){
    unordered_map<char,int> window;
    int b = B.size();
    for(int i=0;i<b;i++) {
        if(window.find(B[i])!=window.end()) window[B[i]]++;
        else window.insert({B[i],1});
    }
    
}

int main(){
    string A = "ADOBECODEBANC", B = "ABC";
    cout << minWindow(A,B);
}