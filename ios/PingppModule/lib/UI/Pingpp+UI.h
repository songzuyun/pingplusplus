//
//  Pingpp+UI.h
//  pingpp+UI
//
//  Created by Afon on 15/9/2.
//  Copyright (c) 2015年 pingplusplus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Pingpp.h"
#import "PingppURLResponse.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^PingppUICompletion)(NSString *result, PingppURLResponse * __nullable response, NSError * __nullable error);

typedef NS_OPTIONS(NSUInteger, PingppBtnOption) {
    PingppBtnAlipay = 1 << 0,
    PingppBtnWx = 1 << 1,
    PingppBtnUpacp = 1 << 2,
    PingppBtnUp = PingppBtnUpacp,
    PingppBtnBfbWap = 1 << 4,
    PingppBtnUpmp = 1 << 5,
    PingppBtnApplePayUpmp = 1 << 6,
    PingppBtnQPayUpmp = 1 << 7,
    PingppBtnCmbWallet = 1 << 8
};

typedef NS_ENUM(NSUInteger, PingppExtraChannel){
    PingppExtraChannelHuabei,
};
@interface Pingpp (UI)

/**
 *  调用「有支付渠道选择」
 *  @param  orderNo         订单号，请注意保证唯一性
 *  @param  amount          订单金额，单位为分。例：150 表示 1.5 元。
 *  @param  params          自定义参数，请求 chargeURL 时，会放在 custom_params 字段
 *  @param  chargeURL       壹收款会向该地址发送请求，该地址需要返回 charge 的 JSON 字符串
 *  @param  appURLScheme    Info.plist 中填写的 URL Scheme，支付宝渠道和测试模式需要
 *  @param  viewController  当前的 ViewController
 *  @param  handler         回调
 */
+ (void)payWithOrderNo:(NSString *)orderNo
                amount:(NSUInteger)amount
                params:(nullable NSDictionary *)params
             chargeURL:(NSString *)url
          appURLScheme:(nullable NSString *)scheme
        viewController:(UIViewController *)viewController
     completionHandler:(PingppUICompletion)handler;


/**
 *  调用「无支付渠道选择」
 *  @param  charge
 *  @param  appURLScheme    Info.plist 中填写的 URL Scheme，支付宝渠道和测试模式需要
 *  @param  viewController  当前的 ViewController
 *  @param  completion         回调
 */
+ (void)createPay:(nonnull NSObject *)charge
       viewController:(nonnull UIViewController*)viewController
         appURLScheme:(nonnull NSString*)appURLScheme
       withCompletion:(PingppCompletion) completion;



/**
 *  设置请求 charge 的 URL（会被上述方法的 chargeURL 覆盖）
 *  @param  chargeURLString  请求 charge 的 URL
 */
+ (void)setChargeURLString:(NSString *)chargeURLString;

/**
 *  获取当前设置的 chargeURLString
 *  @return  设置的 charge 的 URL
 */
+ (NSString *)chargeURLString;

/**
 *  设置需要显示的渠道按钮（有序）
 *  @param  channels  渠道数组，与 API 的 channel 字段对应。例: @[@"wx", @"alipay", @"upacp", @"bfb"]
 */
+ (void)enableChannels:(NSArray *)channels;

/**
 *  设置需要显示的渠道按钮（请用上面的方法代替）
 *  @param  option  渠道。例: PingppBtnAlipay|PingppBtnWx|PingppBtnUpacp|PingppBtnBfb
 */
+ (void)enableBtn:(PingppBtnOption)option;

/**
 *  设置已有渠道的扩展(如:花呗分期)
 *  @param extend 支付渠道的扩展 (如:花呗分期)
 *  @param index 改扩展渠道显示的位置
 */
+ (void) enableExtraChannel:(PingppExtraChannel)extend index:(NSInteger)index;

/**
 * 获取 壹收款 版本号
 */
+ (NSString *) getVersion;

@end

NS_ASSUME_NONNULL_END
