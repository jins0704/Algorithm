//
//  main.cpp
//  직업군추천하기
//
//  Created by 홍진석 on 2021/08/23.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#define FOR(i,n) for(int i=0; i<(n); i++)

using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    int answerScore = 0;
    
    FOR(i, table.size()){
        stringstream ss(table[i]);
        map<string, int> score;
        string temp;
        string name;
        
        getline(ss, name, ' ');
        
        int grade = 5;
        while (getline(ss, temp, ' ')) {
            score.insert(make_pair(temp, grade--));
        }
        
        int total = 0;
        
        FOR(j, languages.size()){
            total += score[languages[j]] * preference[j];
            
            if((answerScore < total) || (answerScore == total && answer > name)){
                answerScore = total;
                answer = name;
            }
        }
    }
    
    return answer;
}

int main() {
    vector<string> table = {"SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA"};
    vector<string> languages = {"PYTHON", "C++", "SQL"};
    vector<int> preference = {7,5,5};
    cout << solution(table, languages, preference);
    
    return 0;
}
