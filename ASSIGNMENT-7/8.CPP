#include <iostream>
#include <vector>

bool checkStraightLine(const std::vector<std::vector<int>>& coordinates) {
    int n = coordinates.size();

    // Calculate the slope between the first two points
    int x0 = coordinates[0][0];
    int y0 = coordinates[0][1];
    int x1 = coordinates[1][0];
    int y1 = coordinates[1][1];
    int deltaX = x1 - x0;
    int deltaY = y1 - y0;

    // Check if all other points lie on the same line
    for (int i = 2; i < n; ++i) {
        int x = coordinates[i][0];
        int y = coordinates[i][1];

        if (deltaX * (y - y1) != deltaY * (x - x1)) {
            return false;
        }
    }

    return true;
}

int main() {
    std::vector<std::vector<int>> coordinates = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    
    bool isStraightLine = checkStraightLine(coordinates);

    if (isStraightLine) {
        std::cout << "The points make a straight line." << std::endl;
    } else {
        std::cout << "The points do not make a straight line." << std::endl;
    }

    return 0;
}
