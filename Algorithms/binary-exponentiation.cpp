#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
#define endl '\n'

constexpr ll MOD = 1e9 + 7;

int main() {

    ll base = 5, exp = 2;
    ll answer = 1;

    while(exp > 0) {
        if(exp & 1) {
            answer = (answer * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1;
    }

    cout << answer << endl;

    // Time Conplexity: O(log n);

    // base = 5, exp = 10;
    // exp = (1 0 1 0) in bin.
    //     2^3          2^2           2^1            2^0
    //      1            0             1              0               <-- Binary of exp;
    // base = 5^8    base = 5^4    base = 5^2     base = 5^1;
    // 
    // answer = 5^2 * 5^8; (product of base where bit of exp is 1);
    // answer = 5 ^ 10;

    return 0;
}