#include <iostream>
#include <vector>
using namespace std;

int N, M, W;
vector<pair<pair<int, int>, int>> edge; //<시작정점, 끝정점, 시간>
vector<string> result;

void Bellman_Ford(){
    vector<int> time(N+1, 999999999);
    for(int i=1; i<N; i++){ //N(정점의 개수)-1번 탐색
        for(int j=0; j<edge.size(); j++){
            int start=edge[j].first.first;
            int end=edge[j].first.second;
            int t=edge[j].second;
            
            if(time[end] > time[start]+t) time[end]=time[start]+t;
        }
    }
    for(int j=0; j<edge.size(); j++){ //한번 더 탐색시에 값이 바뀌면 음의 사이클 존재
        int start=edge[j].first.first;
        int end=edge[j].first.second;
        int t=edge[j].second;

        if(time[end] > time[start]+t){
            result.push_back("YES");
            return;
        }
    }
    result.push_back("NO");
}
int main(){
    int TC, S, E, T;
    cin >> TC;
    for(int i=0; i<TC; i++){
        cin >> N >> M >> W;
        edge.clear(); // 매 테스트케이스마다 edge 초기화
        for(int j=0; j<M; j++){
            cin >> S >> E >> T;
            edge.push_back(make_pair(make_pair(S,E),T));
            edge.push_back(make_pair(make_pair(E,S),T));
        }
        for(int k=0; k<W; k++){
            cin >> S >> E >> T;
            edge.push_back(make_pair(make_pair(S,E),-T));
        }
        Bellman_Ford();
    }
    
    for(int i=0; i<TC; i++){
        cout << result[i] << "\n";
    }
    return 0;
}