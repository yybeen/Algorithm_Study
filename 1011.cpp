#include <iostream>
using namespace std;

int main(){
    long N, x, y, distance, m, q, r, result;
    cin >> N;
    for(int i=0; i < N; i++){
        long z=1;
        cin >> x >> y;
        distance = y-x; // x와 y사이 거리
        while(z*z<=distance){// distance보다 작거나 같은 값 중 가장 큰 값의 제곱근(z)찾기
            z++;
        }
        z-=1;// while문에서 구하고자하는 값보다 1큰 값을 구할 수 있으므로 1빼기
        m=distance-z*z;   // distance와 구한 z의 제곱의 차이
        if(m==0){    // 두 값이 같은 경우
            result=z*2-1;
        }
        else{
            q=m/z;  // 남은 거리(m)에 z가 몇번 들어갈 수 있는가
            r=m%z;  // 남은 거리(m)에 z가 아닌 값이 존재할 수 있는가
            if(r==0){   // z가 아닌 다른 값이 존재하지 않아도 되는 경우
                result=z*2+q-1;
            }
            else{   // z가 아닌 다른 값이 하나 들어가야하는 경우
                result=z*2+q;
            }
        }
        cout << result << endl;
    }
}