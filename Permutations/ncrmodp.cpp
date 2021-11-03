#include <bits/stdc++.h>
using namespace std;
int solve(int A,int B, int C){
        B = min(B,A-B);
    vector <int> prev(B+1,0);
    prev[0] = 1;
    for(int i =2;i<=A+1;i++){
        vector <int> next(B+1,0);
        next[0] = 1;
        for(int j=1;j<=B;j++){
            next[j] = (prev[j]+prev[j-1])%C;
        }
        // for(auto g : prev) cout << g << " - ";
        // cout << endl;
        prev = next;
    }
    // for(auto g : prev) cout << g << " - ";
    // cout << endl;
    return prev[B]%C;
}
int main(){
    int ans = solve(41,27,143);
    cout << ans << endl;
}