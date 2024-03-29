#include "OrgChart.hpp"
using namespace std;

namespace ariel{

    OrgChart::OrgChart(){}

    ostream& operator<< (ostream& output, const OrgChart& orgChart){
        return output;
    }

    OrgChart& OrgChart::add_root(const string& name){
        if (this->root != NULL) {
            this->root->name = name;        
        }else{
            this->root = new Node{name};
        }
        return *this;
    }
    OrgChart& OrgChart::add_sub(const string& father, const string& child){
        if (root == NULL) {
            throw logic_error ("there is no root");
        }
        if(root->children->empty() && root->name != father){
            throw logic_error(father + "does not exist");
        }
        this->exist = false;
        add_sub(root, father, child);
        if (!this->exist) {
            throw logic_error(father + "does not exist");
        }
        return *this;
    }
    void OrgChart::add_sub(Node* n,const string& father,const string& child){
        if (n->name == father) {
            Node* new_node = new Node(child);
            n->children->push_back(new_node);
            this->exist = true;
            return;
        }
        for (uint son = 0; son < n->children->size(); son++) {
            add_sub(n->children->at(son), father, child);
        }
    }

    OrgChart::Iterator OrgChart::begin()const {
		return Iterator{LEVEL, root};
	}
	
	OrgChart::Iterator OrgChart::end()const {
        if (this->root == NULL) {
            throw logic_error("the organization chart is empty");
        }
		return Iterator {nullptr};
	}

	OrgChart::Iterator OrgChart::begin_level_order()const {
        return Iterator{LEVEL, root};
    }

    OrgChart::Iterator OrgChart::end_level_order()const {
        if (this->root == NULL) {
            throw logic_error("the organization chart is empty");
        }
        return Iterator {nullptr};
    }

    OrgChart::Iterator OrgChart::begin_reverse_order()const {
        return Iterator{REVERSE, root};
    }

    OrgChart::Iterator OrgChart::reverse_order()const {
        if (this->root == NULL) {
            throw logic_error("the organization chart is empty");
        }
        return Iterator {nullptr};
    }

    OrgChart::Iterator OrgChart::begin_preorder()const {
        return Iterator{PRE_ORDER, root};
    }

    OrgChart::Iterator OrgChart::end_preorder()const {
        if (this->root == NULL) {
            throw logic_error("the organization chart is empty");
        }
        return Iterator {nullptr};
    }

    //***** Iterator implements *****
    OrgChart::Iterator::Iterator(int type, Node* node) : type(type), current_node(node) {
        if (node == NULL) {
            throw logic_error("the organization chart is empty");
        }
        if(type == LEVEL){
            level();
        }else if (type == REVERSE) {
            reverse();
        }else {
            pre_order();
        }
    }
    
    void OrgChart::Iterator::level(){
        this->q = new queue<Node*>();
        if(current_node->children == NULL){
            return;
        }
        this->q->push(current_node);
        Node* tmp = current_node;
        while(!this->q->empty()) { 
            int number_of_nodes_in_current_level = this->q->size(); 
            while(number_of_nodes_in_current_level > 0 ) {
                Node* top = this->q->front();
                tmp->next = top;
                tmp = tmp->next;
                this->q->pop();
                if (top->children != NULL){
                    for (uint i = 0; i < top->children->size(); i++){
                        this->q->push(top->children->at(i));
                    }   
                }
                number_of_nodes_in_current_level--;
            } // end of while 2
        }// end of while 1
    }
    void OrgChart::Iterator::reverse(){
        this->q = new queue<Node*>();
        this->s =new stack<Node*>();
        stack<Node*> s_tmp; 
        if(this->current_node->children == NULL){
            return;
        }
        this->q->push(current_node);
        while(!this->q->empty()) {
            Node* top = this->q->front();
            this->s->push(top);
            this->q->pop();
            if(top->children != NULL){
                for (uint i = 0; i < top->children->size(); i++){
                    s_tmp.push(top->children->at(i));
                }
                while (!s_tmp.empty()) {
                    Node* tmp = s_tmp.top();
                    s_tmp.pop(); 
                    this->q->push(tmp);
                }
            }
        }
        current_node = this->s->top();
        this->s->pop();
        Node* tmp = current_node;
        while (!this->s->empty()){
            Node* top= this->s->top();
            tmp->next = top;
            tmp= tmp->next;
            tmp->next = nullptr;
            this->s->pop();
        }
    }
    void OrgChart::Iterator::pre_order(){
        this->q = new queue<Node*>();
        this->q->push(current_node);
        pre_order(current_node);
        current_node = this->q->front();
        this->q->pop();
        Node* tmp = current_node;
        while (!this->q->empty()){
            Node* top= this->q->front();
            tmp->next = top;
            tmp= tmp->next;
            tmp->next = nullptr;
            this->q->pop();
        }
    }
    void OrgChart::Iterator::pre_order(Node* node){
        if (node->children == NULL) {
            return;
        }
        for (uint i = 0; i < node->children->size(); i++) {
            this->q->push(node->children->at(i));
            pre_order(node->children->at(i));
        }
    }
    string& OrgChart::Iterator::operator*() const { 
        return this->current_node->name;
    }

    string* OrgChart::Iterator::operator->() const {
        return &(current_node->name);
    }

    OrgChart::Iterator& OrgChart::Iterator::operator++() { // postfix
        current_node = current_node->next;
        return *this;
    }

    OrgChart::Iterator OrgChart::Iterator::operator++(int) {  // prefix
        OrgChart::Iterator tmp= *this;
        current_node = current_node->next;
        return tmp;
    }

    bool OrgChart::Iterator::operator==(const OrgChart::Iterator& iter) const {
        return current_node == iter.current_node;
    }

    bool OrgChart::Iterator::operator!=(const OrgChart::Iterator& iter) const {
        return !(current_node == iter.current_node);
    }

}