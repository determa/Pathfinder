#include "../inc/libmx.h"

void mx_printint(int n) {
	if(n != 0) {
		char v[20];
		int i = 0;
		long val = n;
		if(val < 0) {
			mx_printchar('-');
			val = -val;
		}
	
		while(val != 0) {
			 v[i++] = val % 10 + '0';
			 val /= 10;
		}
	
		for(int j = i - 1; j >= 0; j--)
			mx_printchar(v[j]);
	} 
	else 
		mx_printchar('0');
}

