#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string seq1, seq2;
    cin >> seq1;
    cin >> seq2;
    int size1=seq1.size(), size2=seq2.size();
    vector<vector<int>> dp(size1+1, vector<int>(size2+1,0));
    
    for(int i=1; i<size1+1; i++){
        for(int j=1; j<size2+1; j++){
            if(seq1[i-1]==seq2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else{
                if(dp[i-1][j]>dp[i][j-1]) dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i][j-1];
            }
        }
    }
    
    cout << dp[size1][size2];
    return 0;
}