#include <iostream>
using namespace std;

int ary[7];

void pi(int cnt, int a, int b){
    if(cnt==b){
        for( int k=0; k<b; k++){
            cout << ary[k] << " ";
        }
        cout << '\n';
        return;
    }
    else{
        for(int i=1; i<=a; i++){
            if(cnt==0){
                ary[cnt]=i;
                pi(cnt+1, a, b);
            }
            else if(ary[cnt-1]<=i){
                ary[cnt]=i;
                pi(cnt+1, a, b);
            }
        }
    }
}
int main(){
    int a, b;
    
    cin >> a >> b;
    pi(0,a,b);
    return 0;
}