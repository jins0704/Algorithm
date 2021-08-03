//
//  main.cpp
//  프린터
//
//  Created by 홍진석 on 2021/08/02.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int, int>> q;
    
    for(int i=0; i<priorities.size(); i++){
        pq.push(priorities[i]);
        q.push(make_pair(priorities[i], i)); // 중요도 , location
    }
    
    while(!q.empty()){
        if(q.front().first == pq.top()){
            answer++;
            if(q.front().second == location){break;}
            pq.pop();
            q.pop();
        }
        else{
            q.push(make_pair(q.front().first, q.front().second));
            q.pop();
        }
        
    }
    
    return answer;
}

int main() {
    return 0;
}
