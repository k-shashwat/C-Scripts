#include <bits/stdc++.h>
using namespace std;

void subs(vector<vector<int>> &ans,vector<int> arr, vector <int> res, int start){
    if(start == arr.size()){
        ans.push_back(res);
        return;
    }
    subs(ans,arr,res,start+1);
    res.push_back(arr[start]);
    subs(ans,arr,res,start+1);
    res.pop_back();
}

int main(){
    vector <int> arr = {1,2,3},res;
    vector <vector<int>> ans;
    int n = 3;
    subs(ans,arr,res,0);
    int k = ans.size();
    for(int i=0;i<k;i++){
        for(auto g : ans[i]) cout << g << " ";
        cout << endl;
    }
}