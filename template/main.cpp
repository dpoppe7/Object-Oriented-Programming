#include <iostream>
#include <string>
#include "labeled.hpp"
using namespace std;


int main(){
    int i;
    string s;
    double d;
    cin >> i >> s >> d;
    Labeled<int> li{"int" , i};
    Labeled<string> ls{"string" , s};
    Labeled<double> ld{"double" , d};

    cout << li << ls << ld << endl;
}