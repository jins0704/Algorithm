//
//  main.cpp
//  K번째수
//
//  Created by 홍진석 on 2021/05/07.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int s=0; s<commands.size(); s++){
        int i = commands.at(s).at(0); // i 번째부터
        int j = commands.at(s).at(1); // j 숫자까지 자르고 정렬
        int k = commands.at(s).at(2); // k 번째 수
        
        vector<int> cutarray;
        
        cutarray.assign(array.begin()+i-1, array.begin()+j);
        sort(cutarray.begin(), cutarray.end());
        
        answer.push_back(cutarray.at(k-1));
    }
    return answer;
}

int main() {
    vector<int> array;
    array.push_back(1);
    array.push_back(5);
    array.push_back(2);
    array.push_back(6);
    array.push_back(3);
    array.push_back(7);
    array.push_back(4);
    
    vector<vector<int>> commands;
    vector<int> a1;
    a1.push_back(2);
    a1.push_back(5);
    a1.push_back(3);
    
    vector<int> a2;
    a2.push_back(4);
    a2.push_back(4);
    a2.push_back(1);
    
    vector<int> a3;
    a3.push_back(1);
    a3.push_back(7);
    a3.push_back(3);
    
    commands.push_back(a1);
    commands.push_back(a2);
    commands.push_back(a3);
    
    solution(array, commands);
    
    
    return 0;
}
