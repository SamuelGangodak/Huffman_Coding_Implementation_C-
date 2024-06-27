# include<iostream>
# include<fstream>
# include<string>
# include"bitStream.cpp"
# include"encoder.cpp"
# include"decoder.cpp"

int main() {
    ifstream inputFile("./input.txt");
    ofstream encodedOutputFile("./encodedOutput.txt");
    ofstream decodedOutputFile("./decodedOutput.txt");

    if(!inputFile) {
        cout<<"Hello"<<endl;
        cerr<<"cannot open the file"<<endl;
        return -1;
    }

    if (!encodedOutputFile) {
        cerr << "Error opening file for writing" << std::endl;
        return 1;
    }

    if(!decodedOutputFile) {
        cerr << "Error opening file for writing" << std::endl;
        return 1;
    }

    string str1="";
    string line;
    while (getline(inputFile, line)) {
        str1+=line;
    }

    cout<<"Text Taken -"<<endl;
    cout<<str1<<endl;
    Encoder* encoder=new Encoder();
    string bin=encoder->encodeText(str1);

    BitStream* stream=new BitStream();
    char ch;
    for(int i=0; i<bin.length(); i++) {
        if(stream->is_BitStream_Full()) {
            ch=stream->bitStream_getBit();
            encodedOutputFile<<ch;
            stream->clear_bitStream();
        }
        stream->push_bit_right(bin[i]);
    }
    ch=stream->bitStream_getBit();
    encodedOutputFile<<ch;
    
    cout<<"\n\nBit Stream created\n\n"<<endl;

    Decoder* decoder=new Decoder();

    string str2=decoder->decodeText(bin, encoder->getStringMap());

    decodedOutputFile<<str2;

    cout<<"Status : Completed\n\n";

    inputFile.close();
    encodedOutputFile.close();
    decodedOutputFile.close();
    
    return 0;
}