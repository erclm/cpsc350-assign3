#include"GetFile.h"

#include<iostream>
#include<fstream>
#include<string>


using namespace std;


GetFile::GetFile(){
  linenumber = 0;
}

GetFile::GetFile(string in, string out){
  infile.open(in, ifstream::in);
  outfile.open(out, ios_base::app);
  linenumber = 0;
}

GetFile::~GetFile(){
  infile.close();
  outfile.close();
}

void GetFile::clear(){
  infile.clear();
  infile.seekg(0, ios::beg);
}

int GetFile::lineCount(){
  infile.seekg(0, ios::end);
  int r = infile.tellg();
  clear();
  return r;
}

string GetFile::nextLine(){
  string line;
  if(getline(infile,line)){
    linenumber++;
    return line;
  }else{
    return "$endl*%";
  }
}

void GetFile::writeLine(string line){
  outfile<<line<<endl;
}
