//
//  main.cpp
//  최소직사각형
//
//  Created by 홍진석 on 2021/10/06.
//

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int a = sizes[0][0];
    int b = sizes[0][1];
    int big = 0;
    int small = 0;
    for(int i=1; i<sizes.size(); i++){
        if(sizes[i][0] > sizes[i][1]) {
            big = sizes[i][0];
            small = sizes[i][1];
        }
        else{
            big = sizes[i][1];
            small = sizes[i][0];
        }
        
        if(a>b){
            a = a > big ? a : big;
            b = b > small ? b : small;
        }
        else{
            a = a > small ? a : small;
            b = b > big ? b : big;
        }
    }
    
    answer = a*b;
    return answer;
}
