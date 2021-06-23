//
//  main.cpp
//  약수의갯수와덧셈
//
//  Created by 홍진석 on 2021/06/23.
//

#include <string>
#include <iostream>

using namespace std;

int devisor(int num){
    
    for(int i=1; i <= 34; i++){
        if(i*i == num){
            return 1;
        }
    }
    return 2;
}
int solution(int left, int right) {
    int answer = 0;
    
    for(int i = left; i<= right; i++){
        
        if(devisor(i) == 2){
            answer += i;
        }
        else{
            answer -= i;
        }
    }
    return answer;
}
