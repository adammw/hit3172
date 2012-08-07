#include "message.h"
#include <iostream>		//for cout

message::message(string txt) {
	_text = txt;
}

void message::print() {
	cout << _text << endl;
}