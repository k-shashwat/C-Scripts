#include <bits/stdc++.h>
using namespace std;

int sum_of_dig(int n, int sum){
    if(n==0) return sum;
    return sum_of_dig(n/10,sum + n%10);
}
int main(){
    cout << sum_of_dig(978981,0);
}