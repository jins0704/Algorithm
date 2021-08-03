//
//  main.cpp
//  1차다트게임
//
//  Created by 홍진석 on 2021/07/31.
//

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

int checkBonus(char c, int score){
    if(c=='S'){return score;}
    else if(c=='D'){return score*score;}
    else{return score*score*score;}
}

int solution(string dartResult) {
    int answer = 0;
    vector<int> turnScore;

    while(!dartResult.empty()){
        int idx = 0;
        int score = stoi(dartResult);
        if(score == 10){idx += 2;}
        else{idx = 1;}
        
        int bonusScore = checkBonus(dartResult[idx],score); idx++;

        if(!isdigit(dartResult[idx])){
            if(dartResult[idx]=='*'){
                if(!turnScore.empty()){
                    turnScore[turnScore.size()-1] *= 2;
                }
                bonusScore *= 2;
            }
            else if(dartResult[idx] =='#'){
                bonusScore *= -1;
            }
            idx++;
        }
        turnScore.push_back(bonusScore);
        if(idx >= dartResult.size()){break;}
        dartResult = dartResult.substr(idx,-1);
    }
    for(int i=0; i<turnScore.size(); i++){
        answer += turnScore[i];
    }
    return answer;
}

int main() {
    string s = "1D#2S*3S";
    solution(s);
    return 0;
}


//다트 총 3번
//각 기회마다 0~10점
//S - 1제곱 , D - 2제곱 , T - 3제곱
//* - 바로 전 얻은 점수 각 2배
//# 해당 점수는 마이너스
//중첩 가능
//점수,보너스,옵션 이루어진 문자열 세트
