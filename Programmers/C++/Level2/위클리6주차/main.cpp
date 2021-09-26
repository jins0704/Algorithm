//
//  main.cpp
//  위클리6주차
//
//  Created by 홍진석 on 2021/09/26.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0; i<n; i++)

using namespace std;

struct boxer {
    int weight; //무게
    int winTime = 0; //이긴횟수
    int loseTime = 0; //진횟수
    int winToHeavy = 0; //무거운 사람에게 이긴 횟수
    int id; //번호
};

bool comp(boxer &a, boxer &b) {
    double aPer = a.winTime + a.loseTime == 0 ? 0 : double(a.winTime)/(a.winTime + a.loseTime);
    double bPer = b.winTime + b.loseTime == 0 ? 0 :  double(b.winTime)/(b.winTime + b.loseTime);
    
    if(aPer == bPer){
        if(a.winToHeavy == b.winToHeavy){
            if(a.weight == b.weight){
                return a.id < b.id;
            }
            else{ return a.weight > b.weight; }
        }
        else{ return a.winToHeavy > b.winToHeavy; }
    }
    else{
return aPer > bPer; }
}
vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    vector<boxer> boxers;
    boxers.assign(weights.size(), boxer());
    
    FOR(i, head2head.size()){
        boxers[i].weight = weights[i];
        boxers[i].id = i+1;
        for(int j = i; j < head2head[i].size(); j++){
            if(i == j) { continue; }
            if(head2head[i][j] == 'W'){
                boxers[i].winTime++;
                boxers[j].loseTime++;
                if(weights[i] < weights[j]) { boxers[i].winToHeavy++; }
            }
            else if(head2head[i][j] == 'L'){
                boxers[j].winTime++;
                boxers[i].loseTime++;
                if(weights[j] < weights[i]) { boxers[j].winToHeavy++; }
            }
        }
    }

    sort(boxers.begin(), boxers.end(), comp);
    FOR(i, boxers.size()){ answer.push_back(boxers[i].id); }
    
    return answer;
}


int main() {
    vector<int> weights = {60, 70, 60};
    vector<string> head2head = {"NNN", "NNN", "NNN"};
    solution(weights, head2head);
    return 0;
}


