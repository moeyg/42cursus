# Libft Note

## Part 1 - Libc functions

| **Function**     | `isalpha`                                                                                      |
| ---------------- | ---------------------------------------------------------------------------------------------- |
| **Header file**  | #include <ctype.h>                                                                             |
| **Synopsis**     | int isalpha(int c);                                                                            |
| **Description**  | The isalpha() function tests for any character for which isupper(3) **or** islower(3) is true. |
| **Return value** | Returns zero if the character tests false and returns non-zero if the character tests true.    |

<br>

| **Function**     | `isdigit`                                                                                  |
| ---------------- | ------------------------------------------------------------------------------------------ |
| **Header file**  | #include <ctype.h>                                                                         |
| **Synopsis**     | int isdigit(int c);                                                                        |
| **Description**  | The isdigit() function tests for a decimal digit character.                                |
| **Return value** | Returns zero if the character tests false and return non-zero if the character tests true. |

<br>

| **Function <br> name** | `isalnum`                                                                                      |
| ---------------------- | ---------------------------------------------------------------------------------------------- |
| **Header file**        | #include <ctype.h>                                                                             |
| **Synopsis**           | int isalnum(int c);                                                                            |
| **Description**        | The isalnum() function tests for any character for which isalpha(3) **or** isdigit(3) is true. |
| **Return value**       | Returns zero if the character tests false and returns non-zero if the character tests true.    |

<br>

| **Function**     | `isascii`                                                                                                                                          |
| ---------------- | -------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Header file**  | #include <ctype.h>                                                                                                                                 |
| **Synopsis**     | int isascii(int c);                                                                                                                                |
| **Description**  | The isascii() function tests for an ASCII character, which is any character between 0 and octal 0177 inclusive. (0177 in octal is 127 in decimal.) |
| **Return value** | Returns zero if the character tests false and return non-zero if the character tests true.                                                         |

<br>

| **Function**     | `isprint`                                                                                                                                                                                               |
| ---------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Header file**  | #include <ctype.h>                                                                                                                                                                                      |
| **Synopsis**     | int isprint(int c);                                                                                                                                                                                     |
| **Description**  | The isprint() function tests for any printing character, including space (‘ ’). In the ASCII character set, between octal 040 and octal 0177 inclusive. (040 = 32 in decimal. / 0177 = 127 in decimal.) |
| **Return value** | Returns zero if the character tests false and return non-zero if the character tests true.                                                                                                              |

<br>

| **Function**     | `strlen`                                                                                                                                     |
| ---------------- | -------------------------------------------------------------------------------------------------------------------------------------------- |
| **Header file**  | #include <string.h>                                                                                                                          |
| **Synopsis**     | size_t strlen(const char \*s);                                                                                                               |
| **Description**  | The strlen() function computes the length of the string s.                                                                                   |
| **Return value** | Returns the number of characters that precede the terminating NUL character.                                                                 |
| **Knowledge**    | `size_t` 는 부호 없는 정수형이나 실제 데이터형은 아니다. <br> C99 표준에서 최소 16 bit 를 요구하고, 보통은 unsigned int (32 bit)를 사용한다. |

<br>

| **Function**     | `memset`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| ---------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| **Header file**  | #include <string.h>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
| **Synopsis**     | void *ft_memset(void *b, int c, size_t len)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
|                  |
| **Description**  | The memset() function writes len bytes of value c (converted to an unsigned char) to the string b.                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| **Return value** | Returns its first argument.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| **Knowledge**    | `memset = memory + setting` <br> 첫 번째 인자 `void *b` 는 세팅하고자 하는 `메모리의 시작 주소`를 받는다. <br> 두 번째 인자 `int c` 는 `메모리에 세팅하고 하는 값`을 받는다. int 타입으로 받지만, 내부에서 unsigned char 로 형변환이 되어 저장된다. 즉, **1 byte 단위로 값을 초기화 하기 때문에 int 값을 보낼 경우 예상할 수 없는 값으로 세팅이 될 수 있다.** (= len bytes of value c (converted to an unsigned char) to the string b.) <br> 마지막 인자 `size_t len` 은 `바이트 단위로 메모리 길이`를 받는다. 보통 `length * sizeof(data type)` 의 형태로 보낸다. |

<br>

| **Function**     | `bzero`                                                                                                                                                                                                                                              |
| ---------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Header file**  | #include <strings.h>                                                                                                                                                                                                                                 |
| **Synopsis**     | void bzero(void \*s, size_t n);                                                                                                                                                                                                                      |
| **Description**  | The bzero() function writes n zeroed bytes to the string s. If n is zero, bzero() does nothing.                                                                                                                                                      |
| **Return value** | -                                                                                                                                                                                                                                                    |
| **Knowledge**    | `bzero` 는 malloc이나 calloc에서 할당 받은 메모리 또는 배열, 구조체 변수의 메모리 영역을 0으로 초기화 하는 함수이다. <br> 첫 번째 인자 `void *s` 는 메모리의 크기를 변경할 포인터를 받는다. <br> 두 번째 인자 `size_t n` 은 초기화 할 크기를 받는다. |

<br>

| **Function**     | `memcpy`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| ---------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| **Header file**  | #include <string.h>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| **Synopsis**     | void \*memcpy(void \*dst, const void \*src, size_t n);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
| **Description**  | The memcpy() function copies n bytes from memory area src to memory area dst.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| **Return value** | Returns the original value of dst.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| **Knowledge**    | `memcpy = memory + copy` <br> 첫 번째 인자 `void *dst` 는 복사 받을 메모리를 가리키는 포인터를 받는다. <br> 두 번째 인자 `const void *src` 는 복사할 메모리를 가리키고 있는 포인터를 받는다. <br> 세 번째 인자 `size_t n` 은 복사할 데이터의 길이를 바이트 단위로 받는다. <br> 즉, src의 원본을 길이 n만큼 복사해서 dst에 붙여 넣는 함수이다. <br> `memcpy` 는 복사할 src 메모리 블록과 복사한 값을 붙여넣는 dst 메모리 블록이 겹쳐져 있는 곳에서는 함수가 작동하지 않는다. (= dst and src overlap, behavior is undefined.) <br> 만약 동일한 메모리 공간에 덮어 씌워야 할 경우 memmove 함수를 사용한다. (= Applications in which dst and src might overlap should use memmove(3) instead.) |

<br>

| **Function**     | `memmove`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| ---------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Header file**  | #include <string.h>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| **Synopsis**     | void *ft_memmove(void *dst, const void \*src, size_t len);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| **Description**  | The memmove() function copies len bytes from string src to string dst. The two strings may overlap; the copy is always done in a non-destructive manner.                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| **Return value** | Returns the original value of dst.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| **Knowledge**    | `memmove = momery + move` <br> 첫 번째 인자 `void *dst` 는 복사한 걸 붙여넣을 메모리(위치)를 가리키는 포인터를 받는다. <br> 두 번째 인자 `const void *src` 는 복사할 메모리를 가리키는 포인터를 받는다. <br> 마지막 인자 `size_t len` 은 복사할 바이트 길이를 받는다. <br> 즉, src가 가리키는 메모리로부터 len 바이트 사이즈만큼 dest가 가리키는 메모리로 옮긴다. `memcpy` 함수와 비슷한 기능을 가졌지만, 더 안전하게 작동이 되는데, 우선 복사할 것을 버퍼에 복사하고 해당 위치에 가서 복사된 것을 붙이는 식으로 작동된다. 성능면에서는 `memcpy` 함수가 버퍼를 거치지 않으니 빠르지만, 안정성 면에서는 `memmove` 함수가 더 높다. |
| **Issue**        | `memmove` 함수를 구현할 때, `The two strings may overlap; the copy is always done in a non-destructive manner.` 를 고려해야 하기 때문에 dest 메모리 위치가 src 메모리 위치가 오버랩 되는 상황(`!(dest < src)`)에서는 뒤에서부터 복사해야 안전하게 동작할 수 있다.                                                                                                                                                                                                                                                                                                                                                                |

<br>

| **Function**     | `strlcpy`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| ---------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Header file**  | #include <string.h>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| **Synopsis**     | size_t strlcpy(char *dst, const char *src, size_t dstsize);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| **Description**  | The strlcpy() and strlcat() functions copy and concatenate strings with the same input parameters and output result as snprintf(3). They are designed to be safer, more consistent, and less error prone replacements for the easily misused functions strncpy(3) and strncat(3). <br> strlcpy() and strlcat() take the full size of the destination buffer and guarantee NUL-termination if there is room. Note that room for the NUL should be included in dstsize. <br> strlcpy() copies up to dstsize - 1 characters from the string src to dst, NUL-terminating the result if dstsize is not 0. |
| **Return value** | Return the total length of the string they tried to create. For strlcpy() that means the **length of src.**                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| **Knowledge**    | 문자열 복사 함수 `strlcpy` 함수는 첫 번째 인자 `char *dst` 에 두 번째 정적 인자 `const char *src` 의 값을 복사한다. <br> 세 번째 인자 `size_t dstsize` 는 복사 범위를 지정할 때 사용된다. 그 이유로는 `strlcpy` 는 `src` 의 `\0` 을 만나기 전, 혹은 `dstsize - 1` 만큼 복사가 이루어 졌을 때 복사를 중지하기 때문이다. <br> `strlcpy` 는 다른 복사 함수보다 안정성 있는데, `dstsize - 1` 만큼 복사가 이루어져 마지막에 `\0` 값을 넣어주기 때문이다. <br> 즉, 다른 함수(`strcpy`, `strncpy`) 보다 `\0` 보장이 확실하다.                                                                               |

<br>

| **Function**     | `strlcat`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| ---------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Header file**  | #include <string.h>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| **Synopsis**     | size_t strlcat(char *dst, const char *src, size_t dstsize);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| **Description**  | The strlcpy() and strlcat() functions copy and concatenate strings with the same input parameters and output result as snprintf(3). They are designed to be safer, more consistent, and less error prone replacements for the easily misused functions strncpy(3) and strncat(3). <br> strlcpy() and strlcat() take the full size of the destination buffer and guarantee NUL-termination if there is room. Note that room for the NUL should be included in dstsize. <br> strlcat() appends string src to the end of dst. It will append at most dstsize - strlen(dst) - 1 characters. <br> It will then NUL-terminate, unless dstsize is 0 or the original dst string was longer than dstsize (in practice this should not happen as it means that either dstsize is incorrect or that dst is not a proper string). <br> If the src and dst strings overlap, the behavior is undefined. |
| **Return value** | Return the total length of the string they tried to create. For strlcat() that means **the initial length of dst + the length of src.**                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| **Knowledge**    | `strlcat` 함수는 첫 번째 인자 `char *dst` 의 뒤에 두 번째 정적 인자 `const char *src` 를 세 번째 인자 `size_t dstsize` 만큼 붙인다. <br> 만약 `dst` 의 길이 >= `dstsize` 라면, 문자열을 붙이지 않고 `dst` 의 내용을 유지한다. 따라서 `dst` 의 길이 < `dstsize` 일 때, 정상적으로 작동할 수 있다. <br> 만약 `dst + src` 의 길이 >= `dstsize` 라면, `dst` 의 길이를 제외하고 남은 길이만큼(즉, dstsize - dst 길이 - 1) `src` 의 내용을 이어 붙여준다. <br> `dstsize - 1` 만큼 이어 붙이기가 이루어져 마지막에 `\0` 값을 넣어주어야 안정성이 보장된다.                                                                                                                                                                                                                                                                                                                                       |

<br>

| **Function**     | `strncmp`                                                                                                                                                                                                                          |
| ---------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Header file**  | #include <string.h>                                                                                                                                                                                                                |
| **Synopsis**     | int strncmp(const char *s1, const char *s2, size_t n);                                                                                                                                                                             |
| **Description**  | The strncmp() function compares not more than n characters. Because strncmp() is designed for comparing strings rather than binary data, characters that appear after a ‘\0’ character are not compared.                           |
| **Return value** | The strcmp() and strncmp() functions return an integer greater than, equal to, or less than 0, according as the string s1 is greater than, equal to, or less than the string s2. The comparison is done using unsigned characters. |
| **Knowledge**    | 반환값을 도출하는 과정에서 `unsigned char` 로 캐스팅 하는 이유는 0을 기준으로 음수, 양수 값으로 반환되어야 하는데 부호로 인해 계산 결과 값이 달라질 수 있기 때문에 꼭 캐스팅 하는 과정이 필요하다.                                 |

<br>

| **Function**     | `toupper`          |
| ---------------- | ------------------ |
| **Header file**  | #include <ctype.h> |
| **Synopsis**     |                    |
| **Description**  |                    |
| **Return value** |                    |

<br>

| **Function**     | `tolower`          |
| ---------------- | ------------------ |
| **Header file**  | #include <ctype.h> |
| **Synopsis**     |                    |
| **Description**  |                    |
| **Return value** |                    |

<br>

| **Function**     | `strchr`           |
| ---------------- | ------------------ |
| **Header file**  | #include <ctype.h> |
| **Synopsis**     |                    |
| **Description**  |                    |
| **Return value** |                    |

<br>

| **Function**     | `strrchr`          |
| ---------------- | ------------------ |
| **Header file**  | #include <ctype.h> |
| **Synopsis**     |                    |
| **Description**  |                    |
| **Return value** |                    |

<br>

| **Function**     | `memchr`           |
| ---------------- | ------------------ |
| **Header file**  | #include <ctype.h> |
| **Synopsis**     |                    |
| **Description**  |                    |
| **Return value** |                    |

<br>

| **Function**     | `memcmp`           |
| ---------------- | ------------------ |
| **Header file**  | #include <ctype.h> |
| **Synopsis**     |                    |
| **Description**  |                    |
| **Return value** |                    |

<br>

| **Function**     | `strnstr`          |
| ---------------- | ------------------ |
| **Header file**  | #include <ctype.h> |
| **Synopsis**     |                    |
| **Description**  |                    |
| **Return value** |                    |

<br>

| **Function**     | `atoi`             |
| ---------------- | ------------------ |
| **Header file**  | #include <ctype.h> |
| **Synopsis**     |                    |
| **Description**  |                    |
| **Return value** |                    |
