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
			// vector<Node*>* next_level;
			explicit Node(string& s, Node* next) : data(s), next(next) {
		    }
	    };

        Node* root;
        public:

        OrgChart():root(nullptr){}
        // OrgChart(OrgChart& other){
        //     this->root = other.root;
        // }
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
		    // // root = root->next_level;
		    // for (uint i = 0 ; i <tmp->next_level->size(); i++) {
            //     delete tmp->next_level->at(i);
            // }
	    }  

        OrgChart& add_root(const string& name){
			// this->root->next->data = name;
			// this->root->next->next = nullptr;
			return *this;
		}
        OrgChart& add_sub(const string& ,const string&){
			return *this;
		}


	//-------------------------------------------------------------------
	// iterator related code:
	// inner class and methods that return instances of it)
	//-------------------------------------------------------------------
	class iterator {

	  private:
		Node* current_node;
		// vector<Node*>* current_level;
	public:

		explicit iterator(Node* ptr = nullptr)
			: current_node(ptr) {}
        // OrgChart& operator=(OrgChart& other);
        // bool operator==(OrgChart& other);
        // bool operator!=(OrgChart& other);
        // OrgChart& operator*(OrgChart& other);
        // OrgChart& operator++(); // prefix
        // OrgChart operator++(int dummy); // postfix

		// Note that the method is const as this operator does not
		// allow changing of the iterator.
		// Note that it returns T& as it allows to change what it points to.
		// A const_iterator class will return const T&
		// and the method will still be const
		string& operator*() const { ///////////////////////////////////////////
			//return *current_node;
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