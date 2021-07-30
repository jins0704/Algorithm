//
//  main.cpp
//  가장큰수
//
//  Created by 홍진석 on 2021/07/30.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(string a ,string b){
    if(a.size() == b.size()){
        return a > b;
    }
    else{
        return a+b > b+a;
        
    }
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> numsToString;
    bool zeroCheck = false;
    for(int i=0; i< numbers.size(); i++){
        if(numbers[i] != 0){zeroCheck = true;}
        numsToString.push_back(to_string(numbers[i]));
    }
    if(!zeroCheck){return "0";}
    sort(numsToString.begin(), numsToString.end(), cmp);
    
    for(int i=0; i<numsToString.size(); i++){
       answer += numsToString[i];
    }
    
    return answer;
}

int main() {
    vector<int> v;
    v.push_back(0);
    solution(v);
    return 0;
}
