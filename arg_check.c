//Run a check to ensure that the command line inputs are valid
//Need to ensure that number of strings passed with argc is valid for board size
//Need to make sure that the values passed in argv strings are valid for board size
//Return 1 if arg check passes, return 0 if arg check is ERROR


//This function will check if the string contains only valid characters
//Return of 1 is valid, return of 0 is error
int valid_character_and_argc_check(int argc, char *argv)
{
    int i;

    i = 0;
    if (argc != 2)
        return (0);
    while (argv[i] != '\0')
    {
        if ((argv[i] > '9') || (argv[i] < '0'))
            return (0);
        i++;
    }
    return (1);
}

//This function will check if the digits in the string are valid for the current board size
int valid_digit_check(char *argv, int N)
{
    int i;

    i = 0;
    while (argv[i] != '\0')
    {
        if ((argv[i] > N) || (argv[i] < 1))
            return (0);
        i++;
    }
    return (1);
}