//
//  LoginAdapter.h
//  ios
//
//  Created by NiYao on 1/21/17.
//  Copyright © 2017 suneny. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AlipayHeader.h"

@class MtopExtRequest;

@protocol LoginProtocol <NSObject>
+ (id)sharedInstantce;
- (NSDictionary *)currentSession;
- (void)loginWithLoginOption:(int)arg1 extraInfo:(NSDictionary *)arg2 completionHandler:(void (^)(BOOL, NSDictionary *))arg3 cancelationHandler:(void (^)(void))arg4;
- (void)loginWithLoginOption:(int)arg1 completionHandler:(void (^)(BOOL, NSDictionary *))arg2 cancelationHandler:(void (^)(void))arg3;
- (BOOL)isValidLogin;

@optional
- (void)logout;
- (void)markInvalidLogin;
- (BOOL)isProcessingLogin;
@end

@interface LoginAdapter : NSObject

+ (id)sharedInstantce;
@property(retain, nonatomic) NSRecursiveLock *pending_lock; // @synthesize pending_lock=_pending_lock;
@property(retain, nonatomic) NSMutableArray *loginPendingRequests; // @synthesize loginPendingRequests=_loginPendingRequests;
@property(retain, nonatomic) id <LoginProtocol> login_service; // @synthesize login_service=_login_service;
@property(retain, nonatomic) id <LoginProtocol> network_config; // @synthesize network_config=_network_config;

- (void)storeSessionWithLoginResult:(id)arg1;
- (id)currentUserId;
- (void)notifyNetworkSDK:(id)arg1;
- (void)logout:(id)arg1;
- (void)logined:(id)arg1;
- (void)loadAlu:(Class)arg1;
- (void)loadLoginModule;
- (void)loadNetworSDKConfig;
- (void)failedPendingLoginRequests;
- (void)redoPendingLoginRequests;
- (void)pendingLoginRequest:(id)arg1;
- (void)releasePendingLock;
- (void)accquirePendingLock;
- (void)releaseLoginLock;
- (BOOL)accquireLoginLock;
- (int)tryLogin:(id)arg1 isForce:(BOOL)arg2;
- (int)tryLogin:(id)arg1;
- (void)logout;
- (id)currentSession;
- (NSInteger)loginWithLoginOption:(int)option
                          isForce:(BOOL)isForce
                        extraInfo:(NSDictionary *)extraInfo
                completionHandler:(AlipayCompletionHandler)completionHandler
               cancelationHandler:(AlipayCancelationHandler)cancelationHandler
                          request:(MtopExtRequest *)request;
- (void)loginWithLoginOption:(int)arg1 extraInfo:(id)arg2 completionHandler:(CDUnknownBlockType)arg3 cancelationHandler:(CDUnknownBlockType)arg4;
- (void)loginWithLoginOption:(int)arg1 completionHandler:(CDUnknownBlockType)arg2 cancelationHandler:(CDUnknownBlockType)arg3;
- (BOOL)isValidLogin;
- (BOOL)isProcessingLogin;
- (void)markInvalidLogin;
- (id)setCustomLoginModule:(id)arg1;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned int hash;
@property(readonly) Class superclass;


@end
