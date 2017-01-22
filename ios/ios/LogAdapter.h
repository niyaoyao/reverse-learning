//
//  LogAdapter.h
//  ios
//
//  Created by NiYao on 1/22/17.
//  Copyright © 2017 suneny. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol TLogLogProtocol <NSObject>


@end

@interface LogAdapter : NSObject


+ (id)getInstance;
@property(retain, nonatomic) id <TLogLogProtocol> log; // @synthesize log=_log;

- (void)error:(id)arg1;
- (void)warn:(id)arg1;
- (void)info:(id)arg1;
- (void)debug:(id)arg1;
- (void)dealloc;
- (void)loadTlog;
- (id)init;

@end
