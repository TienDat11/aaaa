#include <iostream>
#include <windows.h>
int main(){
	float x,y,z;
	for(y=1.5;y>-1.5;y-=0.1){
		for(x = -1.5; x < 1.5; x += 0.05){
			z= x*x + y*y -1.0065;
			putchar(z*z*z-x*x*y*y*y-0.0005<=0.0 ? '*':' ');
		}
		Sleep(200);
		putchar('\n');
	}
	printf("                   Yeu Dat duoc khong??? Van qua troi pai noi dc k Dat muc");
	return 0;
}
