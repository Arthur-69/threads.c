Task1:

This code introduces basic thread handling in C with pthread_create and pthread_join. Each thread prints a message containing its unique thread ID. This task demonstrates thread creation and synchronization using pthread_join to ensure that all threads complete before the main program exits.

Task2: 

Here, we demonstrate dividing an array processing task across two threads. The ArrayRange structure defines which section of the array each thread processes. Each thread calculates and prints the sum of its assigned array portion. This task shows how threads can work independently on portions of data and the ease of dividing tasks among multiple threads.

Task3: 

This code shows how multiple threads can perform the same task (printing numbers) in parallel. Due to the concurrent nature of threads, the printed numbers may appear in an unpredictable order, illustrating how threads are scheduled by the OS and do not execute sequentially unless synchronized.

Task4: 

This code demonstrates simple parallel processing by creating a thread for each element in an array. Each thread calculates the square of a number and prints it. This example highlights the usefulness of threads for tasks that can be split into independent calculations. By parallelizing such operations, we can potentially speed up computation, especially on multi-core systems.
