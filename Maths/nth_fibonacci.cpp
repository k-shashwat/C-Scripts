#include <bits/stdc++.h>
using namespace std;
int fib_n(int n){
    if(n<=2) return 1;
    int a =1,b=1;
    for(int i=3;i<=n;i++){
        int temp = a;
        a=b;
        b=temp+b;
    }
    return b;
}

int main(){
    cout << fib_n(5);
}
