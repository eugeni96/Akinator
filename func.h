#ifndef FUNC_H_
#define FUNC_H_

class Akinator
{
public:
    Akinator();
    void play();
    void initAkinator();

private:
    struct Node
    {
        char data[64];
        Node *pos;
        Node *neg;
    };
    Node *root;
    void addNode(Akinator::Node *&p);
};







#endif // FUNC_H_
