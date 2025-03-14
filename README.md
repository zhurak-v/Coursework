# Coursework in Computer Science - 1st Year 2025

## Project Overview
This project is a coursework assignment for the 1st-year Computer Science program. The main objective is to solve kinematics problems by implementing mathematical models describing the motion of a point in space. The project involves calculating distances, solving nonlinear equations, and visualizing motion trajectories using C++.

## Point trajectory

The motion of a point is determined by parametric equations:

$$
x = t^3 - 5t - 6
$$

$$
y = t - 2e^{-t}
$$

$$
z = t^2 + 2^t \cos(t)
$$


The goal of the project is to:
- Compute the distance between the initial position \( t = 0 \) and the position when the point reaches \( X = 5 \).
- Solve the nonlinear equation \( x(t) = 5 \) using a numerical method.
- Implement the solution in C++.
- Compare results obtained via different methods.

## Implementation Details
- **Programming Language:** C++
- **Numerical Method:** One of the root-finding algorithms (depending on the assigned task variant)
- **Libraries Used:** Standard C++ libraries for numerical computation and file handling
- **Visualization:** Optional, using external libraries if needed

## How to Run the Project
1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/coursework.git
   cd coursework
   git submodule update --init --recursive
   ```
2. Build the project using CMake:
    ```
   run ./scripts/build.sh
   ```
   or
   ```sh
   mkdir build
   cd build
   cmake ..
   cmake --build .
   ```
3. Run the executable:
   ```sh
   ./coursework
   ```

## Expected Output
- The program should output the computed distance.
- It should display the number of iterations taken to find the root.
- The results should be saved to a file for comparison.

## Future Enhancements
- Improve numerical stability and precision.
- Add visualization of the trajectory using OpenGL.
- Implement additional numerical methods for solving equations.

## Author
**Volodymyr Zhurakivskyi**

For any questions or suggestions, feel free to contribute or reach out!

