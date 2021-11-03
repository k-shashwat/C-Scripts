#include <bits/stdc++.h>
using namespace std;

unordered_set <int> row_set,col_set,left_diag_set,right_diag_set;
vector<vector<vector<int>>> ans;
vector <vector<string>> result;
void nQueens(vector<vector<int>>board, int N, int row){
    if(row == N) ans.push_back(board);
    for(int col=0;col<N;col++){
        if((row_set.find(row)==row_set.end()) && 
        (col_set.find(col)==col_set.end()) &&
        (left_diag_set.find(row+col)==left_diag_set.end()) &&
        (right_diag_set.find(row-col)==right_diag_set.end())){
            board[row][col] = 1;
            row_set.insert(row),col_set.insert(col),left_diag_set.insert(row+col),right_diag_set.insert(row-col);
            nQueens(board,N,row+1);
            board[row][col] = 0;
            row_set.erase(row),col_set.erase(col),left_diag_set.erase(row+col),right_diag_set.erase(row-col);
        }
    }
}
int main(){
    int n = 5;
    vector<vector<int>>board (n, vector<int>(n,0));
    nQueens(board,n,0);
    int k = ans.size();
    for(int l=0;l<k;l++){
        vector<string> p;
        for(int i=0;i<n;i++) {
            string temp = "";
            for(int j=0;j<n;j++){
                if(ans[l][i][j]==0) temp = temp + '.';
                else temp = temp + 'Q'; 
            }
            p.push_back(temp);
        }
        result.push_back(p);
    }

    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            cout << result[i][j] <<endl;
        }
        cout << "--------------------------" << endl;
    }
}
