#include <iostream>
#include <algorithm>
#define MAX 999999999
using namespace std;

int main(){
    int N; //배달해야하는 킬로 수
    int dp[5001]; //dp[m]=n m:총 킬로 수, n:최소 봉지 수

    cin >> N;

    //memset(dp, MAX, sizeof(dp)); //dp 최대값으로 초기화-memset은 0또는 -1말고는 이상한 값으로 초기화
    for(int i=0; i<=N; i++){
        dp[i]=MAX;
    }
    
    dp[3]=1;
    dp[5]=1;
    
    for(int i=3; i<=N; i++){
        for(int j=3; j<i/2+1; j++){
            dp[i]=min(dp[j]+dp[i-j],dp[i]);
        }
    }

    if(dp[N]==MAX) cout << -1;
    else cout << dp[N];
    
    return 0;
}