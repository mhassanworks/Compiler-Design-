<div align="center">

<br/>

```
 ██████╗ ██████╗ ███╗   ███╗██████╗ ██╗██╗     ███████╗██████╗
██╔════╝██╔═══██╗████╗ ████║██╔══██╗██║██║     ██╔════╝██╔══██╗
██║     ██║   ██║██╔████╔██║██████╔╝██║██║     █████╗  ██████╔╝
██║     ██║   ██║██║╚██╔╝██║██╔═══╝ ██║██║     ██╔══╝  ██╔══██╗
╚██████╗╚██████╔╝██║ ╚═╝ ██║██║     ██║███████╗███████╗██║  ██║
 ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝
                    D  E  S  I  G  N
```

# 🔬 Compiler Design

### *A Structured Journey Through the Heart of Programming Languages*

<br/>

[![C++](https://img.shields.io/badge/C++17-Programming-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Flex](https://img.shields.io/badge/Flex-Lexer%20Generator-4A90E2?style=for-the-badge)](https://github.com/westes/flex)
[![Bison](https://img.shields.io/badge/GNU%20Bison-Parser%20Generator-A8D08D?style=for-the-badge)](https://www.gnu.org/software/bison/)
[![Linux](https://img.shields.io/badge/Linux-Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white)](https://ubuntu.com/)
[![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)](LICENSE)
[![Status](https://img.shields.io/badge/Status-Active%20Development-brightgreen?style=for-the-badge)]()

<br/>

> *"A compiler is the most complex program most programmers will ever use — and the most rewarding one to build."*

<br/>

</div>

---

## 📌 Table of Contents

| # | Section |
|---|---------|
| 01 | [What Is This Repository?](#-what-is-this-repository) |
| 02 | [Compiler Pipeline — Full Architecture](#️-compiler-pipeline--full-architecture) |
| 03 | [Implemented Modules](#-implemented-modules) |
| 04 | [Repository Structure](#-repository-structure) |
| 05 | [Concept Deep Dives](#-concept-deep-dives) |
| 06 | [Getting Started](#-getting-started) |
| 07 | [Compilation Guide](#️-compilation--execution-guide) |
| 08 | [Learning Outcomes](#-learning-outcomes) |
| 09 | [Roadmap](#-roadmap--future-implementations) |
| 10 | [Contributing](#-contributing) |
| 11 | [Author](#-author) |

---

## 🧬 What Is This Repository?

This repository is a **hands-on, weekly-practice compiler design lab** — a systematic, bottom-up construction of every major phase of a real compiler, implemented from scratch in **C++** with **Flex** and **Bison**.

Rather than reading about compilers theoretically, every concept here is **written, compiled, and tested** — transforming abstract theory into working code.

### Why This Matters

| 🎯 Goal | 💡 Approach |
|---------|------------|
| Understand how source code becomes machine code | Implement each phase manually |
| Master parsing theory (LL, LR, operator precedence) | Code FIRST/FOLLOW, Shift-Reduce parsers |
| Bridge academic theory with real toolchains | Integrate Flex & Bison |
| Build systems-level programming instincts | Write low-level C++ implementations |

---

## 🏗️ Compiler Pipeline — Full Architecture

```
┌─────────────────────────────────────────────────────────────────────┐
│                        SOURCE CODE (.c / .py / ...)                 │
└─────────────────────────────────┬───────────────────────────────────┘
                                  │
                    ┌─────────────▼──────────────┐
                    │    PHASE 1 · LEXICAL        │  ← Lexical Analyzer.cpp
                    │       ANALYSIS              │     Basic Flex Program.cpp
                    │  Token Stream Generation    │     FLEX and BISON.cpp
                    └─────────────┬──────────────┘
                                  │  [Token Stream]
                    ┌─────────────▼──────────────┐
                    │    PHASE 2 · SYNTAX         │  ← Shift-Reduce Parser.cpp
                    │       ANALYSIS              │     FIRST and FOLLOW.cpp
                    │  Grammar + Parse Tree       │     LEADING and TRAILING.cpp
                    └─────────────┬──────────────┘
                                  │  [Parse Tree / AST]
                    ┌─────────────▼──────────────┐
                    │    PHASE 3 · SEMANTIC        │  ← Design.cpp
                    │       ANALYSIS              │
                    │  Type Checking & Scoping    │
                    └─────────────┬──────────────┘
                                  │  [Annotated AST]
                    ┌─────────────▼──────────────┐
                    │    PHASE 4 · INTERMEDIATE   │  ← Intermediate Code.cpp
                    │     CODE GENERATION         │     Implement backpatching.cpp
                    │  Three-Address Code / IR    │
                    └─────────────┬──────────────┘
                                  │  [IR Code]
                    ┌─────────────▼──────────────┐
                    │    PHASE 5 · CODE           │  ← Machine Code Generation.cpp
                    │      GENERATION             │
                    │  Target Assembly / Machine  │
                    └─────────────┬──────────────┘
                                  │
┌─────────────────────────────────▼───────────────────────────────────┐
│                      EXECUTABLE / BINARY OUTPUT                      │
└─────────────────────────────────────────────────────────────────────┘
```

---

## 📦 Implemented Modules

### 🔷 Phase 1 — Lexical Analysis

| File | Description | Key Concepts |
|------|-------------|--------------|
| `Lexical Analyzer.cpp` | Hand-written lexer | Token classification: keywords, identifiers, operators, constants, delimiters |
| `Basic Flex Program.cpp` | Flex-based scanner | Regular expressions, `yylex()`, token actions |
| `FLEX and BISON.cpp` | Full scanner-parser pipeline | `%token`, `%type`, lexer-parser interface |

> **What it does:** Reads raw source characters and produces a structured **token stream** — the first step every compiler takes before it can understand anything.

---

### 🔷 Phase 2 — Syntax Analysis & Parsing

| File | Description | Key Concepts |
|------|-------------|--------------|
| `Shift-Reduce Parser.cpp` | Bottom-up LR parsing | Parse stack, shift/reduce decisions, handle recognition |
| `FIRST and FOLLOW.cpp` | Grammar analysis sets | FIRST(α), FOLLOW(A), nullable derivations |
| `LEADING and TRAILING.cpp` | Operator precedence analysis | LEADING/TRAILING sets, precedence table construction |

> **What it does:** Validates whether a token stream conforms to the grammar of a language, building the **parse tree** that represents the program's structure.

---

### 🔷 Phase 3 — Semantic Analysis

| File | Description | Key Concepts |
|------|-------------|--------------|
| `Design.cpp` | Compiler architecture driver | Symbol table design, scope management, type resolution |

> **What it does:** Walks the parse tree to check **meaning** — type correctness, undeclared variables, scope violations — things syntax alone cannot catch.

---

### 🔷 Phase 4 — Intermediate Code Generation

| File | Description | Key Concepts |
|------|-------------|--------------|
| `Intermediate Code.cpp` | Three-address code (TAC) generation | Temporaries, quadruples, expression flattening |
| `Implement backpatching.cpp` | Control flow with backpatching | Truelist, falselist, backpatch(), `goto` resolution |

> **What it does:** Converts the AST into a **machine-independent intermediate representation** (IR) — making the compiler portable and enabling optimization passes.

---

### 🔷 Phase 5 — Machine Code Generation

| File | Description | Key Concepts |
|------|-------------|--------------|
| `Machine Code Generation.cpp` | Target code emission | Register allocation basics, instruction selection, address modes |

> **What it does:** Translates IR into **actual machine-level instructions** — the final output a processor can execute.

---

### 🔷 Utilities & Tools

| File | Description |
|------|-------------|
| `simple calculator.cpp` | Expression evaluator — grammar + evaluation in one |
| `Driver File.cpp` | Integration harness linking all compiler phases |

---

## 📂 Repository Structure

```
Compiler-Design-/
│
├── 📄 Lexical Analyzer.cpp           ← Phase 1: Handwritten lexer
├── 📄 Basic Flex Program.cpp         ← Phase 1: Flex scanner intro
├── 📄 FLEX and BISON.cpp             ← Phase 1+2: Full Flex+Bison pipeline
│
├── 📄 Shift-Reduce Parser.cpp        ← Phase 2: Bottom-up LR parsing
├── 📄 FIRST and FOLLOW.cpp           ← Phase 2: Grammar set computation
├── 📄 LEADING and TRAILING.cpp       ← Phase 2: Operator precedence analysis
│
├── 📄 Design.cpp                     ← Phase 3: Semantic analysis scaffold
│
├── 📄 Intermediate Code.cpp          ← Phase 4: Three-address code generation
├── 📄 Implement backpatching.cpp     ← Phase 4: Backpatching for control flow
│
├── 📄 Machine Code Generation.cpp    ← Phase 5: Assembly/machine instruction gen
│
├── 📄 simple calculator.cpp          ← Utility: Grammar-based evaluator
├── 📄 Driver File.cpp                ← Utility: Compiler pipeline driver
│
└── 📄 README.md
```

---

## 🔬 Concept Deep Dives

<details>
<summary><strong>🔹 FIRST & FOLLOW Sets — Why They Matter</strong></summary>

<br/>

**FIRST(α)** = the set of terminal symbols that can appear as the **first character** of any string derived from `α`.

**FOLLOW(A)** = the set of terminals that can appear **immediately to the right** of non-terminal `A` in some sentential form.

These sets are the mathematical backbone of **LL(1) parsing** and **predictive parsing tables**. Without them, the parser has no way to make a deterministic decision about which production to apply.

```
Grammar:  E → T E'
          E' → + T E' | ε
          T → F T'
          T' → * F T' | ε
          F → ( E ) | id

FIRST(E)  = { (, id }
FIRST(E') = { +, ε }
FIRST(T)  = { (, id }
FIRST(T') = { *, ε }
FIRST(F)  = { (, id }

FOLLOW(E)  = { $, ) }
FOLLOW(E') = { $, ) }
FOLLOW(T)  = { +, $, ) }
```

</details>

<details>
<summary><strong>🔹 Shift-Reduce Parsing — The LR Method</strong></summary>

<br/>

Shift-reduce parsing is a **bottom-up** technique. It reads input left-to-right and builds the parse tree from leaves to root.

**Two fundamental actions:**
- **SHIFT** — push the next input token onto the stack
- **REDUCE** — pop a handle off the stack, replace with the grammar's LHS non-terminal

```
Stack           Input           Action
─────────────────────────────────────────
$               id + id * id $  SHIFT
$ id            + id * id $     REDUCE: F → id
$ F             + id * id $     REDUCE: T → F
$ T             + id * id $     REDUCE: E → T
$ E             + id * id $     SHIFT
$ E +           id * id $       SHIFT
$ E + id        * id $          REDUCE: F → id
$ E + F         * id $          REDUCE: T → F
$ E + T         * id $          SHIFT
$ E + T *       id $            SHIFT
$ E + T * id    $               REDUCE: F → id
$ E + T * F     $               REDUCE: T → T * F
$ E + T         $               REDUCE: E → E + T
$ E             $               ACCEPT ✓
```

</details>

<details>
<summary><strong>🔹 Backpatching — Resolving Forward Jumps</strong></summary>

<br/>

When generating code for `if-else` and `while` loops, the **destination of a jump** isn't known at the time the jump instruction is emitted. **Backpatching** defers filling in the jump target until the destination is known.

```cpp
// Generating code for:  if (x < y) then S1 else S2

E.truelist  = { 100 }     // instruction 100: if x < y goto ___
E.falselist = { 101 }     // instruction 101: goto ___

// After generating S1:
backpatch(E.truelist, nextquad)   // fill in target of true jump

// After generating S2:
backpatch(E.falselist, nextquad)  // fill in target of false jump
```

This is **one of the most elegant algorithms in compiler construction** — it lets you generate linear single-pass code for structured control flow.

</details>

<details>
<summary><strong>🔹 Flex & Bison — The Professional Toolchain</strong></summary>

<br/>

**Flex** (Fast Lexical Analyzer) generates a C lexer from regular expression rules:

```lex
%%
[0-9]+      { yylval = atoi(yytext); return NUMBER; }
"if"        { return IF; }
[a-zA-Z]+   { return IDENTIFIER; }
[ \t\n]     ;   /* skip whitespace */
%%
```

**Bison** (GNU Parser Generator) generates an LALR(1) parser from a BNF grammar:

```yacc
%token NUMBER IF IDENTIFIER
%%
stmt : IF '(' expr ')' stmt
     | IDENTIFIER '=' expr ';'
     ;
expr : expr '+' expr   { $$ = $1 + $3; }
     | NUMBER           { $$ = $1; }
     ;
%%
```

Together, they form the standard professional pipeline for **language tool development**.

</details>

---

## 🚀 Getting Started

### Prerequisites

```bash
# Ubuntu / Debian
sudo apt-get update
sudo apt-get install g++ flex bison build-essential -y

# macOS (via Homebrew)
brew install gcc flex bison

# Verify installations
g++ --version
flex --version
bison --version
```

### Clone the Repository

```bash
git clone https://github.com/mhassanworks/Compiler-Design-.git
cd Compiler-Design-
```

---

## ⚙️ Compilation & Execution Guide

### 🔧 Compiling C++ Programs

```bash
# Standard compile
g++ -std=c++17 -o output "Lexical Analyzer.cpp"
./output

# With warnings (recommended for learning)
g++ -std=c++17 -Wall -Wextra -o output "Shift-Reduce Parser.cpp"
./output

# FIRST and FOLLOW
g++ -std=c++17 -o first_follow "FIRST and FOLLOW.cpp"
./first_follow
```

---

### 🔧 Running Flex Programs

```bash
# Step 1: Generate C code from Flex specification
flex filename.l

# Step 2: Compile the generated scanner
gcc lex.yy.c -o scanner -lfl

# Step 3: Run the scanner
./scanner < input.txt
```

---

### 🔧 Running Bison + Flex Together

```bash
# Step 1: Generate parser from Bison grammar
bison -d filename.y
# Produces: filename.tab.c  filename.tab.h

# Step 2: Generate lexer
flex filename.l
# Produces: lex.yy.c

# Step 3: Compile everything together
gcc filename.tab.c lex.yy.c -o parser -lfl

# Step 4: Run the parser
./parser < input.txt
```

---

### 🔧 Quick Test: Simple Calculator

```bash
g++ -std=c++17 -o calc "simple calculator.cpp"
echo "3 + 5 * 2" | ./calc
# Expected: 13
```

---

## 📚 Learning Outcomes

After working through this repository, you will have practical mastery of:

```
Compiler Phases          → Full pipeline from source to machine code
Formal Grammars          → Context-free grammars (CFG), BNF, EBNF
Lexical Analysis         → Regular expressions, DFAs, NFAs, token design
Parsing Theory           → LL(k), LR(k), LALR(1) techniques
Parse Tree Construction  → Derivations, abstract syntax trees (AST)
Grammar Analysis Sets    → FIRST, FOLLOW, LEADING, TRAILING computation
Operator Precedence      → Precedence functions, handle recognition
Intermediate Repr.       → Three-address code, quadruples, triples
Control Flow             → Backpatching, boolean expression code gen
Code Generation          → Register allocation, instruction selection
Tool Usage               → Flex, Bison, G++, Unix build toolchain
Systems Programming      → Low-level C++ for language processing
```

---

## 🔮 Roadmap — Future Implementations

### 🔜 In Progress

- [ ] **Recursive Descent Parser** — Top-down LL(1) implementation
- [ ] **LL(1) Parser with Parse Table** — Predictive parsing with goto table
- [ ] **Symbol Table Manager** — Hash-based scope-aware symbol storage

### 📅 Planned

- [ ] **LR(0) and SLR(1) Parser** — Full automaton + action/goto table construction
- [ ] **LALR(1) Parser** — Merged LR states for efficient parsing
- [ ] **DAG Optimization** — Common subexpression elimination via DAG
- [ ] **Semantic Analyzer** — Full type system with scope resolution
- [ ] **Register Allocation** — Graph coloring algorithm
- [ ] **Tiny Language Compiler** — End-to-end mini-language (tokenize → run)
- [ ] **Mini C Compiler** — Subset of C compiled to x86-like assembly

---

## 🤝 Contributing

Contributions, improvements, and alternative implementations are warmly welcome.

### Contribution Workflow

```bash
# 1. Fork the repository on GitHub

# 2. Clone your fork
git clone https://github.com/YOUR-USERNAME/Compiler-Design-.git
cd Compiler-Design-

# 3. Create a descriptive feature branch
git checkout -b feature/add-ll1-parser

# 4. Implement your changes with clear comments

# 5. Commit with a meaningful message
git commit -m "feat: Add LL(1) predictive parser with parse table"

# 6. Push to your fork
git push origin feature/add-ll1-parser

# 7. Open a Pull Request on the main repository
```

### Contribution Guidelines

- Follow the existing naming conventions (`Concept Name.cpp`)
- Add comments explaining the algorithm — this is a **learning repository**
- Include sample input/output in a comment header at the top of each file
- Keep each file focused on one core concept

---

## ⚙️ Tech Stack

| Technology | Role | Version |
|------------|------|---------|
| **C++** | Core implementation language | C++17 |
| **Flex** | Lexical analyzer generator | ≥ 2.6 |
| **GNU Bison** | LALR(1) parser generator | ≥ 3.0 |
| **GCC / G++** | Compiler toolchain | ≥ 9.0 |
| **Linux / Ubuntu** | Recommended build environment | 20.04+ |

---

## 📜 License

This project is open-source under the **MIT License**.
See [`LICENSE`](LICENSE) for full terms.

---

## 👨‍💻 Author

<div align="center">

### Mohammad Hassan

*Systems programmer · Compiler enthusiast · CS practitioner*

[![GitHub](https://img.shields.io/badge/GitHub-mhassanworks-181717?style=for-the-badge&logo=github)](https://github.com/mhassanworks)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Mohammad%20Hassan-0A66C2?style=for-the-badge&logo=linkedin)](https://www.linkedin.com/in/mohammad-hassan-b756352a9)

</div>

---

<div align="center">

## ⭐ Star History

*If this repository helped you understand compilers better — leave a star. It helps others find it.*

[![Star this repo](https://img.shields.io/github/stars/mhassanworks/Compiler-Design-?style=social)](https://github.com/mhassanworks/Compiler-Design-)

<br/>

```
Built with curiosity · Compiled with discipline · Linked with purpose
```

<br/>

**© 2024 Mohammad Hassan · MIT License**

</div>
