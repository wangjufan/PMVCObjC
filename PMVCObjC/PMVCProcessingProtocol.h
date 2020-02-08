//
//  PMVCProcessingProtocol.h
//  PMVCObjC
//
//  Created by jufan wang on 2020/2/8.
//  Copyright © 2020 jufan wang. All rights reserved.
//

#ifndef PMVCProcessingProtocol_h
#define PMVCProcessingProtocol_h

@protocol PMVCProcessingProtocol <NSObject>

- (id<PMVCProcessingProtocol>)nextPMVCProcessor;

@end


#endif /* PMVCProcessingProtocol_h */
