
#include "library.h"

//this function receives file name, and all the variables passed as addresses to the parameters
//variables include name, population, square_mileage, pollution, crime, expense, highways in order
//the function then reads the particular file name, assigns all the variables with the respective values in the input file
//and returns those values
//since we are declaring the variables in the main function and want the variable to be updated after reading the file
//we pass them as address which reflects the changes in the main.c file
//input function also controls the while loop in the main function which will stop once all the lines of the input file is read
int input(FILE *fp, char *name, int *population, int *square_mileage, int *pollution, int *crime, int *expense, int *highways) {
    return fscanf(fp, "%s %d %d %d %d %d %d", name, population, square_mileage, pollution, crime, expense, highways);
}

// This function outputs the city's information to the console in a formatted manner.
// It takes the city's name, livability score, and population density as parameters.
// The name is displayed left-aligned within a width of 17 characters,
// while the livability score and population density are displayed right-aligned
// with 2 decimal places, occupying widths of 10 and 15 characters respectively.
//this ensures that they are displayed with enough space in between just to make them readable
//we are not returning any changed value of name, yet we are passing it by value because since name is a string array composed of
//characters it is efficient to pass the address rather than copying the whole new array elements
void output(const char *name, double livability, double pop_density) {
    printf("%-17s %10.2f %15.2f\n", name, livability, pop_density);
}

/*
 * This function generates a summary report based on the number of cities processed,
 * the total livability score, the best city name, and its livability score.
 *
 * It receives the following parameters:
 * - city_count: An integer representing the total number of cities evaluated.
 * - total_livability: A double value representing the cumulative livability score
 *   of all cities, used to calculate the average livability.
 * - best_city: A string containing the name of the city with the highest livability.
 * - best_livability: A double value representing the livability score of the most
 *   livable city.
 *
 * The function calculates the average livability by dividing the total livability
 * by the number of cities and prints a summary that includes:
 * - The average livability rounded to two decimal places.
 * - The name of the most livable city along with its livability score, also rounded
 *   to two decimal places.
 */
void summary(int city_count, double total_livability, const char *best_city, double best_livability) {
    printf("\nOf %d cities, the average liability is %.2f\n", city_count,total_livability / city_count );
    printf("The most livable city is %s with a livability of %.2f\n", best_city, best_livability);
}
