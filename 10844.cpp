#include <iostream>
#include <vector>
using namespace std;
/*dp[i][j]=길이가 i인 계단 수 중 j로 끝나는 수의 개수
  j!=0,9 -> dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1] 
  j=0 -> dp[i][j]=dp[i-1][j+1]
  j=9 -> dp[i][j]=dp[i-1][j-1]*/
int main(){
    int N;
    cin >> N;
    vector<vector<int>> dp(N+1,vector<int>(10,0));
    
    for(int i=1; i<10; i++){
        dp[1][i]=1;
    }
    for(int i=2; i<N+1; i++){
        for(int j=0; j<10; j++){
            if(j==0) dp[i][j]=dp[i-1][j+1];
            else if(j==9) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%1000000000;
        }
    }
    int sum=0;
    for(int i=0; i<10; i++){
        sum=(sum+dp[N][i])%1000000000;
    }
    cout << sum;
    return 0;
}