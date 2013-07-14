#include <stdio.h>
#include "gnublin.h"
main()							
{
	gnublin_adc adc;
	int voltage;
	while (1) {
    	voltage = adc.getVoltage(1);
    	if (adc.fail()) {
  	    	println("Es ist ein Fehler aufgetreten!");
		}
        else {
            println("%i mV", voltage);
        }	
	    usleep(200000);
	}
}

