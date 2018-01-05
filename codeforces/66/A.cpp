#include <iostream>
using namespace std;
long double a,b,n;
main(){
cin>>a;
if(a<=127) cout<<"byte"; 
else if(a<=32767) cout<<"short";
else if(a<=2147483647) cout<<"int";
else if(a<=9223372036854775807) cout<<"long";
else cout<<"BigInteger";
}