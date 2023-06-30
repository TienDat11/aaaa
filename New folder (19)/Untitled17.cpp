#include <stdio.h>

int countWays(int money, int count2k, int count5k, int count10k) {
if (money < 0 || count5k < count10k || count2k != count5k * 2) {
return 0;
}

if (count2k == count5k * 2 && count10k >= 1) {
return 1;
}
// Th? mua m?t món quà 2k
int ways = countWays(money - 2, count2k + 1, count5k, count10k);
// Th? mua m?t món quà 5k
ways += countWays(money - 5, count2k, count5k + 1, count10k);
// Th? mua m?t món quà 10k
ways += countWays(money - 10, count2k, count5k, count10k + 1);
return ways;
}
int main() {
int money = 20; // S? ti?n ban t? ch?c giao cho
int ways = countWays(money, 0, 0, 0); // Ð?m s? cách mua quà
printf("So cach mua qua la: %d\n", ways);
return 0;
}
