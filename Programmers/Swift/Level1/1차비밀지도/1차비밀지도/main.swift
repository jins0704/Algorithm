//
//  main.swift
//  1차비밀지도
//
//  Created by 홍진석 on 2021/08/08.
//

import Foundation

func makeBinary(_ num : Int, _ size : Int) -> [Int]{
    var binary = [Int](repeating: 0, count: size)
    var idx = size-1
    var n = num

    while(n >= 1){
        binary[idx] = n%2
        n /= 2; idx-=1
    }
   
    return binary
    
}

func makeResult(_ arr1:[Int], _ arr2:[Int]) -> String{
    var ans = ""
    for i in 0..<arr1.count {
        if arr1[i] == 1 || arr2[i] == 1 { ans.append("#") }
        else{ ans.append(" ") }
    }
    return ans
}

func solution(_ n:Int, _ arr1:[Int], _ arr2:[Int]) -> [String] {
    var answer: [String] = []
    for i in 0..<arr1.count {
        answer.append(makeResult(makeBinary(arr1[i],n), makeBinary(arr2[i],n)))
    }
    
    return answer
}

print(solution(5, [9,20,28,18,11], [30,1,21,17,28]))
