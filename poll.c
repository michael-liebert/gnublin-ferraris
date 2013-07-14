#include <stdio.h>

main()							
{
	FILE *f;
	//f=fopen("value", "r");
	while(1){
		f=fopen("/sys/class/gpio/gpio11/value", "r");
		int val = fgetc(f);
		printf("Val=%c\n", val);
		fclose(f);
		usleep(100000);
	}
}

