#include <bits/stdc++.h>
using namespace std;

void comb(vector<vector<int>> &ans, vector <int> &arr,int start,vector <int> res,int B){
    if(B==0) {
        ans.insert(ans.begin(),res);
        res.clear();
        return;
    }
    else if(start == arr.size()) return;
    comb(ans,arr,start+1,res,B);
    res.push_back(arr[start]);
    comb(ans,arr,start+1,res,B-1);
}
vector<vector<int> > combine(int A, int B) {
    vector<vector<int> > ans;
    vector<int> result;
    if(B>A) return ans;
    vector<int> arr(A,0);
    for(int i=0;i<A;i++) arr[i] = i+1;
    comb(ans,arr,0,result,B);
    return ans;
}

int main(){
    vector<vector<int> > ans = combine(5,3);
    int n = ans.size();
    int m = ans[0].size();
    cout << "[ ";
    for(int i=0;i<n;i++){
        cout << "[ ";
        for(int j=0;j<m;j++){
            cout << ans[i][j] << " ";
        }
        cout << "], ";
    }
    cout << "] ";
}