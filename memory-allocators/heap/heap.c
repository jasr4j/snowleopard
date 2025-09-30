#include<stdio.h>
#include<stddef.h>

const size_t TOTAL = 256; 
#define T 256 // used to make sure that the heap struct has a defined size at compile time

typedef struct {
    char* base_addr; 
    size_t curr_alloc_bytes; 
    size_t curr_alloc_chunks; 
    char* chunkLi[T]; 
} heap; 

char* init(heap *myHeap) {
    myHeap->curr_alloc_chunks = 0; 
    myHeap->curr_alloc_bytes = 0; 
    myHeap->base_addr = myHeap->chunkLi[0]; 
}

void list(heap *myHeap) {
    printf("Total Allocated Bytes: %zu/%zu\n", myHeap->curr_alloc_bytes, TOTAL); 
    printf("Total Allocated Chunks: %zu\n", myHeap->curr_alloc_chunks); 
    for (int i = 0; i < myHeap->curr_alloc_chunks; i++) {
        printf("Memory Chunk %d Base Addr.: %p\n", i+1, (myHeap->chunkLi)[i]); 
    }

}

char* my_malloc(heap *myHeap, size_t bytes) {
    // initialize a new array in the chunkLi
    if (myHeap->curr_alloc_bytes + bytes > TOTAL) {
        printf("Cannot allocate more bytes than total memory\n"); 
        return NULL; 
    }
    myHeap->curr_alloc_chunks ++; 
    myHeap->curr_alloc_bytes += bytes; 
    char* addr = myHeap->base_addr; 
    myHeap->chunkLi[myHeap->curr_alloc_chunks - 1] = addr;
    myHeap->base_addr += bytes; 
    list(myHeap); 
    return addr;
    // add 1 to chunks, add bytes to num_bytes allocated
    // return base mem addr (chunkLi[index of new thing])
}

int main() {
    heap myHeap; 
    init(&myHeap); 
    list(&myHeap); 
    char in = '!'; 
    while (in != 'q') {
        printf("M (malloc) or Q (quit): "); 
        scanf(" %c", &in); 
        if (in == 'M') {
            size_t b; 
            printf("# of bytes: "); 
            scanf(" %zu", &b); 
            my_malloc(&myHeap, b); 
        } else if (in == 'Q') {
            return 0; 
        } else {
            printf("INVALID INPUT- EXITING PROGRAM\nExit Code 1\n");
            return 1; 
        }
    }
    return 0;
}