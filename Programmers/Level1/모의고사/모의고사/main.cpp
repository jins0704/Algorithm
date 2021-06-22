//
//  main.cpp
//  모의고사
//
//  Created by 홍진석 on 2021/06/22.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer_1[5] = {1,2,3,4,5};
int answer_2[8] = {2,1,2,3,2,4,2,5};
int answer_3[10] = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    
    vector<int> answer;
    
    int result[4] = {0, }; //result[3] 최댓값 저장
    
    for(int i=0; i<answers.size(); i++){
        if(answers[i] == answer_1[i%5]){result[0]++;}
        if(answers[i] == answer_2[i%8]){result[1]++;}
        if(answers[i] == answer_3[i%10]){result[2]++;}
    }
    
    for(int i=0; i<3; i++){
        if(result[i] > result[3]){
            result[3] = result[i];
        }
    }
    
    for(int i=0; i<3; i++){
        if(result[i] == result[3]){
            answer.push_back(i+1);
        }
    }
    
    // for(int i=0; i< 3; i++){
    //     if(result[i] !=0){
    //         if(result[3] == result[i]){
    //             answer.push_back(i+1);
    //             result[3] = result[i];
    //         }
    //         else if(result[3] < result[i]){
    //             answer.clear();
    //             answer.push_back(i+1);
    //             result[3] = result[i];
    //         }
    //     }
    // }
    return answer;
    
}
