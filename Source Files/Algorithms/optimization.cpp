#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
int a[250000001];
int count = 0;
void process()
{
    for(auto i = 0; i <= 250000000; i++)
    {
        a[i] = i;
    }
}
void OptimizeSearch(int* A, size_t s, size_t e, int& item)
{
    size_t mid;
    while(s < e)
    {
        mid = (s + e)/2;
        if(A[mid] > item) s = mid + 1;
        else e = mid;
        count++;
        cout << "Compare :: " << count << endl;
    }
    if(A[s] == item) cout << "Item found @ : " << mid << endl;
    else cout << "Item not found !" << endl;
}
void binarysearch(int* A, size_t s, size_t e, int& item)
{
    if( s >= e ) 
    {
        cout << "Item not found ! " << endl;
        return;
    }
    size_t mid = (s + e)/2;
    if(A[mid] > item)
    {
        ++count;
        cout << " First half :: mid = " << mid  << " Comaparision : " << count << endl;
        binarysearch(A, s, mid, item);
    } 
    else if(A[mid] < item)
    {
        ++count;
        cout << " Second half :: mid = " << mid << " Comaparision : " << count << endl; 
        binarysearch(A, mid, e, item);
    }
    else
    {
        cout << "Item = " << item << " Pos = " << mid << endl;
    }
}
int main()
{
    process();
    int item;
    cin >> item;
    OptimizeSearch(a,0,250000000,item);
    binarysearch(a,0,250000000,item);
    return 0;
}