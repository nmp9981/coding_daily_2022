#include <iostream>
using namespace std;

int main()
{
    //위
    for(int i=0;i<15;i++){
        for(int j=0;j<30;j++){
            if(j==15) cout<<225<<" ";
            else cout<<0<<" ";
        }
        cout<<"\n";
    }
    //가운데
    for(int j=0;j<30;j++){
        if(j<15) cout<<1<<" "; 
        else if(j==15) cout<<0<<" ";
        else if(j>15) cout<<15<<" ";
    }
    cout<<"\n";
    //아래
    for(int i=16;i<30;i++){
        for(int j=0;j<30;j++){
            if(j==15) cout<<3375<<" ";
            else cout<<0<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
