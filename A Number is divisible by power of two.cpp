// Find n % 2^k.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
     ll n ,k;
     cin >> n >> k;

     if (!(n & ((1LL << k) -1))){
          cout << "YES" <<endl;
     }
     else {
          cout << "NO" <<endl;
     }
     return 0;
}