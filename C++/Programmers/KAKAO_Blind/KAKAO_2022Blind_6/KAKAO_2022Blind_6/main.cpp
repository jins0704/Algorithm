//
//  main.cpp
//  KAKAO_2022Blind_6
//
//  Created by 홍진석 on 2021/09/11.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    for(int i=0; i< skill.size(); i++){
        
        for(int j= skill[i][1]; j<=skill[i][3]; j++){
            for(int k = skill[i][2]; k<= skill[i][4]; k++){
                if(skill[i][0] == 1){
                    board[j][k] -= skill[i][5];
                }
                else{
                    board[j][k] += skill[i][5];
                }
            }
        }
    }
    
    for (int i=0; i<board.size(); i++) {
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j] > 0){
                answer ++;
            }
        }
    }
    return answer;
}

int main() {
    vector<vector<int>> board = {{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5}};
    vector<vector<int>> skill = {{1,0,0,3,4,4},{1,2,0,2,3,2},{2,1,0,3,1,2},{1,0,1,3,3,1}};
    cout << solution(board, skill);
    return 0;
}

//NxM 내구도를 가진 건물 한칸
//공격 받으면 내구도 감소하고, 0이하이면 파괴
//회복스킬 사용하여 건물들의 내구도 높힌다.
//적의 공격, 아군의 회복 스킬은 항상 직사각형 모양
//파괴된 건물도 공격을 받으면 계속 내구도 하락한다

//건물의 내구도 2차원 배열 board
//적의 공격 혹은 아군의 회복 나타내는 정수배열 skill
//파괴되지 않은 건물 개수 return
//skill = [type, r1, c1, r2,c2, degree]
    // type = 1 공격, type = 2 회복
    // (r2 - r1) , (c2-c1)
    // degree : 내구도
