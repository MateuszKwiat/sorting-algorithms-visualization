<h1 align="center">Sorting Algorithms Visualization</h1>
A C++20 desktop application that visualizes various sorting algorithms in real time. Built using SFML, ImGui, and imgui-sfml, the project offers an interactive way to explore how different sorting techniques operate step-by-step.

<p align="center">
  <img src="assets/demo.gif" alt="Sorting visualization demo"/>
</p>

## ✨ Features
- Visualization of common sorting algorithms:
  - Bubble Sort
  - Insertion Sort
  - Selection Sort
  - Quick Sort
- Adjustable speed, array size, and algortihm selection
- Real-time bars and animations
- Simple and responsive ImGui interface
- Cross-platform (Windows, Linux, macOS)

## 🧱 Technologies
- Language: C++20
- Libraries:
  - [SFML](https://github.com/SFML/SFML)
  - [ImGui](https://github.com/ocornut/imgui)
  - [imgui-sfml](https://github.com/SFML/imgui-sfml)
- Build system: CMake

## 🛠️ Building
### Prerequisites
Make sure you have:
- CMake $\geq$ 4.0.2
- C++20 - compatible compiler
- Git
All libraries are fetched automatically via cmake `FetchContent`

### Clone & build
```bash
git clone https://github.com/MateuszKwiat/sorting-algorithms-visualization.git
cd sorting_algorithms_visualization/
cmake -B build -S .
cmake --build build
```

### Run
```bash
./build/bin/sorting_algorithms_visualization
```

## 🚀 Future Plans
- Add more algorithms

## 🧑‍💻 Author
Mateusz Kwiatkowski  
📚 Systems Engineering (Data Engineering) student at Wrocław University of Science and Technology  
🔗 GitHub Profile  
🔗 Linkedin Profile  

## 📜 License
This project is licnesed under the [MIT License](LICENSE.txt).