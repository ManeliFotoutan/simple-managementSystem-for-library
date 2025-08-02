# 📚 Library Management System in C++

This project implements a basic **Library Management System** in **C++**, enabling functionality such as:

- Managing multiple libraries
- Managing books and book types
- Borrowing and returning books
- Finding books by type or availability
- Searching for nearest libraries with a specific book

---

## 🛠️ Features

- 📖 Add books to libraries
- 👤 Register new members
- 🧾 Borrow and return books (with limitations)
- 🔎 Search books by name or type
- 📍 Find nearest library that has a specific book
- ❌ Error handling for duplicate libraries, books, or members

---

## 🧩 Class Structure

### `Publisher`
- Represents a publisher with name and location.
- Auto-incremented unique ID for each publisher.

### `Book`
- Stores book details: name, type, publisher, and ID.
- Book types are defined by the `enum BookType`:
  - `SCIENTIFIC`, `CRIME`, `FANTASY`, `HORROR`, `CLASSICS`

### `Member`
- Represents a library member.
- Can borrow up to 5 books at a time.
- Maintains a list of borrowed books per library.

### `Library`
- Contains books and has a unique position.
- Supports:
  - Adding books
  - Retrieving books by name or type
  - Showing book info
  - Checking if a book exists

### `LibrariesHandler`
- Handles all libraries and members.
- Global operations like:
  - Creating libraries
  - Adding books
  - Borrowing and returning books
  - Filtering books
  - Finding nearest libraries with available books

---

## 🚀 How to Run

1. Compile the program using a C++ compiler such as `g++`:

```bash
g++ main.cpp -o library
