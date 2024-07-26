
# Huffman_Coding_Implementation

## Introduction
Huffman coding is a popular algorithm used for lossless data compression.The algorithm assigns variable-length codes to input characters, with shorter codes assigned to more frequent characters, resulting in efficient compression.
## Program Structure 
### File Description
* `bitStream.cpp` : Manages operations at the bit level to manipulate compressed data.

* `dynamicHeap.cpp` : Handles the dynamic heap utilized in building the Huffman tree.

* `Node.cpp` : This includes functions for creating links between nodes and determining binary equivalents.

* `encoder.cpp` : Handles the encoding process, from calculating the frequency of each character to creating the Huffman tree and generating the binary equivalent of the input text.

* `decoder.cpp` : Decodes the given encoded text.

* `main.cpp` : Contains the main function.

## Compilation 

To compile the code, run Makefile. You can use the following commands based on your operating system:

* For Windows : `mingw32-make all`
* For macOS or Linux : `make all`

### Execution
To execute the code, run the target file generated during compilation.

## Test Case 

Input Text : 

`Huffman coding, developed by David A. Huffman in 1952, is a widely used algorithm for lossless data compression. It assigns variable-length codes to input characters based on their frequencies, with more frequent characters receiving shorter codes. This efficient coding scheme minimizes the overall bit length of encoded data, making Huffman coding a fundamental technique in various applications, such as file compression and data transmission.`

Binary equivalent :

`0110010100111010010100010001011011111000100110111110111001111001101101011111011110000100100000101001101010110000111101100101111101011011101010101011011100101110111101101010110011010100110011001010011101001010001000101101111101110011111010101100001001000110000101010100101011111011101000110101111001100011110111100000101010101101110010011100000011110110101101010100110101101111111110001110011101000110101000110111111110010100110110001000010100001000100011011110101100111011110001001101010000101101111100010001000111001101011110101001101010101100011110101110001000111010011010111100011010010101111111111010110101111010100001010101110101000001111001101001110011111000100110111110000100011000110110111011100111010110010011001111000101001111011111111011001000110001111110001100101111101110000001111011001101011111000111001110001110111111101010011111000010111001001100001110010111000010001010111110011000111100011100111110010000110111111000110101001111100001011100100110000111001111000101001111011111111011001000110001111110001101111100000100001110100101110011110011011101000100111011011111100110001111111000100110111110000100010101001101001100010011111101000110000101001010011100010111000001110011110001001101111101110011110011011101000001010011100001000000110010001110011111100100011101001100100010001100011100111000110011011001000011111101101010010101100101111111000111100101000001111001101001110011111001101101001100000111001001101111100001111011011110101100111011101011111001000101101001011110011110011011100110010100111010010100010001011011111000100110111110111001111001101110101111010100010011011111110101101000000011100111011010101100011000001010011101111110010111001001100011011100111110100101011111111110011010100111000110101101011001011001010111000101011001111100110101111000101011111010000100110010100111110101110001101010011100101000011000100110101000010110111110001000100011100110101111101011011111110110111101011001110111100011111111011011110000100011101000100011100110101111010100`

## Implementation Details :
### How Huffman Coding Works
#### 1. Frequency Calculation:
 Count the frequency of each character in the input data.

#### 2. Tree Construction: 
Build a Huffman tree using a priority queue or a min-heap.

#### 3. Code Assignment: 
Traverse the Huffman tree to assign binary codes to each character.

#### 4. Encoding: 
Encode the input data using the generated Huffman codes.

## Applications of Huffman Coding

Huffman coding, renowned for its efficient compression capabilities, finds diverse applications across various domains:

* `Data Compression in File Systems` : Huffman coding is employed in compression algorithms for effectively reducing file sizes. This not only conserves disk space but also facilitates quicker file transfers.

* `Network Communication` : Huffman coding aids in efficient data transfer over networks by reducing the sizes of messages or packets. This results in decreased bandwidth usage and faster transmission speeds, which is particularly beneficial in internet communication and data exchange.

* `Text Compression in Databases` : In databases, Huffman coding is utilized to compress textual data. By reducing the storage footprint of text, it enables faster querying and processing of data, optimizing database performance.

These applications underscore the versatility and importance of Huffman coding in various technological domains, where efficient data compression is essential for storage, communication, and processing efficiency.
