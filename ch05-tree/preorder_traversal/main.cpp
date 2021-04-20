#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct node *Nodeptr;
typedef struct node {
    int val;   // 此節點的值
    Nodeptr left;   // 左節點
    Nodeptr right;   // 右節點
} Node;   // 直接用 Node 代替 struct node

Node *addtree(Node *tree, int val);
void preorder(Node *tree);
Node *talloc(void);

int main() {
    int n, m;
    while (cin >> n) {   // 數量
        Node *root = NULL;   // 空樹
        for (int i=0; i<n; i++) {
            cin >> m;   // 各節點值
            root = addtree(root, m);   // 插入 m
        }
        preorder(root);   // 呼叫 preorder 函式，印出 Binary Tree
        cout << endl;   // 消失的換行
    }
    return 0;
}

Node *addtree(Node *tree, int val) {   // 插入 val 至 tree
    if (tree == NULL) {   // 這個節點沒東西
        tree = talloc();   // 挪個空間給他
        tree->val = val;   // 就決定是你了！
        tree->left = NULL;   // 定義為空
        tree->right = NULL;
    } else if (val < tree->val)   // 比節點小
        tree->left = addtree(tree->left, val);   // 遞歸呼叫此函式，並以回傳值取代左節點
    else
        tree->right = addtree(tree->right, val);
    return tree;   // 回傳新的 binary tree
}

void preorder(Node *tree) {   // 以 Pre-Order 列出 Binary Tree
    if (!tree)   // 這節點沒東西了
        return;
    printf("%d ", tree->val);   // 中
    preorder(tree->left);   // 左
    preorder(tree->right);   // 右
}

Node *talloc(void) {   // 配置 Node 空間
    return (Node *) malloc(sizeof(struct node));   // 呼叫 malloc (Memory Allocate) 配置適合 Node 的記憶體大小，並轉換為 "Node *" 型態
}