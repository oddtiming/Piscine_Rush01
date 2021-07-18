//This function is to find the whole number square root of the number of elements passed by argv[1]

//This section is for headers and function prototypes (in that order)

//The function(s) start here
int find_board_size(char *argv)
{
    int n;
    int board_size;

    i = 0;
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