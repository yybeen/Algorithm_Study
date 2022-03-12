#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

vector<int> graph[10001];
int visited[10001] = {0};

void dfs(int v){
    visited[v] = 1;
    printf("%d ", v);
    for(int i=0; i<graph[v].size(); i++){
        int next = graph[v][i];
        if(visited[next] = 0) dfs(next);
    }
}

void bfs(int v){
    queue<int> q;
    q.push(v);
    visited[v] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        printf("%d ", cur);
        for(int i=0; i< graph[cur].size(); i++){
            int next = graph[cur][i];
            if(visited[next] = 0){
                visited[next] = 1;
                q.push(next);
            }
        }
    }
}

int main(){
    int N, M, V, start, end;
    scanf("%d %d %d", &N, &M, &V);

    for(int i=0; i<M; i++){
        scanf("%d, %d", &start, &end);
        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    for(int i=1; i<=N; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(V);
    printf("\n");
    memset(visited, 0, sizeof(visited));
    bfs(V);
    return 0;
}