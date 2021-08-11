//
//  main.cpp
//  단체사진찍기
//
//  Created by 홍진석 on 2021/08/11.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#define FOR(i,n) for(int i=0; i<(n); i++)
using namespace std;

struct info{
    char person1;
    char person2;
    char condition;
    int space;
    
};
vector<info> myInfo;
int cnt;

bool checkCondition(map<char,int> &m){
    FOR(i, myInfo.size()){
        switch (myInfo[i].condition) {
            case '>':
                if(abs(m[myInfo[i].person1] - m[myInfo[i].person2]) <= myInfo[i].space){ return false; }
                break;
            case '<':
                if(abs(m[myInfo[i].person1] - m[myInfo[i].person2]) >= myInfo[i].space){ return false; }
                break;
            case '=':
                if(abs(m[myInfo[i].person1] - m[myInfo[i].person2]) != myInfo[i].space) { return false; }
                break;
            default: break;
        }
    }
    return true;
}

bool comp(pair<char, int> a, pair<char, int> b){
    return a.second < b.second;
}
void takePicture(vector<pair<char,bool>> &friends, map<char,int> &m){
    if(m.size() == friends.size()){
        if(checkCondition(m)){ cnt++; }
    }
    else{
        FOR(i, friends.size()){
            if(!friends[i].second){
                m.insert(make_pair(friends[i].first, m.size()));
                friends[i].second = true;
                takePicture(friends, m);
                m.erase(friends[i].first);
                friends[i].second = false;
            }
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    cnt = 0;
    vector<pair<char,bool>> friends = {
        make_pair('A', false), make_pair('C', false),
        make_pair('F', false),make_pair('J', false),
        make_pair('M', false),make_pair('N', false),
        make_pair('R', false),make_pair('T', false)};
    
    myInfo.clear();
    FOR(i,data.size()){
        info newInfo = {data[i][0], data[i][2], data[i][3], data[i][4] - '0' + 1};
        myInfo.push_back(newInfo);
    }//데이터 모아두기
    
    map<char,int> m;
    takePicture(friends, m);
    return cnt;
}

int main() {
    vector<string> data = {"N~F=0", "R~T>2"};
    solution(2, data);
    return 0;
}
