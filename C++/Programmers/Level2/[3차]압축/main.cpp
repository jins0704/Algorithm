//
//  main.cpp
//  [3차]압축
//
//  Created by 홍진석 on 2021/10/10.
//

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string,int> initDictionary(){
    map<string,int> m;
    string a[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    for(int i=0; i<26; i++){
        m.insert(make_pair(a[i],i+1));
    }
    return m;
}

vector<int> solution(string msg) {
    vector<int> answer;
    map<string,int> dic = initDictionary();
    
    int idx = 0;
    int dicCnt = 26;
    
    for(int i=0; i< msg.size(); i++){
        string cur = "";
        cur += msg[i];//1. 길이가 1인 모든 단어를 포함하도록 사전 초기화
        string next = "";
        if(i == msg.size()-1){
            answer.push_back(dic[cur]);
            break;
        }
        int cnt = 0;
        for(int j=i+1; j<msg.size(); j++){
            next = cur + msg[j];
            if(dic.find(next) != dic.end()){//존재한다면
                cur = next;
                cnt ++;
            }
            
            else{ break; }
        }
        i += cnt;
        //3. w에 해당하는 사전의 색인 번호를 출력하고, w를 제거한다.
        dic.insert(make_pair(next,++dicCnt));
        answer.push_back(dic[cur]);
    }
   
    return answer;
}

//4. 처리되지 않은 다음글자(c) 남아있다면, w+c에 해당하는 단어를 사전에 등록한다.
//5. 단계 2로 돌아간다.
