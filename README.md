# Learning C++: The Console Way

A repository dedicated to learning C++ syntax, type safety, stream handling, and overall C++ programming from scratch.

## 🛡️ Architectural Focus: Input Stream Sanitization

Even in lightweight console applications, user input is unpredictable. The primary engineering goal of this project was to tackle user unpredictability caused by type-mismatches in standard input streams (`std::cin`).

Instead of allowing the application to crash or enter an infinite loop state when a user injects alphanumeric characters instead of integers, the application implements a deterministic validation pipe:

*   **Stream Failure Trapping:** Leverages `std::cin.fail()` to immediately intercept state corruption in the standard input sequence.
*   **Buffer Flushing & Recovery:** Implements `std::cin.clear()` to reset the stream's internal error state, combined with `std::cin.ignore()` and `std::numeric_limits` to completely flush invalid data from the execution sequence.
*   **Crash Resilience:** Ensures the execution lifecycle remains fully operational and crash-resistant, shifting the application gracefully back to a secure waiting state.

## 🎲 Modern Pseudo-Randomization

To prevent predictable value generation, the application avoids legacy `rand()` structures. Instead, it implements modern C++ `<random>` libraries:
*   **Entropy Source:** Utilizes `std::random_device` for hardware-based non-deterministic seeding.
*   **Engine:** Deploys the Mersenne Twister engine (`std::mt19937`) to guarantee efficient, cryptographic-ready value distribution between 1 and 100.

## 🛠️ Tech Stack & Implementation

*   **Language:** C++ (Standard Console I/O)
*   **Core Concepts:** Stream Sanitization, Unidirectional Logic Flow, Defensive Error Handling.

## 🗺️ Future Development Roadmap

To elevate this program into a user ready playable console game, the project is currently being expanded with the following architectural components:

- [x] **Defensive Stream Handling:** Standard input validation and deterministic loop clearance.
- [ ] **Object-Oriented Refactoring (OOP):** Decoupling application logic by introducing a `Player` class (to keep track of name, score, highscore) and a `Game` class (to integrate the central game logic from the original cpp file into a loop and enforce a 3 strike policy).
- [ ] **Local Data Persistence (DAL):** Integrating an embedded **SQLite** database layer to securely log historical match performance and player metrics.
- [ ] **SQL Injection Mitigation (AppSec):** Do one last check to test if there is a need for prepared statements or if becasue the code checks for having only ints if its even needed
