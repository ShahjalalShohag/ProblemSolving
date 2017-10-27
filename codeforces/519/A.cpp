#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,b=0,p,w=0;
    string s;
    for(p=0;p<8;p++){
        cin>>s;
        for(i=0;i<s.length();i++){
                switch(s[i])
                {
                    case 'Q':
                    w+=9;
                    break;
                    case 'R':
                    w+=5;
                    break;
                    case 'B':
                    w+=3;
                    break;
                    case 'N':
                    w+=3;
                    break;
                    case 'P':
                    w+=1;
                    break;
                    case 'q':
                    b+=9;
                    break;
                    case 'r':
                    b+=5;
                    break;
                    case 'b':
                    b+=3;
                    break;
                    case 'n':
                    b+=3;
                    break;
                    case 'p':
                    b+=1;
                    break;
                }
        }

    }
    cout<<(w>b?"White\n":b>w?"Black\n":"Draw\n");
    return 0;
}
