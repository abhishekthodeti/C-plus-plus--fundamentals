# DYNAMIC MEMORY ALLOCATION ON HEAP USING POINTERS
To create a dynamic array,
took a pointer variable and assigned a chunk of  memory ,addresess of int type 
using 'new' keyword
(each took 4-Bytes of memory) in heap.
then after using memory sucessfully,used 'delete[]' keyword.

## OBSERVATION:
* used 'new' keyword to allocate memory
* assigned 0 to the base address of variable(To avoid garbage value)
* after assigning all values ,change pointer address back to the basevalue.
* used 'delete[]' to avoid memory leak.
