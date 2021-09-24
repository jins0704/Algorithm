//
//  main.swift
//  타겟넘버
//
//  Created by 홍진석 on 2021/09/24.
//

import Foundation

var answer : Int = 0
var numbers : [Int] = [1, 1, 1, 1, 1]
var target = 3
print(solution(numbers, target))

func dfs(_ numbers:[Int], _ target:Int, _ sum:Int, _ cnt:Int) -> Void {
    
    if cnt == numbers.count {
        if sum == target{ answer += 1 }
        return
    }
    
    else{
        dfs(numbers, target, sum+numbers[cnt], cnt+1)
        dfs(numbers, target, sum-numbers[cnt], cnt+1)
    }
}

func solution(_ numbers:[Int], _ target:Int) -> Int {
    dfs(numbers, target, 0, 0)
    return answer
}
