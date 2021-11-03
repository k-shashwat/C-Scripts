#include <bits/stdc++.h>
using namespace std;

long long fact(int n,int M){
    if(n==1 || n==0) return 1;
    return (n%M*fact((n-1)%M,M))%M;
}

int findRank(string A) {
    int n = A.size(),M = 1000003;
    if(n==1) return n;
    int x = 'z' - 'A';
    vector <int> alpha_freq(x,0);
    for(int i =0;A[i]!='\0';i++){
        alpha_freq[A[i]-'A']++;
    }
    // for(auto i : alpha_freq) cout << i << " ";
    long long count = 0;
    int j=0;
    while(A.size()>0){
        if(alpha_freq[j]>=1){
            if(A[0]==j+'A'){
                A.erase(A.begin());
                alpha_freq[j]--;
                j=0;
                count %=M;
                continue;
            }
            else count += fact(A.size()-1,M);
        }
        count %= M;
        j++;
    }
    count++;
    int ans = count % M;
    return ans;
}


int main(){
    cout << findRank("BHIWANDI");
}