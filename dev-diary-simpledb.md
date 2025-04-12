# 📘 Dev Diary — SQLite from Scratch

> A running log for my implementation of SQLite in C, following [cstack/db_tutorial](https://cstack.github.io/db_tutorial/). I’m keeping this dev diary to better understand how SQLite works under the hood, practice C, and improve my grasp of systems-level concepts like memory, paging, and file I/O.

---

## 🧭 Project Overview

**Goal:** Build a minimal SQLite clone in C
**Tech Stack:** C, standard I/O, manual memory management, file operations  
**Structure (based on SQLite internals):**

- **Virtual Machine:** interprets SQL queries as bytecode
- **B-Tree:** self-balancing tree made of nodes; each node is one page in size
- **Pager:** interface between B-Tree and disk; handles caching, flushing dirty pages, etc.
- **OS Interface:** thin wrapper over native file I/O (read/write)

---

## 📚 C Pointers & Access Cheatsheet

| Concept                    | Example                       | Explanation                                                            |
| -------------------------- | ----------------------------- | ---------------------------------------------------------------------- |
| Declare a pointer          | `int* ptr;`                   | `ptr` can store the **address** of an `int`                            |
| Get address of a variable  | `ptr = &x;`                   | `&x` gives the address of `x`                                          |
| Dereference a pointer      | `*ptr = 5;`                   | Sets the value at the address to `5`                                   |
| Access struct with pointer | `ptr->field`                  | Shortcut for `(*ptr).field` — used when you have a pointer to a struct |
| Allocate memory            | `malloc(sizeof(int))`         | Allocates enough memory for one `int`                                  |
| Free memory                | `free(ptr);`                  | Frees what `malloc` or `getline` allocated                             |
| Pass pointer to function   | `void modify(int* p)`         | Lets the function change the original value (call with `&x`)           |
| Array indexing via pointer | `*(arr + i)` = `arr[i]`       | They’re equivalent!                                                    |
| String copy (common error) | `strcpy(dest, src)`           | You can't do `dest = src;` for char arrays — use `strcpy()` instead    |
| `getline()` usage          | `getline(&buf, &len, stdin);` | Needs `char* buf = NULL; size_t len = 0;` beforehand                   |

---

## 🗓️ Daily Log

### Day 1: 2025-04-12 — Initial Setup & Concept Mapping

**Tasks Done:**

- Read through C pointer syntax & `getline()` usage
- Studied high-level SQLite architecture

**What I Learned:**

- The core of SQLite is its **Virtual Machine**. SQL is parsed into bytecode, which the VM executes.
- **B-Tree**: each node is 1 page in size (usually 4KB), and they are loaded/saved via the pager
- **Pager**: manages what pages are in memory, and when to flush modified (dirty) pages
- **OS Interface**: handles file I/O directly using system calls; everything else builds on this

**Next Steps:**

- Set up basic REPL loop in `main.c`

---
