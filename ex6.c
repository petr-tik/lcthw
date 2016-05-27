#include <stdio.h>

int main(int argc, char *argv[])
{
   int distance = 100;
   float power = 2.345f;
   double super_power = 56789.4532;
   char initial = 'A';
   char first_name[] = "Petr";
   char last_name[] = "Tikilyaynen";

   printf("You are %d miles away.\n", distance);
   printf("You have %f levels of power.\n", power); // %f takes float numbers
   printf("You have %f awesome super powers.\n", super_power);
   printf("I have an initial %c\n", initial);
   printf("My first name is: %s \n", first_name);
   printf("My surname is: %s \n", last_name);
   printf("My whole name is: %s %c %s \n", first_name, initial, last_name);
   // printf("\n");
   // %c takes one char
   // %s takes an array of chars i.e. a string

   return 0;
}
