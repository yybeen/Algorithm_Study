#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//~x00 -> dp[i-3]+wine[i-1]+wine[i]
//~0x0 -> dp[i-2]+wine[i]
//마지막 잔을 꼭 마시지 않아도 된다
int main(){
    int n, w;
    cin >> n;
    vector<int> dp(n+1,0), wine(n+1,0);

    for(int i=1; i<n+1; i++){
        cin >> w;
        wine[i]=w;
    }

    dp[1]=wine[1];
    dp[2]=wine[1]+wine[2];
    for(int i=3; i<=n; i++){
        dp[i]=max(dp[i-3]+wine[i-1]+wine[i],dp[i-2]+wine[i]);
        dp[i]=max(dp[i],dp[i-1]);
    }
    cout << dp[n];
    return 0;
}