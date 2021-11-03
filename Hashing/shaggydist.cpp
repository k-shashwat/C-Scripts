#include <bits/stdc++.h>
using namespace std;

int get_shag(vector<int> A, int n,pair<int,int> &p){
    unordered_map<int,int> s1;
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        if(s1.find(A[i])!=s1.end()){
            if(ans>i-s1[A[i]]){
                p.first = s1[A[i]];
                p.second = i;
                ans = p.second - p.first; 
            }
            s1[A[i]] = i;
        }
        else s1.insert({A[i],i});
    }
    if(ans == INT_MAX) return -1;
    else return ans;
}

int main(){
    vector<int> q = {1,2,3,2,1,6,3,2,1};
    pair<int,int> p1 = {-1,-1};
    cout << get_shag(q,q.size(),p1) << " = " << p1.second << " - " << p1.first;
    return 0;
}
