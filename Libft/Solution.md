# Solution

<br>

## Part 1 - Libc functions

| **Function name** | `isalpha`                                                                                      |
| ----------------- | ---------------------------------------------------------------------------------------------- |
| **Header file**   | #include <ctype.h>                                                                             |
| **Synopsis**      | int isalpha(int c);                                                                            |
| **Description**   | The isalpha() function tests for any character for which isupper(3) **or** islower(3) is true. |
| **Return value**  | Returns zero if the character tests false and returns non-zero if the character tests true.    |

<br>

| **Function name** | `isdigit`                                                                                  |
| ----------------- | ------------------------------------------------------------------------------------------ |
| **Header file**   | #include <ctype.h>                                                                         |
| **Synopsis**      | int isdigit(int c);                                                                        |
| **Description**   | The isdigit() function tests for a decimal digit character.                                |
| **Return value**  | Returns zero if the character tests false and return non-zero if the character tests true. |

<br>

| **Function name** | `isalnum`                                                                                      |
| ----------------- | ---------------------------------------------------------------------------------------------- |
| **Header file**   | #include <ctype.h>                                                                             |
| **Synopsis**      | int isalnum(int c);                                                                            |
| **Description**   | The isalnum() function tests for any character for which isalpha(3) **or** isdigit(3) is true. |
| **Return value**  | Returns zero if the character tests false and returns non-zero if the character tests true.    |

<br>

| **Function name** | `isascii`                                                                                                                                          |
| ----------------- | -------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Header file**   | #include <ctype.h>                                                                                                                                 |
| **Synopsis**      | int isascii(int c);                                                                                                                                |
| **Description**   | The isascii() function tests for an ASCII character, which is any character between 0 and octal 0177 inclusive. (0177 in octal is 127 in decimal.) |
| **Return value**  | Returns zero if the character tests false and return non-zero if the character tests true.                                                         |

<br>

| **Function name** | `isprint`                                                                                                                                                                                               |
| ----------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Header file**   | #include <ctype.h>                                                                                                                                                                                      |
| **Synopsis**      | int isprint(int c);                                                                                                                                                                                     |
| **Description**   | The isprint() function tests for any printing character, including space (‘ ’). In the ASCII character set, between octal 040 and octal 0177 inclusive. (040 = 32 in decimal. / 0177 = 127 in decimal.) |
| **Return value**  | Returns zero if the character tests false and return non-zero if the character tests true.                                                                                                              |

<br>

| **Function name** | `strlen`                                                                                                                                     |
| ----------------- | -------------------------------------------------------------------------------------------------------------------------------------------- |
| **Header file**   | #include <string.h>                                                                                                                          |
| **Synopsis**      | size_t strlen(const char \*s);                                                                                                               |
| **Description**   | The strlen() function computes the length of the string s.                                                                                   |
| **Return value**  | Returns the number of characters that precede the terminating NUL character.                                                                 |
| **Knowledge**     | `size_t` 는 부호 없는 정수형이나 실제 데이터형은 아니다. <br> C99 표준에서 최소 16 bit 를 요구하고, 보통은 unsigned int (32 bit)를 사용한다. |

<br>

| **Function name** | `memset`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| ----------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Header file**   | #include <string.h>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| **Synopsis**      | void *ft_memset(void *b, int c, size_t len)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
|                   |
| **Description**   | The memset() function writes len bytes of value c (converted to an unsigned char) to the string b.                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| **Return value**  | Returns its first argument                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| **Knowledge**     | `memset = memory + setting` <li> 첫 번째 인자 `void *b` 는 세팅하고자 하는 `메모리의 시작 주소`를 받는다.</li> <li> 두 번째 인자 `int c` 는 메모리에 세팅하고 하는 `값`을 받는다. int 타입으로 받지만, 내부에서 unsigned char 로 형변환이 되어 저장된다. 즉, **1 byte 단위로 값을 초기화 하기 때문에 int 값을 보낼 경우 예상할 수 없는 값으로 세팅이 될 수 있다.** (= len bytes of value c (converted to an unsigned char) to the string b.)</li> <li> 마지막 인자 `size_t len` 은 바이트 단위로 메모리 길이를 받는다. 보통 `length * sizeof(data type)` 의 형태로 보낸다.</li> |

<br>

| **Function name** | `bzero`            |
| ----------------- | ------------------ |
| **Header file**   | #include <ctype.h> |
| **Synopsis**      |                    |
| **Description**   |                    |
| **Return value**  |                    |

<br>

| **Function name** | `memcpy`           |
| ----------------- | ------------------ |
| **Header file**   | #include <ctype.h> |
| **Synopsis**      |                    |
| **Description**   |                    |
| **Return value**  |                    |

<br>

| **Function name** | `memmove`          |
| ----------------- | ------------------ |
| **Header file**   | #include <ctype.h> |
| **Synopsis**      |                    |
| **Description**   |                    |
| **Return value**  |                    |

<br>

| **Function name** | `strlcpy`          |
| ----------------- | ------------------ |
| **Header file**   | #include <ctype.h> |
| **Synopsis**      |                    |
| **Description**   |                    |
| **Return value**  |                    |

<br>

| **Function name** | `strlcat`          |
| ----------------- | ------------------ |
| **Header file**   | #include <ctype.h> |
| **Synopsis**      |                    |
| **Description**   |                    |
| **Return value**  |                    |

<br>

| **Function name** | `strncmp`          |
| ----------------- | ------------------ |
| **Header file**   | #include <ctype.h> |
| **Synopsis**      |                    |
| **Description**   |                    |
| **Return value**  |                    |

<br>

| **Function name** | `toupper`          |
| ----------------- | ------------------ |
| **Header file**   | #include <ctype.h> |
| **Synopsis**      |                    |
| **Description**   |                    |
| **Return value**  |                    |

<br>

| **Function name** | `tolower`          |
| ----------------- | ------------------ |
| **Header file**   | #include <ctype.h> |
| **Synopsis**      |                    |
| **Description**   |                    |
| **Return value**  |                    |

<br>

| **Function name** | `strchr`           |
| ----------------- | ------------------ |
| **Header file**   | #include <ctype.h> |
| **Synopsis**      |                    |
| **Description**   |                    |
| **Return value**  |                    |

<br>

| **Function name** | `strrchr`          |
| ----------------- | ------------------ |
| **Header file**   | #include <ctype.h> |
| **Synopsis**      |                    |
| **Description**   |                    |
| **Return value**  |                    |

<br>

| **Function name** | `memchr`           |
| ----------------- | ------------------ |
| **Header file**   | #include <ctype.h> |
| **Synopsis**      |                    |
| **Description**   |                    |
| **Return value**  |                    |

<br>

| **Function name** | `memcmp`           |
| ----------------- | ------------------ |
| **Header file**   | #include <ctype.h> |
| **Synopsis**      |                    |
| **Description**   |                    |
| **Return value**  |                    |

<br>

| **Function name** | `strnstr`          |
| ----------------- | ------------------ |
| **Header file**   | #include <ctype.h> |
| **Synopsis**      |                    |
| **Description**   |                    |
| **Return value**  |                    |

<br>

| **Function name** | `atoi`             |
| ----------------- | ------------------ |
| **Header file**   | #include <ctype.h> |
| **Synopsis**      |                    |
| **Description**   |                    |
| **Return value**  |                    |
