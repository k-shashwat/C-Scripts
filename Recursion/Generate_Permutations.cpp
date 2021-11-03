#include <bits/stdc++.h>
using namespace std;

void permute(vector< vector <int>> &ans, vector<int> arr,vector<int> res, int start, int n){
    if(start == n){
        ans.push_back(res);
    }
    for(int i=0;i<n;i++){
        // cout << " 1 ";
        if(res[i] == -1){
            res[i] = arr[start];
            permute(ans,arr,res,start+1,n);
            res[i] = -1;
        }
    }
}
int main(){
    vector<int> arr = {1,2,3};
    int n = arr.size();
    vector <int> res(n,-1);
    vector <vector<int>> ans;
    permute(ans,arr,res,0,n);
    int k = ans.size();
    for(int i=0;i<k;i++){
        for(auto g : ans[i]) cout << g << " ";
        cout << endl;
    }
}
