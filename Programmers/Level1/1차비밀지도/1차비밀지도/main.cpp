//
//  main.cpp
//  1차비밀지도
//
//  Created by 홍진석 on 2021/06/24.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int result1[17][17] = {0, };
    int result2[17][17] = {0, };

    for(int i=0; i<n; i++){
        int cnt = 0;
        
        while(arr1[i] >= 1){
            result1[i][cnt] = arr1[i]%2;
            arr1[i] = arr1[i]/2;
            cnt++;
        }
    }
    
    for(int i=0; i<n; i++){
        int cnt = 0;
        while(arr2[i] >= 1){
            result2[i][cnt] = arr2[i]%2;
            arr2[i] = arr2[i]/2;
            cnt++;
        }
    }

    
    for(int i=0; i<n; i++){
        string s;
        
        for(int j=0; j<n; j++){
            if(result1[i][j] == 1 || result2[i][j] == 1){
                s += '#';
            }
            else{s += ' ';}
        }
        reverse(s.begin(), s.end());
        answer.push_back(s);
    }

    return answer;
}
