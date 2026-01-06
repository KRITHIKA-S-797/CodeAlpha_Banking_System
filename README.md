# Simple Banking System (C++)

A simple **console-based** banking application in C++ that demonstrates basic Object-Oriented Programming concepts such as classes, encapsulation, and composition using `Customer` and `Account` classes.

## Features

- Maintains a single customer's bank account.
- Supports deposit and withdrawal operations with basic validation.
- Displays customer details and current account balance.
- Menu-driven interface for user interaction via the terminal.

## Concepts Used

- C++ classes and objects (`Customer`, `Account`).
- Encapsulation using private data members and public getters/setters.
- Constructors with default parameters.
- Menu loop using `do-while` and `switch` statement.
- Basic input validation for user choices and transaction amounts.

## File Structure

- `main.cpp` (or your chosen filename): Contains the full implementation of:
  - `Account` class (handles balance, deposit, withdraw, and balance display).
  - `Customer` class (stores customer name and associated account).
  - `main()` function with the menu loop.

## How It Works

1. A `Customer` object is created with:
   - Name: `"Student"`
   - Account Number: `1001`
   - Initial Balance: `0.0`
2. The program repeatedly shows a menu:
   - `1. Deposit`
   - `2. Withdraw`
   - `3. View Account Details`
   - `4. Exit`
3. On each choice:
   - Deposit: Prompts for an amount, validates it, and updates balance.
   - Withdraw: Prompts for an amount, checks for sufficient balance, and updates balance.
   - View Account Details: Shows customer name, account number, and current balance.
   - Exit: Ends the program.

## Compilation and Execution

Use any C++ compiler like `g++`:

```bash
g++ main.cpp -o banking_app
./banking_app
