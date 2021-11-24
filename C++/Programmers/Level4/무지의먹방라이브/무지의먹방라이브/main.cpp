//
//  main.cpp
//  무지의먹방라이브
//
//  Created by 홍진석 on 2021/07/27.
//

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

//회전판에 먹어야 할 음식 N개
//1~N 번호 각 음식 일정시간 소요
//1번 부터 먹기 시작, 번호가 증가하는 순서대로 무지 앞으로 가져다 놓는다
//마지막 번호의 음식을 섭취한 후에는 다시 1번 음식이 무지 앞으로 온다.
//음식 한개를 1초 동안 섭취 후 남은 음식을 그대로 두고 다음 음식을 섭취한다. (가장 가까운 번호)
//회전하는 시간은 없다.
//K초 후에 방송이 잠시 중단
//다시 방송을 이어갈때 몇번 음식을 먹을지 알곶 ㅏ한다.
//음식 시간 food_times, 네트워크 장애 K초 주어진다
//몇번 음식부터 다시 섭취할지 return
//더 섭취할 음식이 없다면 -1 반환

struct cmp {
    bool operator()(pair<int, int>&a, pair<int, int>&b) {
        if (a.first == b.first) {return a.second > b.second;}
        else {return a.first > b.first;}
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

int solution(vector<int> food_times, long long k) {
    unsigned long long wholeround = 0;

    for(int i=0; i<food_times.size(); i++){
        pq.push(make_pair(food_times[i], i+1));
    }
    int check = false;
    
    while (!check && !pq.empty()) {
        unsigned long long round = pq.top().first; //바퀴 수
        int size = int(pq.size()); // 남은음식 개수
        if((round-wholeround) * size <= k){
            k -= (round-wholeround) * size;
            wholeround = round;
            while(!pq.empty() && round == pq.top().first){
                pq.pop();
            }
        }
        else{check = true;}
    }
    
    if(pq.empty()){
        return -1;
    }
    else{
        vector<int> v;
        while(!pq.empty()){
            v.push_back(pq.top().second);
            pq.pop();
        }
        sort(v.begin(),v.end());
     
        unsigned long long cnt = k%v.size();
      
        return v[cnt];
    }
}
