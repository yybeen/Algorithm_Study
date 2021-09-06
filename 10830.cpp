#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<long long>> matrix;

matrix operator * (matrix& a, matrix& b){ // 행렬의 곱셈 연산자 생성
    int s=a.size();
    matrix m(s, vector<long long>(s));
    
    for(int i=0; i<s; i++){
        for(int j=0; j<s; j++){
            for(int k=0; k<s; k++){
                m[i][j]+=a[i][k]*b[k][j];                
            }
            m[i][j]%=1000;
        }
    }
    return m;
}

matrix Power(matrix a, long long b){
    int s=a.size();
    matrix m(s, vector<long long>(s,0));
    
    for(int i=0; i<s; i++){
        m[i][i]=1;
    }

    while(b>0){
        if(b%2==1){
            m=m*a;
            b-=1;
        }
        else{
            a=a*a;
            b/=2;
        }
    }
    
    return m;
}

int main(){
    int N;
    long long B;

    cin >> N >> B;
    
    matrix a(N, vector<long long>(N));
    matrix result(N, vector<long long>(N));
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> a[i][j];
        }
    }
    
    result=Power(a, B);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << result[i][j] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}