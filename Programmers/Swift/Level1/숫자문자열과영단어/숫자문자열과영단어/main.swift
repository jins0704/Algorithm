//
//  main.swift
//  숫자문자열과영단어
//
//  Created by 홍진석 on 2021/08/07.
//

import Foundation

//s.replacingOccurrences -> 알아보기

func checkword(word : String) -> (Bool,Character){
    switch word {
    case "zero": return (true,"0")
    case "one": return (true,"1")
    case "two": return (true,"2")
    case "three": return (true,"3")
    case "four": return (true,"4")
    case "five": return (true,"5")
    case "six": return (true,"6")
    case "seven": return (true,"7")
    case "eight": return (true,"8")
    case "nine": return (true,"9")
    default: return (false,"0")
    }
}

func solution(_ s:String) -> Int {
    var answer : String =  ""
    var word : String = ""
    for c in s{
        if c.isNumber {answer.append(c)}
        else{
            word.append(c)
            let result = checkword(word: word)
            if(result.0) {
                answer.append(result.1)
                word = ""
            }
        }
    }

    return Int(answer) ?? 0
}

solution("1zerotwozero3");
