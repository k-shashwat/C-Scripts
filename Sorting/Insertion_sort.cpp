#include <bits/stdc++.h>
using namespace std;

void insert_ele(vector<int> &arr,int num){
    if(arr.size()==0 || num>=arr[arr.size()-1]) {
        arr.push_back(num);
        return;
    }
    int val = arr[arr.size()-1];
    arr.pop_back();
    insert_ele(arr,num);
    arr.push_back(val);
}

void ins_sort(vector <int> &arr){
    if(arr.size()==1) return;
    int temp = arr[arr.size()-1];
    arr.pop_back();
    ins_sort(arr);
    insert_ele(arr, temp);
}

int main(){
    vector <int> p = {2,3,7,6,4,5,9};
    ins_sort(p);
    // sort(p.begin(),p.end());
    for(int i=0;i<p.size();i++) cout << p[i] << " ";
}
