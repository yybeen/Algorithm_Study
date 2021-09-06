#include <iostream>
#include <cstdlib>
using namespace std;

int col[15]; // col[i]=행, i=열
int result=0; // 퀸 놓는 총 방법의 수

bool check(int x){ // 행, 대각선으로 안 겹치는지 확인
    for(int i=0; i<x; i++){
        if(col[i]==col[x] || abs(i-x)==abs(col[i]-col[x])) return false;
    }
    return true;
}

void NQueen(int num, int cnt){
    if(cnt==num){
        result++;
    }
    for(int i=0; i<num; i++){ // i행에 놓았을 떄 안 겹치는지 확인
        col[cnt]=i;
        if(check(cnt)==true) NQueen(num, cnt+1); // 안 겹치면 다음 열 확인
    }
}

int main(){
    int n;

    cin >> n;

    NQueen(n,0);

    cout << result;

    return 0;
}