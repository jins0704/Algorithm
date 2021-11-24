//
//  main.swift
//  가운데글자가져오기_Swift
//
//  Created by 홍진석 on 2021/08/06.
//

import Foundation

func solution(_ s:String) -> String {
    return s.count%2 == 0 ? String(Array(s)[(s.count/2)-1 ... (s.count/2)]) : String(Array(s)[s.count/2])
}
