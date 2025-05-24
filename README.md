🛒 C++ Inventory & Customer Management System

 This project implements a comprehensive Inventory and Customer Management System in C++ using fundamental data structures 
 such as Linked Lists, Stacks, and Queues. It is designed for managing a store’s product inventory, handling customer 
 purchases, and generating daily sales reports.

📋 Features

🔐 Admin Authentication

   Secure login with default credentials:
   Username: admin
   Password: admin
   Admin can change their credentials during runtime.

📦 Inventory Management (Linked List)

   Add new products with name, price, and stock.
   Remove products by name.
   View all available products in a formatted table.
   Search for a specific product.
   Automatically alerts admin when stock falls below threshold (default <5).


🧺 Customer Shopping (Queue + Cart)

   Each customer is queued upon entry.
   Customers can :
        Add items to their shopping cart.
        View cart contents and total cost.
        Checkout, which updates inventory and logs their total spent.
   Cart functionality includes product name, quantity, and per-item pricing.

⚠️ Low Stock Alerts (Stack)

   Products with low stock levels are pushed onto a stack.
   Admin can view and clear all current low-stock warnings.

📊 Reporting

   View a Daily Sales Report including:
   Total customers served.
   Total sales revenue.

🧱 Data Structures Used

   Linked List – Manages inventory for dynamic product addition/removal.
   Queue – Tracks customers in the order they arrive.
   Stack – Stores low-stock alerts in LIFO order.
   Array – Used internally within the shopping cart to store products and quantities.

👤 Author

 Developed as a practice project for mastering C++ and fundamental data structures through real-world simulation.
