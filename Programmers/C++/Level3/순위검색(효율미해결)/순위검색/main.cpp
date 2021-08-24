//
//  main.cpp
//  순위검색
//
//  Created by 홍진석 on 2021/08/23.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#define FOR(i,n) for(int i=0; i<(n); i++)

using namespace std;

bool cmp (int a, int b){
    return a < b;
}

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
    
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
    
    return answer;
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<string> condition1;
    vector<string> condition2;
    vector<string> condition3;
    vector<string> condition4;
    vector<string> result;
    pair<string, string> a;
    pair<string, string> b;
    pair<pair<string, string>,pair<string, string>> c;
    vector<vector<string>> infoCase = {{"java", "cpp", "python"}, {"backend","frontend"}, {"junior", "senior"},{"chicken", "pizza"}};
    map<pair<pair<string, string>,pair<string, string>>, vector<int>> apply; //언어 직군 경력 소울 점수
    int low = 0; int high = 0; int mid =0;
    
    FOR(i,info.size()){
        result = split(info[i], ' ');
        a = make_pair(result[0], result[1]);
        b = make_pair(result[2], result[3]);
        c = make_pair(a, b);
        apply[c].push_back(stoi(result[4]));
    }
    
    FOR(i,query.size()){
        int cnt = 0;
        result = split(query[i], ' '); //지원자 정보
        
        if(result[0] == "-"){ condition1 = infoCase[0];}
        else{ condition1 = {result[0]}; }
        
        if(result[2] == "-"){ condition2 = infoCase[1];}
        else{ condition2 = {result[2]}; }
        
        if(result[4] == "-"){ condition3 = infoCase[2];}
        else{ condition3 = {result[4]}; }
        
        if(result[6] == "-"){ condition4 = infoCase[3];}
        else{ condition4 = {result[6]}; }
        
        FOR(j, condition1.size()){
            FOR(q, condition2.size()){
                FOR(w, condition3.size()){
                    FOR(r, condition4.size()){
                        a = make_pair(condition1[j], condition2[q]);
                        b = make_pair(condition3[w], condition4[r]);
                        c = make_pair(a, b);
                        vector<int> vv = apply[c];
                        sort(vv.begin(), vv.end());
                        
                        if(vv.size() > 0){
                            
                            low = 0;
                            int ans =0;
                            high = int(vv.size());
                            if(high > 0){
                                
                                while(low <= high){
                                    mid = (low + high) / 2;
                                    if(vv[mid] < stoi(result[7])){
                                        low = mid+1;
                                    }
                                    else{
                                        high = mid-1;
                                        ans = mid;
                                    }
                                }
                                
                                
                                if(vv[ans] >= stoi(result[7])){
                                    cnt += vv.size() - ans;
                        
                                }
                            }
                        }
                    }
                }
            }
        }
        answer.push_back(cnt);
    }
    
    return answer;
}

int main() {
    vector<string> info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};

    vector<string> query = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
    
    vector<int> v = solution(info, query);
    
    return 0;
}

//언어항목 : cpp, java, python
//직군항목 : backend, frontend
//경력항목 : junior, senior
//소울푸드 : chicken, pizza

//[조건] 만족하는 사람 중 코딩테스트 점수를 X점 이상받은 사람은 모두 몇명인가?
// - 는 조건 고려하지 않겠다.

//[정보, 점수] 문자열 배열 info -  "개발언어 and 직군 and 경력 and 소울푸드
//문의조건 문자열 배열 query -
//해당 사람 숫자 배열아 담아 return
