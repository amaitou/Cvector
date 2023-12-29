# Cvector

I have been struggling with arrays over the past 2 years of using the `C language`, as well as, I have always wondered why there are no dynamic arrays in `C language` like those in C++ language (`Vectors` for instance). <br />
That's why I have decided to create a `generic array` and simulate the vectors' behavior in C using `void pointers`.
So in this project, I made a generic array with dynamic resizing that you can use in your code without even taking care of leaks and resizing your array each time you recognize that your array is full of elements and you cannot pass the reserved memory.

---

# Methods

Like in vectors I have implemented some Functions that would make your life easier when using `Cvector` in ur code.

- __create_v

	```c
	t_vector	*__create_v(void);
	```
	The `__create_v` function is designed to facilitate the dynamic creation and initialization of a resizable array, or vector, as represented by the t_vector structure. This function begins by allocating memory for the structure and the associated data array. Robust error handling ensures that if memory allocation fails at any point, the function returns a null pointer. The vector is then initialized with a default capacity of 5 and a size of 0. Subsequently, memory is allocated for the actual data array within the vector, with additional error checks. The function utilizes memset to initialize the data array, setting all elements to NULL. Upon successful completion, the function returns a pointer to the initialized t_vector structure, providing a convenient and reliable mechanism for dynamically managing resizable arrays in a C program.


- __allocate_v

	```c
	t_vector	*__allocate_v(size_t size_t);
	```

	The `__allocate_v` function is designed to dynamically allocate and initialize a resizable array, represented by the t_vector structure, with a specified initial size. The function begins by allocating memory for the t_vector structure, checking for allocation errors and returning a null pointer if encountered. The capacity of the vector is then determined based on the provided size, with an additional half of that size added. This ensures some initial flexibility for potential growth. The vector is initialized with a size of 0, and memory is allocated for the data array within the vector. The data array is then initialized using memset to set all elements to NULL. If any memory allocation fails during this process, the function returns a null pointer. Finally, the function returns a pointer to the initialized t_vector structure, providing a convenient means to create and set up a dynamic array with a specified initial size in C programs.

	---

- __begin_v

	```c
	void		**__begin_v(t_vector *vector);
	```
	The `__begin_v` function provides a simple and direct means to obtain a pointer to the beginning of the data array within a t_vector structure. Given a t_vector instance as an argument, the function calculates the starting address of the data array using pointer arithmetic, specifically by adding an offset of 0x00 to the base address of the array. The resulting pointer, __begin, is then returned. This function serves as a convenient utility for accessing the starting point of the dynamic array within the vector, allowing users to easily iterate through or manipulate the array elements from the beginning.

	---

- __end_v

	```c
	void		**__end_v(t_vector *vector);
	```

	The `__end_v` function aims to provide a pointer to the end of the data array within a t_vector structure. It achieves this by calculating the end point using pointer arithmetic. The function sets __end to the sum of the base address of the data array (vector->vector) and the size of the vector obtained through the __size_v function. Consequently, the pointer __end points to the location immediately after the last valid element in the array which is NULL.

	---

- __get_v

	```c
	void		*__get_v(t_vector *vector, size_t index);
	```
	The `__get_v` function is designed to retrieve the value stored at a specified index within the dynamic array of a t_vector structure. It performs a boundary check to ensure that the provided index is within the valid range of the vector's size. If the index is out of bounds, the function returns a null pointer ((void *)0x00). Otherwise, it retrieves the value at the specified index from the vector's data array and returns it.

	---

- __front_v

	```c
	void		*__front_v(t_vector *vector);
	```

	The __front_v function is designed to retrieve the value stored at the front (first element) of the dynamic array within a t_vector structure. It checks whether the vector is empty using the __empty_v function. If the vector is not empty, the function returns a pointer to the value at the first index of the vector's data array. If the vector is empty, the function returns a null pointer ((void *)0x00).

	---

- __back_v

	```c
	void		*__back_v(t_vector *vector);
	```
	The `__back_v` function in the t_vector context serves to return a pointer to the last element of the dynamically-sized array represented by the t_vector structure. It comprehensively checks whether the vector contains any elements through the __empty_v check and, if not empty, accesses the last element by its current size minus one. If the vector is found to be empty, the function safely returns a NULL pointer. This utility function is particularly useful for implementing stack-like behavior, or when simply retrieving the most recently added element is required without altering the state of the vector.

	---

- __free_v

	```c
	void		__free_v(t_vector *vector);
	```
	The `__free_v` function is designed to release the memory allocated for a dynamic array managed by the t_vector structure. This function first invokes the __clear_v function to clear any resources held by the elements within the dynamic array. Subsequently, it frees the memory allocated for the array itself using free(vector->vector). Finally, it deallocates the memory reserved for the t_vector structure by calling free(vector). The purpose of this function is to ensure proper cleanup and prevent memory leaks associated with the dynamic array, providing a convenient and comprehensive way to release all resources associated with the t_vector structure.

	---

- __clear_v

	```c
	int			__clear_v(t_vector *vector);
	```
	The `__clear_v` function is responsible for removing all elements from the dynamic array managed by the t_vector structure. It utilizes a loop that repeatedly invokes the __pop_v function until the array becomes empty. The loop condition is checked using the __empty_v function, which returns true if the dynamic array is empty. The function returns 1 (true) if the array is initially empty, indicating that no elements needed to be cleared. Otherwise, it returns 0 (false) after successfully clearing all elements from the dynamic array.

	---

- __pop_v

	```c
	int			__pop_v(t_vector *vector);
	```
	The `__pop_v` function is designed to remove the last element from the dynamic array managed by the t_vector structure. It first calculates the index of the last element using the variable __last, which is equal to the current size of the array minus one. The function then checks if the array is not empty using the __empty_v function. If the array is not empty, it frees the memory allocated for the last element using free(vector->vector[__last]), sets the corresponding element in the array to (void *)0x0 to indicate that it is now unused, and decrements the size of the array. The function returns 0 to signify a successful removal of the element.

	---

- __empty_v

	```c
	int			__empty_v(t_vector *vector);
	```
	The `__empty_v` function is a simple utility function designed to check whether the dynamic array managed by the t_vector structure is empty. It does so by evaluating the condition !vector->size, which returns true (1) if the size of the array is zero, indicating that it contains no elements. Otherwise, it returns false (0), signifying that the array has one or more elements.

	---

- __push_v

	```c
	int			__push_v(t_vector **vector, void *value, size_t size);
	```
	The `__push_v` function is designed to add a new element to the dynamic array managed by the t_vector structure. It takes a pointer to the original vector (*vector), the value to be added (value), and the size of each element in the array (size). The function first allocates memory for a temporary vector __v using malloc, which will be used to store the updated array. If the allocation fails, the function returns 1 to indicate an error.
	<br />
	Next, it checks if the existing vector is at capacity. If so, it doubles the capacity of the temporary vector (__v) and allocates memory for the updated array. It then copies the elements from the original vector to the new vector using the __copy_v function, which ensures that the contents are preserved. If the copying process fails, the function frees the memory associated with the original vector and returns an error.
	- __copy_v
		```c
		static int	__copy_v(t_vector *old_vector, t_vector *new_vector, size_t size)
		{
			size_t	i;

			i = 0;
			while (i < __size_v(old_vector))
			{
				new_vector->vector[i] = (void *)malloc(size);
				if (!new_vector->vector[i])
					return (1);
				memset(new_vector->vector[i], 0, size);
				memcpy(new_vector->vector[i], old_vector->vector[i], size);
				++i;
			}
			return (0);
		}
		```
	If the original vector is not at capacity, the temporary vector is freed. The new element is then added to the original vector at the current size index, and the size of the vector is incremented. Finally, a null pointer is placed at the next index to indicate the end of the array. The function returns 0 to signify a successful addition of the element.

	---

- __size_t

	```c
	size_t		__size_v(t_vector *vector);
	```
	The `__size_v` function is a simple utility function that returns the current size (number of elements) of the dynamic array managed by the t_vector structure. It directly retrieves the size attribute from the vector parameter and returns this value.

	---

- __capacity_v

	```c
	size_t		__capacity_v(t_vector *vector);
	```
	The `__capacity_v` function is a straightforward utility function that returns the current capacity of the dynamic array managed by the t_vector structure. It directly retrieves the capacity attribute from the vector parameter and returns this value.

---

# Usage

Before using this `cvector`  library, make sure to make the lib first by typing
```sh
make # this command will make the library for you using the makefile tool (make sure you have it first)
```
Then compile your code and link it with the created library which in our case `cvector.a`
```sh
gcc -Wall -Wextra -Werror <source> cvector.a -o <output>
```

---

# Example

This main function serves as an illustrative example of utilizing the dynamic array management functionalities provided by the "_cvector.h" header. In this demonstration, a dynamic array, known as a vector, is employed to store and manipulate three instances of the t_struct structure, each comprising integer, float, and string members. The code showcases the sequence of operations involved in dynamic array usage, including memory allocation, element insertion, iteration, and proper memory deallocation. By examining this example, users can gain insights into leveraging the "_cvector.h" functions for efficient and clean handling of dynamic arrays in C, facilitating tasks such as storage, retrieval, and cleanup of variable-sized data structures.

```c
#include "__cvector_.h"

typedef struct s_test
{
    int __int;
    float __float;
    char *__char_pointer;
} t_struct;

int main(void)
{
    // Allocate memory for three t_struct elements
    t_struct *first_element = (t_struct *)malloc(sizeof(t_struct));
    t_struct *second_element = (t_struct *)malloc(sizeof(t_struct));
    t_struct *third_element = (t_struct *)malloc(sizeof(t_struct));

    // Initialize values for the t_struct elements
    first_element->__int = 50;
    first_element->__float = 50.0;
    first_element->__char_pointer = "Hello From The First Struct";
    second_element->__int = 100;
    second_element->__float = 150.0;
    second_element->__char_pointer = "Hello From The Second Struct";
    third_element->__int = 1000;
    third_element->__float = 1000.0;
    third_element->__char_pointer = "Hello From The Third Struct";

    // Create a dynamic array (vector) using __create_v
    t_vector *vector = __create_v();

    // Check if vector creation was successful
    if (!vector)
        return (EXIT_FAILURE);

    // Push the three t_struct elements into the vector
    __push_v(&vector, (void *)first_element, sizeof(t_struct));
    __push_v(&vector, (void *)second_element, sizeof(t_struct));
    __push_v(&vector, (void *)third_element, sizeof(t_struct));

    // Get the beginning iterator of the vector
    void **begin = __begin_v(vector);

    // Iterate through each t_struct element in the vector and print its members
    while (*begin != *__end_v(vector))
    {
        printf("Int: %d\n", ((t_struct *)*begin)->__int);
        printf("Float: %f\n", ((t_struct *)*begin)->__float);
        printf("Char Pointer: %s\n", ((t_struct *)*begin)->__char_pointer);
        ++begin; // Move to the next element in the vector
    }

    // Free the memory associated with the vector using __free_v
    __free_v(vector);

    return (EXIT_SUCCESS);
}
```
The main function begins by allocating memory for three t_struct elements - first_element, second_element, and third_element. These structures represent data entities with integer, float, and string members. Subsequently, a dynamic array, referred to as a vector, is created using the __create_v function from the "_cvector.h" header. This dynamic array is designed to store elements of variable size. The function then utilizes the __push_v function to insert each of the previously allocated t_struct elements into the vector. After obtaining the starting iterator with __begin_v, the main loop iterates through the vector, dereferencing the iterator and printing the values of each member in the t_struct elements. The loop continues until the iterator reaches the end of the vector, which is determined by the __end_v function. Finally, the memory associated with the vector is deallocated using the __free_v function, ensuring proper cleanup and preventing memory leaks. This main function serves as a practical example of using the provided vector functions for dynamic array management, including creation, insertion, iteration, and cleanup.

# Generics in c

In C, unlike some higher-level programming languages, there is no built-in support for generics. Generics allow you to write code that works with different data types without specifying the type explicitly. However, there are certain techniques and patterns in C that can be used to achieve a level of generic programming. which are :

- `Void Pointers (void*)`
	- One common technique is to use void pointers to create generic functions or data structures. This allows you to pass or store pointers to data of any type. However, this approach sacrifices type safety, as you need to cast the void pointers back to the correct type when using them.
---

- `Macro-based Generics`
	- C macros can be used to create generic code. By using macros and preprocessor directives, you can write code that works with different types. This approach, while powerful, can lead to less readable and more error-prone 

---

- `Code Duplication`
	- Another approach is to duplicate code for each data type. This involves creating separate functions or data structures for each type you want to work with. While straightforward, it can lead to code redundancy and maintenance challenges.

But since i love manipulating pointers, I have decided to build this project using the power of void pointer since they are more flexible and i found that they can fit my requirements (I hate casting anyway). <br />

- ### what is void pointers and how would you use them ?

	- In C, a void pointer, denoted as void*, is a special pointer type that is used to represent a memory address without specifying the type of data it points to. It provides a level of abstraction by allowing a single pointer type to accommodate addresses of any data type. This versatility makes void* useful in scenarios where the type of data being pointed to is not known or needs to be determined at runtime. However, it comes with the trade-off of losing compile-time type safety, as explicit type information is not available.

		For example, you might use a void* to create generic functions or data structures that can work with different types. When using a void*, it is common practice to cast it to the appropriate type before dereferencing or manipulating the data it points to. While void* provides flexibility, developers need to exercise caution to ensure proper type casting and avoid potential runtime errors.

> "Void pointers in C are like keys to a universal data kingdom. With great power comes great responsibility - wield them wisely, and your code will be versatile; misuse them, and you might find yourself in the wild west of undefined behavior."

```c
#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers using void pointers
void swapIntegers(void *a, void *b)
{
    int temp = *((int *)a);
    *((int *)a) = *((int *)b);
    *((int *)b) = temp;
}

int main()
{
	int num1;
	int num2;

    num1 = 5
	num2 = 10;
    printf("Before swap: num1 = %d, num2 = %d\n", num1, num2);
    swapIntegers(&num1, &num2);
    printf("After swap: num1 = %d, num2 = %d\n", num1, num2);
    return (EXIT_SUCCESS);
}

```

> Feel free to report any sort of bugs or you might one to contribute, it would be my pleasure to be a part of this project
