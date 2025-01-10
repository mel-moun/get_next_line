# get_next_line 📄

## Overview 📝

`get_next_line` is a C project that implements a function to read a file and return one line at a time. The goal of this project is to manage file reading operations in a way that allows for handling large files and efficient memory management while reading them line by line. It supports reading from standard input as well as files.

This project is part of the 42 coding school curriculum and helps students practice file handling, memory management, and working with buffers in C.

## Features 🌟

- Reads a file (or standard input) and returns a single line at a time.
- Efficient memory management using dynamic allocation.
- Supports reading from large files without loading the entire content into memory.
- Handles edge cases, such as an empty line, multiple consecutive newlines, and EOF (end of file).

## Functions 📚

The main function provided by this project is:

### `get_next_line()`

```c
int get_next_line(int fd, char **line);
