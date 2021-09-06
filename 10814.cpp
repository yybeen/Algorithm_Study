#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Member{
    int age;
    char name[101];
} Member;

bool cmp(const Member &m1, const Member &m2){
   return m1.age < m2.age;
}

int main(){
    int N;
    cin >> N;
    
    Member mem[N];

    for(int i=0; i<N; i++){
        cin >> mem[i].age >> mem[i].name;
    }

    stable_sort(mem,mem+N,cmp);

    for(int k=0; k<N; k++){
        cout << mem[k].age << " " << mem[k].name << '\n';
    }

    return 0;
}