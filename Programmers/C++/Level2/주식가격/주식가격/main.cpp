//
//  main.cpp
//  주식가격
//
//  Created by 홍진석 on 2021/06/23.
//

#include <string>
#include <vector>
#include <stack>
#include <cstring>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<pair<int,int>> st;
    int *result = (int*)malloc(sizeof(int) * prices.size());
    memset(result, 0, sizeof(int) * prices.size());
    
    int cnt = 0;
    
    for(int i=0; i<prices.size(); i++){
        if(st.empty()){
            st.push(make_pair(prices[i],i));
        }
        else{
            while(!st.empty() && st.top().first > prices[i]){
                result[st.top().second] = i-st.top().second;
                st.pop();
            }
            st.push(make_pair(prices[i],i));
        }
    }
    
    while(!st.empty()){
        result[st.top().second] = prices.size() - st.top().second-1;
        st.pop();
    }
    for(int i=0; i<prices.size(); i++){
        answer.push_back(result[i]);
    }
    return answer;
}
