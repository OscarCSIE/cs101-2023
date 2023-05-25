#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class ReplaceMyString {
private:
    ifstream in;
    ofstream out;

public:
    void replaceString(string a, string b) {
        in.open("main.cpp");
        out.open("rmain.cpp");

        string str;
        while (getline(in, str)) {
            size_t pos = str.find(a);
            while (pos != string::npos) {
                str.replace(pos, a.length(), b);
                pos = str.find(a, pos + b.length());
            }
            out << str << endl;
        }

        in.close();
        out.close();
    }
};

int main() {
    ReplaceMyString my;
    my.replaceString("IU", "IU is best");
    return 0;
}
