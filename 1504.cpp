#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 801
#define INF 999999999
using namespace std;

vector<pair<int,int>> node[MAX];

vector<int> dijkstra(int start, int end){
    vector<int> distance(MAX,INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});
    distance[start]=0;
    while(!pq.empty()){
        int cost=pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        if(cost<distance[cur]) continue;
        for(int i=0; i<node[cur].size(); i++){
            int next=node[cur][i].first;
            int n_cost=node[cur][i].second;

            if(cost+n_cost<distance[next]){
                distance[next]=cost+n_cost;
                pq.push({distance[next],next});
            }
        }
    }
    return distance;
}
int main(){
    int N, E, a, b, cost, v1, v2;
    cin >> N >> E;
    
    for(int i=0; i<E; i++){
        cin >> a >> b >> cost;
        node[a].push_back({b,cost});
        node[b].push_back({a,cost});
    }
    cin >> v1 >> v2;
    vector<int> oneTon=dijkstra(1,N);
    vector<int> v1Ton=dijkstra(v1,N);
    vector<int> v2Ton=dijkstra(v2,N);
    int answer=min(oneTon[v1]+v1Ton[v2]+v2Ton[N], oneTon[v2]+v2Ton[v1]+v1Ton[N]);
    if(answer>=INF || answer<0) cout << -1;//answer<0:오버플로우 발생하는 경우
    else cout << answer;
    return 0;
}