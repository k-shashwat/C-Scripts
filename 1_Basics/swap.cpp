#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void swap(int &a, int &b){
    a=a*b;
    b=a/b;
    a=a/b;
}
int main(){
    vector <int> A;
    A.push_back(5);
    A.push_back(6);
    cout << A[0] << " " << A[1] << endl;  
    swap(A[0],A[1]);
    cout << A[0] << " " << A[1];
    return 0;
}