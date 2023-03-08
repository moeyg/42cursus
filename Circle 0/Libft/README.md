# **Libft**

[![dogpark's 42 Libft Score](https://badge42.vercel.app/api/v2/clam4rmh700350fjk8ctdih83/project/2927858)](https://github.com/JaeSeoKim/badge42)

> 🔗 [Libft Notion](https://dogpark-42cursus.notion.site/Libft-c68e47337f4141fea098e7f22e8de603)

##### Your very first own library.

##### _Summary: This project aims to code a C library regrouping usual functions that you’ll be use for all your next projects. Version: 15_

#### 🔗 : _This mark means a connection with a **Notion link**._

<br>

### 📄 Assignment

> 🔗 [Assignment discription](https://dogpark-42cursus.notion.site/Assignment-13c71a5f9c90430da7f8979d8c0f65d5)

### ❓ Question

> 🔗 [Question](https://dogpark-42cursus.notion.site/Question-0ea8fe9acefc4cd4838048802fb9b79b)

<br>

# Mandatory part

| **Program name**    | libft.a                                                                                         |
| ------------------- | ----------------------------------------------------------------------------------------------- |
| **Turn in files**   | `*.c, libft.h, Makefile`                                                                        |
| **Makefile**        | NAME, all, clean, fclean, re                                                                    |
| **External functs** | `Detailed below`                                                                                |
| **Description**     | `Write your own library: a collection of functions that will be a useful tool for your cursus.` |

<br>

# ✲ Part 1 - Libc functions

> 🔗 [Libc fuctions](https://dogpark-42cursus.notion.site/Part-1-Libc-function-d2d84bd029ee4c858b20d756172a17d0)

##### _In this first part, you must re-code a set of the `libc` functions, as defined in their `man`. Your functions will need to present the same prototype and behaviors as the originals. Your functions’ names must be prefixed by "`ft_`". For instance, `strlen`becomes`ft_strlen`.

<br>

> ⚠️
>
> ##### Some of the functions’ prototypes you have to re-code use the "restrict" qualifier. This keyword is part of the c99 standard. It is therefore forbidden to include it in your prototypes and to compile it with the flag `-std=c99`.

<br>

##### _You must re-code the following functions. These function do not need any external functions:_

- [ft_isalpha](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_isalpha.c), [ft_isdigit](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_isdigit.c), [ft_isalnum](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_isalnum.c), [ft_isascii](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_isascii.c), [ft_isprint](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_isprint.c), [ft_toupper](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_toupper.c), [ft_tolower](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_tolower.c)

- [ft_strlen](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_strlen.c), [ft_strlcpy](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_strlcpy.c), [ft_strlcat](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_strlcat.c), [ft_strncmp](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_strncmp.c), [ft_strchr](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_strchr.c), [ft_strnstr](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_strnstr.c), [ft_strrchr](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_strrchr.c), [ft_atoi](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_atoi.c)

- [ft_bzero](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_bzero.c), [ft_memset](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_memset.c)
- [ft_memcpy](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_memcpy.c), [ft_memmove](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_memmove.c), [ft_memchr](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_memchr.c), [ft_memcmp](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_memcmp.c)

#### _You must also re-code the following functions, using the function "`malloc`":_

- [ft_calloc](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_calloc.c)
- [ft_strdup](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_strdup.c)

<br>

# ✲ Part 2 - Additional functions

> 🔗 [Additional fuctions](https://dogpark-42cursus.notion.site/Part-2-Additional-functions-339ab29941d1406892ee73efd419a74f)

##### _In this second part, you must code a set of functions that are either not included in the `libc`, or included in a different form. Some of these functions can be useful to write Part 1’s functions._

<br>

- [ft_substr](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_substr.c)
- [ft_strjoin](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_strjoin.c)
- [ft_strtrim](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_strtrim.c)
- [ft_split](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_split.c)
- [ft_itoa](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_itoa.c)
- [ft_strmapi](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_strmapi.c)
- [ft_striteri](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_striteri.c)
- [ft_putchar_fd](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_putchar_fd.c)
- [ft_putstr_fd](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_putstr_fd.c)
- [ft_putendl_fd](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_putendl_fd.c)
- [ft_putnbr_fd](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_putnbr_fd.c)

<br>

# ✲ Bonus Part

> 🔗 [Bonus Part](https://dogpark-42cursus.notion.site/Bonus-Part-1267ef61c78b43fbbd843048ea2cbcad)

##### _Having functions to manipulate memory and strings is very useful, but you’ll soon discover that having functions to manipulate lists is even more useful._

##### _`make bonus` will add the bonus functions to the `libft.a` library._

##### _You’ll use the following structure to represent the elements of your list. This structure must be added to your `libft.h` file._

```c
typedef struct s_list
{
    void          *content;
    struct s_list *next;
}              t_list;
```

##### _Here is a description of the fields of the t_list struct:_

- ##### _`content` : The data contained in the element. The `void *` allows to store any kind of data._
- ##### _`next` : The next element’s address or `NULL` if it’s the last element._

##### _The following functions will allow you to easily use your lists._

<br>

- [ft_lstnew](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_lstnew.c)
- [ft_lstsize](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_lstsize.c)
- [ft_lstlast](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_lstlast.c)
- [ft_lstadd_front ](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_lstadd_front.c)
- [ft_lstadd_back](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_lstadd_back.c)
- [ft_lstdelone](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_lstdelone.c)
- [ft_lstclear](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_lstclear.c)
- [ft_lstiter](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_lstiter.c)
- [ft_lstmap](https://github.com/moeyg/42cursus/blob/main/Circle%200/Libft/Libft/ft_lstmap.c)
