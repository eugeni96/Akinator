#include "func.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

Akinator::Akinator():
    root(nullptr)
{

}

void Akinator::initAkinator()
{
    root=new Node;
    root->pos=nullptr;
    root->neg=nullptr;
    string rootQuest="Оно летает?";
    root->data=rootQuest;

    Node *posit=nullptr;
    posit=new Node;
    posit->neg=nullptr;
    posit->pos=nullptr;
    string crown="ворона";
    posit->data=crown;

    Node *negat=nullptr;
    negat=new Node;
    negat->neg=nullptr;
    negat->pos=nullptr;
    string dog="собака";
    negat->data=dog;

    root->pos=posit;
    root->neg=negat;

    posit=nullptr;
    negat=nullptr;
}

void Akinator::addNode(Akinator::Node *&p)
{
    cout<<"Введите вопрос:"<<endl;
    string quest;
    cin>>quest;

    cout<<"Введите вариант ответа на ваш вопрос: [да/нет]"<<endl;
    string choise;
    choise=enterProtector();

    string no="нет";
    cout<<"Введите ответ на вопрос, соответствующий указанному варианту:"<<endl;
    string answer;
    cin>>answer;

    Node *n=nullptr;
    n=new Node;
    n->data=answer;
    n->pos=nullptr;
    n->neg=nullptr;

    Node *t=nullptr;
    t=new Node;
    t->data=p->data;
    t->neg=nullptr;
    t->pos=nullptr;

    p->data=quest;
    if (choise!=no)
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
    string enter;
    string yes="да";
    Node *p=root;
    bool aplay=true;
    while (aplay)
    {
        if (p->pos==nullptr)
        {
            cout<<"Ответ: "<<p->data<<endl;
            cout<<"Угадал? [да/нет]"<<endl;
            enter=enterProtector();
            if (enter!=yes)
            {
                Akinator::addNode(p);
            }
            aplay=false;
        }
        else
        {
            cout<<p->data<<" [да/нет]"<<endl;
            enter=enterProtector();
            if (enter!=yes)
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

void Akinator::show(Akinator::Node *p)
{
    if (p)
    {
        cout<<p->data<<endl;
        show(p->neg);
        show(p->pos);
    }
    else
    {
        return;
    }
}

void Akinator::save()
{
    ofstream fout;
    fout.open("data.txt");
    fout.close();
    write(root);

}

void Akinator::write(Akinator::Node *p)
{
    if (p)
    {
        ofstream fout;
        fout.open("data.txt",ios_base::out|ios_base::app);
        fout<<p->data<<endl;
        if (p->neg!=nullptr)
        {
            fout<<"1"<<endl;
        }
        else
        {
            fout<<"0"<<endl;
        }
        fout.close();
        write(p->neg);
        write(p->pos);
    }
    else
    {
        return;
    }
}

void Akinator::read(std::ifstream& mystream, Akinator::Node *&p)
{
    string mydata;
    string isNode;
    p=new Node;
    p->neg=nullptr;
    p->pos=nullptr;
    getline(mystream,mydata);
    p->data=mydata;
    getline(mystream,isNode);
    if(isNode=="1")
    {
        Node *ptrL=nullptr;
        ptrL=new Node;
        ptrL->neg=nullptr;
        ptrL->pos=nullptr;
        p->neg=ptrL;
        ptrL=nullptr;
        read(mystream, p->neg);
        Node *ptrR=nullptr;
        ptrR=new Node;
        ptrR->neg=nullptr;
        ptrR->pos=nullptr;
        p->pos=ptrR;
        ptrR=nullptr;
        read(mystream, p->pos);
    }
}

void Akinator::load()
{
    ifstream mystream("data.txt",ios_base::in);
    read(mystream, root);
    mystream.close();
}

string enterProtector()
{
    string yes="да";
    string no="нет";
    string enter;
    cin>>enter;
    if (enter!=yes && enter!= no)
    {
        cout<<"Неверный ввод. Повторите попытку [да/нет]"<<endl;
        enterProtector();
    }
    return enter;
}
