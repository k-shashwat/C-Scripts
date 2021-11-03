#include <bits/stdc++.h>
using namespace std;

bool check_anagram(string A, string B){
    int n = 'z' - 'A' + 1;
    vector<int> freqA(n,0),freqB(n,0);
    for(int i=0;i<A.size();i++){
        int p = A[i]-'A';
        freqA[p]++;
    }
    for(int i =0;i<B.size();i++){
        int p = B[i]-'A';
        freqB[p]++;
    }
    for(int i=0;i<n;i++){
        if(freqA[i]!=freqB[i]) return false;
    }
    return true;
}
vector<vector<int> > anagrams(const vector<string> &A){
    int n =A.size();
    vector <bool> anag(n,0);
    vector <vector<int>> ans(n);
    for(int i=0;i<n;i++){
        if(anag[i]==0){
            anag[i] =1;
            // ans[i].push_back(i+1);
            for(int j = i; j < n; j++){ //traversing through the array
                if(check_anagram(A[i],A[j])) {
                    ans[i].push_back(j+1);
                    anag[j] = 1;
                }
            }
            // if(ans[i].size()==1) ans[i].pop_back();
        }
    }
    for(int i=0;i<ans.size();i++)
        if(ans[i].size()==0){
            ans.erase(ans.begin()+i);
            i--;
        }
    return ans;
}

int main(){
    vector <string> A = { "cat" ,"dog" ,"god" ,"tca"};
    A = {"abbbaabbbabbbbabababbbbbbbaabaaabbaaababbabbabbaababbbaaabbabaabbaabbabbbbbababbbababbbbaabababba", 
        "abaaabbbabaaabbbbabaabbabaaaababbbbabbbaaaabaababbbbaaaabbbaaaabaabbaaabbaabaaabbabbaaaababbabbaa", 
        "babbabbaaabbbbabaaaabaabaabbbabaabaaabbbbbbabbabababbbabaabaabbaabaabaabbaabbbabaabbbabaaaabbbbab", 
        "bbbabaaabaaaaabaabaaaaaaabbabaaaabbababbabbabbaabbabaaabaabbbabbaabaabaabaaaabbabbabaaababbaababb", 
        "abbbbbbbbbbbbabaabbbbabababaabaabbbababbabbabaaaabaabbabbaaabbaaaabbaabbbbbaaaabaaaaababababaabab", 
        "aabbbbaaabbaabbbbabbbbbaabbababbbbababbbabaabbbbbbababaaaabbbabaabbbbabbbababbbaaabbabaaaabaaaaba", 
        "abbaaababbbabbbbabababbbababbbaaaaabbbbbbaaaabbaaabbbbbbabbabbabbaabbbbaabaabbababbbaabbbaababbaa", 
        "aabaaabaaaaaabbbbaabbabaaaabbaababaaabbabbaaaaababaaabaabbbabbababaabababbaabaababbaabbabbbaaabbb" };
    vector<vector<int>> ans =  anagrams(A);
    int n = ans.size();
    for(int i=0;i<n;i++){
        for(auto g : ans[i]) cout << g << " ";
        cout << endl; 
    }
}
