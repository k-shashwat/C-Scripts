#include <bits/stdc++.h>
using namespace std;

int max1(int x,int y,int z){
    int val = x;
    val = max(val,y);
    val = max(val,z);
    return val;
}

void sum_comb(vector <int> arr,set<vector<int>> &ans,vector<int> res, int B,int start){
    if(B==0) {
        sort(res.begin(),res.end());
        ans.insert(res);
    }
    if(B<0) return;
    if(start == arr.size()) return;
    for(int i=start;i<arr.size();i++){
        res.push_back(arr[i]);
        sum_comb(arr,ans,res,B-arr[i],start);
        res.pop_back();
        if(res.size()==0) {
            arr.erase(arr.begin());
            i--;
        }
    }
}

int main(){
    vector <int> arr = {8, 10, 6, 11, 1, 16, 8},temp;
    int B = 28;
    sort(arr.begin(),arr.end());
    set<vector<int>> ans;
    vector<vector<int>> result;
    sum_comb(arr,ans,temp,B,0);
    int k = ans.size();
    set<vector<int>> :: iterator itr;

    for(itr=ans.begin();itr!=ans.end();itr++){
        result.push_back(*itr);
    }
    for(int i =0;i<k;i++){
        for(int j=0;j<result[i].size();j++) cout << result[i][j] << " ";
        cout << endl;
    }
}
