//
//  main.cpp
//  위클리7주차
//
//  Created by 홍진석 on 2021/09/26.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave) {
    vector<int> answer;
    answer.assign(enter.size(), 0);
    set<int> room;
    
    int idx = 0;
    for(int i=0; i<leave.size(); i++){
        int cnt = 0;
        
        if(room.find(leave[i]) != room.end()) {
            room.erase(leave[i]);
            continue;
        }
        for(int j=idx; j<enter.size(); j++){
            room.insert(enter[j]);
            for(auto i : room){
                if(i == enter[j]){
                    answer[i-1] += int(room.size()-1);
                }
                else{ answer[i-1] += 1;
                }
            }
            cnt ++;
            if(enter[j] == leave[i]){
                room.erase(leave[i]);
                break;
            }
        }
        
        idx += cnt;
    }
    return answer;
}

int main() {
    vector<int> enter = {1,4,2,3};
    vector<int> leave = {2,1,3,4};
    solution(enter, leave);
    return 0;
}

//answer[leave[i]-1] = room.size();

