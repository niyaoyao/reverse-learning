//
//  AlipayHeader.h
//  ios
//
//  Created by NiYao on 1/22/17.
//  Copyright © 2017 suneny. All rights reserved.
//

typedef void (^CDUnknownBlockType)(NSError *error, id response);
typedef void (^AlipayCompletionHandler)(BOOL boolResult, NSDictionary *dictionary);
typedef void (^AlipayCancelationHandler)();
