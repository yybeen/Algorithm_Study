#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> matrix;

matrix operator * (matrix& a, matrix& b){ // 행렬의 곱셈 연산자 생성
    int as=a.size();
    int bs=b[0].size();
    int s=b.size();
    matrix m(as, vector<int>(bs));
    
    for(int i=0; i<as; i++){
        for(int j=0; j<bs; j++){
            for(int k=0; k<s; k++){
                m[i][j]+=a[i][k]*b[k][j];                
            }
        }
    }
    return m;
}

int main(){
    int N, M, K;
    cin >> N >> M;
    matrix m1(N, vector<int>(M));
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> m1[i][j];
        }
    }
    
    cin >> M >> K;
    matrix m2(M, vector<int>(K));
    
    for(int i=0; i<M; i++){
        for(int j=0; j<K; j++){
            cin >> m2[i][j];
        }
    }
    
    matrix result(N, vector<int>(K));
    result=m1*m2;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<K; j++){
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}