## Linear

### Functions: 

* Init

* Alloc

* Reset

### Logic: 

Uses an array to store the data of a static number of bytes in a linear fashion. 

Init: Adds values to the initial linearAllocator of the linear data

Alloc: Allocates a certain amount of bytes, moving the pointer forward in the linear data

Reset: Moves the pointer all the way to the beginning of the data

## Stack

### Functions: 

* Init

* Alloc

* Dealloc

* Reset

### Logic: 

Uses an array to store the data of a static number of bytes in a stack (last in, first out) fashion. 

Init: Adds values to the initial stackAllocator of the stack data

Alloc: Allocates a certain amount of bytes, moving the pointer forward in the stack data

Dealloc: Deallocates the last portion of data allocated to the stack

Reset: Moves the pointer all the way to the beginning of the data

## Heap

### Functions: 

* Init

* Malloc

* Free

* Realloc

* Calloc

### Logic: 

Uses a heap struct and arrays to keep track of memory and dynamically manage it