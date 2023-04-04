# **ft_printf**

> [![dogpark's 42 ft_printf Score](https://badge42.vercel.app/api/v2/clam4rmh700350fjk8ctdih83/project/3048891)](https://github.com/JaeSeoKim/badge42)

> 🔗 [ft_printf](https://dogpark-42cursus.notion.site/ft_printf-99e515c722584b2399349e0d904b1c5d)

##### Because putnbr and putstr aren’t enough

##### _Summary: This project is pretty straight forward. You will recode printf. Hopefully you will be able to reuse it in future projects without the fear of being flagged as a cheater._

##### _You will mainly learn how to use variadic arguments._

#### 🔗 : _This mark means a connection with a **Notion link**._

<br>

### 📄 Assignment

> 🔗 [Assignment discription](https://dogpark-42cursus.notion.site/Assignment-2138fa4ea47d4fcb9eb5e7e2d480e197)

### 📌 Reference

> 🔗 [Reference](https://dogpark-42cursus.notion.site/Reference-a322dac45d284c7c81ef9e5cb636a6d2)

<br>

# ✲ Mandatory part

> 🔗 [ft_printf.c](https://dogpark-42cursus.notion.site/ft_print-c-2f4cbaf720a8407292cd05240e4b6727) <br>
> 🔗 [print_format.c](https://dogpark-42cursus.notion.site/print_format-c-4302a91c8dd44311a37d4a7c6207560b)

<br>

| **Program name**     | libftprintf.a                                                                               |
| -------------------- | ------------------------------------------------------------------------------------------- |
| **Turn in files**    | \*.c, \*/\*.c, \*.h, \*/\*.h, Makefile                                                      |
| **Makefile**         | all, clean, fclean, re, bonus                                                               |
| **External functs**  | malloc, free, write, va_start, va_arg, va_copy, va_end                                      |
| **Libft authorized** | Yes 가능                                                                                    |
| **Description**      | Write a library that contains ft_printf(), a function that will mimic the original printf() |

<br>

- ##### _The prototype of ft_printf should be `int ft_printf(const char *, ...);`_

- ##### _You have to recode the `libc`’s `printf` function_

- ##### _It must not do the buffer management like the real printf_

- ##### _It will manage the following conversions: cspdiuxX%_

- ##### _It will be compared with the real printf_

- ##### _You must use the command `ar` to create your librairy, using the command `libtool` is forbidden._

<br>

##### _A small description of the required conversion:_

- ##### _%c print a single character._

- ##### _%s print a string of characters._

- ##### _%p The void \* pointer argument is printed in hexadecimal._

- ##### _%d print a decimal (base 10) number._

- ##### _%i print an integer in base 10._

- ##### _%u print an unsigned decimal (base 10) number._

- ##### _%x print a number in hexadecimal (base 16), with lowercase._

- ##### _%X print a number in hexadecimal (base 16), with uppercase._

- ##### _%% print a percent sign._

> 💡 <br>
>
> ##### _for more complete references : `man 3 printf / man 3 stdarg`_

<br>

# ✲ Bonus part

- ##### _If the Mandatory part is not perfect don’t even think about bonuses_

- ##### _You don’t need to do all the bonuses_

- ##### _Manage any combination of the following flags: `'-0.'` and minimum field width with all conversions_

- ##### _Manage all the following flags: `'# +'` (yes, one of them is a space)_

> 💡<br>
>
> ##### _If you plan to do bonuses you should think about how to do them from the beginning to avoid a naive approach._
