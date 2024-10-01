// main.c
#include "library.h"

int main() {
    FILE *fp = fopen("cities1.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Variable declarations
    char city_name[100], best_city[100] = "";
    int population, square_mileage, pollution, crime, expense, highways;
    double total_livability = 0, best_livability = 0;
    int city_count = 0;

    printf("%-20s %10s %15s\n", "Name", "Livability", "Pop Density");
    // Loop to process each city
    while (input(fp, city_name, &population, &square_mileage, &pollution, &crime, &expense, &highways) != EOF) {
        double pop_density = population_density(population, square_mileage);
        double pollution_rating, traffic_rating, crime_rating, expense_rating;
        compute(pollution, crime, expense, highways, pop_density, &pollution_rating, &traffic_rating, &crime_rating, &expense_rating);
        double current_livability = livability(pollution_rating, traffic_rating, crime_rating, expense_rating);

        // Output results for current city
        output(city_name, current_livability, pop_density);

        // Update totals and track best city
        update(&city_count, &total_livability, &best_livability, best_city, city_name, current_livability);
    }

    // Close file
    fclose(fp);

    // Output the summary
    summary(city_count, total_livability, best_city, best_livability);
    return 0;
}
