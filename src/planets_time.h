#ifndef _PLANETS_TIME_H_
#define _PLANETS_TIME_H_

#include <time.h>

/**
 * @brief Gets the elapsed time since the start time.
 * @param start Start clock to calculate the elapsed time since.
 * @return Elapsed time in seconds.
 */
double elapsed_seconds(const clock_t start);

#endif