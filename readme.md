<h1 align="center">Sorting Algorithms Visualization</h1>
A C++20 desktop application that visualizes various sorting algorithms in real time. Built using SFML, ImGui, and imgui-sfml, the project offers an interactive way to explore how different sorting techniques operate step-by-step.

<p align="center">
  <img src="assets/demo.gif" alt="Sorting visualization demo"/>
</p>

## Features
- Visualization of common sorting algorithms:
  - Bubble Sort
  - Insertion Sort
  - Selection Sort
  - Quick Sort
- Adjustable speed, array size, and algortihm selection
- Real-time bars and animations
- Simple and responsive ImGui interface
- Cross-platform (Windows, Linux, macOS)

##  Technologies
- Language: C++20
- Libraries:
  - [SFML](https://github.com/SFML/SFML)
  - [ImGui](https://github.com/ocornut/imgui)
  - [imgui-sfml](https://github.com/SFML/imgui-sfml)
- Build system: CMake

##  Building
### Prerequisites
Make sure you have:
- CMake $\geq$ 4.0.2
- C++20 - compatible compiler
- Git  
All libraries are fetched automatically via cmake `FetchContent`

### Linux & macOS
#### Clone & build
```bash
git clone https://github.com/MateuszKwiat/sorting-algorithms-visualization.git
cd sorting-algorithms-visualization/
cmake -B build -S .
cmake --build build
```

#### Run
```bash
./build/bin/sorting_algorithms_visualization
```

 **Linux Users:** Before building, make sure the following packages are installed:
 
 ```bash
 sudo apt update
 sudo apt install build-essential cmake libx11-dev libxrandr-dev libxcursor-dev libxi-dev libudev-dev libgl1-mesa-dev libfreetype6-dev libopenal-dev libvorbis-dev libflac-dev
 ```

### Windows (Visual Studio)
#### Clone & build
```powershell
git clone https://github.com/MateuszKwiat/sorting-algorithms-visualization.git
cd sorting-algorithms-visualization
cmake -B build -S . -G "Visual Studio 17 2022" -A x64
cmake --build build --config Release
```

#### Run
```powershell
build\bin\Release\sorting_algorithms_visualization.exe
```

## 📜 License
This project is licensed under the [MIT License](LICENSE.txt).
