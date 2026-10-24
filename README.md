# Monster Taming C++

A small monster battle project built in C++ to practise programming fundamentals and organising a project with CMake.

## Overview

This project explores how monsters and their moves can be represented using C++ classes. It is a learning project and is currently in development.

## Technologies

- C++
- CMake

## Project Structure

- `MonsterTamingCPP/src/` — source files, including the program entry point
- `MonsterTamingCPP/include/` — header files
- `CMakeLists.txt` — root build configuration
- `CMakePresets.json` — CMake build presets

## Building

With CMake and a compatible C++ compiler installed, run these commands from the repository root:

```bash
cmake -S . -B build
cmake --build build --config Release
```

The executable is generated inside the build directory. Its location depends on the compiler and build configuration.

## Learning Goals

- Organising code into header and source files
- Using classes to represent monsters and moves
- Managing collections with the C++ Standard Library
- Building a C++ project with CMake
- Using pointers and references to access and modify objects
- Understanding object ownership, lifetime, and memory management
- Working with value, reference, and pointer semantics

## Status

In development.
