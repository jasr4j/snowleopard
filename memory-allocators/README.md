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

* Alloc

* Free

* Realloc

### Logic: 

Uses an array to store the data of a static number of bytes in a heap fashion. 

Init: Initializes heap (array of stack allocators)

Alloc: Allocates a certain amount of bytes, moving the pointer forward in the linear data

Free: Frees memory associated with a certain pointer

Reset: Resets the memory (fully)