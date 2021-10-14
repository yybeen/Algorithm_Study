#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int N, M, K, X, A, B;
    cin >> N >> M >> K >> X;
    vector<vector<int>> city(N+1);
    vector<int> visited(N+1,0);
    vector<int> result;
    queue<pair<int,int>> q;
    for(int i=0; i<M; i++){
        cin >> A >> B;
        city[A].push_back(B);
    }
    
    q.push(make_pair(X,0));
    visited[X]=1;
    while(!q.empty()){
        int num=q.front().first;
        int dept=q.front().second;
        q.pop();
        if(dept==K) {
            result.push_back(num);
            continue;
        }
        for(int i=0; i<city[num].size(); i++){
            if(!visited[city[num][i]]){
                q.push(make_pair(city[num][i], dept+1));
                visited[city[num][i]]=1;
            }
        }
    }

    if(result.empty()) cout << -1;
    else{
        sort(result.begin(),result.end());
        for(int i=0; i<result.size(); i++){
            cout << result[i] << "\n";
        }
    }
    return 0;
}