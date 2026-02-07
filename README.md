# 🚀 EPIJAM_1

## 🎯 Project Overview

EPIJAM_1 is a game created during a one‑and‑a‑half‑day game jam. The theme of the jam was **“5 minutes.”**
The project includes both a **server** and a **client**, built in C++20 with Raylib for rendering and Asio for networking.
--- 

## 🕹️ Game Concept 

Your village has been transformed and attacked by sorcerers. You play as the last human able to fight back.
Your mission: 
    - Survive enemy attacks
    - Defeat the sorcerers 
    - Gather tomatoes 
    - Brew a potion to save your village 
The game blends action, movement, and resource collection under a strict time limit.
----

## 🛠️ Dependencies & Requirements

- **C++20** compiler (tested with GCC and Clang)
- **CMake ≥ 3.16**
- **Raylib** (graphics, window, audio)
- **Asio**


## 💻 Build Instructions

### 1. Clone the repository
```bash
git clone git@github.com:janumaruku/EPIJAM_1.git
cd EPIJAM_1
```

## Build with CMake
```bash
mkdir build
cd build
cmake ..
make
```

### 🧩 Launch the Server
```bash
./JamServer <PORT>
    with <PORT>: The port number on which the server will listen for incoming client connections.
./JamClient <PORT>
    with:
    <PORT>: The same port number used by the server.
```
---

## 🎮 Usage
- **Arrow keys**: move the player.
- **Spacebar**: Jump.
- Enemies spawn automatically


