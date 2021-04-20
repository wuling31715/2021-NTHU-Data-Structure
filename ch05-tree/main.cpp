#include <iostream>
#include <string>
#include <queue>

using namespace std;

// class BinaryTree;
class TreeNode{
public:
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode *parent;
    string str;
    
    TreeNode():leftchild(0),rightchild(0),parent(0),str(""){};
    TreeNode(string s):leftchild(0),rightchild(0),parent(0),str(s){};
    
};
class BinaryTree{
public:
    TreeNode *root;			    // 以root作為存取整棵樹的起點
    BinaryTree():root(0){};
    BinaryTree(TreeNode *node):root(node){};
    
    void Preorder(TreeNode *current);
    void Inorder(TreeNode *current);
    void Postorder(TreeNode *current);
    void Levelorder();

    TreeNode* leftmost(TreeNode *current);
    TreeNode* rightmost(TreeNode *current);

    TreeNode* InorderSuccessor(TreeNode *current);
    TreeNode* InorderPredecessor(TreeNode *current);

    void Inorder_by_parent(TreeNode *root);
    void Inorder_Reverse(TreeNode *root);

};

void BinaryTree::Preorder(TreeNode *current){
    if (current) {                          // if current != NULL
        cout << current->str << " ";   // V
        Preorder(current->leftchild);       // L
        Preorder(current->rightchild);      // R
    }
}

void BinaryTree::Inorder(TreeNode *current){
    if (current) {                          // if current != NULL
        Inorder(current->leftchild);        // L
        cout << current->str << " ";   // V
        Inorder(current->rightchild);       // R
    }
}

void BinaryTree::Postorder(TreeNode *current){
    if (current) {                          // if current != NULL
        Postorder(current->leftchild);      // L
        Postorder(current->rightchild);     // R
        cout << current->str << " ";   // V
    }
}

void BinaryTree::Levelorder(){
    
    queue<TreeNode*> q;
    q.push(this->root);					    // 把root作為level-order traversal之起點
    								        // 推進queue中
    while (!q.empty()){                     // 若queue不是空的, 表示還有node沒有visiting

    	TreeNode *current = q.front();      // 取出先進入queue的node
    	q.pop();                          
    	cout << current->str << " ";   // 進行visiting

    	if (current->leftchild != NULL){    // 若leftchild有資料, 將其推進queue
            q.push(current->leftchild);
        }
        if (current->rightchild != NULL){   // 若rightchild有資料, 將其推進queue
            q.push(current->rightchild);
        }
    }
}

TreeNode* BinaryTree::leftmost(TreeNode *current){
    while (current->leftchild != NULL){
        current = current->leftchild;
    }
    return current;
}

TreeNode* BinaryTree::InorderSuccessor(TreeNode *current){
    if (current->rightchild != NULL){
        return leftmost(current->rightchild);
    }
    
    // 利用兩個pointer: successor與current做traversal 
    TreeNode *successor = current->parent;   
    while (successor != NULL && current == successor->rightchild) {
        current = successor;
        successor = successor->parent;
    }
    return successor;
}

void BinaryTree::Inorder_by_parent(TreeNode *root){
    TreeNode *current = new TreeNode;
    current = leftmost(root);

    while(current){
        cout << current->str << " ";
        current = InorderSuccessor(current);
    }
}

TreeNode* BinaryTree::rightmost(TreeNode *current){
    while (current->rightchild != NULL){
        current = current->rightchild;
    }
    return current;
}

TreeNode* BinaryTree::InorderPredecessor(TreeNode *current){
    if (current->leftchild != NULL){
        return rightmost(current->leftchild);
    }
    // 利用兩個pointer: predecessor與current做traversal
    TreeNode *predecessor = current->parent;
    
    while (predecessor != NULL && current == predecessor->leftchild) {
        current = predecessor;
        predecessor = predecessor->parent;
    }    
    return predecessor;
}

void BinaryTree::Inorder_Reverse(TreeNode *root){
    TreeNode *current = new TreeNode;
    current = rightmost(root);
    while(current){
        cout << current->str << " ";
        current = InorderPredecessor(current);
    }
}

int main() {

    TreeNode *nodeA = new TreeNode("A"); 
    TreeNode *nodeB = new TreeNode("B"); 
    TreeNode *nodeC = new TreeNode("C"); 
    TreeNode *nodeD = new TreeNode("D"); 
    TreeNode *nodeE = new TreeNode("E"); 
    TreeNode *nodeF = new TreeNode("F"); 
    TreeNode *nodeG = new TreeNode("G"); 
    TreeNode *nodeH = new TreeNode("H"); 
    TreeNode *nodeI = new TreeNode("I");
    
    nodeA->leftchild = nodeB; 
    nodeA->rightchild = nodeC; 
    nodeB->leftchild = nodeD; 
    nodeB->rightchild = nodeE; 
    nodeE->leftchild = nodeG; 
    nodeE->rightchild = nodeH; 
    nodeC->leftchild = nodeF; 
    nodeF->rightchild = nodeI;

    nodeB->parent = nodeA; 
    nodeC->parent = nodeA;
    nodeD->parent = nodeB; 
    nodeE->parent = nodeB;
    nodeG->parent = nodeE; 
    nodeH->parent = nodeE;
    nodeF->parent = nodeC; 
    nodeI->parent = nodeF;
    
    BinaryTree T(nodeA);
    
    T.Preorder(T.root);
    cout << endl;
    T.Inorder(T.root);
    cout << endl;
    T.Postorder(T.root);
    cout << endl;
    T.Levelorder();
    cout << endl;
    T.Inorder_by_parent(T.root);
    cout << endl;
    T.Inorder_Reverse(T.root);
    cout << endl;    
    
    return 0;
}