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

| **Function name** | `memset`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| ----------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| **Header file**   | #include <string.h>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
| **Synopsis**      | void *ft_memset(void *b, int c, size_t len)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
|                   |
| **Description**   | The memset() function writes len bytes of value c (converted to an unsigned char) to the string b.                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| **Return value**  | Returns its first argument.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| **Knowledge**     | `memset = memory + setting` <br> 첫 번째 인자 `void *b` 는 세팅하고자 하는 `메모리의 시작 주소`를 받는다. <br> 두 번째 인자 `int c` 는 `메모리에 세팅하고 하는 값`을 받는다. int 타입으로 받지만, 내부에서 unsigned char 로 형변환이 되어 저장된다. 즉, **1 byte 단위로 값을 초기화 하기 때문에 int 값을 보낼 경우 예상할 수 없는 값으로 세팅이 될 수 있다.** (= len bytes of value c (converted to an unsigned char) to the string b.) <br> 마지막 인자 `size_t len` 은 `바이트 단위로 메모리 길이`를 받는다. 보통 `length * sizeof(data type)` 의 형태로 보낸다. |

<br>

| **Function name** | `bzero`                                                                                                                                                                                                                                              |
| ----------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Header file**   | #include <strings.h>                                                                                                                                                                                                                                 |
| **Synopsis**      | void bzero(void \*s, size_t n);                                                                                                                                                                                                                      |
| **Description**   | The bzero() function writes n zeroed bytes to the string s. If n is zero, bzero() does nothing.                                                                                                                                                      |
| **Return value**  | -                                                                                                                                                                                                                                                    |
| **Knowledge**     | `bzero` 는 malloc이나 calloc에서 할당 받은 메모리 또는 배열, 구조체 변수의 메모리 영역을 0으로 초기화 하는 함수이다. <br> 첫 번째 인자 `void *s` 는 메모리의 크기를 변경할 포인터를 받는다. <br> 두 번째 인자 `size_t n` 은 초기화 할 크기를 받는다. |

<br>

| **Function name** | `memcpy`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| ----------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| **Header file**   | #include <string.h>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| **Synopsis**      | void \*memcpy(void \*dst, const void \*src, size_t n);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
| **Description**   | The memcpy() function copies n bytes from memory area src to memory area dst.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| **Return value**  | Returns the original value of dst.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| **Knowledge**     | `memcpy = memory + copy` <br> 첫 번째 인자 `void *dst` 는 복사 받을 메모리를 가리키는 포인터를 받는다. <br> 두 번째 인자 `const void *src` 는 복사할 메모리를 가리키고 있는 포인터를 받는다. <br> 세 번째 인자 `size_t n` 은 복사할 데이터의 길이를 바이트 단위로 받는다. <br> 즉, src의 원본을 길이 n만큼 복사해서 dst에 붙여 넣는 함수이다. <br> `memcpy` 는 복사할 src 메모리 블록과 복사한 값을 붙여넣는 dst 메모리 블록이 겹쳐져 있는 곳에서는 함수가 작동하지 않는다. (= dst and src overlap, behavior is undefined.) <br> 만약 동일한 메모리 공간에 덮어 씌워야 할 경우 memmove 함수를 사용한다. (= Applications in which dst and src might overlap should use memmove(3) instead.) |

<br>

| **Function name** | `memmove`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| ----------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Header file**   | #include <string.h>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| **Synopsis**      | void *ft_memmove(void *dst, const void \*src, size_t len);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| **Description**   | The memmove() function copies len bytes from string src to string dst. The two strings may overlap; the copy is always done in a non-destructive manner.                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| **Return value**  | Returns the original value of dst.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| **Knowledge**     | `memmove = momery + move` <br> 첫 번째 인자 `void *dst` 는 복사한 걸 붙여넣을 메모리(위치)를 가리키는 포인터를 받는다. <br> 두 번째 인자 `const void *src` 는 복사할 메모리를 가리키는 포인터를 받는다. <br> 마지막 인자 `size_t len` 은 복사할 바이트 길이를 받는다. <br> 즉, src가 가리키는 메모리로부터 len 바이트 사이즈만큼 dest가 가리키는 메모리로 옮긴다. `memcpy` 함수와 비슷한 기능을 가졌지만, 더 안전하게 작동이 되는데, 우선 복사할 것을 버퍼에 복사하고 해당 위치에 가서 복사된 것을 붙이는 식으로 작동된다. 성능면에서는 `memcpy` 함수가 버퍼를 거치지 않으니 빠르지만, 안정성 면에서는 `memmove` 함수가 더 높다. |
| **Issue**         | `memmove` 함수를 구현할 때, `The two strings may overlap; the copy is always done in a non-destructive manner.` 를 고려해야 하기 때문에 dest 메모리 위치가 src 메모리 위치가 오버랩 되는 상황(`!(dest < src)`)에서는 뒤에서부터 복사해야 안전하게 동작할 수 있다.                                                                                                                                                                                                                                                                                                                                                                |

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
