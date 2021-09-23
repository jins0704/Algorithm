//
//  Extension_String.swift
//  Swift_For_RESTAPI
//
//  Created by 홍진석 on 2021/09/23.
//

import Foundation

extension String {
    func getChar(at index: Int) -> Character {
        return self[self.index(self.startIndex, offsetBy: index)]
    }
    
    subscript(_ range: Range<Int>) -> String {
        let fromIndex = self.index(self.startIndex, offsetBy: range.startIndex)
        let toIndex = self.index(self.startIndex,offsetBy: range.endIndex)
        
        return String(self[fromIndex..<toIndex])
    }
}
