//
//  main.cpp
//  디스크컨트롤러
//
//  Created by 홍진석 on 2021/09/03.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define FOR(i,n) for(int i=0; i<(n); i++)

using namespace std;

struct comp{
    bool operator()(pair<int,int> &a, pair<int, int> &b){
        if(a.first == b.first){ return a.second > b.second; }
        else{ return a.first > b.first; }
    }
};

struct shortTime{
    bool operator()(pair<int,int> &a, pair<int, int> &b){
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int currentTime = 0;
    pair<int, int> result;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> waitingQueue;
    priority_queue<pair<int, int>, vector<pair<int, int>>, shortTime> readyQueue;
    
    FOR(i, jobs.size()){
        waitingQueue.push(make_pair(jobs[i].front(), jobs[i].back()));
    }

    while (1) {
        if(waitingQueue.empty() && readyQueue.empty()) { break; }
        
        while (1) {//가능한 것들 readyQueue로 이동
            if(waitingQueue.empty()){ break; }

            if(waitingQueue.top().first <= currentTime) {
                readyQueue.push(make_pair(waitingQueue.top().first, waitingQueue.top().second));
                waitingQueue.pop();
            }
            else { break; }
        }
        
        if(readyQueue.empty()){ currentTime ++; } // 준비된 스케줄러가 없다면 시간 +1
        else{//준비된 스케줄러가 있다면 제일 적게 소요되는거 처리하기
            currentTime += readyQueue.top().second;
            result.first += currentTime-readyQueue.top().first;
            result.second += 1;
            readyQueue.pop();
        }
    }
    
    answer = result.first/result.second;
    return answer;
}

int main() {
    vector<vector<int>> jobs = {{0,3}, {1,9}, {2,6}};
    cout << solution(jobs);
    return 0;
}

//한번에 하나의 작업만 수행
//평균을 가장 줄이는 방법 return
