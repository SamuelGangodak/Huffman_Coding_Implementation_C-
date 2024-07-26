# include<iostream>
using namespace::std;

class BitStream{
    private:
        char byte;
        int size;
    public:
        BitStream() {
            this->byte=0;
            this->size=0;
        }
        bool is_BitStream_Full() {
            bool ret_val=false;
            if(this->size==7) ret_val=true;
            return ret_val;
        }
        void push_bit_right(char bit) {
            int b=0;
            if(bit=='1') b=1;
            char x = (char)(b);
            this->byte = this->byte << 1;
            this->byte |= x;
            this->size++;
        }
        void clear_bitStream() {
            this->byte = 0;
            this->size = 0;
        }
        char bitStream_getBit() {
            return this->byte;
        }
};