# cecs326project2
In this project, we were tasked with designing a real scenario/application with
multiple threads using a threads programming interface, POSIX Threads (Pthreads). This was
implemented in Linux, which supports Pthreads as part of the GNU C library.

The specific task that we were assigned to accomplish was the following:
A list of integers is divided into two smaller lists of equal size. Two separate threads (which we will term sorting
threads) sort each sublist using a sorting algorithm of your choice. The two sublists are then merged
by a third thread—a merging thread—which merges the two sublists into a single sorted list.

In order to execute the file, in the Ubuntu Virtual Machine, after having downloaded the file and saved it onto said
Virtual Machine, the following code was executed in a Terminal window in order to demonstrate this lab.

Compiling
----------------------------------
Compile with Makefile using:
*  make pro2_sample

Or Compile Manually:
* gcc pro2_sample.c -o  pro2_sample -pthread

Running
----------------------------------

* ./pro2_sample
* 
## Authors
Sebastian Vasquez
Spencer Gravel
