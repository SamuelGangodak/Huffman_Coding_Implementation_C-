# include<iostream>
# include"Node.cpp"
using namespace::std;

const int DEFAULT_SIZE=128;

class Heap{
    public:
        Node* data;
        int size;
        int curr_size;

        Heap() {
            this->data=new Node[DEFAULT_SIZE];
            this->size=DEFAULT_SIZE;
            this->curr_size=0;
        }

        int compare(Node value1, Node value2) {
            int ret_val=0;
            if(value1.frequency<value2.frequency) ret_val=1;
            return ret_val;
        }

        bool IsHeapFull() {
            bool ret_val=false;
            if(this->curr_size==this->size) ret_val=true;
            return ret_val;
        }

        void ExpandHeap() {
            Node* temp=new  Node[DEFAULT_SIZE*2];
            for(int i=0; i<this->size; i++) {
                temp[i]=this->data[i];
            }
            delete this->data;
            this->data=temp;
        }

        void swap(int indx1, int indx2) {
            Node temp=this->data[indx1];
            this->data[indx1]=this->data[indx2];
            this->data[indx2]=temp;
        }

        void printHeap() {
            printf("heap curr size : %d\n",this->curr_size);
            for(int i=0; i<this->curr_size; i++) {
                cout<<this->data[i].str<<" "<<this->data[i].frequency<<endl;
            }
        }

        void InsertNode(Node *value) {
            if(this->IsHeapFull()) {
                printf("The Heap is Full, need to expand");
                this->ExpandHeap();
            }
            this->data[this->curr_size]=*value;
            this->curr_size++;
            int childIndx=this->curr_size-1;
            int parentIndx=(childIndx-1)/2;
            while(childIndx>0 && compare(this->data[childIndx],this->data[parentIndx] )) {
                swap(childIndx, parentIndx);
                childIndx=parentIndx;
                parentIndx=(childIndx-1)/2;
            }
        }

        Node* DeleteRootNode() {
            Node *root=new Node(this->data[0].str, this->data[0].frequency);
            root->left=this->data[0].left;
            root->right=this->data[0].right;
            int i=0;
            this->data[i]=this->data[(this->curr_size)-1];
            (this->curr_size)--;
            int index1=2*i+1;
            int index2=2*i+2;
            int flag=1;
                
            while(index2<(this->curr_size) && flag==1) {
                if(compare(this->data[i], this->data[index1]) && compare(this->data[i], this->data[index2])) {
                    flag=0;
                }
                else {
                    if(compare(this->data[index1], this->data[index2]) && compare(this->data[index1], this->data[i])) {
                        swap(i, index1);
                        i=index1;
                        index1=2*i+1;
                        index2=2*i+2;
                }
                    else {
                        swap(i, index2);
                        i=index2;
                        index1=2*i+1;
                        index2=2*i+2;
                    }
                }
            }
            if(index1<this->curr_size && compare(this->data[index1], this->data[i])) {
                swap(i, index1);
            }
            return root;
        }
};