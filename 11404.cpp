#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, M, a, b, c;

    cin >> N >> M;

    vector<vector<int>> cost(N,vector<int>(N,999999999));

    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        if(cost[a-1][b-1] > c) cost[a-1][b-1]=c;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                cost[j][k]=min(cost[j][k],cost[j][i]+cost[i][k]);
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i==j || cost[i][j]==999999999) cout << 0 << " ";
            else cout << cost[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}