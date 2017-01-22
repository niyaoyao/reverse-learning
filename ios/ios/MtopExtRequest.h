//
//  MtopExtRequest.h
//  ios
//
//  Created by NiYao on 1/22/17.
//  Copyright © 2017 suneny. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AlipayHeader.h"

@class UTDataSet;
@class MtopExtRequest;
@class MtopExtResponse;
@class TBSDKRequest;

@protocol MtopExtRequestDelegate <NSObject>

@optional
- (void)succeed:(MtopExtResponse *)arg1;
- (void)failed:(MtopExtResponse *)arg1;
- (void)started:(MtopExtRequest *)arg1;
@end

@interface MtopExtRequest : NSObject

@property(retain, nonatomic) NSString *request_id; // @synthesize request_id=_request_id;
@property(nonatomic) BOOL isNotUseMainThreadCallback; // @synthesize isNotUseMainThreadCallback=_isNotUseMainThreadCallback;
@property(nonatomic) BOOL isNeedValidateResponse; // @synthesize isNeedValidateResponse=_isNeedValidateResponse;
@property(nonatomic) int serverType; // @synthesize serverType=_serverType;
@property(retain, nonatomic) UTDataSet *mtopUT; // @synthesize mtopUT=_mtopUT;
@property(nonatomic) BOOL retryCount; // @synthesize retryCount=_retryCount;
@property(nonatomic) __weak id context; // @synthesize context=_context;
@property(copy) CDUnknownBlockType succeedBlock; // @synthesize succeedBlock=_succeedBlock;
@property(copy) CDUnknownBlockType failedBlock; // @synthesize failedBlock=_failedBlock;
@property(copy) CDUnknownBlockType startedBlock; // @synthesize startedBlock=_startedBlock;
@property BOOL isCanceled; // @synthesize isCanceled=_isCanceled;
@property(retain, nonatomic) NSString *customHost; // @synthesize customHost=_customHost;
@property(nonatomic) float yCoordinate; // @synthesize yCoordinate=_yCoordinate;
@property(nonatomic) float xCoordinate; // @synthesize xCoordinate=_xCoordinate;
@property(retain, nonatomic) NSString *wuaCtrlName; // @synthesize wuaCtrlName=_wuaCtrlName;
@property(retain, nonatomic) NSString *wuaPageName; // @synthesize wuaPageName=_wuaPageName;
@property(nonatomic) BOOL isEnableWUA; // @synthesize isEnableWUA=_isEnableWUA;
@property(nonatomic) BOOL isNeedEcode; // @synthesize isNeedEcode=_isNeedEcode;
@property(nonatomic) BOOL isSync; // @synthesize isSync=_isSync;
@property(nonatomic) BOOL isForceSpdy; // @synthesize isForceSpdy;
@property(nonatomic) BOOL isForceHttps; // @synthesize isForceHttps;
@property(retain, nonatomic) NSString *ttid; // @synthesize ttid;
@property __weak id <MtopExtRequestDelegate> delegate; // @synthesize delegate;
@property(retain, nonatomic) TBSDKRequest *mrequest; // @synthesize mrequest;
@property(nonatomic) BOOL isFromOfflineOperation; // @synthesize isFromOfflineOperation;
@property(retain, nonatomic) NSMutableArray *excludedCacheKeyParameters; // @synthesize excludedCacheKeyParameters;
@property(nonatomic) int cachePolicy; // @synthesize cachePolicy;
@property(nonatomic) int sessionExpiredOption; // @synthesize sessionExpiredOption;

- (void)useCustomHostIfNeed;
- (id)nextId;
- (BOOL)isNeedCallback;
- (void)cancel;
- (void)utJsonParseEndTime;
- (void)utJsonParseStartTime;
- (void)utEnd;
- (void)utStart:(BOOL)arg1;
- (BOOL)isNeedRetry;
- (void)retryed;
- (BOOL)isUseHttps;
- (BOOL)isUseHttpPost;
- (id)getBizParameters;
- (id)getExtParameters;
- (void)setApiVersion:(id)arg1;
- (void)setApiName:(id)arg1;
- (id)getApiVersion;
- (id)getApiName;
- (id)getRequestId;
- (id)enableWUAWithPageName:(id)arg1 ctrlName:(id)arg2 xCoordinate:(float)arg3 yCoordinate:(float)arg4;
- (id)enableWUA;
- (id)addExcludedCacheKeyParameter:(id)arg1;
- (id)addUploadFileWithData:(id)arg1 fileName:(id)arg2 forKey:(id)arg3;
- (id)clearBizParameters;
- (id)removeBizParameter:(id)arg1;
- (id)addBizParameters:(id)arg1;
- (id)addBizParameter:(id)arg1 forKey:(id)arg2;
- (id)removeExtParameter:(id)arg1;
- (id)addExtParameters:(id)arg1;
- (id)addExtParameter:(id)arg1 forKey:(id)arg2;
- (id)addProtocolParameter:(id)arg1 forKey:(id)arg2;
- (id)addHttpHeaders:(id)arg1;
- (id)addHttpHeader:(id)arg1 forKey:(id)arg2;
- (id)useHttpPost;
- (id)disableHttps;
- (id)useHttps;
- (id)setNetworkTimeout:(int)arg1;
- (void)dealloc;
- (id)initWithApiName:(id)arg1 apiVersion:(id)arg2;


@end

@class TBSDKConnection;

@protocol TBSDKConnectionDelegate <NSObject>

@optional
- (void)proxyAuthenticationNeededForRequest:(TBSDKConnection *)arg1;
- (void)authenticationNeededForRequest:(TBSDKConnection *)arg1;
- (void)request:(TBSDKConnection *)arg1 didReceiveData:(NSData *)arg2;
- (void)requestRedirected:(TBSDKConnection *)arg1;
- (void)requestFailed:(TBSDKConnection *)arg1;
- (void)requestNetworkDataSet:(NSDictionary *)arg1 withFinishedTime:(double)arg2;
- (void)requestFinished:(TBSDKConnection *)arg1;
- (void)request:(TBSDKConnection *)arg1 willRedirectToURL:(NSURL *)arg2;
- (void)request:(TBSDKConnection *)arg1 didReceiveResponseHeaders:(NSDictionary *)arg2;
- (void)requestStarted:(TBSDKConnection *)arg1;
@end

@protocol TBSDKProgressDelegate <NSObject>

@optional
- (void)request:(TBSDKConnection *)arg1 incrementUploadSizeBy:(long long)arg2;
- (void)request:(TBSDKConnection *)arg1 incrementDownloadSizeBy:(long long)arg2;
- (void)request:(TBSDKConnection *)arg1 didSendBytes:(long long)arg2;
- (void)request:(TBSDKConnection *)arg1 didReceiveBytes:(long long)arg2;
- (void)setProgress:(float)arg1;
@end

@protocol TBSDKRequestProgressProtocol <NSObject>

@end

@protocol TBSDKRequestDataSource <NSObject>

@end

@protocol TBSDKRequestDelegate <NSObject>

@end

@interface TBSDKRequest : NSObject <TBSDKConnectionDelegate, TBSDKProgressDelegate>

+ (id)urlEncode:(id)arg1;
+ (id)dict2QueryString:(id)arg1;
+ (void)cancelTBSDKAllRequest;
+ (void)initialize;

@property(retain, nonatomic) id context; // @synthesize context=_context;
@property(retain, nonatomic) NSString *unitPrefix; // @synthesize unitPrefix=_unitPrefix;
@property(nonatomic) BOOL isUseHttpPost; // @synthesize isUseHttpPost=_isUseHttpPost;
@property(nonatomic) BOOL isUseHttps; // @synthesize isUseHttps=_isUseHttps;
@property(retain, nonatomic) NSMutableArray *uploadFiles; // @synthesize uploadFiles=_uploadFiles;
@property(retain, nonatomic) NSMutableDictionary *bizParameters; // @synthesize bizParameters=_bizParameters;
@property(retain, nonatomic) NSMutableDictionary *extParameters; // @synthesize extParameters=_extParameters;
@property(retain, nonatomic) NSMutableDictionary *httpHeaders; // @synthesize httpHeaders=_httpHeaders;
@property(retain, nonatomic) NSMutableDictionary *protocolParameters; // @synthesize protocolParameters=_protocolParameters;
@property(retain, nonatomic) NSString *apiVersion; // @synthesize apiVersion=_apiVersion;
@property(retain, nonatomic) NSString *apiName; // @synthesize apiName=_apiName;
@property(retain, nonatomic) NSString *userId; // @synthesize userId=_userId;
@property(nonatomic) double networkFinishedTime; // @synthesize networkFinishedTime=_networkFinishedTime;
@property(nonatomic) double operationQueueTime; // @synthesize operationQueueTime=_operationQueueTime;
@property(retain, nonatomic) NSMutableDictionary *networkDataSet; // @synthesize networkDataSet=_networkDataSet;
@property(retain, nonatomic) NSArray *blackCacheKeyParam; // @synthesize blackCacheKeyParam=_blackCacheKeyParam;
@property(nonatomic) int gzipLimitedSize; // @synthesize gzipLimitedSize=_gzipLimitedSize;
@property(nonatomic) BOOL isAvalancheCache; // @synthesize isAvalancheCache=_isAvalancheCache;
@property(retain, nonatomic) NSString *apiMethod; // @synthesize apiMethod=_apiMethod;
@property(nonatomic) BOOL forceRefresh; // @synthesize forceRefresh=_forceRefresh;
@property(nonatomic) BOOL useHTTPCache; // @synthesize useHTTPCache=_useHTTPCache;
@property(retain, nonatomic) NSDictionary *requestHeaders; // @synthesize requestHeaders=_requestHeaders;
@property(readonly, nonatomic) NSDictionary *responseHeaders; // @synthesize responseHeaders=_responseHeaders;
@property(nonatomic) int responseStatusCode; // @synthesize responseStatusCode=_responseStatusCode;
@property(retain, nonatomic) NSString *responseString; // @synthesize responseString=_responseString;
@property(retain, nonatomic) NSData *responseData; // @synthesize responseData=_responseData;
@property(nonatomic) double timeOutSeconds; // @synthesize timeOutSeconds=_timeOutSeconds;
@property(retain, nonatomic) NSString *customHost; // @synthesize customHost=_customHost;
@property(retain, nonatomic) NSURL *url; // @synthesize url=_url;
@property(readonly, nonatomic) TBSDKConnection *request; // @synthesize request=_request;
@property(nonatomic) __weak id <TBSDKRequestProgressProtocol> requestProgressDelegate; // @synthesize requestProgressDelegate=_requestProgressDelegate;
@property(nonatomic) __weak id <TBSDKRequestDataSource> dataSource; // @synthesize dataSource=_dataSource;
@property(nonatomic) __weak id <TBSDKRequestDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain, nonatomic) NSError *error; // @synthesize error=_error;

- (id)getApiURL4Env;
- (id)getRequestURL;
- (void)reset;
- (void)addUploadFileWithData:(id)arg1 fileName:(id)arg2 forKey:(id)arg3;
- (void)removeBizParameter:(id)arg1;
- (void)addBizParameter:(id)arg1 forKey:(id)arg2;
- (void)removeExtParameter:(id)arg1;
- (void)addExtParameter:(id)arg1 forKey:(id)arg2;
- (void)addHttpHeader:(id)arg1 forKey:(id)arg2;
- (void)addProtocolParameter:(id)arg1 forKey:(id)arg2;
- (id)initWithApiName:(id)arg1 apiVersion:(id)arg2;
- (id)init;
- (void)clearResponseForCache;
- (void)request:(id)arg1 didSendBytes:(long long)arg2;
- (void)setProgress:(float)arg1;
- (void)request:(id)arg1 didReceiveData:(id)arg2;
- (void)requestFailed:(id)arg1;
- (void)requestFinished:(id)arg1;
- (void)requestNetworkDataSet:(id)arg1 withFinishedTime:(double)arg2;
- (void)request:(id)arg1 didReceiveResponseHeaders:(id)arg2;
- (void)requestStarted:(id)arg1;
- (void)installCookies:(id)arg1;
- (void)setResponse;
- (BOOL)isResponseCompressed;
- (void)cancelTBSDKAllRequest;
- (void)cancelRequest;
- (void)startAsynchronous;
- (BOOL)startSynchronous;
- (id)getMTOPCookies;
- (void)setCookies;
- (void)setRequestPostData;
- (void)setRequestPostValue;
- (void)setHTTPRequestHeader;
- (void)installRequest;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned int hash;
@property(readonly) Class superclass;

@end
