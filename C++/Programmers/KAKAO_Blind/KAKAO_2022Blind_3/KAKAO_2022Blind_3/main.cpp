//
//  main.cpp
//  KAKAO_2022Blind_3
//
//  Created by 홍진석 on 2021/09/11.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

#define FOR(i,n) for(int i=0; i<(n); i++)

using namespace std;

vector<string> split(string input, char delimiter){
    vector<string> answer;
    stringstream ss(input);
    string temp;
    
    while(getline(ss,temp,delimiter)){
        answer.push_back(temp);
    }
    return answer;
}
int calTime(string outTime, string inTime){
    
    vector<string> ot = split(outTime, ':');
    vector<string> it = split(inTime, ':');
    
    int hour = stoi(ot[0]) - stoi(it[0]);
    int minute = stoi(ot[1]) - stoi(it[1]);
    if(minute < 0) {
        hour --;
        minute += 60;
    }
    int wholeTime = 60*hour + minute;

    return wholeTime;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    //fee[0] = 기본시간, fee[1] = 기본요금, fee[2] = 단위시간, fee[3] = 단위요금
    
    map<string, string> checkIn;
    map<string, int> checkTime;
    
    FOR(i, records.size()){
        vector<string> info = split(records[i], ' ');
        //Info[0] = 시각, Info[1] = 차량번호, Info[2] = 내역
        
        if(checkIn.find(info[1]) == checkIn.end()){//입차
            checkIn.insert(make_pair(info[1], info[0]));
        }
        else{//출차
            int t = calTime(info[0],checkIn[info[1]]);
            
            if(checkTime.find(info[1]) == checkTime.end()){
                checkTime.insert(make_pair(info[1], t));
            }
            else{ checkTime[info[1]] += t;}
            
            checkIn.erase(info[1]);
        }
    }
    
    for(auto i : checkIn){
        int t = calTime("23:59", i.second);
        if(checkTime.find(i.first) == checkTime.end()){
            checkTime.insert(make_pair(i.first, t));
        }
        else{
            checkTime[i.first] += t;
        }
    }
    
    for(auto i : checkTime){
        int money = fees[1];
        int overTime = i.second - fees[0] > 0 ? i.second-fees[0] : 0;
        money += (overTime/fees[2] * fees[3]);
        if(overTime % fees[2] != 0){
            money += fees[3];
        }
        
        answer.push_back(money);
    }

    return answer;
}





int main() {
    vector<int> fees = {180, 5000, 10, 600};
    vector<string> records = {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};
    solution(fees, records);
    return 0;
}

//주차장의 요금표와 입차 출차 기록 주어진다.
//차량별 주차요금 계산한다.
//출차내역 없다면 무조건 23:59분 출차로 간주
//누적 주차시간이 기본 이하라면 기본요금
//기본 초과라면 ->5000 +⌈(670 - 180) / 10⌉x 600 = 34400 ㄱ같은 형식
//초과시간이 단위시간으로 단위시간으로 나누어 떨어지지않으면 올림
//시각 - HH:MM
//차량번호 - 4인 문자열 0~9
//내역 - IN 또는 OUT
//records는 시각 기준으로 오름차순
//차량번호 작은 자동차 부터 요금 차례대로 return
