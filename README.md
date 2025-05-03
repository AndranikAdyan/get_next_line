# 📄 get\_next\_line

> A 42 project that implements a function to read input **line by line** from a file descriptor — handling memory and buffer boundaries safely in pure C.

---

## 🧠 Project Objective

The goal of `get_next_line` is to create a function `get_next_line(int fd)` that reads and returns **a single line** from a file descriptor, including the newline character (`\n`) if present.

---

## 🔧 How to Compile

There is **no Makefile**. Compile manually like this:

### 👉 Mandatory part:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

> Replace `main.c` with your own test file.

### 👉 Bonus part:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c
```

---

## 🧪 Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

---

## 📘 Function Prototype

```c
char *get_next_line(int fd);
```

* **fd** – File descriptor to read from
* Returns the next line, or `NULL` at EOF or error

---

## 📦 BUFFER\_SIZE

You can define `BUFFER_SIZE` at compile time using `-D`:

```bash
gcc -D BUFFER_SIZE=100 ...
```

Or add this to your test file before including the header:

```c
#define BUFFER_SIZE 100
#include "get_next_line.h"
```

---

## 🧼 Memory Management

* All returned lines are `malloc`'d — must be `free`d by the caller
* No memory leaks (check with `valgrind`!)

---

## ✅ Norm Requirements

* Fully **Norm-compliant**
* Only allowed C functions: `read`, `malloc`, `free`
