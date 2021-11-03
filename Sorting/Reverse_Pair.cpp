#include <bits/stdc++.h>
using namespace std;

int merger(vector<int> &A, int l, int mid, int r){
    vector<int> temp(A.size(),0);
    int p1=l,p2= mid+1,i=l,inv_count=0;
    // cout << endl;
    while(p1<=mid && p2<=r){
        if(A[p2]<=A[p1]) {
            temp[i++] = A[p2++];
            inv_count = inv_count + mid - p1 + 1;
        }
        else {
            temp[i++] = A[p1++];
        }
    }
    // cout << endl;
    while(p1<=mid) temp[i++] = A[p1++];
    while(p2<=r) temp[i++] = A[p2++];
    for(int j=l;j<=r;j++) A[j] = temp[j];
    return inv_count;
    // for(auto g:temp) cout << g << " ";
    // cout << endl;
}

int inv_pair(vector<int> &A, int l, int r){
    int mid = (l+r)/2;
    if(l==r) return 0;
    int ans=0;
    ans += inv_pair(A,l,mid);
    ans += inv_pair(A,mid+1,r);
    ans += merger(A,l,mid,r);
    return ans;
}
int main(){
    vector <int> p = {45, 10, 15, 25, 50};
    int res = inv_pair(p,0,p.size()-1);
    cout << res;
    // for(int i=0;i<p.size();i++) cout << p[i] << " ";
}
