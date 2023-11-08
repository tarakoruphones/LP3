#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
  
    // One of the input characters 
    char data; 

    // Frequency of the character 
    unsigned freq; 
  
    // Left and right child 
    Node *left, *right; 
  
    Node(char data, unsigned freq) 
  
    { 
  
        left = right = NULL; 
        this->data = data; 
        this->freq = freq; 
    } 

}; 
  
// For comparison of 
// two heap nodes (needed in min heap) 
struct compare { 
  
    bool operator()(Node* a, Node* b) 
  
    { 
        return (a->freq > b->freq); 
    } 
    
}; 
  
// Prints huffman codes from 
// the root of Huffman Tree. 
void printCodes(Node* head,string str="")

{

    if(head==NULL) return;

    if(head->left==NULL && head->right==NULL)
    {
        cout<<head->data<<" -> "<<str<<endl;
        return;
    }


    printCodes(head->left,str+"0");
    printCodes(head->right,str+"1");

}

  
// The main function that builds a Huffman Tree and 
// print codes by traversing the built Huffman Tree 
void HuffmanCodes(char data[], int freq[], int size) 
{ 
    struct Node *left, *right, *top; 
  
    // Create a min heap & inserts all characters of data[] 
    priority_queue <Node*, vector<Node*>, compare> minHeap; 
  
    for (int i = 0; i < size; ++i) 
        minHeap.push(new Node(data[i], freq[i])); 
  
    // Iterate while size of heap doesn't become 1 
    while (minHeap.size() != 1) { 
  
        // Extract the two minimum 
        // freq items from min heap 
        left = minHeap.top(); 
        minHeap.pop(); 
  
        right = minHeap.top(); 
        minHeap.pop(); 
  
        // Create a new internal node with 
        // frequency equal to the sum of the 
        // two nodes frequencies. Make the 
        // two extracted node as left and right children 
        // of this new node. Add this node 
        // to the min heap '$' is a special value 
        // for internal nodes, not used 
        top = new Node('$', left->freq + right->freq); 
  
        top->left = left; 
        top->right = right; 

        minHeap.push(top); 
    } 


    printCodes(minHeap.top(), ""); 
} 
  
int main() 
{ 
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
    int freq[] = { 5, 9, 12, 13, 16, 45 }; 
    int size = sizeof(arr) / sizeof(arr[0]); 
    HuffmanCodes(arr, freq, size); 
    return 0; 
} 
