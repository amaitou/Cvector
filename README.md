# Cvector

I have been struggling with arrays over the past 2 years of using the `C language`, as well as, I have always wondered why there are no dynamic arrays in `C language` like those in C++ language (`Vectors` for instance). <br />
That's why I have decided to create a `generic array` and simulate the vectors' behavior in C using `void pointers`.
So in this project, I made a generic array with dynamic resizing that you can use in your code without even taking care of leaks and resizing your array each time you recognize that your array is full of elements and you cannot pass the reserved for the memory.

# Methods

Like in vectors I have implemented some Functions that would make your life easier when using `Cvector` in ur code.

- __create_v

	```c
	t_vector	*__create_v(void);
	```
	The __create_v function is designed to facilitate the dynamic creation and initialization of a resizable array, or vector, as represented by the t_vector structure. This function begins by allocating memory for the structure and the associated data array. Robust error handling ensures that if memory allocation fails at any point, the function returns a null pointer. The vector is then initialized with a default capacity of 5 and a size of 0. Subsequently, memory is allocated for the actual data array within the vector, with additional error checks. The function utilizes memset to initialize the data array, setting all elements to NULL. Upon successful completion, the function returns a pointer to the initialized t_vector structure, providing a convenient and reliable mechanism for dynamically managing resizable arrays in a C program.


- __allocate_v

	```c
	t_vector	*__allocate_v(size_t size_t);
	```

	The __allocate_v function is designed to dynamically allocate and initialize a resizable array, represented by the t_vector structure, with a specified initial size. The function begins by allocating memory for the t_vector structure, checking for allocation errors and returning a null pointer if encountered. The capacity of the vector is then determined based on the provided size, with an additional half of that size added. This ensures some initial flexibility for potential growth. The vector is initialized with a size of 0, and memory is allocated for the data array within the vector. The data array is then initialized using memset to set all elements to NULL. If any memory allocation fails during this process, the function returns a null pointer. Finally, the function returns a pointer to the initialized t_vector structure, providing a convenient means to create and set up a dynamic array with a specified initial size in C programs.

- __begin_v

	```c
	void		**__begin_v(t_vector *vector);
	```
	The __begin_v function provides a simple and direct means to obtain a pointer to the beginning of the data array within a t_vector structure. Given a t_vector instance as an argument, the function calculates the starting address of the data array using pointer arithmetic, specifically by adding an offset of 0x00 to the base address of the array. The resulting pointer, __begin, is then returned. This function serves as a convenient utility for accessing the starting point of the dynamic array within the vector, allowing users to easily iterate through or manipulate the array elements from the beginning.

- __end_v

	```c
	void		**__end_v(t_vector *vector);
	```

	The __end_v function aims to provide a pointer to the end of the data array within a t_vector structure. It achieves this by calculating the end point using pointer arithmetic. The function sets __end to the sum of the base address of the data array (vector->vector) and the size of the vector obtained through the __size_v function. Consequently, the pointer __end points to the location immediately after the last valid element in the array which is NULL.