#include <bits/stdc++.h>
using namespace std;
void counter(string &A, int &left, int &right){
    for(int i=0;i<A.size();i++){
        if(A[i]=='(') left++;
        if(A[i]==')'){
            if(left>0) left--;
            else right++;
        }
    }
}
void InvalidParenthesis(string &A,int start,string res, set<string> &ans, int open, int closed, int balance){
    if(start == A.size()){
       if(open ==0 && closed ==0) ans.insert(res);
       return;
    } 
    else if(balance >=0){
        if(A[start] == '(' && open >0) InvalidParenthesis(A,start+1,res,ans,open-1,closed,balance);
        if(A[start] == ')' && closed >0) InvalidParenthesis(A,start+1,res,ans,open,closed-1,balance);
        int flag=0;
        if(A[start]=='(') flag = 1;
        if(A[start]==')') flag = -1;
        InvalidParenthesis(A,start+1,res+A[start],ans,open,closed,balance+flag);
    }
}
vector<string> solve(string A) {
    set<string> ans;
    vector<string> result;
    int left =0,right =0;
    counter(A,left,right);
    InvalidParenthesis(A,0,"",ans,left,right,0);
    for(string itr:ans) result.push_back(itr);
    return result;
}
int main(){
    vector <string> fin = solve("()))()");
    for(auto g : fin) cout << g << endl;
}