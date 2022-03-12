#include <iostream>
#include <vector>
#define INF 999999
using namespace std;

int main(){
    int N, M, a, b;
    int answer=0;
    cin >> N >> M;
    vector<vector<int>> student(N+1,vector<int>(N+1,INF));
    for(int i=0; i<M; i++){
        cin >> a >> b;
        student[a][b]=1;
    }

    for(int k=1; k<N+1; k++){
        for(int i=1; i<N+1; i++){
            for(int j=1; j<N+1; j++){
                if(student[i][j]>student[i][k]+student[k][j]) {
                    student[i][j]=student[i][k]+student[k][j];
                }
            }
        }
    }

    for(int i=1; i<N+1; i++){
        int cnt=0;
        for(int j=1; j<N+1; j++){
            if(student[i][j]!=INF || student[j][i]!=INF) cnt++;
        }
        if(cnt==N-1) answer++;
    }
    
    cout << answer;
    return 0;
}