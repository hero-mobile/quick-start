//
//  BSD License
//  Copyright (c) Hero software.
//  All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without modification,
//  are permitted provided that the following conditions are met:
//
//  * Redistributions of source code must retain the above copyright notice, this
//  list of conditions and the following disclaimer.
//
//  * Redistributions in binary form must reproduce the above copyright notice,
//  this list of conditions and the following disclaimer in the documentation
//  and/or other materials provided with the distribution.
//
//  * Neither the name Facebook nor the names of its contributors may be used to
//  endorse or promote products derived from this software without specific
//  prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
//  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
//  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
//  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
//  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
//  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
//  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
//  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//  Created by 朱成尧 on 5/5/16.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, HeroUploadState){
    HeroUploadStateReady = 0,
    HeroUploadStateUploading = 1,
    HeroUploadStateUploaded = 2,
    HeroUploadStateCanceled = 3,
    HeroUploadStateFailed = 4,
};

@class HeroImageUploader;
@protocol HeroImageUploaderDelegate <NSObject>
@optional
- (void)upload:(HeroImageUploader *)uploader didSendFirstRespone:(NSURLResponse *)response;
- (void)upload:(HeroImageUploader *)uploader didSendData:(uint64_t)sendLength onTotal:(uint64_t)totalLength progress:(float)progress;
- (void)upload:(HeroImageUploader *)uploader didStopWithError:(NSError *)error;
- (void)upload:(HeroImageUploader *)uploader didFinishWithSuccessData:(id)data;


@end

@interface HeroImageUploader : NSOperation <NSURLConnectionDelegate, NSURLConnectionDataDelegate>

@property (nonatomic, weak) id<HeroImageUploaderDelegate> delegate;
@property (nonatomic) HeroUploadState state;
@property (nonatomic) float percentage;

- (instancetype)initWithURL:(NSURL *)URL data:(NSData *)data fileName:(NSString *)fileName delegate:(id)delegate;
- (void)cancel;

@end
