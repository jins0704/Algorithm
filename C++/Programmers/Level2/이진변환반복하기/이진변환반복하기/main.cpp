//
//  main.cpp
//  이진변환반복하기
//
//  Created by 홍진석 on 2021/09/17.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string makeBinary(int n){
    string s = "";
    while(n >= 1){
        s = to_string(n%2) + s;
        n /= 2;
    }
    return s;
}

vector<int> solution(string s) {
    vector<int> answer;
    int t = 0; //횟수
    int zeroSum = 0;

    while(s.size() > 1){
        int zeroCnt = 0;
        
        for(int i=0; i<s.size(); i++){
            if(s[i] == '0') { zeroCnt ++; }
        }
        int n = int(s.size())-zeroCnt;
        s = makeBinary(n);
        t++;
        zeroSum += zeroCnt;
    }
    
    answer.push_back(t);
    answer.push_back(zeroSum);
    
    return answer;
}

int main() {
    solution("110010101001");
    return 0;
}

//x의 모든 0 제거
//
