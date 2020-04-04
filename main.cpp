#include<iostream>
#include<fstream>
#include<string>
#include"Syntax.h"

using namespace std;

bool exists(string name) {
    ifstream f(name);
    return f.good();
}

int main(int argc, char const *argv[]) {
  Syntax *s;
	if (argc>1){
		s = new Syntax(argv[1]);
		while(!s->check()){
			string str;
      //repeat
			cout << "Another File?[Y/N]"<< endl;
			cin>>str;
			if (str == "y"||str == "Y"){
				delete s;//setup for new file
				cout << "File Name: "<< endl;
				cin>>str;
        if(!exists(str)){
          std::cout << "Illegal file name" << '\n';
          break;
        }
				s = new Syntax(str);
			}else{
        break;
      }
		}
	}else{
    cout << "Illegal file name"<<endl;
  }

  /* code */
  return 0;
}
