//how to ues pointer in C: data type *pointer_name = &variable_name;
// *pointer_name is the value of the variable_name

#include <stdio.h>

int main() {
int a =6;
int *ptr= &a;
printf("%d\n", *ptr);
printf("%p\n", ptr);



}