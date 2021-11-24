//
//  main.cpp
//  [1차]캐시
//
//  Created by 홍진석 on 2021/08/25.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#define FOR(i,n) for(int i=0; i<(n); i++)
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int cnt = 0;
    
    map<string, int> m;
    
    FOR(i, cities.size()){
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        
        if(m.find(cities[i]) != m.end()){ //있으면
            answer += 1;
            m[cities[i]] = cnt++;
        }
        else{//없으면
            if(cacheSize == 0){ answer += 5; }
            else{
                if(m.size() < cacheSize) { m.insert(make_pair(cities[i], cnt++)); }
                else{
                    string lowest = "";
                    int lowestCnt = 1000000;
                    for(auto i : m){
                        if(lowestCnt > i.second){
                            lowestCnt = i.second;
                            lowest = i.first;
                        }
                    }
                    m.erase(lowest);
                    m.insert(make_pair(cities[i], cnt++));
                }
                
                answer += 5;
            }
        }
    }
    
    return answer;
}

int main() {
    vector<string> cities = {"LA","LA"};
    cout << solution(0, cities);
    return 0;
}

//캐시크기 , 도시이름 배열
//도시 최대 100,000개
//도시는 오직 영문자로 구성, 최대 20글자
//캐시교체는 LRU
//hit -> 1
//miss -> 5

