# **Get Next Line**

** Add score **

> 🔗 [Get Next Line Notion](https://dogpark-42cursus.notion.site/Get-Next-Line-1b3a739678164fad83079944463c942b)

##### Reading a line on a fd is way too tedious

##### _Summary: The aim of this project is to make you code a function that returns a line, read from a file descriptor._

#### 🔗 : _This mark means a connection with a **Notion link**._

<br>

### 📄 Assignment

> 🔗 [Assignment discription](https://dogpark-42cursus.notion.site/Assignment-6ec0805a79d748dc93f67666ae2bd05e)

### 📌 Reference

> 🔗 [Reference](https://dogpark-42cursus.notion.site/Reference-7ffdfc7679294dddb40e364cf1074d49)

<br>

# ✲ Mandatory part

> 🔗 [Get Next Line](https://dogpark-42cursus.notion.site/Mandatory-Part-Get-Next-Line-c6b1844ab08a4ee3a8564c72c8db9f20)

<br>

| **Function name**            | get_next_line                                                                     |
| ---------------------------- | --------------------------------------------------------------------------------- |
| **Prototype**                | char \*get_next_line(int fd);                                                     |
| **Turn in files**            | get_next_line.c, get_next_line_utils.c, get_next_line.h                           |
| **Parameters**               | fd: The file descriptor to read from                                              |
| **Return value**             | Read line: correct behavior <br> NULL: there is nothing else to read, or an error |
| occurred                     |
| **사용가능한 <br>외부 함수** | `read, malloc, free`                                                              |
| **설명**                     | Write a function that returns a line read from a                                  |
| file descriptor              |

<br>

- ##### _Calling your function `get_next_line` in a loop will then allow you to read the text available on the file descriptor one line at a time until the end of it._

- ##### _Your function should return the line that has just been read. If there is nothing else to read or if an error has occurred it should return NULL._

- ##### _Make sure that your function behaves well when it reads from a file and when it reads from the standard input._

- ##### _`libft` is not allowed for this project. You must add a `get_next_line_utils.c` file which will contain the functions that are needed for your `get_next_line` to work._

- ##### _Your program must compile with the flag `-D BUFFER_SIZE=xx` which will be used as the buffer size for the read calls in your `get_next_line`. This value will be modified by your evaluators and by the moulinette._

- ##### _The program will be compiled in this way: `gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c`._

- ##### _Your read must use the `BUFFER_SIZE` defined during compilation to read from a file or from stdin. This value will be modified during the evaluation for testing purposes._

- ##### _In the header file `get_next_line.h` you must have at least the prototype of the function `get_next_line`._

<br>
<br>

> 💡 <br>
>
> ##### _Does your function still work if the BUFFER_SIZE value is 9999? And if the BUFFER_SIZE value is 1? And 10000000? Do you know why?_

<br>
<br>

> 💡 <br>
>
> ##### _You should try to read as little as possible each time get_next_line is called. If you encounter a newline, you have to return the current line. Don’t read the whole file and then process each line._

<br>
<br>

> 💡 <br>
>
> ##### _Don’t turn in your project without testing. There are many tests to run, cover your bases. Try to read from a file, from a redirection, from standard input. How does your program behave when you send a newline to the standard output? And CTRL-D?_

<br>
<br>

- ##### _lseek is not an allowed function. File reading must be done only once._

- ##### _We consider that `get_next_line` has undefined behavior if, between two calls, the same file descriptor switches to a different file before reading everything from the first fd._

- ##### _Finally we consider that `get_next_line` has undefined behavior when reading from a binary file. However, if you wish, you can make this behavior coherent._

- ##### _Global variables are forbidden._

- ##### _Important: The returned line should include the ’\n’, except if you have reached the end of file and there is no ’\n’.._

<br>
<br>

> ℹ️ <br>
>
> ##### _A good start would be to know what a static variable is:_
>
> <br> https://en.wikipedia.org/wiki/Static_variable

<br>
<br>

# ✲ Bonus part

<br>

##### _The project `get_next_line` is straightforward and leaves very little room for bonuses, but we are sure that you have a lot of imagination. If you have aced the mandatory part, then by all means, complete this bonus part to go further. Just to be clear, no bonuses will be taken into consideration if the mandatory part isn’t perfect._

##### _Turn-in all 3 mandatory files ending by \_bonus.[c\h] for this part._

- ##### _To succeed `get_next_line` with a single static variable._

- ##### _To be able to manage multiple file descriptors with your `get_next_line`. For example, if the file descriptors 3, 4 and 5 are accessible for reading, then you can call `get_next_line` once on 3, once on 4, once again on 3 then once on 5 etc. without losing the reading thread on each of the descriptors._
