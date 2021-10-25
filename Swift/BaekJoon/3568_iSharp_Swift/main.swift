//
//  main.swift
//  3568_iSharp_Swift
//
//  Created by 홍진석 on 2021/10/25.
//

import Foundation

let iType = ["]", "[", "*", "&"]
let input = readLine()
var answer = [(String,String)]()
let info = input!.split(separator: " ")

for (idx,i) in info.enumerated() {
    if idx == 0 { continue }
    
    let type = i.filter {
        iType.contains(String($0))
    }.replacingOccurrences(of: "[]", with: "][")
    
    let alpha = i.filter { $0.isLetter }
    
    answer.append((String(type.reversed()),String(alpha)))
}


for a in answer {
    print(info[0] + a.0 + " " + a.1 + ";")
}
