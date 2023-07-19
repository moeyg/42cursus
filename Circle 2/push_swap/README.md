# Push_swap

##### _Because Swap_push isn’t as natural_

##### _Summary: This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting._

##### _Version: 6_

<br>

# ✲ Introduction

##### _The `Push_swap` project is a very simple and highly straightforward algorithm project: data must be sorted._ 

#### _You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks._

##### _Your goal? Write a program in `C` called `push_swap` which calculates and displays on the standard output the smallest program, made of `Push_swap language` instructions, that sorts the integers as received._

##### _Easy?_

##### _We’ll see about that..._

<br>

# ✲ Objectives

##### _Writing a sorting algorithm is always a very important step in a developer’s journey. It is often the first encounter with the concept of [complexity](https://en.wikipedia.org/wiki/Analysis_of_algorithms)._

##### _Sorting algorithms and their complexities are part of the classic questions discussed during job interviews. It’s probably a good time to look at these concepts because you’ll have to face them at one point._

##### _The learning objectives of this project are rigor, use of C, and use of basic algorithms. Especially focusing on their complexity._

##### _Sorting values is simple. To sort them the fastest way possible is less simple, especially because from one integers configuration to another, the most efficient sorting algorithm can differ._

<br>

# ✲ Common Instructions

- ##### _Your project must be written in C._

- ##### _Your project must be written in accordance with the Norm. If you have bonus files/functions, they are included in the norm check and you will receive 0 if there is a norm error inside._

- ##### _Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors. If this happens, your project will be considered non functional and will receive a 0 during the evaluation._

- ##### _All heap allocated memory space must be properly freed when necessary. No leaks will be tolerated._

- ##### _If the subject requires it, you must submit a Makefile which will compile your source files to the required output with the flags `-Wall, -Wextra -Werror`, and your Makefile must not relink._

- ##### _Your Makefile must at least contain the rules `$(NAME)`, `all`, `clean`, `fclean` and `re`._

- ##### _To turn in bonuses to your project, you must include a rule bonus to your Makefile, which will add all the various headers, librairies or functions that are forbidden on the main part of the project. Bonuses must be in a different file `_bonus.{c/h}`. Mandatory and bonus part evaluation is done separately._

- ##### _If your project allows you to use your libft, you must copy its sources and its associated Makefile in a libft folder with its associated Makefile. Your project’s Makefile must compile the library by using its Makefile, then compile the project._

- ##### _We encourage you to create test programs for your project even though this work won’t have to be submitted and won’t be graded. It will give you a chance to easily test your work and your peers’ work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating._

- ##### _Submit your work to your assigned git repository. Only the work in the git repository will be graded. If Deepthought is assigned to grade your work, it will be done after your peer-evaluations. If an error happens in any section of your work during Deepthought’s grading, the evaluation will stop._

<br>

# ✲ Mandatory part

## The rules

- ##### _You have 2 [stacks](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) named a and b._

- ##### _At the beginning:_

	- ##### _The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated._

	- ##### _The stack b is empty._

- ##### _The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:_

	- ##### _**sa** : (`swap a`) - Swap the first 2 elements at the top of stack a.<br/>Do nothing if there is only one or no elements._

	- ##### _**sb** : (`swap b`) - Swap the first 2 elements at the top of stack b.<br/>Do nothing if there is only one or no elements._

	- ##### _**ss** : `sa` and `sb` at the same time._

	- ##### _**pa** : (`push a`) - Take the first element at the top of b and put it at the top of a.<br/>Do nothing if b is empty._

	- ##### _**pb** : (`push b`)- Take the first element at the top of a and put it at the top of b.<br/>Do nothing if a is empty._

	- ##### _**ra** : (`rotate a`) - Shift up all elements of stack a by 1.<br/>The first element becomes the last one._

  	- ##### _**rb** : (`rotate b`)- Shift up all elements of stack b by 1.<br/>The first element becomes the last one._

	- ##### _**rr** : `ra` and `rb` at the same time._

	- ##### _**rra** : (`reverse rotate a`) - Shift down all elements of stack a by 1.<br/>The last element becomes the first one._

	- ##### _**rrb** : (`reverse rotate b`) - Shift down all elements of stack b by 1.<br/>The last element becomes the first one._

	- ##### _rrr : `rra` and `rrb` at the same time._

<br>

## Example

##### _To illustrate the effect of some of these instructions, let’s sort a random list of integers.<br>In this example, we’ll consider that both stack are growing from the right._

```
----------------------------------------------------------------------------------------------------------
Init a and b:
2
1
3
6
5
8
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec sa:
1
2
3
6
5
8
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec pb pb pb:
6 3
5 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec ra rb (equiv. to rr):
5 2
8 1
6 3
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec rra rrb (equiv. to rrr):
6 3
5 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec sa:
5 3
6 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec pa pa pa:
1
2
3
5
6
8
_ _
a b
----------------------------------------------------------------------------------------------------------
```

##### _Inteagers from a get sorted in 12 instructions. Can you do better?_

<br>

## The “push_swap” program

| **Program name** |push_swap|
|---|---|
| **Turn in files** | Makefile, *.h, *.c |
| **Makefile** | NAME, all, clean, fclean, re |
| **Arguments** | stack a: A list of integers |
| **External functs.** | • read, write, malloc, free, exit<br/> • ft_printf and ny equivalent YOU coded |
| **Libft authorized** | Yes |
| **Description** | Sort stacks |

##### _Your project must comply with the following rules:_

- ##### _You have to turn in a `Makefile` which will compile your source files. It must not relink._

- ##### _Global variables are forbidden._

- ##### _You have to write a program named `push_swap` that takes as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order)._

- ##### _The program must display the smallest list of instructions possible to sort the stack a, the smallest number being at the top._

- ##### _Instructions must be separaed by a ’\n’ and nothing else._

- ##### _The goal is to sort the stack with the lowest possible number of operations. During the evaluation process, the number of instructions found by your program will be compared against a limit: the maximum number of operations tolerated. If your program either dispalys a longer list of or if the numbers aren't sorted properly, your grade will be 0._

- ##### _If no parameters are specified, the program must not display anything and give the prompt back._

- ##### _In case of error, you must display `"Error"` followed by a `'\n'` on the standard error. Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer and/or there are duplicates._

```sh
$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
$>./push_swap 0 one 2 3
Error
$>
```

##### _During the evaluation process, a binary will be provided in order to properly check your program._

#### _It will work as follows:_

```sh
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK
$>
```

##### _If the program `checker_OS` displays `"KO"`, it means that your `push_swap` came up with a list of instructions that doesn’t sort the numbers._

> ℹ️ <br>
>
> ##### _The `checker_OS` program is available in the resources of the project on the intranet. You can find in the bonus section of this document a description of how it works._
>


<br>

# ✲ Bonus part

##### _This project leaves little room for adding extra features due to simplicity. However, how about creating your own checker?_


> ℹ️ <br>
>
> ##### _Thanks to the checker program, you will be able to check wheter the list of instructions generated by the push_swap program actually srots the stack properly._
>

<br>

## The "Checker" Program

| Program name | checker |
| --- | --- |
| Turn in files | *.h, *.c |
| Makefile | bonus |
| Arguments | stack a : A lsit of inteagers |
| External functs. | • read, write, malloc, free, exit <br/> • ft_printf and any equivalent YOU coded |
| Libft authorized | Yes |
| Description | Execute the sorting instructions |

- ##### _Write a program named `checker` that takes get as an argument the stack `a` formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order). If no argument is given, it stops and displays nothing._

- ##### _It will then wait and read instructions on the standard input, each instruction will be followed by ’\n’. Once all the instructions have been read, the program has to execute them on the stack received as an argument._

- ##### _If after executing those instructions, stack `a` is actually sorted and the stack `b` is empty, then the program must display "`OK`" followed by a ’\n’ on the standard output._

- ##### _In every other case, `checker` must display "`KO`" followed by a ’\n’ on the standard output._

- ##### _In case of error, you must display `Error` followed by a ’\n’ on the `standard error`. Errors include for example: some arguments are not integers, some arguments are bigger than an integer, there are duplicates, an instruction don’t exist and/or is incorrectly formatted._


```sh
$>./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
$>./checker 3 2 1 0
sa
rra
pb
KO
$>./checker 3 2 one 0
Error
$>./checker "" 1
Error
$>
```

> ⚠️ <br>
>
> ##### _You DO NOT have to reproduce the exact same behavior as the binary we are giving to you. It is mandatory to manage the errors but it is up to you how you decide to parse the arguments._
>

> ⚠️ <br>
>
>##### _The bonus part will only be assessed if the mandatory part is PERFECT. Perfect means the mandatory part has been integrally done and works without malfunctioning. If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all._
>
