# include<iostream>
# include<unordered_map>
# include"dynamicHeap.cpp"
using namespace::std;

class Encoder{
    private:
        Heap *heap;
        unordered_map<char, int> charMap;
        unordered_map<string, char> stringMap;
        string bin;
    public:
        Encoder() {
            heap=new Heap();
        }

        unordered_map<string, char> getStringMap() {
            return stringMap;
        }

        string encodeText(string text) {
            for(int i=0; i<text.length(); i++) {
                if(charMap.find(text[i])==charMap.end()) {
                    charMap[text[i]]=1;
                }
                else {
                    int value=charMap[text[i]];
                    charMap.erase(text[i]);
                    charMap[text[i]]=value+1;
                }
            }

            for(auto i : charMap) {
                cout<<i.first<<" "<<i.second<<endl;
            }

            for(auto it : charMap) {
                string str;
                str.push_back(it.first);
                Node *charNode=new Node(str, it.second);
                heap->InsertNode(charNode);
                delete charNode;
            }

            Node *first, *second, *joined;
            while(heap->curr_size>1) {
                first=heap->DeleteRootNode();
                second=heap->DeleteRootNode();
                joined=Node::linking(first, second);
                heap->InsertNode(joined);
            }

            first = NULL;
            second = NULL;
            joined = NULL;
            
            Node *root=heap->DeleteRootNode();
            
            int i=0;
            while(i<text.length()) {
                string temp="";
                string str="";
                str.push_back(text[i]);
                temp=root->binaryEq(temp, str);
                if(stringMap.find(temp)==stringMap.end()) {
                    stringMap[temp]=text[i];
                }
                bin+=temp;
                i++;
            }

            for(auto it : stringMap) {
                cout<<it.second<<" "<<it.first<<endl;
            }

            return bin;
        }
};