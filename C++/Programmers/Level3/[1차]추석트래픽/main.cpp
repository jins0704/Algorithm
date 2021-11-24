//
//  main.cpp
//  [1차]추석트래픽
//
//  Created by 홍진석 on 2021/11/16.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#define FOR(i,n) for(int i=0; i<n; i++)

using namespace std;

vector<string> split(string input, char c){
    vector<string> result;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, c)) {
        result.push_back(temp);
    }
    return result;
}
int getMSecond(string s) {
    vector<string> result = split(s, ':');
    int h = stoi(result[0])*3600000;
    int m = stoi(result[1])*60000;
    int sec = stof(result[2])*10000/10;
    return h+m+sec;
}

bool comp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<int,int>> schedule;
    
    FOR(i, lines.size()){
        vector<string> result = split(lines[i], ' ');
        int et = getMSecond(result[1]);
        int t = stof(result[2])*10000/10;
        int st = et - t + 1;
        schedule.push_back(make_pair(st, et));
    }

    FOR(i, schedule.size()){
        int oneSectionBegin = schedule[i].second;
        int oneSectionLast = oneSectionBegin + 999;
        int cnt = 0;
        
        for(int j = i; j<schedule.size(); j++){
            if(schedule[j].first <= oneSectionLast) {
                cnt ++;
            }
        }

        answer = max(cnt, answer);
    }

    
    return answer;
}

int main() {
    vector<string> lines = {"2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"};
    cout << solution(lines);
    return 0;
}
