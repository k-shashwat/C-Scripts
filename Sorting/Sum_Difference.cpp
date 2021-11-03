#include <bits/stdc++.h>
using namespace std;

long long fast(long long A, int B, long long M){
    if(B==0) return 1;
    if(B%2==0) return fast((A%M*A%M)%M,B/2,M);
    return (A%M*fast((A%M*A%M)%M,(B-1)/2,M))%M;
}

int solve(vector<int> &A) {
    int n=A.size();
    sort(A.begin(),A.end());
    long long diff_sum = 0;
    long long M = 1000000007;
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            long long d = long(A[j]-A[i])%M;
            long long k = fast(2,j-i-1,M);
            diff_sum += (k*d)%M;
            diff_sum %= M;
        }
    }
    diff_sum %= M;
    return int(diff_sum); 
}
int main(){
    vector <int> A = {2,6,7,1,9};
    int res = solve(A);
    cout << res;
}
