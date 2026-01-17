#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;         
    int freq;       
    int index;        
    Node *left,*right;

    Node(char c,int f,int i){
        ch=c;
        freq=f;
        index=i;
        left=right=NULL;
    }
};
struct Compare{
    bool operator()(Node* a,Node* b) {
        if (a->freq==b->freq)
            return a->index>b->index;
        return a->freq>b->freq;        
    }
};
void preorder(Node* root,string code) {
    if (!root) return;

    if (root->left == NULL && root->right == NULL) {
        cout << root->ch << " : " << code << endl;
        return;
    }
    preorder(root->left, code + "0");
    preorder(root->right, code + "1");
}

int main(){
    int N;
    cout<<"Enter no. of characters: ";
    cin>>N;
    string S;
    cout<<"Enter characters: ";
    cin>>S;
    vector<int>freq(N);
    cout<<"Enter frequencies: ";
    for(int i=0;i<N;i++) {
        cin>>freq[i];
    }
    priority_queue<Node*,vector<Node*>,Compare>pq;
    for (int i=0;i<N; i++) {
        pq.push(new Node(S[i], freq[i],i));
    }
    int idx = N;
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* merged = new Node('$', left->freq + right->freq, idx++);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }
    cout << "Huffman Codes:\n";
    preorder(pq.top(), "");
    return 0;
}