# FDF - 42 Project

## Introduction

The FDF project at 42 is designed to introduce students to graphical programming by rendering **3D wireframe maps** using **the MiniLibX graphics library**. The objective is to read a file containing a 3D map representation and project it onto a 2D window, applying  $\color{LightSkyBlue}{\textbf{isometric}}$ or $\color{LimeGreen}{\textbf{parallel}}$ $\color{LimeGreen}{\textbf{projections}}$.

Concept

## Concept

FDF (Fil De Fer, meaning "wireframe" in French) involves reading a **heightmap file** (a ```.fdf file```) and displaying the corresponding $\color{DarkOrange}{\textbf{3D representation}}$ using **line segments**. The project requires knowledge of:

  - **2D and 3D coordinate systems**

  - **Mathematical transformations** (scaling, rotation, translation, projection)

  - **Bresenham's line-drawing algorithm**

  - **Handling user inputs for interactivity**

  - **Using MiniLibX for graphics rendering**

## Mandatory Requirements

  - **Read a ```.fdf``` file** containing a grid of integers representing heights.

  - **Render a wireframe model** using $\color{LimeGreen}{\textbf{line segments}}$.

  - **Implement at least one type of projection:**

    - $\color{LightSkyBlue}{\textbf{Isometric Projection}}$ (default, giving a 3D effect)

    - $\color{LimeGreen}{\textbf{Parallel Projection}}$ (optional for a different perspective)

  - Handle user interactions, such as:

    - **Zooming in/out**

    - **Rotating the model**

    - **Translating the view**

    - **Changing projection type**

  - **Use MiniLibX for graphical rendering**.

  - **No external graphics libraries are allowed**.

## Bonus Features

  - **Additional Projections** (e.g., orthographic, perspective)

  - **Color Gradients** based on height values

  - **Smooth Animations** for transformations

  - **Mouse Controls** for rotation and zoom

  - **Multiple File Support** to load different maps dynamically

## Implementation Details

### Parsing the ```.fdf``` File

The ```.fdf``` file contains a **grid of numbers** separated by spaces, where each number represents a height value:

```console
0  1  2  3
1  2  3  4
2  3  4  5
```

The program must:

  - Read the file and **store the height values** in a structured format (e.g., a 2D array).

  - Normalize the data for rendering.

  - Convert 3D points into 2D projections.

## Projection Transformations

$\color{LightSkyBlue}{\textbf{Isometric Projection}}$ (Default)

Uses a standard formula to project 3D points onto a 2D plane:

```console
x_iso = (x - y) * cos(θ)
y_iso = (x + y) * sin(θ) - z
```

$\color{LimeGreen}{\textbf{Parallel Projection}}$

  - Keeps the coordinate alignment without perspective distortion.

  - Ideal for technical or blueprint-like views.

### Line Drawing Algorithm

  - $\color{YellowGreen}{\textbf{Bresenham’s Algorithm}}$ is used to draw lines between projected points efficiently.

### User Interactions

  - $\color{SeaGreen}{\textbf{Keyboard controls}}$ for rotating, zooming, and moving the map.

  - $\color{SeaGreen}{\textbf{Mouse support}}$ (optional for smooth user experience).

### Compilation and Usage

To compile the project, use:

```console
make
```

To run the program:

```console
./fdf maps/42.fdf
```

## Project with bonus
![FDF Visualization](./FdFgif.gif)
###### Here is my FDF i did it with the bonus and extras

## Common Pitfalls

  - $\color{Crimson}{\textbf{Incorrect parsing}}$ ```.fdf``` files leading to segmentation faults.

  - $\color{Crimson}{\textbf{Not handling edge cases}}$, such as missing files or incorrect formats.

  - $\color{Crimson}{\textbf{Floating-point precision errors}}$ affecting line drawing and transformations.

  - $\color{Crimson}{\textbf{Inefficient rendering}}$, causing performance issues on large maps.

## Conclusion

The FDF project is an excellent introduction to $\color{RoyalBlue}{\textbf{graphics programming}}$, requiring a combination of $\color{RoyalBlue}{\textbf{mathematics, algorithmic thinking, and software engineering}}$. It teaches students how to handle graphical data structures, implement transformations, and optimize rendering for real-time visualization.
