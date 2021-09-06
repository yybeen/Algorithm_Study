#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, S;
    cin >> N >> S;

    vector<int> seq(N);
    for(int i=0; i<N; i++){
        cin >> seq[i];
    }

    int start=0, end=0, psum=seq[0], lmin=100001;

    while(start<=end && end<N){
        if(psum>S){
            lmin=min(lmin, end-start+1);
            if(lmin==1) break;
            psum-=seq[start++];
        }
        else if(psum==S){
            lmin=min(lmin, end-start+1);
            if(lmin==1) break;
            psum+=seq[++end];
        }
        else psum+=seq[++end];
    }

    if(lmin==100001) cout << 0;
    else cout << lmin;

    return 0;
}