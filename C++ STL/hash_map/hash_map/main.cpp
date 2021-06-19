//
//  main.cpp
//  hash_map
//
//  Created by 홍진석 on 2021/06/19.
//

#include <iostream>
#include <unordered_map>

// ket(string) -> value(int) 빠른 검색
// 정렬 x
using namespace std;

int main() {
   
    unordered_map<string, int> table;
    
    table.insert(make_pair("jin", 1));
    table.insert(make_pair("hong", 2));
    table.insert({"seok", 3});
    
    //key 찾기 O(1)
    if(table.find("jin") != table.end()){
        cout << "find jin" << endl;
    }
    else{
        cout << "no" << endl;
    }
    
    //삭제
    table.erase("seok");
    
    //traverse - 다만 Unordered하기에 정렬 x
    for(auto iter : table){
        cout << iter.first << " " << iter.second << endl;
    }
    
    return 0;
}
