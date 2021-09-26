#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N, tmp, a, b;
    long long result=0, sum=0;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<N; i++){
        cin >> tmp;
        pq.push(tmp);
    }

    if(N==1) result=0;
    else{
        while(pq.size()>1){
            a=pq.top();
            pq.pop();
            b=pq.top();
            pq.pop();
            sum=a+b;
            result+=sum;
            pq.push(sum);
        }
    }
    
    cout << result;
    return 0;
}