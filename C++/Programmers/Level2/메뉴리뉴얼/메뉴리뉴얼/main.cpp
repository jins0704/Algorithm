//
//  main.cpp
//  메뉴리뉴얼
//
//  Created by 홍진석 on 2021/07/29.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

void comb(string &subString, int idx, bool check[], string s, vector<string> &sub){
    if(subString.size()== idx){
        sub.push_back(subString);
        return;
    }
    else{
        for(int i=0; i<s.size(); i++){
            if(!check[i]){
                if(subString.empty()){subString.push_back(s[i]);}
                else{
                    if(subString.back() < s[i]){subString.push_back(s[i]);}
                    else{continue;}
                }

                check[i] = true;
                comb(subString, idx, check, s, sub);
                subString.pop_back();
                check[i] = false;
            }
        }
    }
}

vector<string> makeSubset(string s){
    vector<string> sub;
    for(int i=1; i<=s.size(); i++){
        sort(s.begin(), s.end());
        string subString = "";
        bool check[11] ={0,};
        comb(subString, i, check, s, sub);
    }
    
    return sub;
}

bool cmp(pair<string, int> a, pair<string, int> b){
    if(a.first.size() == b.first.size()){
        if(a.second == b.second){
            return a.first < b.first;
        }
        else{
            return a.second > b.second;
        }
    }
    else{
        return a.first.size() < b.first.size();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<string,int> m;
    for(int i=0; i<orders.size(); i++){
        vector<string> subset = makeSubset(orders[i]);
        for(int j=0; j<subset.size(); j++){
            if(m.find(subset[j]) == m.end()){
                m.insert(make_pair(subset[j], 1));
            }
            else{
                m[subset[j]] ++;
            }
        }
    }
    
    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);

    int t = 0;
    for(int i=0; i<course.size(); i++){
        // course[i] 코스 수
        bool first = true;
        int courseCnt = 0;

        for(int j = t; j<v.size(); j++){
            if(first){
                if(v[j].first.size() == course[i] && v[j].second >1){
                    answer.push_back(v[j].first);
                    courseCnt = v[j].second;
                    first = false;
                }
            }
            else{
                if(v[j].second == courseCnt){
                    answer.push_back(v[j].first);
                }
                else{
                    t = j+1;
                    break;
                }
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}





int main(int argc, const char * argv[]) {
    
    vector<string> v;
    v.push_back("XYZ");
    v.push_back("XWY");
    v.push_back("WXA");
    vector<int> v2;
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
    solution(v, v2);
    return 0;
}
