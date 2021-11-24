//
//  main.cpp
//  KAKAO_2022Blind_1
//
//  Created by 홍진석 on 2021/09/11.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#define FOR(i,n) for(int i=0; i<(n); i++)

using namespace std;

void checkMail(string s, map<string, pair<int, set<string>>> &m){
    stringstream ss(s);
    string a = "";//신고자
    string b = "";//신고당한사람
    
    getline(ss,a, ' ');
    getline(ss,b, ' ');
    
    if(m.find(b) == m.end()){
        set<string> se;
        se.insert(a);
        m.insert(make_pair(b, make_pair(1, se)));
    }
    else{
        if(m[b].second.find(a) == m[b].second.end()){
            m[b].first++;
            m[b].second.insert(a);
        }
    }
    
    
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, pair<int, set<string>>> m; //신고당한 사람 , 횟수 , 신고자
    
    FOR(i, report.size()){
        checkMail(report[i], m);
    }
    
    map<string, int> receiver;
    
    for(auto i : m){
        if(i.second.first >= k){
            for(auto j : i.second.second){
                if(receiver.find(j) == receiver.end()){
                    receiver.insert(make_pair(j, 1));
                }
                else{
                    receiver[j]++;
                }
            }
        }
    }
    
    FOR(i, id_list.size()){
        if(receiver.find(id_list[i]) == receiver.end()){ answer.push_back(0); }
        else{ answer.push_back(receiver[id_list[i]]); }
    }
    
    return answer;
}

int main() {
    vector<string> id_list = {"con", "ryan"};
    vector<string> report = {"ryan con", "ryan con", "ryan con", "ryan con"};
    
    solution(id_list, report, 2);
    return 0;
}

//게시판 불량 이용자 신고 개발
//각 유저는 한번에 한명의 유저 신고
    //신고 횟수 제한은 없다 - 서로 다른 유저를 계속해서 신고할 수 있다.
    //한 유저를 여러번 신고할 수 있지만 동일한 유저에 대해 신고횟수는 1회로 처리
//k번 이상 신고된 유저는 즉시! 게시판 이용이 정지 -> 해당 유저를 신고한 모든 유저에게 정지사실을 메일로 발송
    // 정지된 유저도 불량 이용자 신고 가능

//
