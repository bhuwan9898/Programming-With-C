# City Livability Project

## Overview

The City Livability Project is a C program designed to evaluate and compare the livability of different cities based on various metrics such as population density, pollution, traffic, crime, and expenses. The program reads city data from a file, calculates livability scores, and provides a summary report.

## Features

- **Data Input**: Read city information from a file, including:
    - City name
    - Population
    - Square mileage
    - Pollution rating
    - Crime rating
    - Expense rating
    - Traffic rating

- **Calculations**:
    - Population density calculation.
    - Livability score calculation based on multiple factors.

- **Output**:
    - Display a formatted table with city names, livability scores, and population densities.
    - Provide a summary report with the average livability and the most livable city.
## Requirements

- C compiler (e.g., GCC)
- CMake (version 3.29 or higher)

## Build Instructions

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/CityLivability.git
   cd CityLivability
   mkdir build
   cd build
   cmake ..
   make
## Contributing
Contributions are welcome! If you have suggestions or improvements, please fork the repository and submit a pull request.
## License
This project is licensed under the MIT License - see the LICENSE file for details.

