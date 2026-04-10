#include <iostream>
#include "IntArrayList.h"

using namespace std;

int main(){
    IntArrayList list1;
    IntArrayList list2(10, 175);

    cout << "List2 shoudld be size 10: " << list2.size() << endl;

    return 0;
}