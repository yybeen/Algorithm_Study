#include <iostream>
using namespace std;

bool PrimeNumber(int num){
    int half, r;
    if(num==2 || num==3) return true;
    half=num/2;
    for(int i=2; i<=half; i++){
        r=num%i;
        if(r==0) return false;
    }
    return true;
}

int main(){
    int Cnt, n, p1, p2;
    cin >> Cnt; // 입력할 짝수(n)개수
    
    for(int k=0; k<Cnt; k++){
        cin >> n;
        p1=n/2;
        if(PrimeNumber(p1)==true){ // n의 절반이 소수일 때
            cout << p1 << " " << p1 << endl;
        }
        else{
            if(p1%2==0) { // 2가 아닌 짝수는 소수일 수 없다
                p1-=1;
            }
            else{ // 홀수인데 p1은 소수가 아니므로 다음 홀수
                p1-=2;
            }
            while(1){ // p1, p2가 소수인 값 찾을 때까지 반복
                if(PrimeNumber(p1)==true){ // p1이 소수일 때
                    p2=n-p1;
                    if(PrimeNumber(p2)==true){ // p2가 소수일 때
                        cout << p1 << " " << p2 << endl;
                        break;
                    }
                    else{
                        p1-=2;  // 홀수 중에 찾아야하므로 2씩 빼줘야함
                    }
                }
                else{
                    p1-=2; // 홀수 중에 찾아야하므로 2씩 빼줘야함
                }

            }
        }
    }
    return 0;
}