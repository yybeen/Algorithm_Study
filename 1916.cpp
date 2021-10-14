#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define INF 999999999
using namespace std;

int main(){
    int N, M, start, end, cost, S, E;
    cin >> N >> M;
    vector<pair<int, int>> bus[MAX];
    vector<int> distance(MAX,INF);
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i=0; i<M; i++){
        cin >> start >> end >> cost;
        bus[start].push_back({end,cost});
    }
    cin >> S >> E;
    pq.push({0,S});
    distance[S]=0;
    while(!pq.empty()){
        int cost=pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        if(cost>distance[cur]) continue; //이거 빠지면 시간초과=>이미 최소비용 계산한것은 다시 계산하지 않고 넘어가기
        for(int i=0; i<bus[cur].size(); i++){
            int next=bus[cur][i].first;
            int n_cost=bus[cur][i].second;

            if(n_cost + cost < distance[next]){
                distance[next]=n_cost + cost;
                pq.push({distance[next],next});
            }
        }
    }
    cout << distance[E];
    return 0;
}