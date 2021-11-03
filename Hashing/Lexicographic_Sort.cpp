#include <bits/stdc++.h>
using namespace std;

string lex_sort(string word, string dict){
    vector<int> freq(dict.size(),0);
    vector<int> rank(dict.size(),0);
    for(int i=0;i<dict.size();i++) rank[dict[i]-'a'] = i;
    string res = "";
    for(int i=0;i<word.size();i++) freq[rank[word[i]-'a']]++;
    for(int i=0;i<dict.size();i++){
        while(freq[i]>0){
            res = res + dict[i];
            freq[i]--;
        }
    }
    // cout << word << endl << dict << endl;
    // for(auto g : freq) cout << g;
    
    return res;
}

int main(){
    string q = "aabcade";
    string dict = "cbfade";
    cout << lex_sort(q,dict);
}