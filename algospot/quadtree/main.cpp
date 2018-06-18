// https://algospot.com/judge/problem/read/QUADTREE

#include <iostream>
#include <string>

using namespace std;

const int MAX_CHILD = 4;
const int REVERT_TABLE[MAX_CHILD] = {2, 3, 0, 1};

class Node {
    private:
    char m_value;
    Node *mp_child[MAX_CHILD];
    
    public:
    Node(char currVal) {
        this->m_value = currVal;
        for (int i=0; i<MAX_CHILD; ++i)
            mp_child[i] = NULL;
    }
    void setChild(int idx, Node* child) { mp_child[idx] = child; }
    Node* getChild(int idx) { return mp_child[idx]; }
    char getValue(void) { return m_value; }
    bool hasChild(void) { return (mp_child[0] == NULL) ? false : true; }
};

class QuardTree{
    private:
    Node *m_head;
    
    public:
    QuardTree(void) { m_head = NULL; }
    void makeTree(Node* pParent, string* pStrInfo) {
        if (pStrInfo->empty())
            return;

        if (pParent == NULL && pStrInfo->size() == 1 ) {
            m_head = pParent = new Node((*pStrInfo)[0]);
            return;
        }

        if (pParent == NULL) {
            m_head = pParent = new Node((*pStrInfo)[0]);
            *pStrInfo = pStrInfo->substr(1);
        }

        for (int i=0; i<MAX_CHILD; ++i) {
            Node* pCurrNode = new Node((*pStrInfo)[0]);
            *pStrInfo = pStrInfo->substr(1);
            pParent->setChild(i, pCurrNode);

            if (pCurrNode->getValue() == 'x') {
                makeTree(pCurrNode, pStrInfo);
            }
        }
    }
    void parseImgStr(string strInfo) {
        makeTree(m_head, &strInfo);
    }
    void reverseTree(Node* pParent) {
        cout<< pParent->getValue();

        if (!pParent->hasChild())
            return;

        for (int i=0; i<MAX_CHILD; ++i) {
            Node* childNode = pParent->getChild(REVERT_TABLE[i]);
            if (childNode->hasChild()) {
                reverseTree(childNode);
            }
            else {
                cout<< childNode->getValue();
            }
        }
    }
    void printTree(void) {
        reverseTree(m_head);
    }
};

int main(void) {
    int tc;
    cin>> tc;

    while(tc--) {
        string strInfo;
        cin >> strInfo;
        QuardTree quardTree;
        quardTree.parseImgStr(strInfo);
        quardTree.printTree();
        cout<< endl;
    }
}