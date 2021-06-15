//
//  main.cpp
//  String
//
//  Created by 홍진석 on 2021/06/15.
//

#include <iostream>
//#include <string>
#include <algorithm>
using namespace std;

int main() {
    
    string sentence = "hello string";
    cout << sentence << endl;
    
    //삭제*******
    sentence.erase(0,6);
        //index 0부터 5까지 삭제
    cout << sentence << endl;
    sentence.insert(3, "ggg");
        //index 3번째 자리에 gg추가
    cout << sentence << endl;
   
    //추가*******
    sentence.append("oo"); //sentence 가장 뒤에 추가
        //sentence.push_back('o');
        //sentence.push_back('o');  vector의 형태로 push_back 가능
        //문자열끼리 합치기 가능
    cout << sentence << endl;
    
    //특정 문자열 제거*******
    string sentence2 = "reomove a particular char";
    sentence2.erase(remove(sentence2.begin(), sentence2.end(), 'a'), sentence.end());
        //특정문자 'a' 제거
    cout << sentence2 << endl;
    
    //문자열 정수로 변환*******
    string ten = "10";
    string twopointfive = "22325";
    
    cout << stoi(ten) << endl;
    cout << stoi(twopointfive)<< endl;
        //stoi는 앞에서부터 숫자까지만 인식하여 정수로 변환
    
    const char* char_num = twopointfive.c_str();
    cout << atoi(char_num) << endl;
        //atoi는 char 배열에 사용
    
    //특정 문자 찾아 바꾸기******
    string sentence3 = "hello good hello";
    string replace_str = "bye";
    cout << sentence3.find("good") << endl;
        // 조회 : 찾은 문자 시작하는 인덱스 알려줌 => 6
    sentence3.replace(sentence3.find("he"), 2, replace_str);
        //가장 먼저 찾은 부분만 바꾼다. => byello good hello
    cout << sentence3 << endl;
    
    //문자열 비교*******
    string compare_str = "my name is jin";
    string compare_str2 = "my name is jin";
    
    cout << compare_str.compare(compare_str2) << endl;
        //같다면 0 출력
    
    //문자열 추출*******
    string phone_num = "01012345678";
    string sub_num = phone_num.substr(2,2); //2부터 5개
    string sub_num2 = phone_num.substr(8,phone_num.size()); //8부터 끝까지
    cout << sub_num << endl;
    cout << sub_num2 << endl;
    
    

    
    return 0;
}
