#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char alphabet;
    int freq;
     struct node* left, *right;
} SYMBOL;

struct Tree {
    unsigned size;
    unsigned capacity;
    SYMBOL **array;
};

SYMBOL* newnode(char alphabet, unsigned freq){
    SYMBOL* temp = (SYMBOL*) malloc(sizeof(SYMBOL));

    if(temp == NULL){
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    temp->left = temp->right = NULL;
    temp->alphabet = alphabet;
    temp->freq = freq;

    return temp;
}

struct Tree* createMinHeap(unsigned cap){
    struct Tree* minHeap = (struct Tree*)malloc(sizeof(struct Tree));

    minHeap->size = 0;
    minHeap->capacity = cap;
    minHeap->array = (SYMBOL**)malloc(minHeap->capacity * sizeof(SYMBOL*));

    return minHeap;
}

void swapSymbols(SYMBOL **a, SYMBOL **b){
    SYMBOL* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify (struct Tree* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if(left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    
    if(right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
    
    if(smallest != idx) {
        swapSymbols(&minHeap->array[smallest], &minHeap->array[idx]);

        minHeapify(minHeap, smallest);
    }
}

int isSizeOne (struct Tree* minHeap) {
    return (minHeap->size == 1);
}

SYMBOL * extractMin (struct Tree* minHeap){
    SYMBOL* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size -1];

    minHeap->size--;

    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap ( struct Tree* minHeap, SYMBOL* node) {
    minHeap->size ++;
    int i = minHeap->size -1;

    while (i && node->freq < minHeap->array[(i-1)/2]->freq) {
        minHeap->array[i] = minHeap->array[(i-1)/2];
        i = (i-1)/2;
    }
    minHeap->array[i] = node;
}

void buildMinHeap ( struct Tree* minHeap) {
    int n = minHeap->size-1;
    for(int i = (n-1)/2; i>=0; --i) {
        minHeapify(minHeap, i);
    }
}

int isLeaf(SYMBOL* root){
    return !(root->left) && !(root->right);
}

struct Tree* createAndBuildMinHeap(char alphabet[], int freq[], int size) {
    struct Tree* minHeap = createMinHeap(size);
    for(int i=0; i<size; i++) {
        minHeap->array[i] = newnode(alphabet[i], freq[i]);
    }

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

SYMBOL* buildHuffmanTree(char alphabet[], int freq[], int size) {
    SYMBOL* left, *right, *top;

    struct Tree* minHeap = createAndBuildMinHeap(alphabet, freq, size);

    while(!isSizeOne(minHeap)){
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newnode ('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

void printInorder(SYMBOL * root) {
    if(root->left) {
        printInorder(root->left);
    }

    if(root->right) {
        printInorder(root->right);
    }

    if(isLeaf(root)) {
        printf("%c ", root->alphabet);
    }
}


int main() {
    int n, i;
    printf ("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    char alphabet[n];
    int freq[n];

    printf("Enter the alphabets : ");
    for(i = 0; i< n; i++) {
        scanf(" %c", &alphabet[i]);
    }
    printf("Enter its frequencies: ");
    for(i = 0; i<n; i++) {
        scanf("%d", &freq[i]);
    }

    SYMBOL *root = buildHuffmanTree(alphabet, freq, n);

    printf("\nIn-order traversal of the tree (Huffman): ");
    printInorder(root);

    free(root);

    return 0;

}