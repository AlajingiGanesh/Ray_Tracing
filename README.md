# Ray Tracing in C++ | Learning & Custom Renderer

![C++](https://img.shields.io/badge/C%2B%2B-17-blue)
![CMake](https://img.shields.io/badge/CMake-4.4-success)
![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey)
![Status](https://img.shields.io/badge/Status-Learning-orange)

A modern C++ ray tracing project focused on learning computer graphics, physically based rendering, and building a custom ray tracing engine from scratch. This repository documents my progress, experiments, and feature implementations throughout the learning journey.

> **Note:** This project is based on the excellent **Ray Tracing in One Weekend** book series by **Peter Shirley**. The purpose of this repository is to learn, experiment, extend the renderer, and gradually build my own ray tracing engine.

<p align="center">
  <img src="images/my_first_render.png" alt="First Ray Traced Render" width="850"/>
</p>

---

# ✨ Features

- CPU-based Ray Tracer
- Physically Based Rendering (PBR Concepts)
- Diffuse (Lambertian) Materials
- Metal Materials
- Dielectric (Glass) Materials
- Recursive Ray Tracing
- Anti-Aliasing
- Depth of Field
- Multiple Scene Rendering
- CMake Build System
- Cross-Platform Support

---

# 📈 Current Status

- ✅ Successfully built on Windows
- ✅ Generated first ray-traced image
- ✅ CMake project configured
- 🔄 Learning rendering pipeline
- 🚀 Building my own renderer step by step

---

# 🛠 Tech Stack

- C++
- CMake
- MinGW GCC
- Visual Studio Code
- Git
- GitHub

---

# 📁 Project Structure

```text
Ray_Tracing/
│
├── books/
├── build/
├── images/
├── src/
│   ├── external/
│   ├── InOneWeekend/
│   ├── TheNextWeek/
│   └── TheRestOfYourLife/
│
├── CMakeLists.txt
└── README.md
```

---

# 🚀 Getting Started

## Clone Repository

```bash
git clone https://github.com/AlajingiGanesh/Ray_Tracing.git
cd Ray_Tracing
```

## Build

```bash
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
cmake --build .
```

## Run

```bash
.\inOneWeekend.exe > image.ppm
```

---

# 🖼️ Gallery

### First Ray Traced Render

<p align="center">
  <img src="images/my_first_render.png" width="750">
</p>

---

# 🎯 Learning Roadmap

- [x] Project setup
- [x] Configure CMake
- [x] Successful compilation
- [x] Generate first render
- [ ] Understand rendering pipeline
- [ ] Ray generation
- [ ] Camera implementation
- [ ] Ray-object intersection
- [ ] Materials
- [ ] Reflection & Refraction
- [ ] Texture Mapping
- [ ] Lighting
- [ ] Build custom scene
- [ ] Performance optimization
- [ ] Build my own ray tracing engine

---

# 📌 Planned Improvements

- Direct PNG export
- Custom camera controls
- New materials
- New geometric primitives
- Texture mapping
- HDR environment lighting
- Skybox rendering
- Motion blur
- Soft shadows
- Multithreaded rendering
- BVH optimization
- OBJ model loading
- Performance benchmarking
- Interactive rendering controls

---

# 📊 Repository Information

| Category | Details |
|----------|----------|
| Language | C++ |
| Build System | CMake |
| Compiler | MinGW GCC |
| IDE | Visual Studio Code |
| Platform | Windows |
| Rendering | CPU Ray Tracing |

---

# 🙏 Acknowledgements

Special thanks to **Peter Shirley** for the outstanding **Ray Tracing in One Weekend** book series, which serves as the foundation for learning ray tracing and computer graphics.

This repository is maintained as a personal learning project while progressively extending the renderer with new features and custom implementations.

---

## ⭐ If you found this project interesting, consider giving it a star!
