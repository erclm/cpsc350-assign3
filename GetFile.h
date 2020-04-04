#include<iostream>
#include<fstream>

using namespace std;

class GetFile{
public:
  GetFile();
  GetFile(string in, string out);
  ~GetFile();
  void clear();
  int lineCount();
  void writeLine(string line);
  string nextLine();

  ifstream infile;
  ofstream outfile;
  int linenumber;
};
