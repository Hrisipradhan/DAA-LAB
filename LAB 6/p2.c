#include <stdio.h>
#include <stdlib.h>

// Define the structure SYMBOL
struct SYMBOL {
    char alphabet;
    int frequency;
};

// Define the structure for a node in the Huffman Tree
struct HuffmanNode {
    char alphabet;
    int frequency;
    struct HuffmanNode *left, *right;
};

// A structure for Min-Heap (Priority Queue)
struct MinHeap {
    int size;
    int capacity;
    struct HuffmanNode** array;
};

// Create a new node for the Huffman Tree
struct HuffmanNode* newNode(char alphabet, int frequency) {
    struct HuffmanNode* temp = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
    temp->alphabet = alphabet;
    temp->frequency = frequency;
    temp->left = temp->right = NULL;
    return temp;
}

// Create a Min-Heap
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct HuffmanNode**)malloc(minHeap->capacity * sizeof(struct HuffmanNode*));
    return minHeap;
}

// Swap two nodes in the heap
void swapNodes(struct HuffmanNode** a, struct HuffmanNode** b) {
    struct HuffmanNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function to maintain the min-heap property
void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;

    if (smallest != idx) {
        swapNodes(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Check if the size of the heap is one
int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// Extract the node with minimum frequency
struct HuffmanNode* extractMin(struct MinHeap* minHeap) {
    struct HuffmanNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

// Insert a new node into the min-heap
void insertMinHeap(struct MinHeap* minHeap, struct HuffmanNode* node) {
    minHeap->size++;
    int i = minHeap->size - 1;
    while (i && node->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

// Build a min-heap
void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; i--)
        minHeapify(minHeap, i);
}

// Create a min-heap of given capacity and insert all characters of SYMBOL array
struct MinHeap* createAndBuildMinHeap(struct SYMBOL symbol[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(symbol[i].alphabet, symbol[i].frequency);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

// Build the Huffman Tree
struct HuffmanNode* buildHuffmanTree(struct SYMBOL symbol[], int size) {
    struct HuffmanNode *left, *right, *top;

    // Create a min-heap and insert all symbols
    struct MinHeap* minHeap = createAndBuildMinHeap(symbol, size);

    // Iterate while the size of the heap is greater than 1
    while (!isSizeOne(minHeap)) {
        // Extract two nodes with the minimum frequency
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        // Create a new internal node with frequency equal to the sum of the two nodes' frequencies
        top = newNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        // Insert the new node into the min-heap
        insertMinHeap(minHeap, top);
    }

    // The remaining node is the root of the Huffman tree
    return extractMin(minHeap);
}

// In-order traversal of the Huffman Tree
void inOrderTraversal(struct HuffmanNode* root) {
    if (root == NULL)
        return;

    // Traverse left subtree
    inOrderTraversal(root->left);

    // Print the character if it's a leaf node
    if (root->alphabet != '$')
        printf("%c ", root->alphabet);

    // Traverse right subtree
    inOrderTraversal(root->right);
}

int main() {
    int n;

    // Input number of distinct alphabets
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    // Create an array of SYMBOL structures
    struct SYMBOL symbols[n];

    // Input the alphabets
    printf("Enter the alphabets: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &symbols[i].alphabet);
    }

    // Input the frequencies
    printf("Enter its frequencies: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &symbols[i].frequency);
    }

    // Build Huffman Tree
    struct HuffmanNode* root = buildHuffmanTree(symbols, n);

    // Perform in-order traversal of the Huffman tree
    printf("In-order traversal of the tree (Huffman): ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
