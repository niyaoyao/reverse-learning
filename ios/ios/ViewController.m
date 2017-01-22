//
//  ViewController.m
//  ios
//
//  Created by NiYao on 1/19/17.
//  Copyright © 2017 suneny. All rights reserved.
//

#import "ViewController.h"
#import <SystemConfiguration/CaptiveNetwork.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    NSLog(@"Hello, World!");
    NSArray *supportedInterfaces = (__bridge_transfer id)CNCopySupportedInterfaces();
    for (NSObject *object in supportedInterfaces) {
        NSLog(@"%@,%@\n", object, [object class]);
    }
    NSString *networkNameNS = [supportedInterfaces objectAtIndex:0];
    CFStringRef networkName = (__bridge CFStringRef)networkNameNS;
    NSDictionary *networkInfo = (__bridge_transfer id)CNCopyCurrentNetworkInfo(networkName);
    NSLog(@"%@", networkInfo);
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
