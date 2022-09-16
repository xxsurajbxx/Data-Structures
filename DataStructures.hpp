#pragma once
#include <iostream>
namespace xxsurajbxx::DataStructures {
    class BinaryTree {
    public:
        enum TraversalTypes {
            preOrder=0, inOrder=1, postOrder=2
        };
    private:        struct Node {
            public:
                Node* Parent;
                Node* Cleft;
                Node* Cright;
                int value;
                Node(int val):Parent(nullptr), Cleft(nullptr), Cright(nullptr), value(val) {}
                Node(Node* parent, int val):Parent(parent), Cleft(nullptr), Cright(nullptr), value(val) {}
        };
        Node* root;
        void addNode(Node* parent, int element) {
            if(element > parent->value) {
                if(parent->Cright==nullptr) {
                    parent->Cright = new Node(parent, element);
                }
                else {
                    addNode(parent->Cright, element);
                }
            }
            if(element < parent->value) {
                if(parent->Cleft==nullptr) {
                    parent->Cleft = new Node(parent, element);
                }
                else {
                    addNode(parent->Cleft, element);
                }
            }
        }
        void printTree(Node* parent, TraversalTypes tt) {
            switch(tt) {
                case preOrder:
                    std::cout << parent->value << std::endl;
                    if(parent->Cleft!=nullptr) {
                        printTree(parent->Cleft, tt);
                    }
                    if(parent->Cright!=nullptr) {
                        printTree(parent->Cright, tt);
                    }
                    break;
                case inOrder:
                    if(parent->Cleft!=nullptr) {
                        printTree(parent->Cleft, tt);
                    }
                    std::cout << parent->value << std::endl;
                    if(parent->Cright!=nullptr) {
                        printTree(parent->Cright, tt);
                    }
                    break;
                case postOrder:
                    if(parent->Cleft!=nullptr) {
                        printTree(parent->Cleft, tt);
                    }
                    if(parent->Cright!=nullptr) {
                        printTree(parent->Cright, tt);
                    }
                    std::cout << parent->value << std::endl;
                    break;
            }
        }
    public:
        BinaryTree(int val):root(new Node(val)) {}
        void addNode(int element) {
            if(element > root->value) {
                if(root->Cright==nullptr) {
                    root->Cright = new Node(root, element);
                }
                else {
                    addNode(root->Cright, element);
                }
            }
            if(element < root->value) {
                if(root->Cleft==nullptr) {
                    root->Cleft = new Node(root, element);
                }
                else {
                    addNode(root->Cleft, element);
                }
            }
        }
        void printTree(TraversalTypes tt) {
            switch(tt) {
                case preOrder:
                    std::cout << root->value << std::endl;
                    if(root->Cleft!=nullptr) {
                        printTree(root->Cleft, tt);
                    }
                    if(root->Cright!=nullptr) {
                        printTree(root->Cright, tt);
                    }
                    break;
                case inOrder:
                    if(root->Cleft!=nullptr) {
                        printTree(root->Cleft, tt);
                    }
                    std::cout << root->value << std::endl;
                    if(root->Cright!=nullptr) {
                        printTree(root->Cright, tt);
                    }
                    break;
                case postOrder:
                    if(root->Cleft!=nullptr) {
                        printTree(root->Cleft, tt);
                    }
                    if(root->Cright!=nullptr) {
                        printTree(root->Cright, tt);
                    }
                    std::cout << root->value << std::endl;
                    break;
            }
        }
    };    template<typename type>
    class LinkedList {
        private:
        class Link {            public:                Link* prev;                type val;                Link* nxt;                Link(Link* previous, type value, Link* next):prev(previous), val(value), nxt(next) {}        };
        Link* firstLink;        public:        int length;        //make a new value like null which holds all the possible null vals for all the different types        LinkedList():length(0) {}        LinkedList(type firstval):firstLink(nullptr, firstval, nullptr), length(1) {}        ~LinkedList() {            Link* temp=&firstLink;            for(int i=0; i<length-1; i++) {                temp = temp->nxt;            }            for(int i=length; i>0; i++) {                Link* anothertemp = temp;                temp = temp->prev;                delete anothertemp;            }        }        void changeValue(int index, type value) {            Link* link = &firstLink;            for(int i=0; i<index; i++) {                link = link->nxt;            }            link->val = value;        }        void addElement(type value) {            static Link* currentlink = &firstLink;            if(length>0) {                currentlink->nxt = new Link(currentlink, value, nullptr);                currentlink = currentlink->nxt;            }            else {                firstLink = new Link(nullptr, value, nullptr);                currentlink = firstLink;            }            length++;        }        void removeElement(int index) {            Link* link = &firstLink;            for(int i=0; i<index; i++) {                if(i==index-1) {                    Link* temp = link->nxt;                    link->nxt = link->nxt->nxt;                    delete temp;                    if(index<length-1) {                        link->nxt->prev = link;                    }                }                link = link->nxt;            }        }        int find(type SV) {            Link* link = &firstLink;            for(int i=0; i<length; i++) {                if(SV==link->val) {return i;}                else {link = link->nxt;}            }            return -1;        }        type getValue(int index) {            Link* link = &firstLink;            for(int i=0; i<index; i++) {                link = link->nxt;            }            return link->val;        }
    };    //make this so it only works with strings    //this thing straight barely works, fix it    template<typename type>    class HashTable {        private:            LinkedList<type>* table;            int* tableLens;            int tablesize;        public:            HashTable(int tblsize):table(new LinkedList<type>[tblsize]), tableLens(new int[tablesize]), tablesize(tblsize) {}            void addElement(type inpt) {                                //make some sort of equation here                int total=0;                /* for(int i=0; i<inpt.length(); i++) {                    total += (int)inpt[i];                } */                total = (int)inpt;                total*=100;                total%=tablesize;                table[total].addElement(inpt);                tableLens[total]++;            }            void printLens() {                for(int i=0; i<tablesize; i++) {                    std::cout << tableLens[i] << std::endl;                }            }    };}