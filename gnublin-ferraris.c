#include <stdio.h>
#include "gnublin.h"
#include <stdbool.h>
#include <time.h>

#define DEBUG
#define THRESHOLD 2700

time_t previousRed;
bool init = true;
    
int getVoltage()
{
    gnublin_adc adc;
    int voltage;
    voltage = adc.getVoltage(1);
    if (adc.fail()) {
        printf("adc.getVoltage() returned with an error!\n");
        exit(1);
    }
    else {
        #ifdef DEBUG    
        printf("%i mV\n", voltage);
        #endif
        return voltage;
    }
}

void logRed()
{
	if (init) {
		#ifdef DEBUG
		printf("first sight of red bar, ignoring");
		#endif
		init = false;
		time(&previousRed); // initially set to current time
		return;
	}
	double seconds = difftime(time(NULL), previousRed);
	#ifdef DEBUG
    printf("one round completed, duration: %f seconds.\n", seconds);
    #endif
    // TODO: log to file
    
    time(&previousRed); // set to current time
}

int main()
{
    int v;
    bool red = false;

    while (1) {
        v = getVoltage();
        if (v > THRESHOLD) {
            if (red == false) { 
                red = true;
                logRed();
            }
        }
        else
            red = false; 

        usleep(200000);
    }
}
