//
//  main.cpp
//  H-Index
//
//  Created by 홍진석 on 2021/09/03.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 100000;
    
    sort(citations.begin(), citations.end());
    int low = 0;
    int high = int(citations.size());
    
    while(low <= high){
        int mid = (low+high)/2; //h로 지정
        if(citations[citations.size()-mid] >= mid){
            answer = min(answer, mid);
            answer = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    return answer;
}

int main() {
    vector<int> c = {5,5,5,5};
    cout << solution(c);
    return 0;
}
//9 16
