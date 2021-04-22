#include <iostream>
using namespace std;

struct Node {
	int data;
    int parent;
	Node* left;
	Node* right;
};

Node* newNode(int data, int parent) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
    node->parent = parent;
	node->left = node->right = NULL;
	return (node);
}

Node* insertNode(int **matrix, int r, int c, Node* root, int y, int x) {
	if (y < r && x < c) {
		Node* temp = newNode(matrix[y][x], 0);
		root = temp;
        if (x - 1 >= 0 && matrix[y][x - 1] != 0) {
            root->left = insertNode(matrix, r, c, root->left, y, x - 1);
        }
	}
	return root;
}

void inOrder(Node* root) {
	if (root != NULL) {
		inOrder(root->left);
		cout << root->data <<" ";
		inOrder(root->right);
	}
}


int main(void) {
    int r, c, x, y;
    cin >> r >> c >> x >> y;
    // int matrix[m][n]; // fixed size array
    int** matrix = new int* [r]; // dynamic array
    for (int i = 0; i < r; i++) {
        matrix[i] = new int[c];
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> matrix[i][j];
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    int center = matrix[y][x];
    cout << center << endl;
    Node* root = insertNode(matrix, r, c, root, y, x);
    inOrder(root);
	cout << endl;

    return 0;
}