//
//  main.cpp
//  표편집
//
//  Created by 홍진석 on 2021/07/31.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

struct node{
    int prev;
    int next;
};

int moveIdx(char c, int X, int idx, vector<node> &nodes){
    if(c== 'U'){
        while(X > 0){
            idx = nodes[idx].prev; X--;
        }
    }
    else{
        while(X > 0){
            idx = nodes[idx].next; X--;
        }
    }
    return idx;
}

node initNode(int prev, int cur, int next){
    node newNode;
    newNode.prev = prev;
    newNode.next = next;
    return newNode;
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    bool check[1000001];
    stack<int> backupData;
    vector<node> nodes;
    for(int i=0; i<n; i++){
        check[i] = true;
        nodes.push_back(initNode(i-1, i, i+1));
    }
    nodes.back().next = -1;
    
    for(int i=0; i<cmd.size(); i++){
        
        if(cmd[i][0] == 'U' || cmd[i][0] == 'D'){
            k = moveIdx(cmd[i][0], stoi(cmd[i].substr(2,-1)), k, nodes);
        }

        else if(cmd[i][0] == 'C'){
            backupData.push(k);
            check[k] = false;
            if(nodes[k].next == -1){//last
                nodes[nodes[k].prev].next = nodes[k].next;
                k = nodes[k].prev;
            }
            else{
                if(nodes[k].prev != -1){
                    nodes[nodes[k].prev].next = nodes[k].next;
                    nodes[nodes[k].next].prev = nodes[k].prev;
                }
                else{//first
                    nodes[nodes[k].next].prev = -1;
                }
                k = nodes[k].next;
            }
        }
        else{//Z
            int backupIdx = backupData.top();
            backupData.pop();
            check[backupIdx] = true;
            if(nodes[nodes[backupIdx].prev].next == -1){
                nodes[nodes[backupIdx].prev].next = backupIdx;
                nodes[backupIdx].next = -1;
            }
            else{
                if(nodes[nodes[backupIdx].next].prev == -1){
                    nodes[nodes[backupIdx].next].prev = backupIdx;
                    nodes[backupIdx].prev = -1;
                }
                else{
                    nodes[backupIdx].next = nodes[nodes[backupIdx].prev].next;
                    nodes[nodes[backupIdx].prev].next = backupIdx;
                    nodes[backupIdx].prev = nodes[nodes[backupIdx].next].prev;
                    nodes[nodes[backupIdx].next].prev = backupIdx;
                }
            }
        }
    }
    
    for(int i=0; i<n; i++){
        if(check[i]){answer.push_back('O');}
        else{answer.push_back('X');}
    }

    return answer;
}

int main() {
    
    vector<string> v;
    v.push_back("D 2");
    v.push_back("C");
    v.push_back("U 3");
    v.push_back("C");
    v.push_back("D 4");
    v.push_back("C");
    v.push_back("U 2");
    v.push_back("Z");
    v.push_back("Z");
    v.push_back("U 1");
    v.push_back("C");
    v.push_back("C");
    solution(8, 2, v);
    return 0;
}
