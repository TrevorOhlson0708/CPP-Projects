#include <iostream>
using namespace std;
void PrintInts(int** ptr, int s);

int main()
{
    int** pInts = new int*[3]{nullptr};
    pInts[0] = new int[10];
    pInts[1] = new int[100];
    pInts[2] = new int[1000];
    PrintInts(pInts, 3);
    
    int** pTmps = new int*[4] {nullptr};
    for (int i = 0; i < 3; i++) pTmps [i] = pInts[i];
    pTmps[3] = new int{10000};
    delete [] pInts;
    pInts = pTmps;
    pTmps = nullptr;
    PrintInts(pInts,4);
    
    pTmps = new int*[2]{nullptr};
    for (int i = 0; i < 3; i++) pTmps [i] = pInts [i];
    for(int ii = 2; ii< 4; ii++) delete pInts[ii];
    delete [] pInts;
    pInts = pTmps;
    pTmps = nullptr;
    PrintInts(pInts, 2);
    
    return 0;
}

void PrintInts(int** ptr, int s){
    for (int i = 0; i < s; i++) cout << *ptr[i] << endl;
    cout << endl;
}