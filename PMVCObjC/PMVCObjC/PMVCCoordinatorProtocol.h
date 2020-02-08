//
//  PMVCCoordinatorProtocol.h
//  PMVCObjC
//
//  Created by jufan wang on 2020/2/8.
//  Copyright © 2020 jufan wang. All rights reserved.
//

#ifndef PMVCCoordinatorProtocol_h
#define PMVCCoordinatorProtocol_h

#import <Foundation/Foundation.h>

/*
 The coordinator takes control of horizontal process chain  in business .
 And it is hard to define a real protocol for it to follow.
 A coordinator encapsulate a case , a whole or port of flow .
 It owns kinds of functional components which did not know others at all .
 */

//@property (nonatomic, copy) void (^switchChangedBlock)(BOOL isOn);

@protocol PMVCCoordinatorProtocol <NSObject>

- (void)addChildCoordinator:(id<PMVCCoordinatorProtocol>)child; //thread safe
- (void)removeChildCoordinator:(id<PMVCCoordinatorProtocol>)child; //thread safe

- (void)beginProcessSuccess:(void (^)(id infor))success
                     failed:(void (^)(id error))failed;

- (void)beginProcess;
- (void)cancelProcess;

@end

#endif /* PMVCCoordinatorProtocol_h */
