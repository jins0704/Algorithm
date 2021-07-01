//
//  main.cpp
//  기능개발
//
//  Created by 홍진석 on 2021/07/01.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int day = 0;
    int index = 0;
    
    while(index < progresses.size()){
        int releaseCnt = 0;
        day ++;
        while(progresses[index] + day*speeds[index] >= 100){
            releaseCnt ++;
            index++;
            if(index >= progresses.size()){break;}
        }
        
        if(releaseCnt > 0){
            answer.push_back(releaseCnt);
        }
    }
    return answer;
}
