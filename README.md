# 🎮 So_long - 2D Game Project

![So_long Gameplay](./textures/gameplay.png)

## 📋 Description

**So_long** is a 2D top-down adventure game built in C using the **MLX42** graphics library. It focuses on implementing game development fundamentals including graphics rendering, collision detection, map parsing, and game mechanics.

The game features a player character that must collect all collectibles (carrots) on a map and reach the exit to win. The bonus version includes enemies that patrol the map and must be avoided.

## ✨ Features

### Mandatory Features
- ✅ Customizable 2D maps with various terrain types
- ✅ Player movement with smooth controls (WASD or Arrow Keys)
- ✅ Collectible items (carrots) to gather
- ✅ Exit portal to complete the level
- ✅ Collision detection with walls and boundaries
- ✅ Real-time move counter display
- ✅ Sprite rendering and animation
- ✅ Map validation and error handling

### Bonus Features
- 🎯 Enemy sprites that patrol the map
- 🎯 Enemy AI and collision detection
- 🎯 Visual feedback for damage/death
- 🎯 Enhanced graphics and animations
- 🎯 Additional gameplay elements

## 🛠️ Requirements

- **OS**: Linux (tested on Linux kernel)
- **Compiler**: gcc or clang with C99 support
- **Build Tool**: make
- **Graphics Library**: MLX42
- **Dependencies**: libglfw3-dev, libx11-dev, libxext-dev (for MLX42)

## 🚀 Installation & Compilation

### 1. Clone and Setup
```bash
git clone <repository-url>
cd so_long
```

### 2. Compile the Project

**Mandatory Version:**
```bash
make
```

**Bonus Version:**
```bash
make bonus
```

**Clean Build Files:**
```bash
make clean      # Remove object files
make fclean     # Remove all generated files
make re         # Clean and rebuild
```

### 3. Run the Game

**Mandatory:**
```bash
./so_long maps/mandatory_map.ber
```

**Bonus:**
```bash
./so_long_bonus maps/bonus_map.ber
```

## 🎮 How to Play

### Controls
- **Arrow Keys** or **WASD**: Move the character
  - `↑` or `W`: Move up
  - `↓` or `S`: Move down
  - `←` or `A`: Move left
  - `→` or `D`: Move right
- **ESC**: Close the game window

### Objective
1. **Collect all carrots** 🥕 scattered throughout the map
2. **Reach the exit** (portal) to complete the level
3. **Avoid enemies** (in bonus version) - contact causes game over
4. **Minimize moves** - the game displays your move count

### Win Condition
Collect all collectibles and reach the exit portal

### Lose Condition (Bonus)
Contact with an enemy sprite

## 📁 Project Structure

```
so_long/
├── Makefile                 # Build configuration
├── README.md               # This file
├── maps/                   # Game map files
│   ├── mandatory_map.ber
│   └── bonus_map.ber
├── textures/               # Game sprites and assets
├── include/                # Header files
│   ├── so_long_mandatory.h
│   └── bonus/
│       └── so_long_bonus.h
├── src/                    # Mandatory version source code
│   ├── main.c
│   ├── init.c
│   ├── render.c
│   ├── controls.c
│   ├── map_read.c
│   ├── map_validate.c
│   ├── map_checks.c
│   ├── validation.c
│   ├── free.c
│   └── ...
├── bonus/                  # Bonus version source code
│   ├── src/
│   │   ├── main.c
│   │   ├── init.c
│   │   ├── render.c
│   │   ├── controls.c
│   │   ├── handle_enemy.c
│   │   ├── map_checks.c
│   │   └── ...
│   └── include/
│       └── so_long_bonus.h
└── libs/                   # External libraries
    ├── libft/              # Custom C library
    └── MLX42/              # Graphics library
```

## 🗺️ Map Format

Maps are defined in `.ber` format with the following rules:

- **`1`**: Wall (obstacle)
- **`0`**: Empty space (walkable)
- **`P`**: Player starting position (exactly 1)
- **`E`**: Exit/Portal (exactly 1)
- **`C`**: Collectible/Carrot (at least 1)
- **`X`**: Enemy (bonus version only)

### Example Map
```
1111111111111111
1P0000000000000C1
1000000E0000000C1
1000111111110001
1C000000000C0001
1111111111111111
```

### Map Validation
- Must be rectangular
- Must be surrounded by walls
- Must contain at least 1 collectible
- Must have exactly 1 player and 1 exit
- All characters must be valid

## 🔧 Code Structure

### Key Modules

| Module | Purpose |
|--------|---------|
| `main.c` | Program entry point and game loop |
| `init.c` | Game initialization and setup |
| `render.c` | Graphics rendering and display |
| `controls.c` | Player input handling |
| `map_read.c` | Map file parsing |
| `map_validate.c` | Map validation logic |
| `validation.c` | General validation functions |
| `free.c` | Memory deallocation |
| `handle_enemy.c` (bonus) | Enemy AI and behavior |

## 📚 Libraries Used

### MLX42
Modern graphics library for 2D rendering
- Window management
- Image handling
- Event loop
- Pixel manipulation

### libft
Custom C library with utility functions
- String manipulation
- Memory allocation
- Linked lists
- Character classification
- Get next line (for file reading)

## 🎯 Learning Outcomes

This project demonstrates proficiency in:
- **C Programming**: Pointers, memory management, file I/O
- **Game Development**: Game loops, collision detection, rendering
- **Graphics Programming**: Sprite rendering, image handling
- **Algorithm Design**: Map parsing, pathfinding concepts
- **Software Architecture**: Modular code structure, separation of concerns
- **Debugging**: Error handling and validation

## 📝 Compilation Details

The Makefile automatically:
1. Compiles the custom `libft` library
2. Builds MLX42 using CMake
3. Compiles all source files
4. Links everything into an executable

### Compiler Flags
- `-Wall -Wextra -Werror`: Strict warning checking
- `-std=c99`: C99 standard compliance
- Optimization flags for performance

## 🐛 Troubleshooting

| Issue | Solution |
|-------|----------|
| Missing MLX42 dependencies | Install: `sudo apt-get install libglfw3-dev libx11-dev libxext-dev` |
| Compilation errors | Run `make fclean && make` for a clean rebuild |
| Map file not found | Use absolute path or ensure map file exists in `maps/` directory |
| Segmentation fault | Check map validation and ensure map file is properly formatted |

## 👨‍💻 Author

**gbercaco**

## 📄 License

This project is part of the 42 School curriculum.

## 🔗 Resources

- [MLX42 Documentation](https://github.com/codam-coding-school/MLX42)
- [Map Format Documentation](./docs/MAP_FORMAT.md) (if available)

---

**Happy Gaming! 🎮**

*Last Updated: January 2026*
