#include <iostream>
#include "cmylist.h"

using namespace std;

int main()
{
    CMyList<int> list;

    list.addFirst(5);
    list.addFirst(5);
    list.addFirst(5);
    list.addFirst(45);
    list.addFirst(3);
    list.addFirst(5);
    //list.remove(5);

    const uint64_t sizet = 10;
    int tab[sizet];
    list.getItems(tab,sizet);
    for(int i=0;i<sizet;i++)
        cout<<tab[i]<<endl;

    list.removeLast();
    list.removeFirst();
    list.clear();

    return 0;
}

