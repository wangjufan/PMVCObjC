//
//  PMVCCoordinator.m
//  PMVCObjC
//
//  Created by jufan wang on 2020/2/8.
//  Copyright © 2020 jufan wang. All rights reserved.
//

#import "PMVCCoordinator.h"


@interface PMVCCoordinator()

@property (nonatomic, strong, readonly) NSMutableArray *childCoordinators;

@end


@implementation PMVCCoordinator

- (instancetype)initWithChildCoordinators:(id<PMVCCoordinatorProtocol, PMVCMediatorProtocol>)coordinators {
    if (self = [super init]) {
        _childCoordinators = [NSMutableArray array];
    }
    return self;
}


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-designated-initializers"
- (instancetype)init {
    return nil;
}
#pragma clang diagnostic pop


- (void)addChildCoordinator:(id<PMVCCoordinatorProtocol>)child {
    [self.childCoordinators addObject:child];
}

- (void)removeChildCoordinator:(id<PMVCCoordinatorProtocol>)child {
    if (child) {
        [self.childCoordinators removeObject:child];
    }
}

- (void)beginProcess {
    
}


- (void)beginProcessSuccess:(void (^)(id infor))success
                     failed:(void (^)(id error))failed{
    
}


- (void)cancelProcess {
    
}


@end

