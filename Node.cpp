# include<iostream>
using namespace::std;

class Node{
    public:
        string str;
        int frequency;
        Node* left;
        Node* right;

        Node() {
            this->str="";
            this->frequency=-1;
            this->left=NULL;
            this->right=NULL;
        }
    
        Node(string str,int frequency) {
            this->str=str;
            this->frequency=frequency;
            this->left=NULL;
            this->right=NULL;
        }   

        string binaryEq(string bin, string ch) {
            if(this->str==ch || this->left==NULL || this->right==NULL) 
                return bin;

            int i=0;
            if(this->left->str.find(ch)!=string::npos) {
                bin+="0";
                return this->left->binaryEq(bin, ch);
            }
            else {
                bin+="1";
                return this->right->binaryEq(bin, ch);
            }
        }

        static Node* linking(Node *n1, Node *n2) {
            string str=n1->str+n2->str;
            int value=n1->frequency+n2->frequency;
            Node *n3=new Node(str, value);
            if(n1->frequency<n2->frequency) {
                n3->right=n2;
                n3->left=n1;
            }
            else{
                n3->right=n1;
                n3->left=n2;
            }
            return n3;
        }
};