//
// Created by zhuanxu on 17/3/5.
//

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string line,word;
    char c;
    while(getline(cin,line)){
        // read a line from theinput into line do per-line processing
        istringstream stream(line);  // bind to stream to the
        cout << "we read word:" << endl;
        while(stream >> c){
            cout << c << endl;
        }
//        while(stream >> word){
//            cout << word << endl;
//        }
    }
}