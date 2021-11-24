//
//  main.cpp
//  자물쇠와열쇠
//
//  Created by 홍진석 on 2021/08/16.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

set<pair<int,int>> rotate90(vector<vector<int>> &key){
    vector<vector<int>> rotateV;
    set<pair<int, int>> rotateS;
    
    int ksize = int(key.size());
    for(int i=0; i<ksize; i++){
        vector<int> v;
        for(int j= ksize-1; j>=0; j--){
            v.push_back(key[j][i]);
            
            if(key[j][i]== 1){
                rotateS.insert(make_pair(i, ksize-1-j));
            }
        }
        
        rotateV.push_back(v);
    }
    key = rotateV;
    return rotateS;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

    vector<vector<int>> rotateV;
    set<pair<int, int>> sol;
    
    //자물쇠 구멍 위치
    for(int i=0; i<lock.size(); i++){
        for(int j=0; j<lock.size(); j++){
            if(lock[i][j] == 0){ sol.insert(make_pair(i, j)); }
        }
    }
    
    
    for(int k =0; k<4; k++) {
        //90도 회전
        set<pair<int,int>> s = rotate90(key);
       
        int ksize = int(key.size());
        int lsize = int(lock.size());
        
        for(int i=-ksize+1; i<lsize; i++){
            for(int j=-ksize+1; j<lsize; j++){
                int check = 0;
                for(auto keyIdx : s){
                    if(keyIdx.first+i >= 0 && keyIdx.second+j >=0){
                        if(keyIdx.first+i < lsize && keyIdx.second+j < lsize){
                            if(sol.find(make_pair(keyIdx.first+i, keyIdx.second+j)) == sol.end()){
                                check = -1;
                                break; }
                            else{ check ++; }
                        }
                    }
                }
                if(check == sol.size()) { return true;}
            }
        }
    }
    
    return false;
}


int main() {
    
    vector<vector<int>> key = {{0,0,0}, {1,0,0}, {0,1,1}};
    vector<vector<int>> lock = {{1,1,1}, {1,1,0}, {1,0,1}};
    
    solution(key, lock);
    return 0;
}

//자물쇠 NxN
//열쇠 MxM


