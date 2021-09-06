#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N, val;
    cin >> N;
    int input[N];

    priority_queue<int, vector<int>, greater<int>> q;

    for(int i=0; i<N; i++){
        cin >> val;
        input[i] = val;
    }
    for(int i=0; i<N; i++){
        if(input[i]==0){
            if(q.size()==0){
                cout << '0' << '\n';
            }
            else{
                cout << q.top() << '\n';
                q.pop();
            }
        }
        else{
            q.push(input[i]);
        }
    }
    return 0;
}