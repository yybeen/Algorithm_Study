#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    int sum=0, wait=0;

    cin >> N;
    
    vector<int> P(N); 

    for(int i=0; i<N; i++){
        cin >> P[i];
    }

    sort(P.begin(),P.end());

    for(int i=0; i<N; i++){
        wait+=P[i];
        sum+=wait;
    }

    cout << sum;
    return 0;
}