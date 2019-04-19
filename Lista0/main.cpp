#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    double p,s,ad,bd,cd;
    string a,b,c;
    cin >> a >> b >> c;
    ad=stod(a);
    bd=stod(b);
    cd=stod(c);
    p=(ad+bd+cd)/2;
    s=sqrt(p*(p-ad)*(p-bd)*(p-cd));
    cout << s;
    return 0;
}
