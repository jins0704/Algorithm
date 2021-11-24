//
//  main.cpp
//  보석쇼핑
//
//  Created by 홍진석 on 2021/05/23.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems){
    set<string> s1(gems.begin(),gems.end());

    int low = int(s1.size()); //최소 범위
    int high = int(gems.size()); // 최대 범위
    int solLow = 0;
    int solHigh = 0;
    
    while(low <= high){
        int mid = (low+high)/2;
        unordered_map<string, int> m1;
        //cout << mid << endl;
        bool possible = false;
        
        for(int i=0; i<mid; i++){
            if(m1.find(gems[i]) == m1.end()){
                m1.insert(make_pair(gems[i], 1));
            }
            else{
                m1[gems[i]] ++;
            }
        }

        if(m1.size() == s1.size()){
            possible = true;
            solLow = 1;
            solHigh = mid;
            //cout << solLow <<" f " <<solHigh << endl;
            
        }
        if(!possible){
            for(int i=mid; i<gems.size(); i++){
                if(m1.at(gems[i-mid]) == 1){//한개만 있다면
                    m1.erase(gems[i-mid]);
                }
                else{
                    m1.at(gems[i-mid])--;//몇개 있다면
                }
                
                if(m1.find(gems[i]) == m1.end()){
                    m1.insert(make_pair(gems[i], 1));
                }
                else{m1.at(gems[i])++;}
                
                if(m1.size() == s1.size()){
                    possible = true;
                    solLow = i-mid+2;
                    solHigh = i+1;
                }
                if(possible){break;}
            }
        }
        
        if(possible){
            high = mid;
        }
        else{
            low = mid+1;
        }
        
        if(possible && low == high){break;}
    }
    cout << solLow << " " <<solHigh << endl;
    vector<int> answer;
    answer.push_back(solLow);
    answer.push_back(solHigh);
    return answer;
}

int main() {
    vector<string> gems;
    gems.push_back("XYZ");
    gems.push_back("XYZ");
    gems.push_back("XYZ");
//
//    gems.push_back("ZZZ");
//    gems.push_back("YYY");
//    gems.push_back("NNNN");
//    gems.push_back("YYY");
//    gems.push_back("BBB");
    
    solution(gems);
    
    return 0;
}
