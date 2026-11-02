
#include <iostream>
#include <queue>
using namespace std;

// Structure for Huffman Tree node
struct Node
{
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f)
    {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

// Comparator for Min Heap
struct Compare
{
    bool operator()(Node* a, Node* b)
    {
        return a->freq > b->freq;
    }
};

// Generate Huffman Codes
void printCodes(Node* root, string code)
{
    if(root == NULL)
        return;

    // Leaf node
    if(root->left == NULL && root->right == NULL)
    {
        cout << root->ch << " : " << code << endl;
        return;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main()
{
    char ch[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int n = 6;

    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Insert all characters into Min Heap
    for(int i = 0; i < n; i++)
    {
        pq.push(new Node(ch[i], freq[i]));
    }

    // Build Huffman Tree
    while(pq.size() > 1)
    {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* top = new Node('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        pq.push(top);
    }

    // Print Huffman Codes
    cout << "Huffman Codes:" << endl;
    printCodes(pq.top(), "");

    return 0;
}
