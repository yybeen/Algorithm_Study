#include <iostream>
#include <queue>
using namespace std;

int main(){
    int TC, N, M, tmp, cnt;

    cin >> TC;
    for(int i=0; i<TC; i++){
        queue<pair<int,int>> document_q;
        priority_queue<int> document_pq;
        cin >> N >> M;
        
        for(int j=0; j<N; j++){
            cin >> tmp;
            document_q.push(make_pair(tmp,j));
            document_pq.push(tmp);
        }
        
        cnt=0;
        while(!document_q.empty()){
            int a = document_q.front().first;
            int b = document_q.front().second;
            document_q.pop();

            if(a==document_pq.top()){
                document_pq.pop();
                cnt++;
                if(b==M) break;
            }
            else{
                document_q.push(make_pair(a,b));
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}