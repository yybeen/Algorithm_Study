#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

    string S, T;
    int slen, tlen;

    cin >> S >> T;

    slen = S.size();
    tlen = T.size();
    while(slen < tlen){
        if(T[tlen-1]=='A'){//마지막 문자가 A일 때 > A 삭제
            T = T.substr(0,tlen-1);
        }
        else{//마지막 문자가 B일 때 > B 삭제 후 뒤집기
            T = T.substr(0,tlen-1);
            reverse(T.begin(), T.end());
        }
        tlen--;
    }

    if(S==T) cout << 1;
    else cout << 0;

    return 0;
}