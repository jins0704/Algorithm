//
//  RequestHandler.swift
//  Swift_For_RESTAPI
//
//  Created by 홍진석 on 2021/09/23.
//

import Foundation
import Alamofire

struct RequestHandler {
    static let shared = RequestHandler()
    
    func judgeStatus<T: Codable>(by statusCode: Int, _ data: Data, _ decodeType: T.Type) -> NetworkResult<Any> {
        let decoder = JSONDecoder()
        
        guard let decodedData = try? decoder.decode(decodeType, from: data)
        else { return .paramErr }
        
        switch statusCode {
        case 200: return .success(decodedData)
        case 400: return .paramErr
        case 401: return .authErr
        default: return .serverErr
        }
    }
    
    func makeParameter<T: Codable>(model: T) -> [String: Any]? {
        let jsonEncoder = JSONEncoder()
        guard let jsonData = try? jsonEncoder.encode(model) else { return nil }
        guard let dictionary = try? JSONSerialization.jsonObject(with: jsonData, options: []) as? [String: Any] else { return nil }
        
        return dictionary
    }
    
    func requestData<T: Codable>(url: String, httpmethod: HTTPMethod, param: Parameters?, header: HTTPHeaders, decodeType: T.Type, completion: @escaping (NetworkResult<Any>) -> Void) {
        
        let dataRequest = AF.request(url,
                                     method: httpmethod,
                                     parameters: param,
                                     encoding: JSONEncoding.default,
                                     headers: header).validate(statusCode: 200 ... 500)
        dataRequest.responseData { response in
            print(response)
            switch response.result {
            case .success:
                guard let statusCode = response.response?.statusCode else { return }
                print(statusCode)
                guard let value = response.value else { return }
        
                let networkResult = self.judgeStatus(by: statusCode, value, decodeType)
                
                completion(networkResult)
            case .failure:
                completion(.serverErr)
            }
        }
    }
}
