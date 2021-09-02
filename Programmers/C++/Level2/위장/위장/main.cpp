//
//  main.cpp
//  위장
//
//  Created by 홍진석 on 2021/09/02.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, vector<string>> item;
    
    for(int i=0; i<clothes.size(); i++){
        if(item.find(clothes[i][1]) != item.end()){//있으면
            item[clothes[i][1]].push_back(clothes[i][0]);
        }
        else{//없으면
            vector<string> v = {clothes[i][0]};
            item.insert(make_pair(clothes[i][1], v));
        }
    }
    
    for(auto i : item){ answer *= i.second.size()+1; }
    return answer-1;
}

int main() {
    vector<vector<string>> clothes = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
    cout << solution(clothes);
    return 0;
}
