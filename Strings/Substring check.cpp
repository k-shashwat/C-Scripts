#include <bits/stdc++.h>
using namespace std;

string prefix(vector<string> arr,string common,int start){
    string com ="";
    for(int i =0;common[i]!= '\0' && arr[start][i] != '\0';i++){
        if(common[i] == arr[start][i]){
            com = com + common[i];
            continue;
        }
        break;
    }
    
}
int main(){
}