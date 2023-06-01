#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class myString
{
private:
    string my_str;
public:
    myString(string s){
        my_str = s;
    }
};

class ReadClass
{
public:
   void showClass(){
       ifstream input;
       input.open("main.cpp");
       string line;
       int count = 0;
       while (getline(input, line)) {
           if (line.find("class ") != string::npos && (int)line.find("class ") == 0) {
               count++;
           }
       }
       input.close();
       cout<<count<<" class in main.cpp"<<endl;
       
       input.open("main.cpp");
       
       string out;
       
       while(getline(input, line)){
           
           if(line.find("class ") != string::npos && (int)line.find("class ") == 0){
               size_t startpos = line.find("class ") + 6;
               size_t endpos = line.find("{");
               out = line.substr(startpos, endpos);
               cout<<"class "<<out<<endl;
           }
       }
       input.close();
   }
};

int main() {
    ReadClass rfile;
    rfile.showClass();
    return 0;
}
