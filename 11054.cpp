#include <iostream>
#include <vector>
using namespace std;
//dp[i]=앞에서부터 i번째까지 오름차순 수열이 되는 최대 개수
//dp_back[i]=뒤에서부터 i번째까지 오름차순 수열이 되는 최대 개수
int main(){
    int N;
    vector<int> A(N), dp(N,1), dp_back(N,1);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<i; j++){
            if(A[i]>A[j] && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
            }
        }
    }
    
    for(int i=N; i>-1; i--){
        for(int j=N-1; j>i; j--){
            if(A[i]>A[j] && dp_back[i]<dp_back[j]+1){
                dp_back[i]=dp_back[j]+1;
            }
        }
    }
    
    int result=0;
    
    for(int i=0;i<N;i++){
        if(result<dp[i]+dp_back[i]-1) result=dp[i]+dp_back[i]-1;
    }
    cout << result;
    return 0;
}