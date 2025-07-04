#include<bits/stdc++.h>
using namespace std;

// Levenshtein Distance is to find the minimum number of single-character edits (insertions, deletions or substitutions) required to change a string to the other

int helper(string s1, string s2, int i, int j, vector<vector<int>>&dp){
    if(i==0) return j;
    if(j==0) return i;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i-1] == s2[j-1]) return dp[i][j] = helper(s1,s2,i-1,j-1,dp);

    int insertop = 1+helper(s1,s2,i,j-1,dp);
    int deleteop = 1+helper(s1,s2,i-1,j,dp);
    int replaceop = 1+helper(s1,s2,i-1,j-1,dp);

    return dp[i][j] = min({insertop,deleteop,replaceop});
}

int main(){
    string s1,s2;
    cin >> s1 >> s2;

    vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));

    cout << helper(s1,s2,s1.size(),s2.size(), dp) << endl;
}