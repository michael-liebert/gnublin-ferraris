#include <stdio.h>
#include "gnublin.h"
#include <stdbool.h>

#define DEBUG
#define THRESHOLD 2700

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
    printf("one round completed\n");
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
