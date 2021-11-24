//
//  main.cpp
//  최댓값과최솟값
//
//  Created by 홍진석 on 2021/08/25.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    string temp;
    vector<int> v;
    
    while(getline(ss, temp, ' ')){
        v.push_back(stoi(temp));
    }
    
    sort(v.begin(), v.end());
    answer += to_string(v.front()) + " " + to_string(v.back());
    
    return answer;
}

int main() {
    string s = "-1 1 2 3 -5";
    solution(s);
    return 0;
}
