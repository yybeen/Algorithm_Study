#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, tmp, cnt, S, E;
    vector<int> list, result;

    scanf("%d", &N);
    list.push_back(0);

    for(int i=0; i<N; i++){
        scanf("%d",&tmp);
        list.push_back(tmp);
    }

    int dp[2001][2001]={0};

    for(int i=1; i<N+1; i++){
        dp[i][i]=1;
        if(i!=N){
            if(list[i]==list[i+1]) dp[i][i+1]=1;
        }
    }

    for(int i=2; i<N+1; i++){
        for(int j=1; j<=N-i; j++){
            int k=i+j;
           if(list[j]==list[k] && dp[j+1][k-1]==1) dp[j][k]=1;
        }
    }

    cin >> cnt;
    for(int i=0; i<cnt; i++){
        scanf("%d %d", &S, &E);
        result.push_back(dp[S][E]);
    }

    for(int i=0; i<result.size(); i++){
        cout << result[i] << "\n";
    }
    return 0;
}