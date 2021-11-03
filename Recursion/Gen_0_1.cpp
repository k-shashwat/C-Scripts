#include <bits/stdc++.h>
using namespace std;

void g(vector <vector<int>> &ans, vector<int> arr, int n){
    if(n==0){
        ans.push_back(arr);
        return;
    }
    arr.push_back(0);
    g(ans,arr,n-1);
    arr.pop_back();
    arr.push_back(1);
    g(ans,arr,n-1);
    arr.pop_back();
}
int main(){
    vector <int> arr;
    vector <vector<int>> ans;
    int n = 3;
    g(ans,arr,n);
    int k = ans.size();
    for(int i=0;i<k;i++){
        for(auto g : ans[i]) cout << g << " ";
        cout << endl;
    }
    
}
