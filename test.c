#include <stdio.h>

int main(void)
{
    char *s = "Hi!";
    printf("%p\n", &s);
    printf("%p\n", s);
}
