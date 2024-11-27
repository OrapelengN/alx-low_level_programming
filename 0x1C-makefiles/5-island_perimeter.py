#!/usr/bin/python3
"""
Function that returns the perimeter of the island described in grid.

grid is a list of list of integers:
    - 0 represents a water zone
    - 1 represents a land zone

The function calculates the perimeter of the land zones (1) in the grid.
"""

def island_perimeter(grid):
    """
    Returns the perimeter of the island in the grid.

    Args:
        grid (list of list of int): A 2D grid representing the island, where 1
                                    is land and 0 is water.

    Returns:
        int: The perimeter of the island.
    """
    perimeter = 0

    # Iterate over every cell in the grid
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            # Check if the cell is land
            if grid[i][j] == 1:
                # Check all four directions (up, down, left, right)

                # Top
                if i == 0 or grid[i - 1][j] == 0:
                    perimeter += 1
                # Bottom
                if i == len(grid) - 1 or grid[i + 1][j] == 0:
                    perimeter += 1
                # Left
                if j == 0 or grid[i][j - 1] == 0:
                    perimeter += 1
                # Right
                if j == len(grid[i]) - 1 or grid[i][j + 1] == 0:
                    perimeter += 1

    return perimeter
