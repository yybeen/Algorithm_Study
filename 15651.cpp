#include <iostream>
using namespace std;

int ary[7];

void pi(int cnt, int a, int b){
    if(cnt==b){ //깊이 = 개수. 깊이가 꽉 차면 출력 후 return
        for( int k=0; k<b; k++){
            cout << ary[k] << " ";
        }
        cout << '\n';
        return;
    }
    else{ //개수가 차지 않았으면 1부터 최근 숫자까지 삽입
        for(int i=1; i<=a; i++){
            ary[cnt]=i;
            pi(cnt+1, a, b);
        }
    }
}
int main(){
    int a, b;
    
    cin >> a >> b;

    pi(0,a,b);

    return 0;
}