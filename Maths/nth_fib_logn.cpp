#define mod 1000000007
#include <bits/stdc++.h>
using namespace std;

// Idea is to use a 2x2 matrix with [[1,1],[1,0]] and calculate the first element of (mat^n-1)

vector<vector<long>> multiply(vector<vector<long>> &A,vector<vector<long>> &B) {
    vector<vector<long>> C={{0,0},{0,0}};
    for ( int i=0 ; i<2 ; i++ ) {
        for ( int j=0 ; j<2 ; j++ ) {
            long long sum = 0;
            for ( int k=0 ; k<2; k++)
                sum = (sum + (A[i][k]*B[k][j])%mod)%mod;
            C[i][j] = sum;
            }
        }
    return C;
}
void mat_power ( vector<vector<long>> &mat,int n) {
    if (n == 1) return;
    mat_power(mat,n/2);
    mat = multiply(mat,mat);
    if(n%2==1){
        vector<vector<long>> m = {{1,1},{1,0}};
        mat = multiply(mat,m);
    }
    return;
}

int main(){
// O(logN)  solution
    int n = 10000000;
    vector<vector<long>> mat = {{1,1},{1,0}};
    if (n==0) return 0;
    mat_power(mat,n-1);
    cout << mat[0][0];
}

