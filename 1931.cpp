#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.second==b.second){
        return a.first < b.first;
    }
    else{
        return a.second < b.second;
    }
}

int main(){
    int N, start, end, tmp, cnt;
    vector<pair<int, int>> conference;

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> start >> end;
        conference.push_back(make_pair(start, end));
    }

    sort(conference.begin(), conference.end(), cmp);

    tmp=conference[0].second;
    cnt=1;
    for(int i=1; i<conference.size(); i++){
        if(tmp<=conference[i].first){
            cnt++;
            tmp=conference[i].second;
        }
    }

    cout << cnt;
    return 0;
}