#include "planets_time.h"

double elapsed_seconds(const clock_t start)
{
    const clock_t stop = clock();

    double elapsed = (stop - start) / (double)CLOCKS_PER_SEC;

    return elapsed;
}