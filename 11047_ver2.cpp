#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, K;
    int answer=0;
    cin >> N >> K;
    vector<int> coin(N);
    for(int i=0; i<N; i++){
        cin >> coin[i];
    }
    
    for(int i=N-1; i>=0; i--){
        if(K==0) break;
        if(K>=coin[i]){
            answer+=K/coin[i];
            K-=coin[i]*(K/coin[i]);
        }
    }
    
    cout << answer;
    return 0;
}