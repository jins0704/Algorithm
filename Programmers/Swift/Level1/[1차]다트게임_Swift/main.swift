//
//  main.swift
//  [1차]다트게임_Swift
//
//  Created by 홍진석 on 2021/10/27.
//

import Foundation

func makeScore(_ num : String, _ i : String.Element) -> Int {
    let number = Int(num)!
    switch i {
    case "S" :
        return number
    case "D" :
        return number*number
    case "T" :
        return number*number*number
    default :
        return 0
    }
}

func solution(_ dartResult:String) -> Int {
    var answer = 0
    var num = ""
    var waitingQueue = [Int]()
    
    for i in dartResult {
        if i.isNumber {
            num.append(i)
        }
        else {
            if i == "*" {
                waitingQueue = waitingQueue.map{ $0*2 }
            }
            else if i == "#" {
                waitingQueue[waitingQueue.endIndex-1] *= -1
            }
            else {
                if !num.isEmpty {
                    waitingQueue.append(makeScore(num, i))
                    if waitingQueue.count == 3 {
                        answer += waitingQueue.removeFirst()
                    }
                    num = ""
                }
            }
        }
    }
    while !waitingQueue.isEmpty {
        answer += waitingQueue.removeFirst()
    }
    
    return answer
}

print(solution("1D2S#10S"))

//세번 던지기
//0~10점
//S, D, T - 1제곱. 2제곱, 3제곱
//* - 해당 점수와 바로 전에 얻은 점수 2배
//  - 처음 나오면 첫번째만 2배
//  - 중첩 가능
//# - 해당 점수 마이너스
//*# - -2배
