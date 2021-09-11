//
//  main.cpp
//  KAKAO_2022Blind_4
//
//  Created by 홍진석 on 2021/09/11.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> sol;
int maxValue = -1;
int aScore;
int lScore;
void dfs(int sum, int cnt, int n, vector<int> &info, vector<int> &gameCase, int lastNum){
    if(cnt == n){
        aScore = 0;
        lScore = 0;
        for(int i=0; i<gameCase.size(); i++){
            if(info[i] > gameCase[i]){ aScore += 10-i; }
            else if(info[i] < gameCase[i]){ lScore += 10-i;}
            else{
                if(info[i] == 0){ continue; }
                aScore += 10-i;
            }
        }
        if(lScore > aScore){
            if(lScore - aScore == maxValue){
                sol.push_back(gameCase);
            }
            else if(lScore - aScore > maxValue){
                sol.clear();
                sol.push_back(gameCase);
                maxValue = lScore - aScore;
            }
        }
        
    }
    else{
        for(int i=0; i<=10; i++){
            if(gameCase.empty() || lastNum <= i){
                gameCase[10-i] ++;
                dfs(sum, cnt+1, n, info, gameCase, i);
                gameCase[10-i] --;
            }
        }
    }
}
vector<int> solution(int n, vector<int> info) {
    vector<int> answer;

    int sum = 0;
    
    vector<int> gameCase;
    gameCase.assign(11, 0);
    dfs(sum,0,n,info, gameCase,0);
    
    
    if(sol.empty()){ answer.push_back(-1);}
    else{ answer = sol[0]; }
    return answer;
}



int main() {
    vector<int> info = {0,0,1,2,0,1,1,1,1,1,1};
    solution(9, info);
    return 0;
}

//연속 우승보다 다양한 선수 우승 원함
//우승자 라이언에게 불리하게
// 어피치 n번 쏘고 라이언 n번 쏘고
// k(1~10)점을 어피치가 a발 라이언이 b발 맞추면, 더 많은 화살 K점 맞춘선수가 가져간다
// a == b이면 어피치가 가져간다
// k점 여러발 맞혀도 k점만 가져간다
// a = b = 0 인 경우 아무도 점수 안가져간다
// 최종점수가 같은 경우 어피치가 우승자

//현재 상황
    //어피치가 n발 다 쏘고 라이언이 쏠 차례
    //어피치를 가장 큰 차이로 이기기 위해서 n발을 어느 과녁에 맞춰야할까
// 화살 개수 n, 어피치가 맞춘 점수 Info
// 라이언이 가장 큰 점수 차이로 이기기 위해 n발의 화살을
// info의 i번째 원소는 10-i점 맞힌 개수
