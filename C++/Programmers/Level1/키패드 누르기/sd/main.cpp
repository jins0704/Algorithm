//
//  main.cpp
//  sd
//
//  Created by 홍진석 on 2021/04/25.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int numpad[4][3] = {{1,2,3},{4,5,6},{7,8,9},{11,10,12}};
    
    int LNum = 11;
    int RNum = 12;
    
    for(int i=0; i<numbers.size(); i++){
        int target = numbers.at(i);
        if(target == 0){target = 10;}
        
        if(target == 1 || target == 4 || target == 7){
            answer.append("L");
            LNum = target;
        }
        else if(target == 3 || target == 6 || target == 9){
            answer.append("R");
            RNum = target;
        }
        else{
            int targetX=1,targetY=1,LX=1,LY=1,RX=1,RY=1;
            
            for(int i=0; i<4; i++){
                for(int j=0; j<3; j++){
                    if(target == numpad[i][j]){
                        targetX = i;
                        targetY = j;
                    }
                    if(LNum == numpad[i][j]){
                        LX = i;
                        LY = j;
                    }
                    if(RNum == numpad[i][j]){
                        RX = i;
                        RY = j;
                    }
                }
            }
            int distanceL = abs(targetX - LX) + abs(targetY - LY);
            int distanceR = abs(targetX -RX) + abs(targetY -RY);
            if(distanceL > distanceR){
                answer.append("R");
                RNum = target;
            }
            else if(distanceL < distanceR){
                answer.append("L");
                LNum = target;
            }
            else{
                if(hand.at(0) == 'l'){
                    answer.append("L");
                    LNum = target;
                }
                else{
                    answer.append("R");
                    RNum = target;
                }
            }
        }
    }

    return answer;
}

int main() {
    vector<int> numbers;
    numbers.push_back(7);
    numbers.push_back(0);
    numbers.push_back(8);
    numbers.push_back(2);
    numbers.push_back(8);
    numbers.push_back(3);
    numbers.push_back(1);
    numbers.push_back(5);
    numbers.push_back(7);
    numbers.push_back(6);
    numbers.push_back(2);
    
    string hand = "left";
    cout << solution(numbers, hand);
    return 0;
}
