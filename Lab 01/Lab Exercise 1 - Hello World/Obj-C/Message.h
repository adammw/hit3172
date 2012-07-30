#import <Foundation/Foundation.h>

@interface Message : NSObject {
   NSString *_text;
 }

-(id) initWithText:(NSString *)txt;

-(void) print;

@end