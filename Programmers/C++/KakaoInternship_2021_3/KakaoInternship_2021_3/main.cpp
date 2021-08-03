//
//  main.cpp
//  KakaoInternship_2021_3
//
//  Created by 홍진석 on 2021/05/08.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    stack<int> modifyIndex;

    answer.assign(n, 'O');

    int currentX = k; //처음 선책 행의 위치
    string ncmd;
    
    for(int i=0; i<cmd.size(); i++){//명령 순서대로
        cout << currentX << endl;
        ncmd = cmd.at(i);
        
        if(ncmd.at(0) == 'U'){
            string num = "";

            for(int j =2; j<ncmd.size(); j++){
                num.push_back(ncmd.at(j));
            }
        
            int cnt = stoi(num);
            
            for(int j=currentX-1; j>=0; j--){
                if(answer[j] == 'O'){
                    if(--cnt == 0){
                        currentX = j;
                        break;
                    }
                }
            }
        }
        
        else if(ncmd.at(0) == 'D'){
            string num = "";

            for(int j =2; j<ncmd.size(); j++){
                num.push_back(ncmd.at(j));
            }
            int cnt = stoi(num);
            for(int j=currentX+1; j<n; j++){
                if(answer[j] == 'O'){
                    if(--cnt == 0){
                        currentX = j;
                        break;
                    }
                }
            }
        }

        else if(ncmd.at(0) == 'C'){

            modifyIndex.push(currentX);
            int lastNum = 0;
            
            for(int j=n-1; j>=0; j--){
                if(answer[j] == 'O'){
                    lastNum = j;
                    break;
                }
            }
            
            answer[currentX] = 'X'; //삭제
            
            if(currentX == lastNum){//마지막 행일 경우 위로
                while(1){
                    if(answer[--currentX] == 'O'){break;}
                }
            }
            else{ //아니면 아래로
                while(1){
                    if(answer[++currentX] == 'O'){break;}
                }
            }
        }

        else if(ncmd.at(0) == 'Z'){
            //되돌리기
            if(!modifyIndex.empty()){
                int ret= modifyIndex.top();
                answer[ret] = 'O';
                modifyIndex.pop();
            }
        }
    }
    return answer;
}

int main() {
    vector<string> cmd;

    cmd.push_back("D 2");
    cmd.push_back("C");
    cmd.push_back("U 3");
    cmd.push_back("C");
    cmd.push_back("D 4");
    cmd.push_back("C");
    cmd.push_back("U 2");
    cmd.push_back("Z");
    cmd.push_back("U 1");
    cmd.push_back("C");
    
    cout << solution(8, 2, cmd);
    return 0;
}
