//
//  main.cpp
//  가운데글자가져오기
//
//  Created by 홍진석 on 2021/05/25.
//
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    if(s.size()%2 ==1){//홀수
        answer = s.at(s.size()/2);
    }
    else{//짝수
        answer.push_back(s.at(s.size()/2-1));
        answer.push_back(s.at(s.size()/2));
    }
    return answer;
}
