//
//  main.cpp
//  더맵게
//
//  Created by 홍진석 on 2021/07/03.
//

#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    bool possible = false;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0; i<scoville.size(); i++){
        pq.push(scoville[i]);
    }
    
    while(!pq.empty()){
        int smallest = pq.top();
        pq.pop();
        if(smallest >= K){
            possible = true;
            break;
        }
        
        if(pq.empty()){break;}
        int smaller = pq.top();
        pq.pop();
        
        int comb = smallest + smaller*2;
        pq.push(comb);
        
        answer ++;
    }
           
    if(possible){
        return answer;
    }
    else{
        return -1;
    }
}
