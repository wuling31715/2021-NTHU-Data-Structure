#include <iostream>
using namespace std;

int MIN = 9999999;

struct Node {
	int data;
	Node* left;
    Node* down;
	Node* right;
    Node* up;
};

Node* newNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
    node->down = NULL;
    node->right = NULL;
    node->up = NULL;
	return (node);
}

Node* insertNode(int **matrix, int **visited, int r, int c, Node* root, int y, int x) {
	if (y < r && x < c) {
		Node* temp = newNode(matrix[y][x]);
		root = temp;
        visited[y][x] = 1;
        // show visited
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << visited[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        // visit left
        if (x - 1 >= 0 && matrix[y][x - 1] != 0 && visited[y][x - 1] != 1) {
            root->left = insertNode(matrix, visited, r, c, root->left, y, x - 1);
        }
        // visit down
        if (y + 1 >= 0 && matrix[y + 1][x] != 0 && visited[y + 1][x] != 1) {
            root->down = insertNode(matrix, visited, r, c, root->down, y + 1, x);
        }        
        // visit right
        if (x + 1 >= 0 && matrix[y][x + 1] != 0 && visited[y][x + 1] != 1) {
            root->right = insertNode(matrix, visited, r, c, root->right, y, x + 1);
        }
        // visit up
        if (y - 1 >= 0 && matrix[y - 1][x] != 0 && visited[y - 1][x] != 1) {
            root->up = insertNode(matrix, visited, r, c, root->up, y - 1, x);
        }
	}
	return root;
}

void preOrder(Node* root) {
	if (root != NULL) {
		cout << root->data << " ";
		preOrder(root->left);
		preOrder(root->down);
		preOrder(root->right);
		preOrder(root->up);
	}
}

void printPathsRecur(Node* node, int* path, int pathLen);
void printArray(int* path, int pathLen);

void printPaths(Node* node, int pathLenMax) {
	int* path = new int[pathLenMax];
	printPathsRecur(node, path, 0);
}

void printPathsRecur(Node* node, int* path, int pathLen) {
	if (node == NULL) {
        return;
    }
	/* append this node to the path array */
	path[pathLen] = node->data;
	pathLen++;
	
	/* it's a leaf, so print the path that led to here */
	if (node->left == NULL && node->down == NULL && node->right == NULL && node->up == NULL) {
		printArray(path, pathLen);
	} else {
		/* otherwise try both subtrees */
		printPathsRecur(node->left, path, pathLen);
		printPathsRecur(node->down, path, pathLen);
		printPathsRecur(node->right, path, pathLen);
		printPathsRecur(node->up, path, pathLen);
	}
}

void printArray(int* path, int pathLen) {
    int sum = 0;
	for (int i = 0; i < pathLen; i++) {
		cout << path[i] << " ";
        sum += path[i];
	}
    if (sum < MIN) {
        MIN = sum;
    }
    cout << "sum = " << sum << endl;
}

int main(void) {
    int r, c, x, y;
    cin >> r >> c >> x >> y;
    // int matrix[m][n]; // fixed size array
    int** matrix = new int* [r]; // dynamic array
    int** visited = new int* [r]; // dynamic array
    
    for (int i = 0; i < r; i++) {
        matrix[i] = new int[c];
        visited[i] = new int[c];
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> matrix[i][j];
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    Node* root = insertNode(matrix, visited, r, c, root, y, x);
    // preOrder(root);
    printPaths(root, r * c);
    delete [] matrix;
    delete [] visited;
	cout << MIN << endl;
    return 0;
}