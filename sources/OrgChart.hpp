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
		vector<Node*>* next_level;
		Node(string& s, vector<Node*>* n) : data(s), next_level(n) {
		    }
	    };

        Node* root;

        public:



        OrgChart() : root(nullptr){};
        OrgChart(OrgChart& other){
            this->root = other.root;
        }
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
		    // root = root->next_level;
		    for (uint i = 0 ; i <tmp->next_level->size(); i++) {
                delete tmp->next_level->at(i);
            }
	    }  

        OrgChart add_root(const string&){
			return *this;
		}
        OrgChart add_sub(const string& ,const string&){
			return *this;
		}


	//-------------------------------------------------------------------
	// iterator related code:
	// inner class and methods that return instances of it)
	//-------------------------------------------------------------------
	class iterator {

	  private:
		Node* current_node;
		vector<Node*>* current_level;
	public:

        OrgChart& operator=(OrgChart& other);
        bool operator==(OrgChart& other);
        bool operator!=(OrgChart& other);
        // OrgChart& operator*(OrgChart& other);
        // OrgChart& operator++(); // prefix
        // OrgChart operator++(int dummy); // postfix
		iterator(Node* ptr = nullptr)
			: current_node(ptr) {
		}

		// Note that the method is const as this operator does not
		// allow changing of the iterator.
		// Note that it returns T& as it allows to change what it points to.
		// A const_iterator class will return const T&
		// and the method will still be const
		string& operator*() const { ///////////////////////////////////////////
			//return *current_node;
			return current_node->data;
		}

		string* operator->() const {
			return &(current_node->data);
		}

		// ++i;
		iterator& operator++() {
			//++current_node;
			current_level = current_node->next_level;
			return *this;
		}

		// i++;
		// Usually iterators are passed by value and not by const& as they are small.
		const iterator operator++(int) {
			iterator tmp= *this;
			current_level = current_node->next_level;
			return tmp;
		}

		bool operator==(const iterator& rhs) const {
			return current_node == rhs.current_node;
		}

		bool operator!=(const iterator& rhs) const {
			return current_node != rhs.current_node;
		}
	};  // END OF CLASS ITERATOR

	
	iterator begin() {
		// return &(m_first->m_value); 
		return iterator{root};
	}
	
	iterator end() {
		// return nullptr; 
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