# 🛒 C++ Inventory & Customer Management System

This project implements a comprehensive **Inventory and Customer Management System** in C++ using fundamental data structures such as **Linked Lists**, **Stacks**, and **Queues**. It is designed to manage a store’s product inventory, handle customer purchases, and generate daily sales reports.


## 📋 Features

### 🔐 Admin Authentication
- Secure login with default credentials:  
  **Username:** admin  
  **Password:** admin  
- Admin can change credentials during runtime.

### 📦 Inventory Management (Linked List)
- Add new products (name, price, stock).
- Remove products by name.
- View all available products in a formatted table.
- Search for a specific product.
- Automatic alert when stock falls below threshold (default < 5).

### 🧺 Customer Shopping (Queue + Cart)
- Each customer is queued upon entry.
- Customers can:
  - Add items to shopping cart.
  - View cart contents and total cost.
  - Checkout (updates inventory and logs purchase).
- Cart includes product name, quantity, and per-item pricing.

### ⚠️ Low Stock Alerts (Stack)
- Products with low stock are pushed onto a stack.
- Admin can view and clear all current low-stock warnings.

### 📊 Reporting
- View daily sales report including:
  - Total customers served.
  - Total sales revenue.
<br><br><br>


**Note:** This project was developed to practice C++ and data structures like Linked Lists, Queues, and Stacks through a store simulation.
