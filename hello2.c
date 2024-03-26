#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string first_name = get_string("What's your first name?\n");
    string last_name = get_string("What's your last name?\n");
    int age = get_int("What's your age?\n");
    string phonenumber = get_string("What's your phone number?\n ");
    printf("Hello, %s %s your age is %i and your phone number is %s!\n", first_name, last_name, age, phonenumber);
}
