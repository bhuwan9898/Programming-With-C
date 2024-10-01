// computation.c
#include "library.h"
#include <string.h>

//This function receives the city's population and square_mileage as parameters passed by copy
//It returns the double value of population density which is calculated as population / square_mileage (number of people per unit of square mileage)
//since we are not returning the value of population and square_mileage back to main we can pass them as copy
double population_density(int population, int square_mileage) {
    return (double) population / square_mileage;
}

// This function updates running totals used for summary calculations, specifically:
// - It increments the city_count (number of cities processed).
// - It adds the current city's livability to the total_livability.
// - It checks if the current city's livability is the highest so far (best_livability).
//   If so, it updates the best_livability and copies the current city's name into best_city.
// The parameters city_count, total_livability, best_livability, and best_city are passed by address
// since these values need to be updated and returned to main.
// current_city and current_livability are passed by copy as they are only used in comparisons
// and won't be modified within the function.
//strcpy function helps to remember(or store or update) the best city as the current city if the condition is met
void update(int *city_count, double *total_livability, double *best_livability, char *best_city, const char *current_city, double current_livability) {
    (*city_count)++;
    *total_livability += current_livability;
    if (current_livability > *best_livability) {
        *best_livability = current_livability;
        strcpy(best_city, current_city);
    }
}

//This function receives integer values of pollution, crime, expense and highways, and double values of population density, pollution rating,
//traffic rating, crime rating, expense rating.
//It will then return the calculated values of pollution_rating, traffic_rating, crime_rating and
//expense rating and since we want the change to be shown in main.c file, we pass them by address
void compute(int pollution, int crime, int expense, int highways, double pop_density, double *pollution_rating, double *traffic_rating, double *crime_rating, double *expense_rating) {
    *pollution_rating = pollution * pop_density / POLLUTION_CONST;
    *traffic_rating = (pop_density * TRAFFIC_CONST) / highways;
    *crime_rating = crime * pop_density / CRIME_CONST;
    *expense_rating = expense * pop_density / EXPENSE_CONST;
}

// This function receives pollution_rating, traffic_rating, crime_rating, and expense_rating as parameters passed by copy.
// It returns a double value representing the livability score, which is calculated by subtracting the average of the ratings
// from 100. The ratings are divided by a constant (LIVABILITY_CONST) to normalize the value.
// Since we are only using these rating values in the calculation and not returning them, they are passed by copy.
double livability(double pollution_rating, double traffic_rating, double crime_rating, double expense_rating) {
    return 100 - (pollution_rating + traffic_rating + crime_rating + expense_rating) / LIVABILITY_CONST;
}
