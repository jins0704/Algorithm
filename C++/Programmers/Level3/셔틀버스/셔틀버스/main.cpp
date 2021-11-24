//
//  main.cpp
//  셔틀버스
//
//  Created by 홍진석 on 2021/08/03.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define FOR(i,n) for(int i=0; i<(n); i++)

using namespace std;

struct cmp {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){
        if(a.first == b.first){ return a.second > b.second; }
        else{ return a.first > b.first; }
    }
};

vector<pair<int, int>> makeBusInfo(int t, int n){//버스 정보
    int hour = 9; int minute = 0;
    vector<pair<int, int>> info;
    FOR(i,n){
        info.push_back(make_pair(hour, minute));
        minute += t;
        if(minute >= 60){ hour++; minute -= 60; }
    }
    return info;
}

priority_queue<pair<int, int>,vector<pair<int, int>>,cmp> makePassengerLine(vector<string> &timetable, pair<int, int> lastBus){
    priority_queue<pair<int, int>,vector<pair<int, int>>,cmp> pass;
    FOR(i,timetable.size()){
        int passHour = stoi(timetable[i]);
        int passMinute = stoi(timetable[i].substr(3,-1));
        
        if(lastBus.first > passHour){
            pass.push(make_pair(passHour, passMinute));
        }
        else if(lastBus.first == passHour){
            if(lastBus.second >= passMinute){
                pass.push(make_pair(passHour, passMinute));
            }
        }
    }
    return pass;
}

string makeReturnStr(pair<int, int> t){
    string str = "";
    if(t.first < 10){str += "0";}
    str += to_string(t.first);
    str += ":";
    if(t.second < 10){str += "0";}
    str += to_string(t.second);
    return str;
}
string solution(int n, int t, int m, vector<string> timetable) {
    vector<pair<int, int>> busInfo = makeBusInfo(t, n); //hour, minute
    priority_queue<pair<int, int>,vector<pair<int, int>>,cmp> passengers = makePassengerLine(timetable, busInfo.back());

    FOR(i, busInfo.size()){
        int busHour = busInfo[i].first;
        int busMinute = busInfo[i].second;
        int cnt = 0;
        while(!passengers.empty()){
            if(i == busInfo.size()-1 && cnt == m-1){
                if(passengers.top().second == 0){
                    return makeReturnStr(make_pair(passengers.top().first-1, 59));
                }
                else{
                    return makeReturnStr(make_pair(passengers.top().first, passengers.top().second-1));
                }
            }
            if(busHour > passengers.top().first){
                passengers.pop();
                cnt++;
            }
            else if(busHour == passengers.top().first){
                if(busMinute >= passengers.top().second){
                    passengers.pop();
                    cnt++;
                } else{ break; }
            } else{ break; }
            if(cnt == m){ break; }
        }
        if(passengers.empty()){ return makeReturnStr(busInfo.back()); }
    }

    return "09:00";
}

int main() {
    vector<string> v;
    v.push_back("09:10");
    v.push_back("09:09");
    v.push_back("08:00");
    
    
    cout << solution(2, 10, 2, v);
    return 0;
}

//셔틀은 09:00 부터 n회 t분 간격으로 역에 도착
//최대 m명 탑승 가능
//콘이 셔틀을 타고 사무실로 갈 수 있는 도착시간 중 제일 늦은 시각
//단, 콘은 게으르기 때문에 같은 시각에 도착한 크루 중 대기열에서 제일 뒤에 선다
//모든 크루는 23:59에 집에 돌아간다.

//case1 - 버스 오는 시간 : 09:00
//case2 - 버스 오는 시간 : 09:00 09:10
//case3 - 버스 오는 시간 : 09:00 09:01
//case4 - 버스 오는 시간 : 09:00 09:01
//case5 - 버스 오는 시간 : 09:00
//case6 - 버스 오는 시간 : 09:00 10:00 11:00 12:00 13:00 14:00 15:00 16:00 17:00 18:00


