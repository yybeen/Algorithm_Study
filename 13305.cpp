#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    int oil[N], dis[N-1];

    for(int i=0; i<N-1; i++){
        cin >> dis[i];
    }

    for(int i=0; i<N; i++){
        cin >> oil[i];
    }

    long long cost=0;
    for(int k=0; k<N-1; k++){
        if(k!=0){
         if(oil[k-1]<oil[k]){
                oil[k]=oil[k-1];
            }
        }
        cost+=(long long)oil[k]*dis[k];
    }
    
    cout << cost;

    return 0;
}