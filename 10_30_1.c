#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define sleep_time 50000

void main() {
	int a, b;
	printf("Enter the two integers: ");
	scanf("%d %d", &a, &b);
	int d = 0;
	if (a != 0 && b != 0)
		d = euclid(a, b);

	int x = 0, y = 0;
	if (a > 0 && b > 0) {//a > 0, b > 0
		for (y = 0;; y++) {
			for (x = 0; d <= ((a*x) + (b*y)); x--) {
				if (d == (b*y) + (a*x))
					break;
			}
			if (d == (b*y) + (a*x))
				break;
		}
	}
	else if (a == 0 || b == 0) {//a = 0, b = 0
		printf("%d %d %d\n", 0, 0, 0);
		printf("Programe Exiting\n");
		Sleep(sleep_time);
		exit(0);
	}
	else if (a > 0) {
		if (a >= b*(-1)) {//a > 0, b < 0, |a| >= |b|
			for (y = 0;; y++) {
				for (x = 0; d >= ((a*x) + (b*y)); x++) {
					if (d == (b*y) + (a*x))
						break;
				}
				if (d == (b*y) + (a*x))
					break;
			}
		}
		else {//a > 0, b < 0, |a| < |b|
			for (y = 0;; y--) {
				for (x = 0; d <= ((a*x) + (b*y)); x--) {
					if (d == (b*y) + (a*x))
						break;
				}
				if (d == (b*y) + (a*x))
					break;
			}
		}
	}
	else if (b > 0) {//a < 0, b > 0
		for (y = 0;; y--) {
			for (x = 0; d >= ((a*x) + (b*y)); x--) {
				if (d == (b*y) + (a*x))
					break;
			}
			if (d == (b*y) + (a*x))
				break;
		}
	}
	else {//a < 0, b < 0
		for (y = 0;; y++) {
			for (x = 0; d >= ((a*x) + (b*y)); x--) {
				if (d == (b*y) + (a*x))
					break;
			}
			if (d == (b*y) + (a*x))
				break;
		}
	}
	printf("%d %d %d\n", x, y, d);

	printf("Programe Exiting\n");
	Sleep(sleep_time);
}

int euclid(int a, int b) {
	//make positive
	if (a < 0) {
		a *= -1;
		//printf("a is negative\n");
	}
	if (b < 0) {
		b *= -1;
		//printf("b is negative\n");
	}
	//swap
	if (b > a) {
		int temp = a;
		a = b;
		b = temp;
		//printf("swaped\n");
	}
	//do Euclid's method
	//printf("%d %d\n", a, b);
	if (b == 0) {
		return a;
	}
	else {
		return euclid(b, a%b);
	}
}