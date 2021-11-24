//
//  main.swift
//  모의고사
//
//  Created by 홍진석 on 2021/08/04.
//

import Foundation

func solution(_ answers:[Int]) -> [Int] {
    var answer : [Int] = []
    var cnt : [Int] = [0,0,0]
    
    let one : [Int] = [1,2,3,4,5]
    let two : [Int] = [2,1,2,3,2,4,2,5]
    let three : [Int] = [3,3,1,1,2,2,4,4,5,5]
    
    for i in 0..<answers.count{
        if one[i%5] == answers[i] { cnt[0] += 1 }
        if two[i%8] == answers[i] { cnt[1] += 1 }
        if three[i%10] == answers[i] { cnt[2] += 1 }
    }
    
    for i in 0..<cnt.count{
        if cnt[i] == cnt.max() {
            answer.append(i+1)
        }
    }
    
    return answer
}

  print(solution([1,2,3,4,5]))
