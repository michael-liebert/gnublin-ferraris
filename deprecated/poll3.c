#include <stdio.h>
#include "gnublin.h"
main()							
{
	gnublin_adc adc;
	int voltage;
	while (1) {
    	voltage = adc.getVoltage(1);
    	if (adc.fail()) {
  	    	printf("getVoltage() failed!\n");
		}
        else {
            printf("%i mV\n", voltage);
        }	
	    usleep(200000);
	}
}

