#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    int sum=0;
    cin >> N >> M;

    vector<int> mem(N+1,0);

    for(int i=1; i<=N; i++){
        cin >> mem[i];
    }

    vector<int> cost(N+1,0);

    for(int i=1; i<=N; i++){
        cin >> cost[i];
        sum+=cost[i];
    }

    int result=sum+1;
    vector<vector<int>> dp(N+1,vector<int>(sum+1,0)); //dp[i][j]=i번째 앱까지 중 사용된 비용이 j일때 확보되는 최대 메모리값
    for(int i=1; i<=N; i++){
        for(int j=0; j<=sum; j++){
            if(j>=cost[i]) dp[i][j]=max(dp[i-1][j],dp[i-1][j-cost[i]]+mem[i]);
            else dp[i][j]=dp[i-1][j];

            if(dp[i][j]>=M) result=min(result, j);
        }
    }

    cout << result;
    return 0;
}