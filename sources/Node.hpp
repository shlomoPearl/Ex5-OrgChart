#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;


class Node{
    public:
        const string& name;
        Node* next;
        vector<Node*>* child;    
    Node(const string& name){
        this.name = name;
        this.next = nullptr;
    }
    Node(Node other){
        this.name = other->name;
        this.next = other->next;
    }
    ~Node(){
        
    }
    void add_node(Node* father, Node* child){
        father->next = child;
    }
    
};