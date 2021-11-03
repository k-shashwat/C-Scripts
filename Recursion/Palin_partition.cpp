#include <bits/stdc++.h>
using namespace std;

bool check_palindrome(string p){
    int i=0,l=p.size();
    while(i<l/2) {
        if(p[i]!=p[l-i-1]) return 0;
        i++;
    }
    return 1;
}

void get_palindrome(vector<vector<string>> &ans,string &A,vector<string> res,int ind,int n){
    if(ind == n) {
        ans.push_back(res);
        return;
    }
    for(int i=ind;i<n;i++){
        string k = A.substr(ind,i-ind+1);
        if(check_palindrome(k)){
            res.push_back(k);
            get_palindrome(ans,A,res,i+1,n);
            res.pop_back();
        }
    }
}

vector<vector<string>> p_partition(string &A){
    int n = A.size();
    vector<vector<string>> ans;
    vector<string> t;
    get_palindrome(ans,A,t,0,n);
    return ans;
}
int main(){
    string A = "aabbb";
    vector < vector <string>> result = p_partition(A);
    int k = result.size();
    for(int i=0;i<k;i++){
        for(auto g: result[i]) cout << g << " ";
        cout << endl;
    }
}