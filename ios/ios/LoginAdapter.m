//
//  LoginAdapter.m
//  ios
//
//  Created by NiYao on 1/21/17.
//  Copyright © 2017 suneny. All rights reserved.
//

#import "LoginAdapter.h"
#import "LogAdapter.h"
#import "MtopExtRequest.h"

@implementation LoginAdapter

- (NSInteger)loginWithLoginOption:(int)option
                    isForce:(BOOL)isForce
                  extraInfo:(NSDictionary *)extraInfo
           completionHandler:(AlipayCompletionHandler)completionHandler
          cancelationHandler:(AlipayCancelationHandler)cancelationHandler
                     request:(MtopExtRequest *)request {
    // self 是当前实例指针，a2 对应方法选择器，a3 对应方法参数 option; a4 对应方法参数 isForce; a5 对应方法参数 extraInfo;
    // a6 对应方法参数 completionHandler; a7 对应方法参数 cancelationHandler; a8 对应方法参数 request
    NSInteger returnValue = 0; // v18
   
    if (!self.login_service) {
        returnValue = 0;
    }
    
    if (request) {
        [self accquirePendingLock];
    }
    
    if ([self accquireLoginLock]) {
        
        if (extraInfo || ![self isValidLogin]) {
            if (request) {
                [self pendingLoginRequest:request];
            }
            
            LogAdapter *logAdapter = [LogAdapter getInstance];
            NSString *apiName = [request getApiName];
            NSString *apiVersion = [request getApiVersion];
            NSString *logString = [NSString stringWithFormat:@"[LoginAdapter] apiName: %@, apiVersion: %@ pull login module", apiName, apiVersion];
            [logAdapter warn:logString];
            
            [self.login_service loginWithLoginOption:option
                                           extraInfo:extraInfo
                                   completionHandler:completionHandler
                                  cancelationHandler:cancelationHandler];
            
        } // extraInfo || ![self isValidLogin] end
        
        [self releaseLoginLock];
        
        if (completionHandler) {
            NSDictionary *currentSession = [self.login_service currentSession];
            completionHandler(1, currentSession);
        } else {
            // v38 = v8 即，对 self 进行 retain 操作，无需翻译成 oc 代码
        }
        
        returnValue = 3;
        
    } else {
        if (request) {
            
            if (self.loginPendingRequests.count) {
                returnValue = 0;
            } else {
                [self pendingLoginRequest:request];
                returnValue = 1;
            }
            
        } else {
            returnValue = 0;
        }
        
        if (completionHandler) {
            completionHandler(0, [NSDictionary dictionary]);
        } else {
            completionHandler = nil;
        }
    }
    
    if (request) {
        [self releaseLoginLock];
    }
    
    return returnValue;
}

@end
