#include <bits/stdc++.h>
using namespace std;

long long fact(long A, long M){
    if(A==0 || A==1) return 1;
    return (A%M*fact(A-1,M)%M)%M;
}

long long fast_expo(long A,long B, long M){
    if(B==0) return 1;
    if(B%2==0) return fast_expo(A%M*A%M,B/2,M);
    else return (A%M*fast_expo(A%M*A%M,(B-1)/2,M))%M;
}

long long modul_inv(long A, long M){
    return fast_expo(A,M-2,M);
}

int findRank(string A) {
    int n = A.size();
    long long M = 1000003;
    if(n==1) return n;
    int x = 'z' - 'A'+1;
    vector <long> alpha_freq(x,0);
    
    for(int i =0;A[i]!='\0';i++){
        alpha_freq[A[i]-'A']++;
    }
    
    long long pro=1;
    for(int k =0;k<x;k++){
        pro = pro * fact(alpha_freq[k],M);
        pro %= M;
    }

    long long count = 0;
    while(A.size()>0){
        for(int k=0;k<x;k++){
            if(alpha_freq[k]>0){
                if(A[0]==k+'A'){
                    A.erase(A.begin());
                    pro = pro * modul_inv(alpha_freq[k],M);
                    pro = pro %M;
                    alpha_freq[k]--;
                    k=-1;
                    continue;
                }
                else {
                    long long temp = fact(A.size()-1,M);
                    temp = (temp * modul_inv(pro,M))%M ;
                    count = count + ( temp * ((alpha_freq[k]) %M))%M;
                    count %= M;
                }
            }
        }
    }
    count %= M;
    count ++;
    return int(count);
}

int main(){
    cout << findRank("anhLXekcFPCDaLMPvz");
}