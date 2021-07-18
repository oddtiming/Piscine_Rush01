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

//This function is to find the whole number square root of the number of elements passed by argv[1]

//This section is for headers and function prototypes (in that order)

//The function(s) start here
int find_board_size(char *argv)
{
    int n;
    int board_size;

    n = 0;
    //First we must count the number of elements in the string
    while (argv[1][n] != '\0')
    {
        n++;
    }
    //Now we need to find the square root of i (the number of elements passed from command line)
    board_size = find_root(n);
}

int find_root(int n)
{
    int start;
    int end;
    int mid;
    int result;

    end = n;
    start = 0;
    while (start <= end)
    {
        //If mid is already a perfect square then return n
        mid = (start + end) / 2;
        if (mid * mid == n)
        {
            result = mid;
            return (result);
        }
        //Increment start if we have undershot the root
        if (mid * mid < n)
        {   
            //Reset the result
            result = start;
            //change start to try again
            start = mid + 1;
        }
        //Decrement start if we overshot
        else 
            end = mid -1;
    }
    //If a perfect root is not found, return 0 for ERROR
    return (0);
}

//This function is a wrapper to call the other functions and save space in main
int arg_check_board_size(int argc, char **argv)
{
     int N;

    //This will tell us if the string contains only valid characters, as well as check that the number of arguments is valid
    if (valid_character_and_argc_check(argc, argv[1]) != 1)
        return (0);

    //This will tell us what the board size is, and will return an error if the number of elements passed by argv[1] is invalid
    N = find_board_size(argv[1]);

    //This will tell is if the digits in the string are valid for the board size
    if (valid_digit_check(argv[1], N) != 1)
        return (0);
    return (N);
}