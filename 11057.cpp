#include <iostream>
#include <vector>
using namespace std;
//dp[i][j]=길이가 i인 수 중 마지막 자리가 j인 오르막 수 개수
//dp[i][j]=dp[i][j-1]+dp[i-1][j]
int main(){
    int N;
    cin >> N;
    vector<vector<int>> dp(N+1, vector<int>(10,0));
    
    for(int i=0; i<N+1; i++){
        dp[i][0]=1;
    }
    for(int j=0; j<10; j++){
        dp[1][j]=1;
    }
    for(int i=2; i<N+1; i++){
        for(int j=1; j<10; j++){
            dp[i][j]=(dp[i][j-1]+dp[i-1][j])%10007;
        }
    }
    
    int sum=0;
    for(int i=0; i<10; i++){
        sum=(sum+dp[N][i])%10007;
    }
    cout << sum;
    return 0;
}