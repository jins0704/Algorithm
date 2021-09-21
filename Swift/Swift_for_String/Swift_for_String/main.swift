//
//  main.swift
//  Swift_for_String
//
//  Created by 홍진석 on 2021/09/21.
//

import Foundation

extension String {
    subscript(_ index: Int) -> Character {//index번째 char
        return self[self.index(self.startIndex, offsetBy: index)]
    }
    
    subscript(_ range: Range<Int>) -> String {//범위 문자열 뽑기
        let fromIndex = self.index(self.startIndex, offsetBy: range.startIndex)
        let toIndex = self.index(self.startIndex,offsetBy: range.endIndex)
        
        return String(self[fromIndex..<toIndex])
    }
}

let splitStr = "good,blog,jinShine"
let splitArr = splitStr.split(separator: ",") //문자열 추출
print(splitArr)
//splitArr.map { str in return print(str) }

var a : String = "12dd314"
a.filter{ $0.isNumber } //숫자 추출
print(a.contains("12"))
