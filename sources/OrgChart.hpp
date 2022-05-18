#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
namespace ariel{
    class OrgChart{

        public:

		struct Node {
			string& data;
			Node * next;
			Node(string& s, Node* next) : data(s), next(next) {}
	    };

        Node* root;
        public:

        OrgChart():root(nullptr){}
        ~OrgChart(){
            remove();
        }
		friend ostream& operator<< (ostream& output, const OrgChart& orgChart){
			return output;
		}

        bool empty() const {
		    return root == nullptr;
	    }
        void remove() {
			Node* tmp = root;
	    }  

        OrgChart& add_root(const string& name){
			return *this;
		}
        OrgChart& add_sub(const string& ,const string&){
			return *this;
		}

	class iterator {

	  private:
		Node* current_node;
		// vector<Node*>* current_level;
	public:

		iterator(Node* ptr = nullptr)
			: current_node(ptr) {}
        
		string& operator*() const { 
			return this->current_node->data;
		}

		string* operator->() const {
			return &(current_node->data);
		}

		iterator& operator++() {
			current_node = current_node->next;
			return *this;
		}

		iterator operator++(int) {  //
			iterator tmp= *this;
			current_node = current_node->next;
			return tmp;
		}

		bool operator==(const iterator& iter) const {
			return current_node == iter.current_node;
		}

		bool operator!=(const iterator& iter) const {
			return current_node != iter.current_node;
		}
	};  // END OF CLASS ITERATOR

	
	iterator begin() {
		return iterator{root};
	}
	
	iterator end() {
		return iterator{nullptr};
	}

	iterator begin_level_order() {
        return iterator{root};
    }

    iterator end_level_order() {
        return iterator{nullptr};
    }

    iterator begin_reverse_order() {
        return iterator{root};
    }

    iterator reverse_order() {
        return iterator{nullptr};
    }

    iterator begin_preorder() {
        return iterator{root};
    }

    iterator end_preorder() {
        return iterator{nullptr};
    }
	
    };
};