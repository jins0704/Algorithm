//
//  main.cpp
//  오픈채팅방
//
//  Created by 홍진석 on 2021/06/23.
//

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<int,string>> result; //0은 들어오기 1은 나가기
    unordered_map<string,string> users;
    
     for(int i=0; i<record.size(); i++){
        int sid = int(record[i].find(" "));
        int cnt = 0;
        for(int j= sid+1; j<record[i].size(); j++){
            if(record[i][j] == ' '){
               break;
            }
            cnt++;
        }
        string id = record[i].substr(sid+1,cnt);
  
        if(record[i][0] == 'E'){
            users[id] = record[i].substr(sid+cnt+2, record[i].size());
            users.insert(make_pair(id, record[i].substr(sid+cnt+2, record[i].size())));
            result.push_back(make_pair(0,id));
        }
        else if(record[i][0] == 'L'){
            result.push_back(make_pair(1,id));
        }
        else if(record[i][0] == 'C'){
            users[id] = record[i].substr(sid+cnt+2, record[i].size());
        }
    }
   
    for(int i=0; i<result.size(); i++){
        string a =  users[result[i].second];
        if(result[i].first == 0){//들어오기
            a = a + "님이 들어왔습니다.";
        }
        else{//나가기
            a = a + "님이 나갔습니다.";
        }
        answer.push_back(a);
     }
    
    return answer;
}
