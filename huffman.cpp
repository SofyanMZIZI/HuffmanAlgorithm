#include "huffman.hpp"
#include <unordered_map>
using namespace std;

// getter pour localiser un nouveaux noeud dans l'arbre
Node *getNode(char ch, int freq, Node *left, Node *right)
{
    Node *node = new Node();

    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}
// on traverse  Huffman's arbre and store Huffman Codes on a choisi to store it in an unorder map cuz it's flexible and easy to use 
void encode(Node *root, string str,unordered_map<char, string> &huffmanCode)
{
    if (root == nullptr)
        return;

    if (!root->left && !root->right)
    {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}
// la fonction pour decoder l'arbre
void decode(Node *root, int &index, string str)
{
    if (root == nullptr)
    {
        return;
    }

    // found a leaf node
    if (!root->left && !root->right)
    {
        cout << root->ch;
        return;
    }

    index++;

    if (str[index] == '0')
        decode(root->left, index, str);
    else
        decode(root->right, index, str);
}

// on va construire l'arbre et la decoder
void HuffmanTree(string text){
    //on compte la frequence de chaque character and store it in our  map
    unordered_map<char, int> freq;
    for (char ch : text)
    {
        freq[ch]++;
    }
    // on construit un tableau de noeud ou plus precisement une pile des noeuds et construire enfin l'arbre
    priority_queue<Node *, vector<Node *>, comparer> pq;

    for (auto pair : freq)
    {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }

    while (pq.size() != 1)
    {
        // Remove les deux noeuds of the highest priority
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        // here comes the magic xD
        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }

    Node *root = pq.top();

    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    cout << "les codes du Huffman sont :\n"
         << '\n';
    for (auto pair : huffmanCode)
    {
        cout << pair.first << " " << pair.second << '\n';
    }

    cout << "\nl'Original mot était  :\n"
         << text << '\n';

    // print encoded string
    string str = "";
    for (char ch : text)
    {
        str += huffmanCode[ch];
    }

    cout << "\nEncoded string est :\n"
         << str << '\n';

    // traverse the Huffman Tree again and this time
    // on va decoder the encoded string
    int index = -1;
    cout << "\nDecoded string est: \n";
    while (index < (int)str.size() - 2)
    {
        decode(root, index, str);
    }
}


// la fonction main 
int main()
{
    // Huffman Magic should  starts here
    string text = "abracadabra let's get this party started xD";
    HuffmanTree(text);
    return 0;
}
