# Compiler-Design- 🚀

<div align="center">

![C++](https://img.shields.io/badge/C++-Programming-blue?style=for-the-badge\&logo=cplusplus)
![Compiler Design](https://img.shields.io/badge/Compiler-Design-success?style=for-the-badge)
![Lexical Analysis](https://img.shields.io/badge/Lexical-Analysis-orange?style=for-the-badge)
![Parsing](https://img.shields.io/badge/Parsing-Techniques-purple?style=for-the-badge)
![Flex & Bison](https://img.shields.io/badge/Flex-Bison-red?style=for-the-badge)

### Weekly Practice Implementations of Core Compiler Design Concepts & Algorithms

</div>

---

# 📖 Overview

This repository contains my structured weekly practice implementations of fundamental and advanced concepts in Compiler Design using C++.

The goal of this repository is to build a strong understanding of the internal working of compilers by implementing important compiler construction algorithms from scratch, including:

* Lexical Analysis
* Parsing Techniques
* Syntax Analysis
* Intermediate Code Generation
* Backpatching
* Machine Code Generation
* Grammar Processing
* Flex & Bison Implementations

This repository serves as both a learning archive and a practical implementation reference for students, developers, and compiler enthusiasts.

---

# 🎯 Objectives

* Strengthen understanding of compiler architecture
* Implement core compiler algorithms manually
* Practice parsing and syntax analysis techniques
* Explore code generation methodologies
* Gain hands-on experience with Flex and Bison
* Build strong foundations in systems programming concepts

---

# 🏗️ Compiler Design Workflow

```text id="9p3u2r"
Source Code
     │
     ▼
Lexical Analysis
     │
     ▼
Syntax Analysis
     │
     ▼
Semantic Analysis
     │
     ▼
Intermediate Code Generation
     │
     ▼
Code Optimization
     │
     ▼
Machine Code Generation
```

---

# 📂 Repository Structure

```bash id="wr3zkl"
Compiler-Design-/
│
├── Basic Flex Program.cpp
├── Design.cpp
├── Driver File.cpp
├── FIRST and FOLLOW.cpp
├── FLEX and BISON.cpp
├── Implement backpatching.cpp
├── Intermediate Code.cpp
├── LEADING and TRAILING.cpp
├── Lexical Analyzer.cpp
├── Machine Code Generation.cpp
├── Shift-Reduce Parser.cpp
├── simple calculator.cpp
└── README.md
```

---

# 🧠 Implemented Concepts

## 🔹 Lexical Analysis

### 📌 Lexical Analyzer

Implementation of a lexical analyzer to identify:

* Keywords
* Operators
* Identifiers
* Constants
* Symbols

---

## 🔹 Parsing Techniques

### 📌 Shift Reduce Parser

Implementation of shift-reduce parsing algorithm used in bottom-up parsing.

### 📌 FIRST and FOLLOW

Program to compute FIRST and FOLLOW sets for context-free grammars.

### 📌 LEADING and TRAILING

Implementation for operator precedence grammar analysis.

---

## 🔹 Flex & Bison

### 📌 Basic Flex Program

Introduction to scanner generation using Flex.

### 📌 FLEX and BISON

Implementation demonstrating parser generation using:

* Flex (Lexical Analyzer Generator)
* Bison (Parser Generator)

---

## 🔹 Intermediate Code Generation

### 📌 Intermediate Code

Generation of intermediate representation for expressions and statements.

### 📌 Implement Backpatching

Implementation of backpatching techniques for control flow statements.

---

## 🔹 Machine Code Generation

### 📌 Machine Code Generation

Basic implementation of machine-level instruction generation from intermediate code.

---

## 🔹 Utility Programs

### 📌 Simple Calculator

Expression evaluator implementation.

### 📌 Driver File

Driver implementation for compiler execution flow.

---

# ⚙️ Tech Stack

| Technology          | Usage                       |
| ------------------- | --------------------------- |
| C++                 | Core Programming Language   |
| Flex                | Lexical Analyzer Generation |
| Bison               | Parser Generation           |
| Compiler Algorithms | Parsing & Code Generation   |

---

# 🚀 Getting Started

## Prerequisites

* C++ Compiler (G++)
* Flex
* Bison
* Linux / Unix Environment Recommended

---

# 🔧 Compilation & Execution

## Compile C++ Programs

```bash id="n9k19e"
g++ filename.cpp -o output
./output
```

---

## Run Flex Program

```bash id="qk07uw"
flex filename.l
gcc lex.yy.c -o output
./output
```

---

## Run Bison Program

```bash id="89jlwm"
bison -d filename.y
gcc filename.tab.c -o output
./output
```

---

# 📚 Learning Outcomes

Through these implementations, the repository covers practical understanding of:

* Compiler Phases
* Grammar Parsing
* Syntax Tree Construction
* Parsing Algorithms
* Intermediate Representations
* Code Translation
* Parser Generators
* Automata Concepts
* Context-Free Grammars

---

# 🔮 Future Improvements

* Recursive Descent Parser
* LL(1) Parser
* LR Parser
* DAG Optimization
* Symbol Table Management
* Semantic Analyzer
* Register Allocation
* Tiny Language Compiler
* Mini C Compiler Implementation

---

# 🤝 Contributions

Contributions, improvements, and optimizations are welcome.

## Contribution Workflow

```bash id="pvsuvj"
# Fork Repository

# Create Feature Branch
git checkout -b feature-name

# Commit Changes
git commit -m "Added new implementation"

# Push Changes
git push origin feature-name
```

Then create a Pull Request.

---

# 📜 License

This repository is open-source and available under the MIT License.

---

# 👨‍💻 Author

## Mohammad Hassan

* GitHub: [mhassanworks GitHub](https://github.com/mhassanworks?utm_source=chatgpt.com)
* LinkedIn: [Mohammad Hassan LinkedIn](https://www.linkedin.com/in/mohammad-hassan-b756352a9?utm_source=chatgpt.com)

---

# ⭐ Repository Purpose

This repository represents my continuous weekly learning journey in Compiler Design and low-level language processing concepts through practical implementations and experimentation.

---

<div align="center">

### ⭐ If you found this repository useful, consider giving it a star.

</div>
