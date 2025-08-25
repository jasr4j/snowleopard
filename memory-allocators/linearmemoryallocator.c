#include<stdio.h>
#include<stddef.h>

typedef struct {
    char *memory_pool; 
    char *current_pos; 
    size_t pool_size; 
} linearAllocator; 

int linearInit(linearAllocator* allocator, size_t size, char* data); 
void* linearAlloc(linearAllocator* allocator, size_t size); 
void linearReset(linearAllocator* allocator); 

static size_t SIZE = 128; // in bytes

int main(int argc, char *argv[]) {
    char data[SIZE];
    linearAllocator allocator; 
    linearInit(&allocator, SIZE, data); 
    char input = '!'; 
    while (input != 'q') {
        printf("Allocate (a), Reset (r), Quit (q): "); 
        scanf(" %c", &input); 
        if (input == 'a') {
            printf("How many bytes do you want to allocate? "); 
            size_t bytes; 
            scanf(" %zu", &bytes); 
            linearAlloc(&allocator, bytes); 
        } else if (input == 'r') {
            linearReset(&allocator); 
        } else if (input == 'q') {
            return 0; 
        } else {
            printf("Invalid Input - Try Again\n");
        }
    }
    return 0; 
}

int linearInit(linearAllocator* allocator, size_t size, char* data) {
    allocator->pool_size = size; 
    allocator->memory_pool = data; 
    allocator->current_pos = data; 
    printf("Initialized.\n"); 
    printf("Pool Size: %zu; Memory Pool: %p; Current: %p\n", size, data, data); 
    return 0; 
}

void* linearAlloc(linearAllocator* allocator, size_t size) {
    if (allocator->pool_size - (allocator->current_pos - allocator->memory_pool) < size) {
        printf("Not enough memory in pool\n"); 
        return NULL; 
    } else {
        char* temp = allocator->current_pos;
        allocator->current_pos += size; 
        printf("Allocated %zu bytes of memory.\n", size); 
        printf("Pool Size: %zu; Memory Pool: %p; Current: %p\n", allocator->pool_size, allocator->memory_pool, allocator->current_pos); 
        printf("Used %zu bytes of memory\n", allocator->current_pos - allocator->memory_pool);
        return temp; 
    }
}

void linearReset(linearAllocator* allocator) {
    allocator->current_pos = allocator->memory_pool; 
    printf("Memory Reset\n"); 
    printf("Pool Size: %zu; Memory Pool: %p; Current: %p\n", allocator->pool_size, allocator->memory_pool, allocator->current_pos); 
}

// memory pool = char array since char pointers can be used for any data type
// pointer to first empty spot
// if new data fits in pool, add it and move the pointer
// deallocate by moving to the beginning of the pool