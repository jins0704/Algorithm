//
//  main.cpp
//  프로그래머스_완주하지못한선수
//
//  Created by 홍진석 on 2021/05/06.
//


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    string answer = "";
    int goal1 = 0;
    int goal2 = 0;
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    
    while(!completion.empty()){
        if(participant[goal1] == completion[goal2]){
            goal1++;
            goal2++;
        }
        else{
            break;
        }
    }
    
    answer = participant[goal1];
    return answer;
}

int main() {
    
    vector<string> participant;
    vector<string> completion;
    
    participant.push_back("leo");
    participant.push_back("kiki");
    participant.push_back("gg");
    participant.push_back("eden");
    participant.push_back("kk");
    participant.push_back("qw");
    participant.push_back("eden");
    participant.push_back("qw");
    
    completion.push_back("eden");
    completion.push_back("gg");
    completion.push_back("kiki");
    completion.push_back("leo");
    completion.push_back("qw");
    completion.push_back("qw");completion.push_back("kk");
    
    cout << solution(participant, completion);
    
    return 0;
}
