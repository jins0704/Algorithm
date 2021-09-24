//
//  main.swift
//  짝지어제거하기
//
//  Created by 홍진석 on 2021/09/24.
//

import Foundation

func solution(_ s:String) -> Int{
    var temp = [Character]()
    let arr = Array(s)
    for i in 0..<arr.count{
        if temp.isEmpty {
            temp.append(arr[i])
        }
        else{
            if(temp.last != arr[i]) { temp.append(arr[i])}
            else{ temp.removeLast() }
        }
    }
    
    if temp.count == 0 {return 1}
    else { return 0 }
}

print(solution("baabaa"))
