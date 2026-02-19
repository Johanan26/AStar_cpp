#ifndef PROJECT_H
#define PROJECT_H

#include <vector>

// Simple point type for grid coordinates
struct point {
    int row;
    int col;
};

// Manhattan distance and cost formula f(n) = g(n) + h(n)
// constexpr so it can be used in compile-time contexts as well.
constexpr int manhattanDistance(const point& p1, const point& p2) noexcept {
    return (p1.row > p2.row ? p1.row - p2.row : p2.row - p1.row)
         + (p1.col > p2.col ? p1.col - p2.col : p2.col - p1.col);
}

// f(n) = g(n) + h(n)
constexpr int f_cost(int g, int h) noexcept {
    return g + h;
}

class BinaryMatrix {
private:
    std::vector<std::vector<int>> matrix;
    int rows;
    int cols;
    int startRow;
    int startCol;
    int endRow;
    int endCol;

public:
    // Constructor
    BinaryMatrix(int r, int c);

    // Generate random binary matrix (0 = free, 1 = obstacle)
    void generateRandomMatrix();

    // Pick random start/end on free cells (0)
    void randomizeStartEnd();

    // Ensure reachability by carving a simple Manhattan (L-shaped) corridor
    void carveManhattanCorridorIfNeeded();

    // Build corridor, count free cells crossed, compute simple best-fit line and display
    void solveAndDisplay();

    // Display the matrix with start/end positions
    void displayMatrix() const;

    // Getters
    int getRows() const;
    int getCols() const;
    std::vector<std::vector<int>> getMatrix() const;
};

#endif