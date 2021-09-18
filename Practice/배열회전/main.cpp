//
//  main.cpp
//  배열회전
//
//  Created by 홍진석 on 2021/09/08.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> rotateLeft(vector<vector<int>> &v){
    vector<vector<int>> result;
    
    for(int i=0; i<v.size(); i++){
        vector<int> temp;
        for(int j=0; j<v.size(); j++){
            temp.push_back(v[v.size()-1-j][i]);
        }
        result.push_back(temp);
    }
    
//    cout << endl;
//
//    for(int i=0; i<v.size(); i++){
//        for(int j=0; j<v.size(); j++){
//            cout << v[j][v.size()-1-i] << " ";
//        }cout << endl;
//    }
    
    return result;
}
int main() {
    
    vector<vector<int>> v= {{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20},{21,22,23,24,25}};
    
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            cout << v[i][j] << " ";
        }cout << endl;
    }
    
    vector<vector<int>> t = rotateLeft(v);
    
    
    for(int i=0; i<t.size(); i++){
        for(int j=0; j<t[i].size(); j++){
            cout << t[i][j] << " ";
        }cout << endl;
    }
    
    return 0;
}
