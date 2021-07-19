
//Declare struct here
struct solve_state
{
    int board[10][9][9];
    int views[9][4];
    int N;
    int x;
    int y;
    int z;
};
void    print_entire_board(struct solve_state current);
//This function is to intialize a 3d array with the possible values for each spot on the board based on the edge view values

//Initialize the possible values array with all 0
/****************************************************************************************************************************************/

struct solve_state board_zero_init(struct solve_state current)
{
    int x;
    int y;
    int z;

    x = 0;
    y = 0;
    z = 0;
    while (x < current.N)
    {
        while (y < current.N)
        {
            while (z <= current.N)
            {
                current.board[z][y][x] = 0;
                z++;
            }
            z = 0;
            y++;
        }
        y = 0;
        x++;
    }
     return (current);
}

//Initialize the possible values array with 1- 9
/****************************************************************************************************************************************/

struct solve_state possible_values_init(struct solve_state current)
{
    int x;
    int y;
    int z;

    x = 0;
    y = 0;
    z = 0;
    while (x < current.N)
    {
        while (y < current.N)
        {
            while (z < current.N)
            {
                current.board[z][y][x] = z + 1;
                z++;
            }
            z = 0;
            y++;
        }
        y = 0;
        x++;
    }
     return (current);
}

//Adjust z values base on clues by removing non usable values
/****************************************************************************************************************************************/
    
struct solve_state coldown_edge_clue_init(struct solve_state current)
{
    int x;
    int y;
    int z;
    int possible_index;

    x = 0;
    y = 0;
    z = 0;
    possible_index = 0;

    //For colDown clues we only look at the top target views (current.viewss[0][x]) and we look down (d is y)
    while (x < current.N)
    {
        while (y < current.N)
        {   //If clue is greater than one and less than current.N
            if ((current.views[0][x] > 1) && (current.views[0][x] < current.N))
            {
                possible_index = (current.N - current.views[0][x] + 2 + y);
                z = possible_index;
                while (z < current.N)
                {
                    current.board[z][y][x] = 0;
                    z++;
                }
            }
            z = 0;
            y++;
        }
        y = 0;
        x++;
    }
    return (current);
}

struct solve_state colup_edge_clue_init(struct solve_state current)
{
    int x;
    int y;
    int z;
    int possible_index;

    x = 0;
    y = 0;
    z = 0;
    possible_index = 0;
     //For colUp clues we only look at the bottom target views (current.views[1][x] and we look up (d is current.N - 1 - y)
    while (x < current.N)
    {
        while (y < current.N)
        {   //If clue is greater than one and less than current.N
            if ((current.views[1][x] > 1) && (current.views[1][x] < current.N))
            {
                possible_index = (current.N - current.views[1][x] + 2 + (current.N - 1 - y));
                z = possible_index;
                while (z < current.N)
                {
                    current.board[z][y][x] = 0;
                    z++;
                }
            }
            z = 0;
            y++;
        }
        y = 0;
        x++;
    }
    return (current);
}

struct solve_state colleft_edge_clue_init(struct solve_state current)
{
    int x;
    int y;
    int z;
    int possible_index;

    x = 0;
    y = 0;
    z = 0;
    possible_index = 0;
    //For colLeft clues we only look at the left target views (current.views[2][y] and we look right (d is x)
    x = 0;
    y = 0;
    while (x < current.N)
    {
        while (y < current.N)
        {   //If clue is greater than one and less than current.N
            if ((current.views[2][y] > 1) && (current.views[2][y] < current.N))
            {
                possible_index = (current.N - current.views[2][y] + 2 + x);
                z = possible_index;
                while (z < current.N)
                {
                    current.board[z][y][x] = 0;
                    z++;
                }
            }
            z = 0;
            y++;
        }
        y = 0;
        x++;
    }
    return (current);
}

struct solve_state colright_edge_clue_init(struct solve_state current)
{
    int x;
    int y;
    int z;
    int possible_index;

    x = 0;
    y = 0;
    z = 0;
    possible_index = 0;
     //For colRight clues we only look at the right target views (current.views[3][y] and we look left (d is current.N - 1 - x)
    x = 0;
    y = 0;
    while (x < current.N)
    {
        while (y < current.N)
        {   //If clue is greater than one and less than current.N
            if ((current.views[3][y] > 1) && (current.views[3][y] < current.N))
            {
                possible_index = (current.N - current.views[3][y] + 2 + (current.N - 1 - x));
                z = possible_index;
                while (z < current.N)
                {
                    current.board[z][y][x] = 0;
                    z++;
                }
            }
            z = 0;
            y++;
        }
        y = 0;
        x++;
    }
    return (current);
}

//After running the entire board through current.board algorithms, go back and check for current.N and 1 clues to set them as guaranteed values
/****************************************************************************************************************************************/
  
struct solve_state coldown_clue1_set(struct solve_state current)
{
    int x;
    int y;
    int z;

    //For colDown clues we only look at the top target views (current.views[0][x] and we look down
    //We are only looking at edge clues so we only check the top row by setting y to 0 
    //We also only iterate x for one row
    x = 0;
    y = 0;
    while (x < current.N)
    {   //If clue is one
        if (current.views[0][x] == 1)
        {
            //Set z to 0 and erase all values up to current.N - 1 (leave only largest value)
            z = 0;
            while (z < current.N - 1)
            {
                current.board[z][y][x] = 0;
                z++;
            }
        }
        x++;
    }
    return (current);
}

struct solve_state colup_clue1_set(struct solve_state current)
{
    int x;
    int y;
    int z;

    //For colUp clues we only look at the bottom target views (current.views[1][x] and we look up
    //We are only looking at edge clues so we only check the bottom row by setting y to current.N - 1
    //We also only iterate x for one row
    x = 0;
    y = current.N - 1;
    while (x < current.N)
    {     //If clue is one
          if (current.views[1][x] == 1)
          {
              //Set z to 0 and erase all values up to current.N - 1 (leave only largest value)
              z = 0;
              while (z < current.N - 1)
             {
                 current.board[z][y][x] = 0;
                 z++;
             }
        }
        x++;
    }
    return (current);
}

struct solve_state colleft_clue1_set(struct solve_state current)
{
    int x;
    int y;
    int z;

    //For colLeft clues we only look at the left target views (current.views[2][y] and we look left
    //We are only looking at edge clues so we only check the right column by setting x to 0
    x = 0;
    y = 0;
    while (y < current.N)
    {   //If clue is one
        if (current.views[2][y] == 1)
        {
            //Set z to 0 and erase all values up to current.N - 1 (leave only largest value)
            z = 0;
            while (z < current.N - 1)
            {
                current.board[z][y][x] = 0;
                z++;
            }
        }
        y++;
    }
    return (current);
}

struct solve_state colright_clue1_set(struct solve_state current)
{
    int x;
    int y;
    int z;

    //For colRight clues we only look at the right target views (current.views[3][y] and we look left
    //We are only looking at edge clues so we only check the right column by setting x to current.N - 1
    x = current.N - 1;
    y = 0;
    while (y < current.N)
    {   //If clue is one
        if (current.views[3][y] == 1)
        {
            //Set z to 0 and erase all values up to current.N - 1 (leave only largest value)
            z = 0;
            while (z < current.N - 1)
            {
                current.board[z][y][x] = 0;
                z++;
            }
        }
        y++;
    }
    return (current);
}

//Finally if we encounter a clue of current.N we need to set the guaranteed values
/****************************************************************************************************************************************/

struct solve_state coldown_clueN_set(struct solve_state current)
{
    int x;
    int y;
    int z;

    //For colDown clues we only look at the top target views (current.views[0][x]) and we look down
    //We are only looking at edge clues so we only check the top column by setting y to 0
    x = 0;
    y = 0;
    while (x < current.N)
    {   //If clue is one
        if (current.views[0][x] == current.N)
        {   
            //Iterate through the column
            while (y < current.N)
            {
                //Set z to 0 and erase all values up to current.N
                z = 0;
                while (z < current.N)
                {
                    current.board[z][y][x] = 0;
                    z++;
                }
                //Then set the value of the row from 1 to current.N
                //z value is equal to y
                current.board[y][x][y] = y + 1;
                y++;
            }
            //Reset x for each loop
            y = 0;
        }
        x++;
    }
    return (current);
}

struct solve_state colup_clueN_set(struct solve_state current)
{
    int x;
    int y;
    int z;

    //For colUp clues we only look at the bottom target views (current.views[current.N - 1][x]) and we look up
    //We are only looking at edge clues so we only check the bottom column by setting y to current.N - 1
    x = 0;
    y = current.N - 1;
    while (x < current.N)
    {   //If clue is one
        if (current.views[y][x] == current.N)
        {   
            //Iterate through the column in reverse
            while (y >= 0)
            {
                //Set z to 0 and erase all values up to current.N
                z = 0;
                while (z < current.N)
                {
                    current.board[z][y][x] = 0;
                    z++;
                }
                //Then set the value of the row from 1 to current.N
                //z value is equal to y
                current.board[y][x][y] = current.N - y;
                y--;
            }
            //Reset x for each loop
            y = current.N - 1;
        }
        x++;
    }
    return (current);
}

struct solve_state colleft_clueN_set(struct solve_state current)
{
    int x;
    int y;
    int z;

    //For colLeft clues we only look at the left target views (current.views[y][0]) and we look right
    //We are only looking at edge clues so we only check the right column by setting x to 0
    x = 0;
    y = 0;
    while (y < current.N)
    {   //If clue is one
        if (current.views[2][y] == current.N)
        {   
            //Iterate through the row
            while (x < current.N)
            {
                //Set z to 0 and erase all values up to current.N
                z = 0;
                while (z < current.N - 1)
                {
                    current.board[z][y][x] = 0;
                    z++;
                }
                //Then set the value of the row from 1 to current.N
                //z value is equal to x
                current.board[x][x][y] = x + 1;
                x++;
            }
            //Reset x for each loop
            x = 0;
        }
        y++;
    }
    return (current);
}

struct solve_state colright_clueN_set(struct solve_state current)
{
    int x;
    int y;
    int z;

    //For colRight clues we only look at the right target views (current.views[y][current.N-1]) and we look left
    //We are only looking at edge clues so we only check the right column by setting x to current.N - 1
    x = current.N - 1;
    y = 0;
    while (y < current.N)
    {   //If clue is one
        if (current.views[y][x] == current.N)
        {   
            //Iterate through the row in reverse
            while (x >= 0)
            {
                //Set z to 0 and erase all values up to current.N
                z = 0;
                while (z < current.N)
                {
                    current.board[z][y][x] = 0;
                    z++;
                }
                //Then set the value of the row from 1 to current.N
                //z value is equal to x
                current.board[x][x][y] = current.N - x;
                x--;
            }
            //Reset x for each loop
            x = current.N - 1;
        }
        y++;
    }
    return (current);
}

//This is the wrapper function that calls all of the other functions and handles the main array
/****************************************************************************************************************************************/

struct solve_state board_initialization(struct solve_state current)
{
    //Init the board to all zeros
    current = board_zero_init(current);

    //Init the board values 1-9 for each cell except z position 10
    current = possible_values_init(current);

    //Run the possible values algorithm for each cell
    current = coldown_edge_clue_init(current);
    current = colup_edge_clue_init(current);
    current = colleft_edge_clue_init(current);
    current = colright_edge_clue_init(current);

   
    
    //Run the clue is 1 algorithm for each edge cell
    current = coldown_clue1_set(current);
    current = colup_clue1_set(current);
    current = colleft_clue1_set(current);
    current = colright_clue1_set(current);
   
    //Run the clue is N algorithm for each edge cell
    current = coldown_clueN_set(current);
    current = colup_clueN_set(current);
    current = colleft_clueN_set(current);
    current = colright_clueN_set(current);
    //print_entire_board(current);
    return (current);
}


// This expression will allow us to set the possible values for any location on our board
//current.N is board size, c is the view and d is the distance from the clue starting at 0
//This only works for clues where 1 < c < current.N
//AKA all middle clues
//N - c + 2 + d 


