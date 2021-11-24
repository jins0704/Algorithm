//
//  main.cpp
//  [3차]N진수게임
//
//  Created by 홍진석 on 2021/08/25.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string changeMod(int num, int n){
    if(num >= 0 && num <=9) { return to_string(num); }
    else if(num == 10) { return "A"; }
    else if(num == 11) { return "B"; }
    else if(num == 12) { return "C"; }
    else if(num == 13) { return "D"; }
    else if(num == 14) { return "E"; }
    else { return "F"; }
}

string changeNum(int i, int n){
    string num = "";
    if(i == 0) { return "0"; }
    
    while (i > 0) {
        int mod = (i%n);
        num = changeMod(mod, n) + num;
        i /= n;
    }
    return num;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string all = "";
    for(int i=0; i<=m*t; i++){ all += changeNum(i,n); }
    for(int i=0; i<t; i++){ answer += all[m*i+p-1]; }
    
    return answer;
}

int main() {
    cout << solution(2, 4, 2, 1);
    return 0;
}
