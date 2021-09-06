#include <iostream>
using namespace std;

int main(){
    int N, r, result;
    cin >> N;
    r=N%5;  // 5로 나누었을 때 나머지
    switch(r){
        case 0:
            result=N/5; // 전부 5kg
            break;
        case 1:
            result=(N-6)/5 + 2; // 2개만 3kg, 나머지 5kg
            break;
        case 2:
            if(N!=7){   // 7이 아닐 때
                result=(N-12)/5 + 4;    // 4개만 3kg, 나머지 5kg
            }
            else{
                result=-1;  // 7은 만들 수 없음
            }
            break;
        case 3:
            result=(N-3)/5 + 1; // 1개만 3kg, 나머지 5kg
            break;
        case 4:
            if(N!=4){   // 4가 아닐 때
                result=(N-9)/5 + 3; // 3개만 3kg, 나머지 5kg
            }
            else{
                result=-1;  // 4는 만들 수 없음
            }
            break;
        default:
            break;
    }
    cout << result << endl;
}