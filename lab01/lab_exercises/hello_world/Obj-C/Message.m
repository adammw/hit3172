#import "Message.h"

@implementation Message

-(id) initWithText:(NSString *)txt {
	if ( self = [super init] ) {
		_text = txt;
	}
	return self; 
}

-(void) print {
   	printf("%s\n", [_text UTF8String]);
}

@end