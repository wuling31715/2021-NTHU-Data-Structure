#include <iostream>
using namespace std;

int MAX = 0;

struct Node {
	int data;
    int x;
    int y;
	Node* left;
    Node* down;
	Node* right;
    Node* up;
};

Node* newNode(int data, int x, int y) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
    node->x = x;
    node->y = y;
	node->left = NULL;
    node->down = NULL;
    node->right = NULL;
    node->up = NULL;
	return (node);
}

Node* insertNode(int **matrix, int **visited, int r, int c, Node* root, int y, int x) {
	if (y < r && x < c) {
		Node* temp = newNode(matrix[y][x], x, y);
        cout << x << " " << y << endl;
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
        if (y + 1 < r && matrix[y + 1][x] != 0 && visited[y + 1][x] != 1) {
            root->down = insertNode(matrix, visited, r, c, root->down, y + 1, x);
        }        
        // visit right
        if (x + 1 < c && matrix[y][x + 1] != 0 && visited[y][x + 1] != 1) {
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

void printPathsRecur(Node* node, int* path, int pathLen, int r, int c);
void printArray(int* path, int pathLen);

void printPaths(Node* node, int r, int c) {
    int pathLenMax = r * c;
	int* path = new int[pathLenMax];
	printPathsRecur(node, path, 0, r, c);
}

void printPathsRecur(Node* node, int* path, int pathLen, int r, int c) {
	if (node == NULL) {
        return;
    }
	/* append this node to the path array */
	path[pathLen] = node->data;
	pathLen++;
	
	/* if to the destination, print the path that led to here */
	if (node->y == r - 1 && node->x == c - 1) {
		printArray(path, pathLen);
	} else {
		/* otherwise try both subtrees */
		printPathsRecur(node->left, path, pathLen, r, c);
		printPathsRecur(node->down, path, pathLen, r, c);
		printPathsRecur(node->right, path, pathLen, r, c);
		printPathsRecur(node->up, path, pathLen, r, c);
	}
}

void printArray(int* path, int pathLen) {
    int sum = 0;
	for (int i = 0; i < pathLen; i++) {
		cout << path[i] << " ";
        sum += path[i];
	}
    if (sum > MAX) {
        MAX = sum;
    }
    cout << "sum = " << sum << endl;
}

int main(void) {
    int r, c;
    cin >> r >> c;
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
    Node* root = insertNode(matrix, visited, r, c, root, 0, 0);
    // preOrder(root);
    printPaths(root, r, c);
    delete [] matrix;
    delete [] visited;
	cout << MAX << endl;
    return 0;
}