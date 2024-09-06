# Restaurant Inventory Manager

This project is a restaurant inventory management system that helps a restaurant manager keep track of food items, including their categories, expiration dates, and order frequencies. The system supports three types of food items: Canned, Fish, and Poultry, each with unique characteristics. The program utilizes object-oriented programming principles, a binary search tree (BST) for efficient data management and smart pointers for dynamic memory handling.

## Features

- Binary Search Tree (BST) Implementation: Manages food items efficiently using a BST, allowing quick insertion, searching, and removal of items based on their names and order frequencies.
- Three Food Categories: Supports Canned, Fish, and Poultry items, each with specific attributes like expiration dates, origin, storage temperatures, and fresh-by dates.
- Dynamic Binding and Downcasting: Utilizes dynamic binding to handle different types of food items uniformly. The program demonstrates downcasting to update specific attributes (e.g., the fresh-by date of poultry items).
- Smart Pointers: Implements modern C++ smart pointers (e.g., unique_ptr) to manage memory dynamically and safely, ensuring that memory leaks are prevented.
- Exception Handling: The program includes custom exception handling to manage missing or overwritten data during user interactions, ensuring robust error detection and handling.
- Comprehensive Menu System: The application offers a user-friendly menu for adding, removing, displaying, and updating food items.
