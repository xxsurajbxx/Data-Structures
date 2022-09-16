#pragma once
#include <iostream>

    class BinaryTree {
    public:
        enum TraversalTypes {
            preOrder=0, inOrder=1, postOrder=2
        };
    private:
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
    };
    class LinkedList {
        private:
        class Link {
        Link* firstLink;
    };