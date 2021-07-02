//
//  main.cpp
//  실패율
//
//  Created by 홍진석 on 2021/07/02.
//

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(pair<int, double> &a, pair<int,double> &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    else{
        return a.second > b.second;
    }
}
vector<int> solution(int N, vector<int> stages) {
    map<int,int> m;
    vector<int> answer;
    bool check[200001] = {0, };
    
    for(int i=0; i<stages.size(); i++){
        check[stages[i]] = true;
        if(m.find(stages[i]) != m.end()){
            m[stages[i]] ++;
        }
        else{
            m.insert(make_pair(stages[i],1));
        }
    }
    
    vector<pair<int, double>> failures;
    
    int players = int(stages.size());
    for(auto it = m.begin(); it != m.end(); it++){
        int stageNum = it->first;
        double failPercent = (double)it->second/players;
        players -= it->second;
        
        if(stageNum != N+1){
            failures.push_back(make_pair(stageNum, failPercent));
        }
    }
    
    sort(failures.begin(),failures.end(),comp);
    
    for(int i=0; i<failures.size(); i++){
        answer.push_back(failures[i].first);
    }
    for(int i=1; i<=N; i++){
        if(!check[i]){
            answer.push_back(i);
        }
    }
    return answer;
}
