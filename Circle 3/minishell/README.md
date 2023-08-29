# **Minishell**

> score

> 🔗 [Minishell]()

##### As beautiful as a shell

##### _Summary:<br>This project is about creating a simple shell.<br>Yes, your own little bash.<br>You will learn a lot about processes and file descriptors._

##### _Version: 6_

<br>

### 📄 Assignment

> 🔗 [Assignment discription]()

### 📌 Reference

> 🔗 [Reference]()

<br>

# ✲ Mandatory part

|                      |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| -------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Program name**     | minishell                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| **Turn in files**    | Makefile, _.h, _.c                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| **Makefile**         | all, clean, fclean, re                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| **Parameter**        |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| **External functs**  | `readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history, printf, malloc, free, write, access, open, read, close, fork, wait, waitpid, wait3, wait4, signal, sigaction, sigemptyset, sigaddset, kill, exit, gextcwd, chdir, stat, lstat, fstat, unlink, execve, dup, dup2, pipe, opendir, readdir, closedir, strerror, perror, isatty, ttyname, ttyslot, ioctl, getenv, tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs` |
| **Libft authorized** | Yes                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| **Description**      | Write a shell                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |

<br>

##### _Your shell should:_

- ##### _Display a `prompt` when waiting for new command._

- ##### _Have a working `History`._

- ##### _Search and launch the right executable (based on the PATH variable or by using relative or absolute path)_

- ##### _Not use more than `one global variable`. Think about it. You will have to explain why you do it._

- ##### _Not interpret unclosed quotes or unspecified special characters like \ (backslash) or ; (semicolon)._

- ##### _Handle ' (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence._

- ##### _Hanlde " (double quote) which should prevent the shell from interpeting the metacharacters in the quoted sequence except for $ (dollar sign)._

- ##### _Implement redirections:_

  - ##### _`<` should redirect input._

  - ##### _`>` should redirect output._

  - ##### _`<<` should be given a delimiter, then read the input until a line containing the delimiter is seen. However, it doesn't have to update the history!_

  - ##### _`>>` should redirect output with append mode._

- ##### _Implement `pipes` ( `|` character). The output of each command in the pipeline is connected to the input of the nex command via a pipe._

- ##### _Handle `environment variables` (`$` followed by a sequence of characters) which sould expand to their values._

- ##### _Handle `$?` which should expand to the exit status of the most recently executed foreground pipeline._

- ##### _Handle `ctrl-C, ctrl-D` and `ctrl-\` should have the same result as in bash._

- ##### In interactive mode:

  - ##### _`ctrl-C` print a new prompt on a newline._

  - ##### _`ctrl-D` exit the shell._

  - ##### _`ctrl-\` do nothing._

- ##### _It must implement the `builtins`:_

  - ##### _`echo` with option `-n`_

  - ##### _`cd` with only a relative or absolute path_

  - ##### _`pwd` with no options_

  - ##### _`export` with no options_

  - ##### _`unset` with no options_

  - ##### _`env` with no options or arguments_

  - ##### _`exit` with no options_

##### _The `readline()` function can cause memory leaks. You don't have to fix them. But that `doesn't mean your own code, yes the code you wrote, can have memory leaks.`_

> 💡 <br>
>
> ##### _You should limit yourself to the subject description. Anything that is not asked is not required.<br>If you have any doubt about a requirement, take [bash](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/) as a reference._

<br>

# ✲ Bonus part

##### _Your program has to implement:_

- ##### _`&&, ||` with parenthesis for priorities._

- ##### _Wilcard `*` should work for the current working directory._

> ⚠️ <br>
>
> ##### _The bonus part will only be assessed if the mandatory part is PERFECT. Perfect means the mandatory part has been integrally done and works without malfunctioning. If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all._
