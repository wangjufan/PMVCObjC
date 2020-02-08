//
//  PMVCCoordinator.h
//  PMVCObjC
//
//  Created by jufan wang on 2020/2/8.
//  Copyright © 2020 jufan wang. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PMVCCoordinatorProtocol.h"
#import "PMVCMediatorProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface PMVCCoordinator : NSObject<PMVCCoordinatorProtocol, PMVCMediatorProtocol>

- (instancetype)initWithChildCoordinators:(id<PMVCCoordinatorProtocol, PMVCMediatorProtocol>)coordinators NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
