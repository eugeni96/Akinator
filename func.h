#ifndef FUNC_H_
#define FUNC_H_
#include <fstream>
#include <cstring>

class Akinator
{
public:
    Akinator();
    void play();
    void initAkinator();
    void save();
    void load();
private:
    struct Node
    {
        std::string data;
        Node *pos;
        Node *neg;
    };
    Node *root;
    Akinator(const Akinator &original);
    Akinator &operator = (const Akinator &rhs);
    void addNode(Akinator::Node *&p);
    void show(Akinator::Node *p);
    void write(Akinator::Node *p);
    void read(std::ifstream& mystream, Akinator::Node *&p);
};

std::string enterProtector();

#endif // FUNC_H_
