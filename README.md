Text Compressor
This project is a simple text compressor using Huffman coding. Huffman coding is a popular algorithm used for lossless data compression. This project includes the following functionalities:

Calculating the frequency of each character in a given string.
Building a Huffman tree based on character frequencies.
Encoding the string using the Huffman tree.
Decoding the encoded string back to its original form.
Features
Frequency Calculation: Calculates the frequency of each character in the input string.
Huffman Tree Construction: Constructs a Huffman tree from the character frequencies.
Encoding: Encodes the input string using the Huffman tree.
Decoding: Decodes the encoded string back to the original string.


Code Structure
TreeNode Class: Represents a node in the Huffman tree.
Compare Class: Custom comparator for the priority queue to order the nodes by frequency.
FrequencyDetc Function: Calculates the frequency of each character in the input string.
buildTree Function: Constructs the Huffman tree from the character frequencies.
encode Function: Encodes the input string using the Huffman tree.
decode Function: Decodes the encoded string back to the original string.
Contributing
Feel free to fork this repository and submit pull requests. For major changes, please open an issue first to discuss what you would like to change.
