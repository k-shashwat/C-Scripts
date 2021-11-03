#include <bits/stdc++.h>
using namespace std;

long M = long(10e9+7);
long hashfun(vector<long> k, string s){
    int n = s.size();
    long count = 0;
    for(int i=0;i<n;i++){
        count += (s[i]*k[n-i-1]%M);
        count %=M;
    }
    return count;
}
long checkstring(string text, string word){
    int s = word.size(), t = text.size(), j=0;
    long c = 31, pro = 1, ctr = 0;
    vector<long> k(s,0);
    for(int i=0;i<s;i++){
        k[i] = pro;
        pro = pro*c;
        pro %= M;
    }
    long long check = hashfun(k,word), init = hashfun(k,text.substr(0,s));
    cout << check << endl;
    for(int i=s;i<t;i++){
        // cout << init << endl;
        if(init == check){
            // for(j=0;j<s;j++){
            //     if(word[j]==text[i-s+j]) continue;
            //     else break;
            // }
            // if(j==s) 
            ctr++;
        }
        init = init - (text[i-s]*k[s-1])%M + M;
        init%=M;
        init *= c;
        init %=M;
        init += text[i];
        init %=M;
    }
    return ctr;
}

int main(){
    string text = "ababaaaadfgab";
    string word = "aa";
    cout << checkstring(text,word);
}