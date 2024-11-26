# Restaurant Management System

## Overview
This project is a **Restaurant Management System** developed in C++. It provides functionalities to manage menu items, take customer orders, process payments, and generate invoices. The program is structured into classes and functions, allowing modular management of a restaurant's core operations.

---

## Features
### 1. Menu Management
- Add new menu items.
- Edit existing menu items.
- Delete menu items.
- Display all menu items.

### 2. Order Management
- Create new customer orders.
- Add items to an order.
- Display current orders.

### 3. Payment Processing
- Process payments via cash or credit.

### 4. Invoice Generation
- Generate and display customer invoices.

---

## Project Structure
### Classes
1. **`MenuItem`**: Represents a single menu item with attributes like ID, name, description, price, category, and stock.
2. **`MenuManager`**: Manages a collection of menu items, providing CRUD operations.
3. **`OrderItem`**: Represents a single item in a customer's order with quantity and price.
4. **`OrderManager`**: Handles customer orders, including adding items and calculating total prices.

### Functions
- **Menu Operations**: Add, edit, delete, and display menu items.
- **Order Operations**: Create, view, and manage customer orders.
- **Payment Operations**: Process payments and handle receipts.
- **Invoice Operations**: Generate and display order invoices.

---

## How to Use
### Prerequisites
- A C++ compiler (e.g., GCC, Clang, or Visual Studio).

### Run the Program
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/restaurant-management-system.git
   cd restaurant-management-system
