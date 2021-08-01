//
//  main.cpp
//  표편집(리스트)
//
//  Created by 홍진석 on 2021/07/31.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <list>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    //stack<int> backupData;
    stack<list<int>::iterator> backupData;
    list<int> li;
    for(int i=0; i<n; i++){
        li.push_back(i);
        answer += "X";
    }
    list<int>::iterator idx = li.begin();
    for(int i=0; i<k; i++){idx++;}
    
    for(int i=0; i<cmd.size(); i++){
        if(cmd[i][0] == 'U'){for(int j=0; j<stoi(cmd[i].substr(2,-1)); j ++){idx--;}}
        else if(cmd[i][0] == 'D'){for(int j=0; j<stoi(cmd[i].substr(2,-1)); j++){idx++;}}
        
        else if(cmd[i][0] == 'C'){
            backupData.push(idx);
            if(++idx == li.end()){
                idx--;
                li.erase(idx--);
            }
            else{
                idx--;
                li.erase(idx++);
            }
        }
        else if(cmd[i][0] == 'Z'){
            list<int>::iterator it;
            list<int>::iterator where = backupData.top();
            cout << ", where " << *where << endl;
//            bool check = false;
//            for(it = li.begin(); it != li.end(); it++){
//                if(*it > num){
//                    li.insert(it, num);
//                    check = true;
//                    break;
//                }
//            }
//            if(!check){li.push_back(num);}
            backupData.pop();
        }
    }
    
    for(auto item : li){answer[item] = 'O';}
    
    return answer;
}

int main() {
    
    vector<string> v;
    v.push_back("C");
    v.push_back("C");
    v.push_back("D 3");
    v.push_back("C");
    v.push_back("Z");
    v.push_back("Z");
    solution(8, 2, v);
    return 0;
}
