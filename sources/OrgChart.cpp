#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "OrgChart.hpp"
using namespace std;
namespace ariel{
    
    ostream& operator<< (ostream& output, const OrgChart& orgChart){
        return output;
    }

    OrgChart& OrgChart::add_root(const string& name){
        root = new Node(name);
        return *this;
    }
    OrgChart& OrgChart::add_sub(const string& father,const string& child){
			Node* new_node = new Node(child);
            OrgChart::Node* tmp = this->root;
            while (tmp->next != nullptr && tmp->name != father) {
                tmp->next = tmp->next->next;
            }
            if (tmp->name == father) {
                tmp->next = new_node;
            }
			return *this;
    }
}