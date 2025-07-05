#include<bits/stdc++.h>
using namespace std;

int lowbit(int ind){    // isolate the least significant bit
    return ind & (-ind);
}

void update(int ind, int val, vector<int>&bit, int n){
    while(ind<=n){
        bit[ind]+=val;
        ind+=lowbit(ind);
    }
}

int query(int i, vector<int>&bit){
    int sum = 0;
    while(i>0){
        sum+=bit[i];
        i-=lowbit(i);
    }
    return sum;
}

int main(){
    int n;
    cout << "Enter the size of the array: " << endl;

    cin >> n;
    vector<int>arr(n+1);    // 1 indexed array
    vector<int>bit(n+1,0);

    for(int i=1;i<n+1;i++){
        cin >> arr[i];
        update(i, arr[i], bit, n);
    }

    // Example Queries

    cout << "Prefix Sum of first 5 elements: " << query(5,bit) << endl;

    //  update index 3 with value 5;
    cout << "Updating index 3 with value 5";
    update(3, 5, bit, n);

    cout << "Prefix Sum of first 5 elements after update: " << query(5,bit) << endl;
    return 0;
}
