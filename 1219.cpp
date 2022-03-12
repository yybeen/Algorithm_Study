#include <iostream>
#include <vector>
#define INF -999999999
using namespace std;
int N, S, E;
vector<pair<pair<int, int>, int>> transport;
vector<int> visit;

bool dfs(int x){
    if(x==E) return true;
    visit[x]=1;
    bool ans=false;
    for(int i=0; i<transport.size(); i++){
        int From=transport[i].first.first;
        int To=transport[i].first.second;
        if(From==x && visit[To]==0 && ans == false) ans=dfs(To);//한번 ans가 true가 되면 끝
    }
    return ans;
}

int main(){
    int M, s, e, c;
    bool approach=false;
    cin >> N >> S >> E >> M;
    vector<long long> cost(N,INF);
    vector<int> earn_city(N);
    visit.resize(N, 0);
    
    for(int i=0; i<M; i++){
        cin >> s >> e >> c;
        transport.push_back({{s,e},c});
    }
    for(int i=0; i<N; i++){
        cin >> earn_city[i];
    }

    cost[S]=earn_city[S];
    for(int i=0; i<N-1; i++){
        for(int j=0; j<transport.size(); j++){
            int From=transport[j].first.first;
            int To=transport[j].first.second;
            int Cost=transport[j].second;

            if(cost[From]==INF) continue;
            if(cost[To]<cost[From]-Cost+earn_city[To]) cost[To]=cost[From]-Cost+earn_city[To];
        }
    }

    if(cost[E]==INF) cout << "gg";
    else{
        for(int j=0; j<transport.size(); j++){
            int From=transport[j].first.first;
            int To=transport[j].first.second;
            int Cost=transport[j].second;

            if(cost[From]==INF) continue;
            if(cost[To]<cost[From]-Cost+earn_city[To]){
                if(dfs(From)){
                    approach=true;
                    break;
                }
            }
        }
        if(approach) cout << "Gee";
        else cout << cost[E];
    }
    return 0;
}