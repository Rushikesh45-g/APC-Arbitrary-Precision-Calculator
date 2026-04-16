# 🔢 Arbitrary Precision Calculator (APC) in C

## 📌 Overview
This project implements an Arbitrary Precision Calculator in C to perform arithmetic operations on very large numbers that cannot be handled by standard data types. The calculator uses doubly linked lists to store and process multi-digit numbers efficiently.

---

## 🚀 Features
- Supports large number calculations beyond standard limits
- Implements operations like addition, subtraction, multiplication
- Uses doubly linked list for dynamic data storage
- Efficient handling of carry and borrow operations

---

## 🛠️ Technologies Used
- C Programming
- Doubly Linked List
- Dynamic Memory Allocation
- Pointers and Structures
- Modular Programming

---

## ⚙️ How It Works
Numbers are stored as nodes in a doubly linked list, where each node represents a digit. Arithmetic operations are performed digit by digit, similar to manual calculations, handling carry and borrow accordingly.

---

## ▶️ How to Run
```bash
gcc apc.c -o apc
./apc
