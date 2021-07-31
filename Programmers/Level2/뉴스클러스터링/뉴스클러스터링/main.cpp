//
//  main.cpp
//  뉴스클러스터링
//
//  Created by 홍진석 on 2021/07/30.
//

#include <string>
#include <iostream>
#include <cctype>
#include <vector>
#include <map>

using namespace std;

void makeSubset(string str, map<string,int> &subset){
    for(int i=0; i< str.size()-1; i++){
        string s = "";
        if(!isalpha(str[i]) || !isalpha(str[i+1])){continue;}
        s.push_back(tolower(str[i]));
        s.push_back(tolower(str[i+1]));
        
        if(subset.find(s) == subset.end()){
            subset.insert(make_pair(s, 1));
        }
        else{
            subset[s] ++;
        }
    }
}

void makeUnion(map<string,int> &subset1, map<string,int> &subset2, map<string,int> &uni){
    for(auto item : subset1){
        uni.insert(make_pair(item.first, item.second));
    }
    for(auto item : subset2){
        if(uni.find(item.first) == uni.end()){
            uni.insert(make_pair(item.first, item.second));
        }
        else{
            if(uni[item.first] < item.second){
                uni[item.first] = item.second;
            }
        }
    }
}

double countMap(map<string,int> &m){
    double cnt = 0;
    for(auto t : m){cnt += t.second;}
    return cnt;
}

int solution(string str1, string str2) {
    map<string,int> subsetOfOne;
    map<string,int> subsetOfTwo;
    map<string, int> unionOfAB;
    
    makeSubset(str1, subsetOfOne);
    makeSubset(str2, subsetOfTwo);
    
    makeUnion(subsetOfOne, subsetOfTwo, unionOfAB);
    
    //교집합 = A + B - (AUB)
    double aCnt = countMap(subsetOfOne);
    double bCnt = countMap(subsetOfTwo);
    double unionCnt = countMap(unionOfAB);
    double intersectCnt = aCnt + bCnt - unionCnt;
    
    if(aCnt == 0 && bCnt == 0){ return 65536; }
    else{ return int(intersectCnt/unionCnt * 65536); }
}

int main() {
    string str1 = "FRANCE";
    string str2 = "french";
    
    solution(str1, str2);
    
    return 0;
}
