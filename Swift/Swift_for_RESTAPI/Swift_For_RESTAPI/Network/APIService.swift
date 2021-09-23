//
//  APIService.swift
//  Swift_For_RESTAPI
//
//  Created by 홍진석 on 2021/09/23.
//

import Foundation
import Alamofire

struct APIService {
    static let shared = APIService()
    
    let myHeader : HTTPHeaders = ["X-Auth-Token" : "b88c310b545521df00b31d0c2b7293bb", "Content-Type" : "application/json"]
    
    func startService(problem : Problem, completion: @escaping (Any) -> Void) {
        
        let param = RequestHandler.shared.makeParameter(model: problem)
        
        RequestHandler.shared.requestData(url: APIConstants.startURL, httpmethod: .post, param: param, header: myHeader, decodeType: StartResponse.self) { response in
            completion(response)
        }
    }
}
