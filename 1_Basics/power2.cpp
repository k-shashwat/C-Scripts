#include <bits/stdc++.h>
using namespace std;
bool checkpower(int A){
    int p = A & (A-1);
    if(p==0) return true;
    return false;
}
int main(){
    cout << checkpower(18);
}