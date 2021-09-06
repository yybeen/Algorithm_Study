#include <iostream>
using namespace std;

int main(){
    int n, k;
    int cnt=0;
    cin >> n >> k;
    int coin[n]; //코인의 종류
    
    for(int i=0; i<n; i++){
        cin >> coin[i];
    }
    for(int i=n-1; i>=0; i--){
        if(coin[i]<=k) {
            cnt+=k/coin[i];
            k-=coin[i]*(k/coin[i]);
            if(k==0) break;
        }
    }

    cout << cnt;
    return 0;
}