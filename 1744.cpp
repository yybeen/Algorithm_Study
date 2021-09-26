#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct cmp{
    bool operator()(int a, int b){
        if(a>0 && b>0) return a<b;
        else{
            return a>b;
        }
    }
};

int main(){
    int N, tmp, a, b;
    int sum=0;
    priority_queue<int, vector<int>, cmp> pq;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> tmp;
        pq.push(tmp);
    }

    while(pq.size()>1){
        a=pq.top();
        pq.pop();
        b=pq.top();
        pq.pop();
        if(b==1){
            sum+=b;
            pq.push(a);
        }
        else if(a>0 && b>0 || a<0 && b<0 || a<=0 && b==0) sum+=a*b;
        else{
            sum+=a;
            pq.push(b);
        }
    }

    if(!pq.empty()) sum+=pq.top();
    
    cout << sum;
    return 0;
}