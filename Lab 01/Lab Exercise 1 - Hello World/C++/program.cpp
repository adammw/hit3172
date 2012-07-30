#include "message.h"

int main() {
	message *msg1 = new message("Hello World");
	message *msg2 = new message("This is a C++ program");
	message *msg3 = new message("With 3 Message objects");

	msg1->print();
	msg2->print();
	msg3->print();
	return 0;
}