//
//  main.cpp
//  KakaoInternship_2021_1
//
//  Created by 홍진석 on 2021/05/08.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool checkNum(char c){
    if(c == '0' || c== '1' || c == '2' || c== '3'  || c == '4' || c== '5' || c == '6' || c== '7' || c== '8' || c == '9'){
        return true;
    }
    else{return false;}
}

char checksNum(string sNum){
    if(sNum == "zero"){return '0';}
    else if(sNum == "one"){return '1';}
    else if(sNum == "two"){return '2';}
    else if(sNum == "three"){return '3';}
    else if(sNum == "four"){return '4';}
    else if(sNum == "five"){return '5';}
    else if(sNum == "six"){return '6';}
    else if(sNum == "seven"){return '7';}
    else if(sNum == "eight"){return '8';}
    else if(sNum == "nine"){return '9';}
    else{return 'a';}
}
int solution(string s) {
    string sNum;
    string findNum;
    int answer = 0;
    
    for(int i=0; i<s.length(); i++){
        
        if(checkNum(s.at(i))){
            //숫자인경우

            findNum.push_back(s.at(i));
        }
        else{
            //글자인 경우
            sNum.push_back(s.at(i));
            if(checksNum(sNum)-'0' <= 9){
                findNum.push_back(checksNum(sNum));
                while(!sNum.empty()){
                    sNum.pop_back();
                }
            }
        }
    }
    
    answer = stoi(findNum);
    
    return answer;
}

int main() {
    
    string s = "one4seveneight";

    cout << solution(s);
    
    return 0;
}
