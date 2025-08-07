# Agent Instructions

This document provides instructions for agents working on this repository.

## Adding a New Project

To add a new project, please follow these steps:

1.  **Create a directory:** Create a new directory for your project under the most relevant top-level directory (e.g., `bluetooth`, `wifi`, `sensors`). If no suitable directory exists, create a new one.
2.  **Add a `README.md`:** Each project directory must contain a `README.md` file that includes:
    *   A brief introduction to the project.
    *   A list of required hardware and software.
    *   A clear explanation of the project's working principle.
    *   Schematics or a breadboard layout image.
    *   Instructions on how to test the project.
3.  **Add the code:** Add the Arduino sketch (`.ino` file) and any other source code to the project directory.
4.  **Update the main `README.md`:** Add a link to your new project's `README.md` in the "Projects" section of the main `README.md` file.
5.  **Update the inventory:** If your project uses new hardware components, add them to the `INVENTORY.md` file.

## Coding Style

Please follow these coding style guidelines for Arduino sketches:

*   Use comments to explain complex parts of your code.
*   Use meaningful variable and function names.
*   Use `#define` for constants and pin numbers.
*   Keep the code clean and well-formatted.

## Inventory Management

The `INVENTORY.md` file should be kept up-to-date with all the hardware components available. When you use a new component for a project, please add it to the inventory list.
