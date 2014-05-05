#include <iostream>
#include <cstring>
#include "func.h"

using namespace std;

void control ()
{
    Akinator test;
    test.initAkinator();
    char enter[64]=" ";
    char no[64]="нет";
    while (strcmp(enter,no))
    {
    test.play();
    cout<<"Еще будешь?"<<endl;
    cin.getline(enter,64);
    }
}

int main()
{
    control();
    return 0;
}
