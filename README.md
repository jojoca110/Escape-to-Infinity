# Escape to Infinity 🚀

A thrilling 3D endless runner space game built with C++ and OpenGL. Navigate your spaceship through an infinite procedurally-generated corridor, dodge obstacles, collect power-ups, and see how far you can travel!

## Overview

Escape to Infinity is an arcade-style endless runner where you pilot a spaceship through a procedurally-generated space tunnel. The game features dynamic obstacle generation, collectible power-ups, multiple difficulty levels, and a ranking system to track your best performances.

## Features

- **Procedural Generation**: Infinite gameplay with randomly generated obstacles and power-ups
- **Two Difficulty Levels**:
  - Normal mode for casual players
  - Hard mode for experienced pilots with increased speed and challenge
- **Power-Up System**:
  - ⭐ Stars: Collect to increase your score
  - ❤️ Hearts: Gain extra lives to continue your journey
- **3D Graphics**: Built with OpenGL featuring textured 3D models
- **Ranking System**: Track and compare your high scores for each difficulty
- **First-Person Camera**: Immersive perspective following your spaceship
- **Smooth Controls**: Responsive keyboard input for precise maneuvering

## Prerequisites

- **C++ Compiler**: Visual Studio 2019 or later (Windows)
- **OpenGL**: OpenGL libraries
- **GLUT**: The OpenGL Utility Toolkit
- **NupenGL**: Required OpenGL packages (included via NuGet)

## Installation

1. Clone the repository:
```bash
git clone https://github.com/jojoca110/Escape-to-Infinity.git
cd Escape-to-Infinity
```

2. Open the solution file:
```
Programa_p3.sln
```

3. Restore NuGet packages (Visual Studio will do this automatically)

4. Build the solution (F7 or Build → Build Solution)

5. Run the game (F5 or Debug → Start Debugging)

## How to Play

### Controls

**Main Menu:**
- `SPACE` - Start game / Select difficulty

**Difficulty Selection:**
- `1` - Normal mode
- `2` - Hard mode

**In-Game:**
- `SPACE` - Start moving forward
- `A` - Move left (switch lanes)
- `D` - Move right (switch lanes)
- `W` - Move up
- `S` - Move down
- `P` - Pause

**Game Over Screen:**
- `W` - Scroll up through rankings
- `S` - Scroll down through rankings
- `ESC` - Exit game

**Special:**
- `F11` - Toggle fullscreen mode

### Gameplay

1. **Starting**: Launch the game and select your difficulty level
2. **Movement**: Your spaceship automatically moves forward. Use A/D to switch between three lanes and W/S to adjust height
3. **Obstacles**: Avoid cube obstacles that appear in various positions. Colliding with an obstacle costs you one life
4. **Collectibles**:
   - Collect stars (⭐) to increase your score
   - Collect hearts (❤️) to gain extra lives
5. **Game Over**: When you run out of lives, your score is recorded in the ranking system
6. **Scoring**: Stars collected contribute to your final score

## Game Mechanics

### Lane System
- The game features **3 parallel lanes**
- Each lane can spawn obstacles at two heights (upper and lower)
- Strategic lane switching is crucial for survival

### Procedural Generation
- Obstacles and power-ups spawn procedurally as you progress
- 80% chance for obstacles, 20% chance for star trails
- Obstacles can appear solo or in pairs (upper/lower positions)
- Heart power-ups can replace obstacles based on difficulty

### Difficulty Levels

**Normal Mode:**
- Base speed: 1.0 units/frame
- 3% chance for heart spawn
- Moderate obstacle density

**Hard Mode:**
- Increased speed: 1.5 units/frame
- 5% chance for heart spawn
- Higher obstacle density
- Faster reaction time required

## Project Structure

```
Escape-to-Infinity/
├── Game.cpp/h              # Main game controller
├── MainScene.cpp/h         # Primary gameplay scene
├── MainMenu.cpp/h          # Main menu interface
├── GameOver.cpp/h          # End game screen and rankings
├── Programa_p3.cpp         # Entry point and OpenGL setup
├── Camera.cpp/h            # Base camera class
├── FirstPersonCamera.cpp/h # First-person camera implementation
├── Scene.cpp/h             # Scene management
├── Interfaz.cpp/h          # UI overlay system
├── Model.cpp/h             # 3D model handling
├── ModelLoader.cpp/h       # OBJ/MTL file loader
├── Solid.cpp/h             # Base class for 3D objects
├── Cube.cpp/h              # Cube obstacle
├── Cuboid.cpp/h            # Lane dividers
├── Sphere.cpp/h            # Sphere primitives
├── Cylinder.cpp/h          # Cylinder primitives
├── Torus.cpp/h             # Torus primitives
├── Teapot.cpp/h            # Teapot primitive
├── Triangle.cpp/h          # Triangle primitives
├── Text.cpp/h              # Text rendering
├── Contorno.cpp/h          # Collision boundaries
├── Color.cpp/h             # Color handling
├── vector3d.cpp/h          # 3D vector math
├── Models/                 # 3D model files (.obj)
│   ├── Ships/             # Spaceship models
│   └── PowerUps/          # Power-up models (hearts, stars)
├── Materials/              # Material files (.mtl)
│   ├── Ships/             # Ship textures
│   └── PowerUps/          # Power-up textures
├── RankingNormal.txt      # Normal mode high scores
└── RankingDificil.txt     # Hard mode high scores
```

## Technical Details

### Graphics Engine
- **API**: OpenGL with GLUT
- **Rendering**: Double-buffered RGBA with depth testing
- **Lighting**: Basic OpenGL lighting with GL_LIGHT0
- **Models**: OBJ format with MTL material files
- **Resolution**: 800x600 (default), supports fullscreen

### Collision Detection
- Sphere-based collision detection using bounding volumes
- Real-time collision checking between player and all game objects
- Efficient collision response system

### Architecture
- Object-oriented design with inheritance hierarchy
- Scene management system for different game states
- Component-based game objects with position, orientation, and speed vectors
- Update-render loop with fixed time step

## Dependencies

The project uses the following libraries:
- **OpenGL**: Core graphics rendering
- **GLUT** (OpenGL Utility Toolkit): Window management and input handling
- **NupenGL** (via NuGet): OpenGL bindings for Visual Studio

## Building from Source

### Windows (Visual Studio)
1. Open `Programa_p3.sln` in Visual Studio
2. Ensure NuGet package restore is enabled
3. Build configuration: Debug or Release
4. Platform: x64
5. Build and run

## Rankings

Your high scores are automatically saved:
- **Normal Mode**: `RankingNormal.txt`
- **Hard Mode**: `RankingDificil.txt`

Each ranking entry includes your star count and is sorted in descending order.

## Contributing

Contributions are welcome! If you'd like to improve the game:
1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Push to your branch
5. Open a pull request

## License

This project is available for educational and personal use.

## Acknowledgments

- Built with C++ and OpenGL
- 3D models and materials included in the project
- Developed as a computer graphics programming project

---

**Enjoy your journey to infinity!** 🌌
