//
//  main.cpp
//  다단계칫솔판매
//
//  Created by 홍진석 on 2021/08/09.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#define FOR(i,n) for(int i=0; i<(n); i++)

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    map<string, pair<string, int>> m;
    
    FOR(i, enroll.size()){ m.insert(make_pair(enroll[i], make_pair(referral[i], 0))); }
    
    FOR(i, seller.size()){
        int earnMoney = amount[i]*100;
        string person = seller[i];
        
        while(person != "-"){
            if(int(earnMoney*(0.1)) < 1){ // 10%가 1원 이내라면
                m[person].second += earnMoney; // 자기가 다 갖기
                break;
            }
            else{ //10%가 1원 이상이라면
                m[person].second +=  earnMoney - int(earnMoney*(0.1)); //자신이 90% 갖기
                earnMoney = int(earnMoney*(0.1)); //10% 넘기기
                person = m[person].first;
            }
        }
    }
    
    FOR(i, enroll.size()){ answer.push_back(m[enroll[i]].second); }
    
    return answer;
}

int main() {
    return 0;
}
