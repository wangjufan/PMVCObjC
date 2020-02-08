//
//  PMVCTableViewMediator.h
//  PMVCObjC
//
//  Created by jufan wang on 2020/2/9.
//  Copyright © 2020 jufan wang. All rights reserved.
//

#ifndef PMVCTableViewMediator_h
#define PMVCTableViewMediator_h

#import <UIKit/UIKit.h>
#import "PMVCMediatorProtocol.h"


@protocol PMVCTableViewMediator <PMVCMediatorProtocol>


- (void)pmvcTableView:(UITableView *)tableView cellWillAppear:(UITableViewVell *)cell;
- (void)pmvcTableView:(UITableView *)tableView cellWillDisappear:(UITableViewVell *)cell;

/* The following two methods take replace of
 - (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath;
 - (void)tableView:(UITableView *)tableView didDeselectRowAtIndexPath:(NSIndexPath *)indexPath API_AVAILABLE(ios(3.0));
 */
- (void)pmvcTableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath itemModel:(id)model;
- (void)pmvcTableView:(UITableView *)tableView didDeselectRowAtIndexPath:(NSIndexPath *)indexPath itemModel:(id)model;

@end

#endif /* PMVCTableViewMediator_h */
