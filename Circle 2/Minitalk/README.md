# Minitalk

> [![dogpark's 42 minitalk Score](https://badge42.vercel.app/api/v2/clam4rmh700350fjk8ctdih83/project/3109558)](https://github.com/JaeSeoKim/badge42)

> 🔗 [Minitalk](https://dogpark-42cursus.notion.site/Minitalk-c1bf479a8189448eb378fac331b2d6c1)

##### _Summary: The purpose of this project is to code a small data exchange program using UNIX signals._

##### _Version: 2_

#### 🔗 : _This mark means a connection with a **Notion link**._

<br>

### 📄 Assignment

> 🔗 [Assignment discription](https://dogpark-42cursus.notion.site/Assignment-a724a8c971d442ec97982576472e1379)

### 📌 Reference

> 🔗 [Reference](https://dogpark-42cursus.notion.site/Reference-9ffb4bafc0c646e08cb8aa4caa7b4f56)

<br>

# ✲ Project instructions

- ##### _Name your executable files `client` and `server`._

- ##### _You have to turn in a `Makefile` which will compile your source files. It must not relink._

- ##### _You can definitely use your `libft`._

- ##### _You have to handle errors thoroughly. In no way your program should quit unexpectedly (segmentation fault, bus error, double free, and so forth)._

- ##### _Your program mustn't have `memory leaks`._

- ##### _You can have `one global variable per program` (one of the client and one for the server), but you will have to justify their use._

- ##### _In order to complete the mandatory part, you are allowed to use the following functions:_

  - `write`
  - `ft_printf`
  - `signal`
  - `sigemptyset`
  - `sigaddset`
  - `sigaction`
  - `kill`
  - `getpid`
  - `malloc`
  - `free`
  - `pause`
  - `sleep`
  - `usleep`
  - `exit`

<br>

# ✲ Mandatory Part

> 🔗 [server.c](https://www.notion.so/dogpark-42cursus/server-c-59624566d324450ca54dea7b8bae9491?pvs=4)<br>
> 🔗 [client.c](https://www.notion.so/dogpark-42cursus/client-c-7f0aed5dc27c44ba93ca734ec8f9e363?pvs=4)

##### _You must create a communication program in the form of a `client` and a `server`._

- ##### _The server must be launched first. After its launch, it has to print its PID._

- ##### _The client take two parameters:_

  - ##### _The server PID._

  - ##### _The string to send._

- ##### _The client must communicate the string passed as a parameter to the server. Once the string has been received, the server must print it._

- ##### _The server has to display the string pretty quickly. Quickly means that if you think it takes too long, then it is probably too long._

> 💡 <br>
>
> ##### _1 secon for displaying 100 character is way too much!_

- ##### _Your server should be able to receive strings from several clients in a row without needing to restart._

- ##### _The communication between your client and your server has to be done only using programs should ONLY using UNIX signals._

- ##### _You can only use the two signals `SIGUSR1` and `SIGUSR2`._

> ⚠️ <br>
>
> ##### _Linux system does NOT queue signals when you already have pending signal of this type! Bonus time?_

<br>

# ✲ Bonus part

> 🔗 [server_bonus.c](https://www.notion.so/dogpark-42cursus/server-c-59624566d324450ca54dea7b8bae9491?pvs=4)<br>
> 🔗 [client_bonus.c](https://www.notion.so/dogpark-42cursus/client-c-7f0aed5dc27c44ba93ca734ec8f9e363?pvs=4)

##### _Bonus list :_

- ##### _The server acknowledge every message received by sending back a signal to the client._

- ##### _Unicode characters support!_

> ⚠️ <br>
>
> ##### _The boonus part will only be assessed if the mandatory part is PERFECT. Perfect means the mandatory part has been integrally done and works without amlfunctioning. If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all._
