#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure Definition
typedef struct vector
{
    int size, count;
    int *data;    // Using data point to the store location
} vector; 

// Acquire a SequenceList can store at most n elements
vector *getNewVector(int n) {
    vector *p = (vector *)malloc(sizeof(vector));
    p->size = n;
    p->count = 0;
    p->data = (int *)malloc(sizeof(int) * n);
    return p;
}

int insert(vector *v, int pos, int val) {
    if (pos < 0 || pos > v->count) return 0;  //If the pos is illegel, cannot insert
    if (v->size == v->count) return 0; //Judge whether the SequenceList if fully used, if so, we cannot insert successfully
    for (int i = v->count -1; i >= pos; i--){  // Iterate from the last number in the List to the pos
        v->data[i+1] = v->data[i];         // The number should be moved to next block
    }
    v->data[pos] = val;     // The position emptyed should be replaced as the val inserted
    v->count += 1;          // The number of elements in the dataset should be added(+1)
    // printf("----");
    return 1;               // Replace the insert sucessfully
}

int erase(vector *v, int pos) {
    if (pos < 0 || pos >= v->count) return 0;
    for (int i = pos + 1; i < v->count; i++){
        v->data[i-1] = v->data[i];
    }
    v->count -= 1;
    return 1;
} 

void clear(vector *v) {
    if (v == NULL) return;
    free(v->data);  //clear the continuous storage area
    free(v);        //clear the store space of SquenceList itself
    return;
}

void output_vector(vector *v) {
    int len = 0;
    for (int i = 0; i < v->size; i++) {
        len += printf("%3d", i);
    }
    printf("\n");
    for (int i = 0; i < len; i++) printf("-");
    printf("\n");
    for (int i = 0; i < v->count; i++) {
        printf("%3d", v->data[i]);
    }
    printf("\n");

    return;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    // Test Part
    vector *v = getNewVector(MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 4, pos, val;
        switch (op) {
            case 0:
            case 1:
            case 2:
                pos = rand() % (v->count + 2);
                // printf("%d", v->count);
                val = rand() % 100;
                printf("insert %d at %d to vector = %d\n",
                        val, pos, insert(v, pos, val));
                break;
            case 3:
                pos =rand() % (v->count + 2);
                printf("erase item at %d in vector = %d\n",
                        pos, erase(v, pos));
                break;
        }
        output_vector(v);
    }
    clear(v);
    return 0;
}
