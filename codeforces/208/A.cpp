#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,flag=1;
    string s;
    cin>>s;
    for(i=0;i<s.length();){
        if(s[i]=='W'&&s[i+1]=='U'&&s[i+2]=='B'){
            i+=3;
            if(flag==0){
                cout<<" ";
                flag=1;
            }

        }
        else{
            cout<<s[i];
            flag=0;
            i++;
        }

    }
    cout<<endl;
    return 0;
}
