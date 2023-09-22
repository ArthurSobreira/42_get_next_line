<div align="center"><h1>Get Next Line [125 / 100]</h1></div>

<div align="center">
   <a href="https://github.com/ArthurSobreira/42_libft" target="_blank">
      <img height=170 src="https://github.com/byaliego/42-project-badges/blob/main/badges/get_next_linem.png" hspace = "10">
   </a>
</div>

## Summary

> <i>The second project on the 42sp fundamentals track, <strong>Get Next Line</strong>, is based on the creation</i>
> <i>of a function that returns line by line from a file pointed to by a file descriptor,</i>
> <i>covering topics such as reading and describing files, static variables, dynamic allocation memory, pointers, and more.</i>

<br>

## Project Files

* [`get_next_line.c`](src/get_next_line.c)      [`get_next_line_bonus.c`](src/get_next_line_bonus.c) - main functions (project implementation)
* [`get_next_line.h`](include/get_next_line.h)      [`get_next_line_bonus.h`](include/get_next_line_bonus.h) - header file (prototypes and includes)
* [`get_next_line_utils.c`](utils/get_next_line_utils.c)      [`get_next_line_utils_bonus.c`](utils/get_next_line_utils_bonus.c) - auxiliary functions (project requirements)

<br>

## Run the Program

* Make sure you clone the repository with the following command:

```bash
$> git clone git@github.com:ArthurSobreira/42_get_next_line.git
```

* Once cloned, compile the program with the following command (the value of <strong><i>BUFFER_SIZE</i></strong> can be changed if you prefer):

```bash
$> cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c src/get_next_line.c utils/get_next_line_utils.c include/get_next_line.h && ./a.out
```

* Running the binary, the result should look something like this:

```
Line 1 -> ██╗░░██╗███████╗██╗░░░░░██╗░░░░░░█████╗░  ░██╗░░░░░░░██╗░█████╗░██████╗░██╗░░░░░██████╗░
Line 2 -> ██║░░██║██╔════╝██║░░░░░██║░░░░░██╔══██╗  ░██║░░██╗░░██║██╔══██╗██╔══██╗██║░░░░░██╔══██╗
Line 3 -> ███████║█████╗░░██║░░░░░██║░░░░░██║░░██║  ░╚██╗████╗██╔╝██║░░██║██████╔╝██║░░░░░██║░░██║
Line 4 -> ██╔══██║██╔══╝░░██║░░░░░██║░░░░░██║░░██║  ░░████╔═████║░██║░░██║██╔══██╗██║░░░░░██║░░██║
Line 5 -> ██║░░██║███████╗███████╗███████╗╚█████╔╝  ░░╚██╔╝░╚██╔╝░╚█████╔╝██║░░██║███████╗██████╔╝
Line 6 -> ╚═╝░░╚═╝╚══════╝╚══════╝╚══════╝░╚════╝░  ░░░╚═╝░░░╚═╝░░░╚════╝░╚═╝░░╚═╝╚══════╝╚═════╝░
```








