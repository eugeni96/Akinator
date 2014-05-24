#include <iostream>
#include <cstring>
#include "func.h"

using namespace std;

void control ()
{
    Akinator test;
    test.load();
    string no="нет";
    string intro="да";
    while (intro!=no)
    {
        test.play();
        test.save();
        cout<<"Еще будешь?"<<endl;
        intro=enterProtector();
    }
}

int main()
{
    control();
    return 0;
}
