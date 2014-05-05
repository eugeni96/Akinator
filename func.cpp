#include "func.h"
#include <iostream>
#include <cstring>


using namespace std;

Akinator::Akinator():
    root(nullptr)
{

}

void Akinator::initAkinator()
{
    const int strSize=64;

    root=new Node;
    root->pos=nullptr;
    root->neg=nullptr;
    char rootQuest[strSize]="Оно летает?";
    strcpy(root->data,rootQuest);

    Node *posit=nullptr;
    posit=new Node;
    posit->neg=nullptr;
    posit->pos=nullptr;
    char crown[strSize]="ворона";
    strcpy(posit->data,crown);

    Node *negat=nullptr;
    negat=new Node;
    negat->neg=nullptr;
    negat->pos=nullptr;
    char dog[strSize]="собака";
    strcpy(negat->data,dog);

    root->pos=posit;
    root->neg=negat;

    posit=nullptr;
    negat=nullptr;
}

void Akinator::addNode(Akinator::Node *&p)
{
    const int strSize=64;

    cout<<"Введите вопрос:"<<endl;
    char quest[strSize];
    cin.getline(quest,strSize);

    cout<<"да/нет ?"<<endl;
    char choise[strSize];
    cin.getline(choise,strSize);

    char no[strSize]="нет";
    cout<<"Введите ответ:"<<endl;
    char answer[strSize];
    cin.getline(answer,strSize);

    Node *n=nullptr;
    n=new Node;
    strcpy(n->data,answer);
    n->pos=nullptr;
    n->neg=nullptr;

    Node *t=nullptr;
    t=new Node;
    strcpy(t->data,p->data);
    t->neg=nullptr;
    t->pos=nullptr;

    strcpy(p->data,quest);
    if (strcmp(choise,no))
    {
        p->neg=t;
        p->pos=n;
    }
    else
    {
        p->neg=n;
        p->pos=t;
    }

    t=nullptr;
    n=nullptr;
}

void Akinator::play()
{
    const int strSize=64;

    char enter[strSize];
    char yes[strSize]="да";
    Node *p=root;
    bool aplay=true;
    while (aplay)
    {
        cout<<p->data<<endl;
        if (p->pos==nullptr)
        {
            cout<<"Угадал?"<<endl;
            cout<<"да/нет"<<endl;
            cin.getline(enter,strSize);
            if (strcmp(enter,yes))
            {
                Akinator::addNode(p);
            }
            aplay=false;
        }
        else
        {
            cout<<"да/нет"<<endl;
            cin.getline(enter,strSize);
            if (strcmp(enter,yes))
            {
                p=p->neg;
            }
            else
            {
                p=p->pos;
            }
        }
    }
}
