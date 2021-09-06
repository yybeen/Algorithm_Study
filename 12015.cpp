#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, tmp, change;
    vector<int> sub; //부분 수열
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> tmp;
        if(sub.empty() || sub.back()<tmp){
            sub.push_back(tmp);
        }
        else{
						//auto iter = v.begin();
						//cout << *iter;
            change=lower_bound(sub.begin(), sub.end(), tmp)-sub.begin();
            sub[change]=tmp;
        }
    }
    cout << sub.size();
    return 0;
}