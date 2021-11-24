//
//  main.swift
//  기능개발
//
//  Created by 홍진석 on 2021/08/05.
//

import Foundation

typealias workInfo = (Int,Int)

func solution(_ progresses:[Int], _ speeds:[Int]) -> [Int] {
    
    var day = 0;
    var answer : [Int] = []
    var work : [workInfo] = []
    
    for i in 0..<progresses.count { work.append((progresses[i], speeds[i])) }
    
    while !work.isEmpty {
        var release = 0
        day += 1
        
        while !work.isEmpty && work[0].0 + day * work[0].1 >= 100 {
            release += 1
            work.removeFirst()
        }
        if release > 0 { answer.append(release) }
    }
    
    return answer
}
