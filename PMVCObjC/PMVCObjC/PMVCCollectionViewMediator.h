//
//  PMVCCollectionViewMediator.h
//  PMVCObjC
//
//  Created by jufan wang on 2020/2/9.
//  Copyright © 2020 jufan wang. All rights reserved.
//

#ifndef PMVCCollectionViewMediator_h
#define PMVCCollectionViewMediator_h

#import <UIKit/UIKit.h>

#import "PMVCMediatorProtocol.h"

@protocol PMVCCollectionViewMediator <PMVCMediatorProtocol>

- (void)pmvcCollectionView:(UICollectionView *)collectionView cellWillAppear:(UICollectionViewVell *)cell;
- (void)pmvcCollectionView:(UICollectionView *)collectionView cellWillDisappear:(UICollectionViewVell *)cell;

/* The following four methods take replace of
 - (BOOL)collectionView:(UICollectionView *)collectionView shouldSelectItemAtIndexPath:(NSIndexPath *)indexPath;
 - (BOOL)collectionView:(UICollectionView *)collectionView shouldDeselectItemAtIndexPath:(NSIndexPath *)indexPath; // called when the user taps on an already-selected item in multi-select mode
 - (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath;
 - (void)collectionView:(UICollectionView *)collectionView didDeselectItemAtIndexPath:(NSIndexPath *)indexPath;
 */
- (void)pmvcCollectionView:(UICollectionView *)collectionView
        didSelectIndexPath:(NSIndexPath *)indexPath
                 itemModel:(id)model;

- (void)pmvcCollectionView:(UICollectionView *)collectionView
      didDeselectIndexPath:(NSIndexPath *)indexPath
                 itemModel:(id)model;

- (BOOL)pmvcCollectionView:(UICollectionView *)collectionView shouldSelectItemAtIndexPath:(NSIndexPath *)indexPath;

- (BOOL)pmvcCollectionView:(UICollectionView *)collectionView shouldDeselectItemAtIndexPath:(NSIndexPath *)indexPath;

@end


#endif /* PMVCCollectionViewMediator_h */
