#include <bits/stdc++.h>
using namespace std;

void wordBreak(vector<string> &ans,string A, unordered_set<string> dict, int start,string temp){
    if(start == A.size()){
        ans.push_back(temp);
    }
    for(int i=start;A[i]!='\0';i++){
        string k = string(&A[start], &A[i+1]);
        if(dict.find(k)!=dict.end()){
            wordBreak(ans,A,dict,i+1,temp + k + " ");
        }
    }
}

int main(){
    string A = "catsanddog";
    vector <string> B = {"cat", "cats", "and", "sand", "dog"};
    A = "kamleshisbacke";
    B = {"kam", "lesh" ,"leshis", "isback", "back" ,"kamlesh", "isb" , "ack"};
    unordered_set<string> dict;
    for(auto g : B) dict.insert(g);
    unordered_set<string> :: iterator itr;
    vector<string> ans;
    wordBreak(ans,A,dict,0,"");

    int k = ans.size();
    for(int i=0;i<k;i++) cout << ans[i] << endl;
}
