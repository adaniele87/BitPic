#include <iostream>
using namespace std;

#define repB(v,b,n)  v=v&~(0xff<<n)|b<<n               // replace byte in object
#define prnB(v,n)    cout<<!!(v&1<<n)                  // print a single bit
#define onB(v,n)     v|=1<<n                           // turn bit on
#define offB(v,n)    v&=~(1<<n)                        // turn bit off
#define flipB(v,n)   v^=1<<n                           // flip bit on/off

void bitTree(int*,int,int);

int main()
{
    int pic[9]=
    {
        0x00000000,
        0x00000000,
        0x00000000,
        0x00000000,
        0x00000000,
        0x00000000,
        0x00000000,
        0x00000000,
        0x00000000,
    };
    bitTree(pic, 0, 3);
    
    for(int i = 0; i<9; i++)
    {
        for(int j = 0; j<32; j++) prnB(pic[i],31-j);
        cout << endl;
    }
    
    return 0;
}

void bitTree(int* _pic, int x, int y)
{
    repB(_pic[y],   0x3c, x);
    repB(_pic[y+1], 0x7e, x);
    repB(_pic[y+2], 0x7e, x);
    repB(_pic[y+3], 0x3c, x);
    repB(_pic[y+4], 0x18, x);
    repB(_pic[y+5], 0x18, x);
}