#ifndef PROGRAMMINGASSIGNMENT2_LIBRARY_H
#define PROGRAMMINGASSIGNMENT2_LIBRARY_H

#include <stdio.h>
#include <string.h>

// Constants for formulas
#define POLLUTION_CONST 1112.2
#define TRAFFIC_CONST 1.7
#define CRIME_CONST 872.6
#define EXPENSE_CONST 1617.1
#define LIVABILITY_CONST 13.81

// Function prototypes
int input(FILE *fp, char *name, int *population, int *square_mileage, int *pollution, int *crime, int *expense, int *highways);
double population_density(int population, int square_mileage);
void compute(int pollution, int crime, int expense, int highways, double pop_density, double *pollution_rating, double *traffic_rating, double *crime_rating, double *expense_rating);
double livability(double pollution_rating, double traffic_rating, double crime_rating, double expense_rating);
void output(const char *name, double livability, double pop_density);
void update(int *city_count, double *total_livability, double *best_livability, char *best_city, const char *current_city, double current_livability);
void summary(int city_count, double total_livability, const char *best_city, double best_livability);

#endif
