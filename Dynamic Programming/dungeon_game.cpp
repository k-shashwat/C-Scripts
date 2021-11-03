#include <bits/stdc++.h>
using namespace std;

int calculateMinimumHP(vector<vector<int>>& b) {
    int dirs[2][2] = {{0, 1}, {1, 0}};
    int r = b.size();
    int c = b[0].size();
    vector<vector<int>> dp(r, vector<int>(c, INT_MAX));
    dp[r-1][c-1] = max(1, 1 - b[r-1][c-1]);
    for (int i = r - 1; i >= 0; i--)
    {
        for (int j = c - 1; j >= 0; j--) {
            if (i == r - 1 && j == c - 1) continue;
            for (auto d : dirs) {
                int ni = i + d[0];
                int nj = j + d[1];

                if (ni >= 0 &&  ni < r && nj >= 0 && nj < c) {

                    dp[i][j] = max(min(dp[ni][nj] - b[i][j] , dp[i][j]), 1);
                }
            }

        }
    }

    return dp[0][0];
}
    
int main(){
    vector<vector<int>> b = {{1,-2,-3},{-2,-6,-4},{-5,6,-7}};
    cout << calculateMinimumHP(b);
}
