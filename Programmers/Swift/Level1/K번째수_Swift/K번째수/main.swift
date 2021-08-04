//
//  main.swift
//  K번째수
//
//  Created by 홍진석 on 2021/08/04.
//

import Foundation

typealias command = (first : Int, second : Int, Idx : Int)

func solution(_ array:[Int], _ commands:[[Int]]) -> [Int] {
    var answer : [Int] = []
    for i in commands {
        let c : command = (i[0]-1, i[1]-1, i[2])
        let subArray = array[c.first ... c.second].sorted()
        answer.append(subArray[c.Idx])
    }
    return answer
}
