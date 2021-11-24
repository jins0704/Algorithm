//
//  main.cpp
//  카펫
//
//  Created by 홍진석 on 2021/09/03.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int blocks = brown + yellow; //블럭 수
    
    for(int i=3; i<= blocks; i++){
        if(blocks%i == 0){
            if(i > blocks/i) { break; }
            
            // i <=  blocks/i
            if(2 * (blocks/i + i) - 4 == brown){
                return {blocks/i, i};
            }
            
        }
    }
    
    return answer;
}

int main() {
    solution(24, 24);
    return 0;
}

//중앙 노란색
//테두리 한줄은 갈색
