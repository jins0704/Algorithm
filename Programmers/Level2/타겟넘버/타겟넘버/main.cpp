//
//  main.cpp
//  타겟넘버
//
//  Created by 홍진석 on 2021/06/23.
//

#include <string>
#include <vector>

using namespace std;

int makeTarget(vector<int> &numbers, int target, int sum, int cnt){
    if(cnt == numbers.size()){
        if(sum == target){
           return 1;
        }
        return 0;
    }
    else{
        int a = makeTarget(numbers, target, sum+numbers[cnt], cnt+1);
        int b = makeTarget(numbers, target, sum-numbers[cnt], cnt+1);
        
        return a+b;
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    answer = makeTarget(numbers, target, 0, 0);
    
    return answer;
}
