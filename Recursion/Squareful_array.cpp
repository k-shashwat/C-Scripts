#include <bits/stdc++.h>
using namespace std;
set <vector<int>> ans;

bool check_square(long n){
    long k = sqrt(n);
    return ((k*k) == n);
}


void squareful(int &count, vector<int> A, int i){
    if(i==A.size()) {
        if(ans.find(A)==ans.end()){ 
            ans.insert(A);
            count +=1;
            for(auto g:A) cout << g << " ";
            cout << endl;
            return;
        }
    }
    for(int k=i;k<A.size();++k){
        if(A[i]==A[k] && i!=k) continue;
        swap(A[i],A[k]);
        if(i==0) squareful(count,A,i+1);
        else if((i>0) && check_square(A[i]+A[i-1])) squareful(count,A,i+1);
        swap(A[i],A[k]);
    }
}
int main(){
    vector<int> arr = {36229, 1020, 69, 127, 162, 127,3771};
    // ans.insert(arr1);
    int n = arr.size();
    int count =0;
    squareful(count,arr,0);
    cout << count;
}
