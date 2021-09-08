#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//마지막 전 계단을 밟았을 때=>score[i]=score[i-3]+stairs[i-1]+stairs[i]
//마지막 전 계단을 밟지 않았을 때=>score[i]=score[i-2]+stairs[i]
int main(){
    int N, s;
    cin >> N;
    vector<int> score(N), stairs(N);

    for(int i=0; i<N; i++){
        cin >> s;
        stairs[i]=s;
    }

    score[0]=stairs[0];
    score[1]=stairs[0]+stairs[1];
    score[2]=max(stairs[0]+stairs[2], stairs[1]+stairs[2]);
    for(int i=3; i<N; i++){
        score[i]=max(score[i-3]+stairs[i-1]+stairs[i],score[i-2]+stairs[i]);
    }
    cout << score[N-1];
    return 0;
}