//
//  UIResponder+PMVC.m
//  PMVCObjC
//
//  Created by jufan wang on 2020/2/8.
//  Copyright © 2020 jufan wang. All rights reserved.
//

#import "UIResponder+PMVC.h"

#import <objc/runtime.h>
#import <fishhook/fishhook.h>

@interface UIResponderPMVCBridger : NSObject
@property (nonatomic, weak) id<PMVCMediatorProtocol> mediator;
@end
@implementation UIResponderPMVCBridger
@synthesize mediator = _mediator;
@end

@implementation UIResponder(PMVC)

- (UIResponderPMVCBridger *)PMVCBridger {
    UIResponderPMVCBridger * bridger = objc_getAssociatedObject(self, @selector(nextPMVCMediator));;
    if (!bridger) {
        bridger = [[UIResponderPMVCBridger alloc] init];
        objc_setAssociatedObject(self, @selector(nextPMVCMediator), bridger, OBJC_ASSOCIATION_RETAIN);
    }
    return bridger;
}

- (id<PMVCMediatorProtocol>)nextPMVCMediator {
    UIResponderPMVCBridger *bridger = [self PMVCBridger];
    if (!bridger.mediator) {
        UIResponder * rsp = [self nextResponder];
        while (rsp && ![rsp conformsToProtocol:NSProtocolFromString(@"PMVCMediatorProtocol")]) {
            rsp = [self nextResponder];
        }
        bridger.mediator = (id<PMVCMediatorProtocol>)rsp;
    }
    return bridger.mediator;
}

@end
