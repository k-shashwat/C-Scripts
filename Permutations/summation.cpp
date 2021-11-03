#include <bits/stdc++.h>
using namespace std;
int summation(long long A){
    long long k = A*8 + 1;
        long n = (-1+sqrt(k))/2;
        int ctr =0;
        // cout << k<< " - ";
        for(int i =1;i<=n;i++){
            if(i%2!=0){
                if(A%i==0) ctr++;
            }
            else{
                long k = A+i/2;
                long k1 = A-i/2;
                if((k%i==0) && k1>0) ctr++;
            }
    }
    return ctr;
}
int main(){
    cout << summation(1000000000);
}