#include <string>		// for std::string

using namespace std;	// string now = std::string

class message {
private:
	string _text;

public:
	message(string txt);

	void print();
};
