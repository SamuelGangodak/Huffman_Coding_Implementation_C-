# include<iostream>
# include<unordered_map>
using namespace::std;

class Decoder{
    private:
        string decodedText;

    public:
        Decoder() {
            decodedText="";
        }
        string decodeText(string bin, unordered_map<string, char> stringMap) {
            string temp;
            for(int i=0; i<bin.length(); i++) {
                temp.push_back(bin[i]);
                if(stringMap.find(temp)!=stringMap.end()) {
                    decodedText.push_back(stringMap[temp]);
                    temp="";
                }
            }
            return decodedText;
        }
};