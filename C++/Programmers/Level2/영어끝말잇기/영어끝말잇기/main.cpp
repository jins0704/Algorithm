//
//  main.cpp
//  영어끝말잇기
//
//  Created by 홍진석 on 2021/08/15.
//

#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> useWords;
    int cnt = 1;
    char lastChar = words[0].back();
    useWords.insert(words[0]);
    
    for(int i=1; i<words.size(); i++){
        if(useWords.find(words[i]) == useWords.end() && words[i][0] == lastChar){
            useWords.insert(words[i]);
            lastChar = words[i].back();
            cnt ++;
        }
        else{
            answer = {cnt%n+1, cnt/n+1};
            return answer;
        }
    }
    
    answer = {0,0};
    return answer;
}

int main() {
    vector<string> v = {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"};
    solution(3, v);
    return 0;
}

//1~n 번호의 n명이 영어 끝말잇기

//1번부터 순서대로 단어 하나씩
//마지막 다음에는 1번
//앞사람의 단어의 마지막 문자로 단어
//이전 단어 사용금지
//한글자 인정안됨
//n과 순서대로 말한 단어 words가 주어질 때, 가장 먼저 탈라하는 사람의 번호와
//그 사람이 자신의 몇번째 차례에 탈락하는지 구해서 return
