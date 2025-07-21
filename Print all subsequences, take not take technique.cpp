#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Input the size of the array
    int n;
    cin >> n;

    // Declare a vector to store the elements
    vector<int> arr(n);

    // Input the elements of the array
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Function to print all subsequences
    function<void(int, vector<int>&)> printSubsequences = [&](int index, vector<int>& current) {
        if(index == n) {
            if(current.empty()) {
                cout << "{}\n"; // Print empty subsequence
            } else {
                cout << "{ ";
                for(int x : current) {
                    cout << x << " ";
                }
                cout << "}\n";
            }
            return;
        }

        // Include the current element
        current.push_back(arr[index]);
        printSubsequences(index + 1, current);

        // Exclude the current element
        current.pop_back();
        printSubsequences(index + 1, current);
    };

    vector<int> current;
    printSubsequences(0, current);

    return 0;
}
