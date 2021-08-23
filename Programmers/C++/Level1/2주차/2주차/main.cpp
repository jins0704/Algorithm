//
//  main.cpp
//  2주차
//
//  Created by 홍진석 on 2021/08/23.
//

#include <iostream>
#include <string>
#include <vector>
#define FOR(i,n) for(int i=0; i<(n); i++)

using namespace std;

struct student{
    int maxValue = 0;
    int minValue = 100;
    int num = 0;
    float total = 0;
};

char grade(float score){
    if(score >= 90.0) { return 'A'; }
    else if(score >= 80.0) { return 'B'; }
    else if(score >= 70.0) { return 'C'; }
    else if(score >= 50.0) { return 'D'; }
    else { return 'F'; }
}

string solution(vector<vector<int>> scores) {
    string answer = "";
    
    student arr[scores.size()];
    
    FOR(i, scores.size()){
        FOR(j, scores[i].size()){
            if(i == j) { continue; }
            
            arr[j].total += scores[i][j];
            arr[j].maxValue = max(arr[j].maxValue, scores[i][j]);
            arr[j].minValue = min(arr[j].minValue, scores[i][j]);
        }
        
        arr[i].num = int(scores.size())-1;
    }
    
    FOR(i, scores.size()){
        if(scores[i][i] >= arr[i].minValue && scores[i][i] <= arr[i].maxValue){
            arr[i].total += scores[i][i];
            arr[i].num ++;
        }
       
        answer.push_back(grade(arr[i].total / arr[i].num));
    }
    
    return answer;
}

int main() {
    vector<vector<int>> scores = {{100,90,98,88,65},{50,45,99,85,77},{47,88,95,80,67},{61,57,100,80,65},{24,90,94,75,65}};
    cout << solution(scores);
    return 0;
}
