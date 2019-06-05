# Linked-List-Linux-Kernel-Module

Objective: Practice the programming of basic usage of a Linux kernel module, and management of a linked list.

Problem Statement: Create a Linux kernel module that creates a linked list to store the birthday information of
5 random students. For each person, the birthday information should include month, day, year, and name. When the
module is loaded, traverse through the linked list and output its content to the kernel log buffer. In addition,
write code to identify the oldest student and remove taht student from the list. After removing the oldest student,
output the updated linked list content to the kernel log buffer. In the module exit point, delete the elements from
the updated linked list and return the free memory back to the kernel. Make sure to output a message to the kernel
log buffer everytime an element is deleted.

/********************************************************************************************************/

Instruction: 

1. Put Makefile and simple-solution.c in the same directory
2. Change directory in the command line to that directory
3. Type "make" in the command line to use the Makefile to compile simple-solution.c into a kernel module
The created file simple-solution.ko represents the compiled kernel module
4. type "sudo insmod simple-solution.ko" into the comman line to load the kernel module
5. To check whether the module has loaded, enter the lsmod command and search for the module simple-solution
6. To check the contents of the kernel's output message enter "dmesg" into the command line.
7. To remove the kernel module enter "sudo rmmod simple-solution" into the command line.

/********************************************************************************************************/

Output of program:

![alt text](https://raw.githubusercontent.com/michaelpmoloney/Linked-List-Linux-Kernel-Module/master/Project1_Part2.png)
