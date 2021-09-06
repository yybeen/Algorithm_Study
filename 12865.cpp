#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, K, W, V;
    cin >> N >> K;
    vector<pair<int, int>> product;
    product.push_back(make_pair(-1,-1));
    for(int i=0; i<N; i++){
        cin >> W >> V;
        product.push_back(make_pair(W,V));
    }

    vector<vector<int>> dp(N+1,vector<int>(K+1,0));
    for(int i=1; i<=N; i++){
        for(int j=0; j<=K; j++){
            if(product[i].first<=j) dp[i][j]=max(dp[i-1][j],dp[i-1][j-product[i].first]+product[i].second);
            else dp[i][j]=dp[i-1][j];
        }
    }

    cout << dp[N][K];
    return 0;
}