//
//  main.cpp
//  보석
//
//  Created by 홍진석 on 2021/07/28.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

bool initCheck(int size, int mid, unordered_map<string, int> &m1, vector<string> &gems){
    for(int i=0; i<mid; i++){
        if(m1.find(gems[i]) == m1.end()){m1.insert(make_pair(gems[i], 1));}
        else{m1[gems[i]] ++;}
    }
    
    if(m1.size() == size){return true;}
    else{return false;}
}

bool checkNext(int size, int i, int mid, unordered_map<string, int> &m1, vector<string> &gems){
    //앞쪽 삭제
    if(m1[gems[i-mid]] == 1){m1.erase(gems[i-mid]);}
    else{m1[gems[i-mid]]--;}
    
    //뒤쪽 추가
    if(m1.find(gems[i]) == m1.end()){m1.insert(make_pair(gems[i], 1));}
    else{m1.at(gems[i])++;}
    
    if(m1.size() == size){return true;}
    else{return false;}
}

vector<int> solution(vector<string> gems){
    set<string> s1(gems.begin(),gems.end());
    
    int low = int(s1.size());
    int high = int(gems.size());
    int startIdx = 0;
    int endIdx = 0;
    
    while(low <= high){
        int mid = (low+high)/2;
        bool possible = false;
        unordered_map<string, int> m1;
        
        if(initCheck(int(s1.size()), mid, m1, gems)){
            startIdx = 1;
            endIdx = mid;
            possible = true;
        }
        else{
            for(int i=mid; i<gems.size(); i++){
                if(checkNext(int(s1.size()), i, mid, m1, gems)){
                    possible = true;
                    startIdx = i-mid+2;
                    endIdx = i+1;
                    break;
                }
            }
        }
        
        if(possible){
            high = mid;
            if(low == high){break;}
        }
        else{low = mid+1;}
    }
    vector<int> answer;
    answer.push_back(startIdx);
    answer.push_back(endIdx);
    
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<string> gems;
    gems.push_back("XYZ");
    gems.push_back("XYZ");
    gems.push_back("XYZ");
    
    solution(gems);
    
    return 0;
}
