//
//  main.cpp
//  야근지수
//
//  Created by 홍진석 on 2021/11/15.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
#define FOR(i,n) for(int i=0; i<n; i++)

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    
    FOR(i, works.size()){
        pq.push(works[i]);
    }
    
    while (n > 0 && !pq.empty()) {
        int maxNum = pq.top();
        pq.pop();
        if(maxNum != 1){  pq.push(maxNum-1); }
        n--;
    }
    
    while (!pq.empty()) {
        answer += pow(pq.top(),2);
        pq.pop();
    }
    return answer;
}

int main() {
    vector<int> works = {1,1};
    cout << solution(3, works);
    return 0;
}
