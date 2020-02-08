//
//  UITableView+PMVC.m
//  PMVCObjC
//
//  Created by jufan wang on 2020/2/9.
//  Copyright © 2020 jufan wang. All rights reserved.
//

#import "UITableView+PMVC.h"

#import "UIResponder+PMVC.h"
#import "PMVCTableViewMediator.h"

#import <objc/runtime.h>


@implementation UITableView(PMVC)

+ (void)load {
    Method fromMethod = class_getInstanceMethod([self class], @selector(dequeueReusableCellWithIdentifier:));
    Method toMethod = class_getInstanceMethod([self class], @selector(pmvc_dequeueReusableCellWithIdentifier:));
    method_exchangeImplementations(fromMethod, toMethod);
    
    fromMethod = class_getInstanceMethod([self class], @selector(dequeueReusableCellWithIdentifier:forIndexPath:));
    toMethod = class_getInstanceMethod([self class], @selector(pmvc_dequeueReusableCellWithIdentifier:forIndexPath:));
    method_exchangeImplementations(fromMethod, toMethod);
}

- (UITableViewCell *)pmvc_dequeueReusableCellWithIdentifier:(NSString *)identifier {
    UITableViewCell * cell = [self pmvc_dequeueReusableCellWithIdentifier:identifier];
    id<PMVCTableViewMediator> mediator = (id<PMVCTableViewMediator>)self.nextPMVCMediator;
    if ([mediator respondsToSelector:@selector(pmvcTableView:cellWillAppear:)]) {
        [mediator pmvcTableView:self cellWillAppear:cell];
    }
    return cell;
}

- (UITableViewCell *)pmvc_dequeueReusableCellWithIdentifier:(NSString *)identifier
                                               forIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell * cell = [self pmvc_dequeueReusableCellWithIdentifier:identifier forIndexPath:indexPath];
    id<PMVCTableViewMediator> mediator = (id<PMVCTableViewMediator>)self.nextPMVCMediator;
    if ([mediator respondsToSelector:@selector(pmvcTableView:cellWillAppear:)]) {
        [mediator pmvcTableView:self cellWillAppear:cell];
    }
    return cell;
}


@end

