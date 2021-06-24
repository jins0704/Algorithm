//
//  main.cpp
//  예산
//
//  Created by 홍진석 on 2021/06/24.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    sort(d.begin(),d.end());
    
    for(int i=0; i< d.size(); i++){
        if(budget-d[i] >=0){
            budget -= d[i];
            answer++;
        }
        else{
            break;
        }
    }
    return answer;
}
