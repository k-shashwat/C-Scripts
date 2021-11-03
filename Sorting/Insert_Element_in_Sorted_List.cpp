#include <bits/stdc++.h>
using namespace std;

void insert1(vector<int> &arr,int num){
    if(arr.size()==0 || num>=arr[arr.size()-1]) {
        arr.push_back(num);
        return;
    }
    int val = arr[arr.size()-1];
    arr.pop_back();
    insert1(arr,num);
    arr.push_back(val);
}
int main(){
    vector <int> p = {2,3,4,5,7};
    insert1(p,6);
    // sort(p.begin(),p.end());
    for(int i=0;i<p.size();i++) cout << p[i] << " ";
}
