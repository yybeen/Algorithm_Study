#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(){
    int N, s1, s2;
    cin >> N;
    vector<int> solution(N);
    for(int i=0; i<N; i++){
        cin >> solution[i];
    }
    sort(solution.begin(), solution.end());

    int start=0, end=N-1, smin=2000000000;

    while(start<end){
        int sum=solution[start]+solution[end];
        if(abs(sum)<smin){
            smin=abs(sum);
            s1=start;
            s2=end;
        }
        if(sum==0) break;
        else if(sum>0) end--;
        else start++; 
    }

    cout << solution[s1] << " " << solution[s2];
    return 0;
}