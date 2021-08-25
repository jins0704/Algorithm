//
//  main.cpp
//  방금그곡
//
//  Created by 홍진석 on 2021/08/25.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#define FOR(i,n) for(int i=0; i<(n); i++)

using namespace std;

vector<string> split(string s, char c){
    stringstream ss(s);
    vector<string> v;
    string temp = "";
    while (getline(ss, temp, c)) {
        v.push_back(temp);
    }
    return v;
}
string solution(string m, vector<string> musicinfos) {
    //init
    string answer = "";
    int answerLen = -1;
    
    //음악 정보 순서대로 보기
    FOR(i, musicinfos.size()){
        vector<string> result = split(musicinfos[i], ',');
        int hour = stoi(result[1].substr(0,2)) - stoi(result[0].substr(0,2));
        int wholetime = stoi(result[1].substr(3,-1)) + (hour*60) -stoi(result[0].substr(3,-1)); //음악 재생시간

        int play = 0;
        int shop = 0;
        string sounds = "";
        
        while(play-shop < wholetime){
            sounds.push_back(result[3][play%result[3].size()]);
            if(result[3][play%result[3].size()] == '#'){ shop++; }
            play ++;
        }
        
        if(result[3][play%result[3].size()] == '#') {
            sounds.push_back(result[3][ play%result[3].size()]);
        }
        
        //cout << sounds << endl;
        
        long soundFind = -1;
        while(sounds.find(m) != string::npos){
            soundFind = sounds.find(m);
            if(soundFind >=0 && soundFind < sounds.size()){
                //cout << soundFind + m.size() << endl;
                if(soundFind + m.size() == sounds.size()){//마지막
                    if(answerLen < wholetime){
                        answerLen = wholetime;
                        answer = result[2];
                        break;
                    }
                }
                else{//마지막 아니라면
                    if(sounds[soundFind + m.size()] != '#'){
                        if(answerLen < wholetime){
                            answerLen = wholetime;
                            answer = result[2];
                            break;
                        }
                    }
                }
            }
            sounds = sounds.substr(soundFind+m.size()-1,-1);
        }
    }
    
    if(answerLen == -1) { return "(None)"; }
    return answer;
}

int main() {
    string m = "CCB";
    vector<string> musicinfos = {"03:00,03:10,FOO,CCB#CCB", "04:00,04:08,BAR,ABC"};
    
    cout << solution(m, musicinfos);

    return 0;
}
