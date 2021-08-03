//
//  main.cpp
//  프로그래머스_폰켓몬
//
//  Created by 홍진석 on 2021/05/05.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    vector<int> uniqueV;
    
    sort(nums.begin(),nums.end());
    
    for(unsigned i =0; i< nums.size(); i++){
        if(i==0){
            uniqueV.push_back(nums.at(i));
        }
        else{
            if(nums.at(i-1) < nums.at(i)){
                uniqueV.push_back(nums.at(i));
            }
        }
    }
    
    if(uniqueV.size() <= nums.size()/2){
        answer = (int)uniqueV.size();
    }
    else{
        answer = (int)nums.size()/2;
    }
    return answer;
}

int main() {
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(4);
   
    cout << solution(nums);
    return 0;
}
