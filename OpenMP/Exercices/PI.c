#include <stdio.h>
#include <omp.h>

static long num_steps = 1000000000;
double step;

int main()
{
    int i;
    double x, pi, sum = 0.0;
    step = 1.0 / (double)num_steps;

    // Get the start time using omp_get_wtime
    double start_time = omp_get_wtime();

    // Parallelize the loop using OpenMP
    #pragma omp parallel for private(x) reduction(+:sum)
    for (i = 0; i < num_steps; i++)
    {
        // Calculate the x value for each rectangle
        x = (i + 0.5) * step;

        // Add the area of each rectangle to sum
        sum += 4.0 / (1.0 + x * x);
    }

    // Calculate the final value of pi
    pi = step * sum;

    // Get the end time using omp_get_wtime
    double end_time = omp_get_wtime();

    // Print the value of pi and the time taken
    printf("Value of pi = %lf\n", pi);
    printf("Time taken = %lf seconds\n", end_time - start_time);

    return 0;
