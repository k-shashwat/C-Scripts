#include <bits/stdc++.h>
using namespace std;
vector<vector <int>> Solution(vector<vector<int>>&A){
    int n =A.size();
    vector<vector<int>> ans(2*n-1);
    int sum =0;
    for(int i=0;i<2*n-1;i++){
        for(int j=i;(i-j)>=0 && (i-j)<n;j--){
            cout << A[i-j][j] << " ";
            ans[i].push_back(A[i-j][j]);
        }
    }
    return A;
}

int main(){
    vector<vector <int>> A;
    for(int i= 0;i<4;i++){
        for(int j=0;j<4;j++){
            A[i].push_back(j);
        }
    }
    vector<vector<int>> answer = Solution(A);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
        cout <<answer[i][j] << " ";
    }

}
    
