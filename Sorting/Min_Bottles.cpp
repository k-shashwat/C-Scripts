#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> A = {1,2,6,8,6,3,3};
    sort(A.begin(),A.end());
    int n= A.size();
    int ctr =0,i=0;
    while(i<n-1){
        if(A[i+1]>A[i++]) ctr++;
    }
    cout << (n-ctr);
}
