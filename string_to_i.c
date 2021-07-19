#include <stdio.h>
#include <stdlib.h>
char    *string_to_int(char *c);
int     str_len(char *c);

int main(void) 
{
    char *str = "1 7 6 5 4 7 8 9";

    printf("Initial string: %s\n", str);
    printf("Modified string: %s\n", string_to_int(str));
    return 0;
}

int    *string_to_int(char *str) {
    int i;
    int j;
    char    *intstr;

    i = str_len(str);
    intstr = (char *)malloc(i);
    i = 0;
    j = 0;
    while (i < str_len(str)) {
        if (str[i] >= '0' && str[i] <= '9') {
            intstr[j] = str[i] - '0';
            j++;
        }
        i++;
    }
    return (intstr);
}

int str_len(char *str) {
    int i;

    i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}