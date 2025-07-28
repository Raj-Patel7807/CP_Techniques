#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
#define endl '\n'

int main() {

    ll n = 50;

    vector<bool> isPrime(n+1, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false;

    for(ll i = 2; i <= n; i++) {
        if(isPrime[i]) {
            for(ll j = i*i; j <= n; j++) {
                isPrime[j] = false;
            }
        }
    }

    for(ll i = 2; i <= n; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
        }
    }

    // Time Complexity: (n log(log(n)));

    return 0;
}