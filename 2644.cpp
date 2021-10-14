#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
vector<int> deep; //deep[0]에는 a와 루트의 촌수, deep[1]에는 b와 루트의 촌수
int cnt=0; // 루트를 찾으려면 몇번 들어가는지 센다(이것이 곧 루트와 a의 촌수)

int Find_root(int a){ //루트 찾기
    if(parent[a]==a) {
        deep.push_back(cnt);
        cnt=0;
        return a;
    }
    else {
        cnt++;
        return Find_root(parent[a]);
    }
}

bool Is_same_root(int a, int b){ //루트가 같은지 찾기(같지 않다면 바로 -1 출력)
    int tmp1=Find_root(a);
    int tmp2=Find_root(b);

    if(tmp1==tmp2) return true;
    else return false;
}

int kin(int a, int b){ //루트가 같은경우 촌수계산
    int a_deep=deep[0], b_deep=deep[1];
    if(a_deep==b_deep) {//a와 b가 같은 레벨에 있을 경우
        if(parent[a]==parent[b]) return 2; //부모가 같다면 형제이므로 2촌
        else{//부모가 같지 않다면
            int i=a, j=b;
            for(int m=1; m<=b_deep; m++){//루트까지 가기 전에 같은 부모를 가졌다면 거기서부터 루트까지는 의미가 없다.
                i=parent[i];
                j=parent[j];
                if(i==j) return 2*m;
            }            
        }

    }
    else if(a_deep<b_deep){//b가 a보다 깊은 레벨에 있는 경우
        int i=b;
        for(int m=0; m<b_deep-a_deep; m++) i=parent[i];//a와 같은 레벨이 될 때까지 b의 부모를 찾는다
        if(i==a) return b_deep-a_deep; //같은 레벨이 되었을 때 b의 부모가 a라면 그 레벨의 차이만큼이 촌수
        else{//a가 부모가 아니라면
            int k=a, j=i;
            for(int m=1; m<=a_deep; m++){//루트까지 가기 전에 같은 부모를 가졌다면 거기서부터 루트까지는 의미가 없다.
                k=parent[k];
                j=parent[j];
                if(k==j) return 2*m+b_deep-a_deep;
            }            
        }        
    }
    else{//a가 b보다 깊은 레벨에 있는 경우
        int i=a;
        for(int m=0; m<a_deep-b_deep; m++) i=parent[i]; //b와 같은 레벨이 될 때까지 a의 부모를 찾는다
        if(i==b) return a_deep-b_deep; //같은 레벨이 되었을 떄 a의 부모가 b라면 그 레벨의 차이만큼이 촌수
        else{//b가 부모가 아니라면
            int k=i, j=b;
            for(int m=1; m<=b_deep; m++){//루트까지 가기 전에 같은 부모를 가졌다면 거기서부터 루트까지는 의미가 없다.
                k=parent[k];
                j=parent[j];
                if(k==j) return 2*m+a_deep-b_deep;
            }            
        }        
    }
    return a_deep+b_deep;
}
int main(){
    int N, M, A, B, p, c, answer;

    cin >> N >> A >> B >> M;
    parent.push_back(-1);
    for(int i=1; i<N+1; i++){
        parent.push_back(i);
    }

    for(int i=0; i<M; i++){
        cin >> p >> c;
        parent[c]=p;
    }
    
    if(Is_same_root(A,B)==true){
        answer=kin(A,B);
    }
    else answer=-1;

    cout << answer;
    return 0;
}