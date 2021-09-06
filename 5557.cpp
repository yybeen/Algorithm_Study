#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, tmp;
    vector<int> num;
    long dp[101][21]={0};

    cin >> N;
    num.push_back(-1);
    
    for(int i=1; i<=N; i++){
        cin >> tmp;
        num.push_back(tmp);
    }

    dp[1][num[1]]=1;
    for(int i=2; i<N; i++){
        for(int j=0; j<=20; j++){
            if(dp[i-1][j]!=0){
                if(j+num[i]<=20) dp[i][j+num[i]]+=dp[i-1][j];
                if(j-num[i]>=0) dp[i][j-num[i]]+=dp[i-1][j];
            }
        }
    }

    cout << dp[N-1][num[N]];
    return 0;
}