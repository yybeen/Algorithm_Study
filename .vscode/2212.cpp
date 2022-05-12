#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, K, s, d;
    int sum = 0;
    vector<int> sensor, distance;

    cin >> N;
    cin >> K;

    for(int i=0; i<N; i++){
        cin >> s; 
        sensor.push_back(s);
    }

    //위치 순 정렬
    sort(sensor.begin(), sensor.end());

    //정렬된 센서들 간의 거리 구하기
    for(int i=0; i<N-1; i++){
        d = sensor[i+1] - sensor[i];
        distance.push_back(d);
    }

    //거리 오름차순 정렬
    sort(distance.begin(), distance.end());

    //수신 가능 길이의 합 최소 = 정렬된 거리의 앞에서부터 N-K개를 더한 값(가장 긴 거리부터 k개 만큼 빼기)
    for(int i=0; i<N-K; i++){
        sum += distance[i];
    }

    cout << sum;
    return 0;
}