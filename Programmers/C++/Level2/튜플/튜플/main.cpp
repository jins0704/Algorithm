//
//  main.cpp
//  튜플
//
//  Created by 홍진석 on 2021/09/09.
//

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <map>
#include <algorithm>
#include <sstream>
#define FOR(i,n) for(int i=0; i<(n); i++)

using namespace std;

bool comp(pair<int, pair<int,int>> &a, pair<int, pair<int,int>> &b) {
    if(a.second.first == b.second.first){
        return a.second.second < b.second.second;
    }
    else { return a.second.first > b.second.first; }
}

void insertMap(int num, map<int, pair<int, int>> &m, int idx){
    if(m.find(num) == m.end()){
        m.insert(make_pair(num, make_pair(1, idx)));
    }
    else{ m[num].first++;}
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, pair<int,int>> m;
    int idx = 0;
    
    while(s.size() > 0) {
        FOR(i, s.size()){
            if(isalnum(s[i])){
                int num = stoi(s.substr(i,-1));
                insertMap(num, m , idx++);
                s = s.substr(i+to_string(num).size(),-1);
                break;
            }
            if(i == s.size()-1) { s = "";}
        }
    }
    

    vector<pair<int, pair<int, int>>> v(m.begin(),m.end());
    sort(v.begin(), v.end(), comp);

    FOR(i, v.size()){
        answer.push_back(v[i].first);
    }
    
    return answer;
}

int main() {
    
    solution("{{4,2,3},{3},{2,3,4,1},{2,3}}");
    return 0;
}
