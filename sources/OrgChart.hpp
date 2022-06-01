#pragma once

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

const int LEVEL = 1;
const int REVERSE = 2;
const int PRE_ORDER = 3;

using namespace std;
namespace ariel{
    class OrgChart{

        public:
		OrgChart& operator=(const OrgChart& rhs);

		struct Node {
			string name;
			int size;
			vector<Node*>* children = new vector<Node*>();
			Node* next = nullptr;
			Node(){}
			Node(string name):name(name) {
				size = name.size();
			}
			Node(Node& other):name(other.name), size(other.size),children(other.children){}
	    };

		
		Node* root;
		int size = 0;
		bool exist = false;

		OrgChart();
        ~OrgChart(){}
		friend ostream& operator<< (ostream& output, const OrgChart& orgChart);

        OrgChart& add_root(string);

        OrgChart& add_sub(string ,string);

		void add_sub(Node*, string, string);  

	class Iterator {

	private:

	  	int type;
		Node* current_node;
		queue<Node*>* q;
		stack<Node*>* s;
		
	public:

		Iterator(int type ,Node* ptr);
			
		Iterator(Node* ptr) : current_node(ptr){}

		void level();
		void reverse();
		void pre_order();
		void pre_order(Node*); //recursive
        
		string& operator*() const; 
		
		string* operator->() const;

		Iterator& operator++();

		const Iterator operator++(int);

		bool operator==(const Iterator& iter)const;

		bool operator!=(const Iterator& iter) const;
	};  // end iterator class

	
	Iterator begin();
	
	
	Iterator end();

	Iterator begin_level_order();

    Iterator end_level_order();

    Iterator begin_reverse_order();

    Iterator reverse_order();

    Iterator begin_preorder();

    Iterator end_preorder();
	
    }; // end of OrgChart class
};