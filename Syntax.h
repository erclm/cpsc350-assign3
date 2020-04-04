#include "GetFile.h"
#include "GenStack.h"
using namespace std;

class Syntax
{
public:
	Syntax(string file);
	~Syntax();
	bool check();
	char opposite(char x);
	GetFile *out;
	GenStack<char> *myStack;
};
