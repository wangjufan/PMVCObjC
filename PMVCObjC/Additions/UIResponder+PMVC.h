//
//  UIResponder+PMVC.h
//  PMVCObjC
//
//  Created by jufan wang on 2020/2/8.
//  Copyright © 2020 jufan wang. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "PMVCMediatorProtocol.h"

NS_ASSUME_NONNULL_BEGIN


@protocol PMVCProcessProtocol <NSObject>

- (id<PMVCMediatorProtocol>)nextPMVCMediator;

@end


@interface UIResponder(PMVC)<PMVCProcessProtocol>

@end

NS_ASSUME_NONNULL_END
