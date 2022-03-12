#include <iostream>
#include <string>
using namespace std;

int main(){
    int N;
    int cnt = 0, i = 666;
    string target;

    cin >> N;
    
    while(cnt != N){
        target = to_string(i);
        for(int j=0; j < target.size()-2; j++){
            if(target[j]=='6' && target[j+1]=='6' && target[j+2]=='6'){
                cnt++;
                break;
            }
        }
        i++;
    }

    cout << i-1;
    return 0;
}