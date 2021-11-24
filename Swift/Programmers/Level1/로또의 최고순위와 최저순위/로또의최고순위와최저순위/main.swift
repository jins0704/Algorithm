//
//  main.swift
//  로또의최고순위와최저순위
//
//  Created by 홍진석 on 2021/08/03.
//

import Foundation

func solution(_ lottos:[Int], _ win_nums:[Int]) -> [Int] {
    var best = 7
    var worst = 7

    for i in lottos{
        if(i == 0){ best -= 1 }
        if(win_nums.contains(i)){
            worst -= 1; best -= 1
        }
    }
    return [best == 7 ? 6 : best,  worst == 7 ? 6 : worst]

}
