#include <bits/stdc++.h>
using namespace std;
long fact(int N){
    if(N==0 || N==1) return 1;
    else return N*fact(N-1);
}
long ncr(int A, int B){
    return fact(A) / (fact(B)*fact(A-B));
}
int main(){
    long k = ncr(30,27);
    cout << k;
}