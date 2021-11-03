#include <bits/stdc++.h>
using namespace std; 

int totalWays(int n, string str)
{
    vector<int> IdxOf0s;
    int cntWays = 1;
    for (int i = 0; i < n; i++) if (str[i] == '0') IdxOf0s.push_back(i);
    int M = IdxOf0s.size();
    if (M == 0 or M % 2==1) return 0;
    for (int i = 2; i < M; i += 2) cntWays = cntWays * (IdxOf0s[i] - IdxOf0s[i - 1]);
    return cntWays;
}
 
int main()
{
    string str = "00100100100";
    int n = str.length();
    cout << totalWays(n, str);
    return 0;
}