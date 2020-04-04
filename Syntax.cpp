#include <iostream>
#include "Syntax.h"
using namespace std;

Syntax::Syntax(string file){
	out = new GetFile(file,"");
	myStack = new GenStack<char>();
}

Syntax::~Syntax()
{
	delete out;
	delete myStack;
}


char Syntax::opposite(char c)
{
  if(c ==')'){
    return '(';
  }else if(c =='}'){
    return '{';
  }else if(c ==']'){
    return '[';
  }

  if(c =='('){
    return ')';
  }else if(c =='{'){
    return '}';
  }else if(c =='['){
    return ']';
  }
}

//check mismatch
bool Syntax::check()
{
	int num = 1;
	bool checker = false;
	string line;
	line = out->nextLine();
	while (!(line=="$endl*%")){
		for (char& c : line){
			try{
				if (c == '(' || c == '{' || c == '['){
          myStack->push(c);
        }else if (c == ')' || c == '}' || c == ']'){
					if (this->opposite(c) == myStack->peek()){
            myStack->pop();
          }else{
						cout <<"Line " <<num<< ": Expected " << this->opposite(myStack->peek()) << " and found "<<c<<endl;
						checker = true;
						break;
					}
				}
			}
			//if stack is empty and pop/peak is called then extra closing del
			catch (invalid_argument& e){
				cout <<"Line " <<num<< ": Found an extra: " <<c<<endl;
				checker = true;
				break;
			}
		}
		line = out->nextLine();
		num++;
	}

	if (checker==false){
		//if stack is empty and no mismatch or extra then file is good
		if (myStack->isEmpty()){
			cout << "No errors" << endl;
		}else{
			cout << "Reached end of file: missing "<< this->opposite(myStack->peek()) <<endl;
			checker = true;
		}
	}
  return checker;
}
