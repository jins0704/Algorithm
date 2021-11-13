//
//  main.swift
//  문자열압축_Swift
//
//  Created by 홍진석 on 2021/11/13.
//

import Foundation

func solution(_ s:String) -> Int {
    let str = Array(s)
    var answer = s.count
    var i = 1
    
    while(i == 1 || i <= s.count/2) {
        var word = ""
        var queue = [String]()
        var cnt = 0
        
        for j in 0..<str.count{
            word += String(str[j])
            if word.count == i {
                if !queue.isEmpty && queue.last != word {
                    cnt += i
                    if queue.count != 1 { cnt += String(queue.count).count }
                    queue.removeAll()
                }
                queue.append(word)
                word = ""
            }
        }
        
        if !queue.isEmpty {
            cnt += i
            if queue.count != 1 { cnt += String(queue.count).count }
        }
        cnt += s.count%i
        i += 1
        
        answer = min(answer, cnt)
    }
    
    return answer
}


print(solution("a"))

