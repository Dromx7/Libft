*This project has been created as part of the 42 curriculum by <login>.*

# Libft


## 📝 Description

**Libft** is the first project of the 42 curriculum. It consists of building a custom C library from scratch, compiled as a static archive, `libft.a`, that can be reused in all my future 42 projects.

### 🎯 Goal

The goal is to understand how the standard C library works by recoding it myself, instead of relying on it as a black box. This means handling pointers, memory allocation, and edge cases (`NULL`, `INT_MIN`, overlapping buffers) by hand, while following the 42 Norm and compiling with `-Wall -Wextra -Werror`.

### 🔎 Overview

The library is split into three parts:

- **Part 1 - libc functions:** reimplementations of standard functions (`ft_strlen`, `ft_memcpy`, `ft_atoi`, ...) that behave like the originals.
- **Part 2 - Additional functions:** utilities that aren't in libc or are built on top of it (`ft_split`, `ft_itoa`, `ft_strjoin`, `ft_putnbr_fd`, ...).
- **Part 3 - Linked lists:** functions to create and manipulate lists using the `t_list` structure (`ft_lstnew`, `ft_lstmap`, ...).

## 📋 Library description

`libft.a` is a static C library made of 3 parts: recoded libc functions, additional utility functions, and linked list functions. Everything is declared in a single header, `libft.h`, which also contains the `t_list` structure and the required includes. Each function lives in its own `.c` file, and the library has no dependency other than the system C library (`malloc`, `free`, `write`).

Functions that allocate memory (`ft_strdup`, `ft_calloc`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_lstnew`, `ft_lstmap`) return `NULL` if the allocation fails, and the caller is responsible for freeing the result.

### Part 1 - libc functions

These functions reproduce the behavior of the original libc functions described in `man 3`, with an `ft_` prefix.

**Character functions**

| Prototype | Description |
|---|---|
| `int ft_isalpha(int c)` | Checks if `c` is a letter |
| `int ft_isdigit(int c)` | Checks if `c` is a digit |
| `int ft_isalnum(int c)` | Checks if `c` is a letter or a digit |
| `int ft_isascii(int c)` | Checks if `c` fits in the ASCII table (0-127) |
| `int ft_isprint(int c)` | Checks if `c` is a printable character |
| `int ft_toupper(int c)` | Converts a lowercase letter to uppercase |
| `int ft_tolower(int c)` | Converts an uppercase letter to lowercase |

**String functions**

| Prototype | Description |
|---|---|
| `size_t ft_strlen(const char *s)` | Returns the length of a string |
| `char *ft_strchr(const char *s, int c)` | Finds the first occurrence of `c` in `s` |
| `char *ft_strrchr(const char *s, int c)` | Finds the last occurrence of `c` in `s` |
| `int ft_strncmp(const char *s1, const char *s2, size_t n)` | Compares at most `n` characters of two strings |
| `char *ft_strnstr(const char *big, const char *little, size_t len)` | Finds `little` in the first `len` characters of `big` |
| `size_t ft_strlcpy(char *dst, const char *src, size_t size)` | Copies a string into a buffer of `size` bytes, null-terminating it |
| `size_t ft_strlcat(char *dst, const char *src, size_t size)` | Appends a string to a buffer of `size` bytes, null-terminating it |
| `char *ft_strdup(const char *s)` | Returns a newly allocated copy of a string |
| `int ft_atoi(const char *nptr)` | Converts the beginning of a string to an `int` |

**Memory functions**

| Prototype | Description |
|---|---|
| `void *ft_memset(void *s, int c, size_t n)` | Fills `n` bytes with the byte `c` |
| `void ft_bzero(void *s, size_t n)` | Sets `n` bytes to zero |
| `void *ft_memcpy(void *dest, const void *src, size_t n)` | Copies `n` bytes (buffers must not overlap) |
| `void *ft_memmove(void *dest, const void *src, size_t n)` | Copies `n` bytes, safe when buffers overlap |
| `void *ft_memchr(const void *s, int c, size_t n)` | Finds the first occurrence of a byte in `n` bytes |
| `int ft_memcmp(const void *s1, const void *s2, size_t n)` | Compares `n` bytes of two memory areas |
| `void *ft_calloc(size_t nmemb, size_t size)` | Allocates zero-initialized memory |

### Part 2 - Additional functions

| Prototype | Description |
|---|---|
| `char *ft_substr(char const *s, unsigned int start, size_t len)` | Returns a new string of at most `len` characters starting at index `start` |
| `char *ft_strjoin(char const *s1, char const *s2)` | Returns a new string that is `s1` followed by `s2` |
| `char *ft_strtrim(char const *s1, char const *set)` | Returns a copy of `s1` without the characters of `set` at the beginning and the end |
| `char **ft_split(char const *s, char c)` | Splits `s` using the delimiter `c` and returns a `NULL`-terminated array of strings |
| `char *ft_itoa(int n)` | Converts an integer to a string (handles negatives and `INT_MIN`) |
| `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` | Applies `f` to each character and returns the resulting new string |
| `void ft_striteri(char *s, void (*f)(unsigned int, char *))` | Applies `f` to each character of `s` in place, passing its index |
| `void ft_putchar_fd(char c, int fd)` | Writes a character to a file descriptor |
| `void ft_putstr_fd(char *s, int fd)` | Writes a string to a file descriptor |
| `void ft_putendl_fd(char *s, int fd)` | Writes a string followed by a newline to a file descriptor |
| `void ft_putnbr_fd(int n, int fd)` | Writes an integer to a file descriptor |

### Part 3 - Linked lists

The list functions work with this structure:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Prototype | Description |
|---|---|
| `t_list *ft_lstnew(void *content)` | Creates a new node holding `content` |
| `void ft_lstadd_front(t_list **lst, t_list *new)` | Adds a node at the beginning of the list |
| `int ft_lstsize(t_list *lst)` | Counts the nodes in the list |
| `t_list *ft_lstlast(t_list *lst)` | Returns the last node |
| `void ft_lstadd_back(t_list **lst, t_list *new)` | Adds a node at the end of the list |
| `void ft_lstdelone(t_list *lst, void (*del)(void *))` | Frees one node's content with `del`, then the node itself |
| `void ft_lstclear(t_list **lst, void (*del)(void *))` | Deletes and frees a node and all the nodes after it, then sets the list to `NULL` |
| `void ft_lstiter(t_list *lst, void (*f)(void *))` | Applies `f` to the content of each node |
| `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | Builds a new list by applying `f` to each node, cleaning up with `del` if an allocation fails |


## ⚙️ Instructions

### Requirements

- `cc` (or `gcc` / `clang`)
- `make`
- `ar`

### Installation

```sh
git clone <https://github.com/Dromx7/Libft.git> libft
cd libft
```

### Compilation

```sh
make
```

This compiles every source file with `-Wall -Wextra -Werror` and generates the static library `libft.a` at the root of the repository.

| Command | Effect |
|---|---|
| `make` | Builds `libft.a` (all parts) |
| `make clean` | Removes the object files |
| `make fclean` | Removes the object files and `libft.a` |
| `make re` | Rebuilds everything from scratch (`fclean` + `make`) |

`make` does not relink if nothing has changed.

### Execution

Libft is a library, so there is no executable to run. To use it in your own project, include the header in your source files:

```c
#include "libft.h"
```

Then compile your program and link it with the library:

```sh
gcc main.c libft.a -o program
./program
```


## 📚 Resources

### References

**Documentation**

- [Linux man pages (section 3)](https://man7.org/linux/man-pages/dir_section_3.html): main reference for the behavior, prototype and return value of libc function I recoded (`man 3 strlcpy`, `man 3 memmove`, ...)
- [ISO C standard (ISO/IEC 9899)](https://www.open-std.org/jtc1/sc22/wg14/): official definition of the C language and its standard library, used to check edge cases and undefined behavior
- [Norminette / 42 Norm](https://github.com/42School/norminette): the coding standard of the school, used to format and validate my code

**Articles and tutorials**

- [GeeksforGeeks (C)](https://www.geeksforgeeks.org/c/): articles on pointers, strings, memory allocation, linked lists etc...
- [W3Schools (C)](https://www.w3schools.com/c/): quick explanations and examples of concepts of programming and C syntax

**Videos**

- [CodeVault](https://www.youtube.com/@CodeVault) (YouTube)
- [Hassan El Bahi](https://www.youtube.com/@hassanbahi) (YouTube)

These videos helped me understand pointers, header files, linked lists, and how a library is built and more

### Use of AI

I used AI as a learning companion throughout the project. Whenever a question crossed my mind while coding, or I wanted to understand a new concept, I asked it. It did **not** write any code for me: it guided me by explaining new concepts, and I wrote, tested and understood every function myself.

| Task | How AI was used |
|---|---|
| Understanding concepts | Explanations of the C and low-level concepts I needed for the project, whenever something was new or unclear |
| Questions while coding | Asking "why" and "how" whenever something wasn't clear |
