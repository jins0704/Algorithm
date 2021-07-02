//
//  main.cpp
//  구명보트
//
//  Created by 홍진석 on 2021/07/02.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int couple = 0;
    bool possible = false;
    
    sort(people.begin(), people.end());
    
    int best = people.size()-1;
    for(int i=0; i<people.size(); i++ ){
        for(int j = best; j>i; j--){
            possible = false;
            if(people[i] + people[j] <= limit){
                couple ++;
                best = j-1;
                possible = true;
                break;
            }
        }
        if(!possible){break;}
    }
    
    answer = (int)people.size() - couple;
    return answer;
}
