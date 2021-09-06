#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, K, tmp;
    int dp[10001]={0};
    vector<int> coin;
    
    cin >> N >> K;
    
    for(int i=0; i<N; i++){
        cin >> tmp;
        coin.push_back(tmp);
    }
    
    dp[0]=1;
    for(int i=0; i<N; i++){
        for(int j=coin[i]; j<=K; j++){
            dp[j]+=dp[j-coin[i]];
        }
    }
    
    cout << dp[K] << "\n";
    
    return 0;
}