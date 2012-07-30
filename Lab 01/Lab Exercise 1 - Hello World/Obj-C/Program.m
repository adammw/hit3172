#import "Message.h"

int main() {
	@autoreleasepool {
		Message *m = [[Message alloc]
			initWithText:@"Hello World"];
		[m print];
	}
	return 0;
}