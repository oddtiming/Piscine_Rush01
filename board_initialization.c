

//This function is to intialize a 3d array with the possible values for each spot on the board based on the edge view values


void    board_initialization(int **target_view, int N)
{
    int possible_values[9][9][9];
    int x;
    int y;
    int z;
    int possible_index;
    int value;

    x = 0;
    y = 0;
    z = 0;
    value = 1;
    possible_index = 0;



   //Initialize the possible values array with 1- 9
    while (x < N)
    {
        while (y < N)
        {
            while (z < N)
            {
        
                possible_values[z][y][x] = z + 1;
                z++;
            }
            z = 0;
            y++;
        }
        y = 0;
        x++;
    }


    //Adjust z values base on clues by removing non usable values
    
void coldown_edge_clue_init(int **target_view, int ***possible_values, int N);
    //For colDown clues we only look at the top target views (target_views[0][x]) and we look down (d is y)
    x = 0;
    y = 0;
    while (x < N)
    {
        while (y < N)
        {   //If clue is greater than one and less than N
            if ((target_view[0][x] > 1) && (target_view[0][x] < N))
            {
                possible_index = (N - target_view[0][x] + 2 + y);
                z = possible_index;
                while (z < N)
                {
                    possible_values[z][y][x] = 0;
                    z++;
                }
            }
            z = 0;
            y++;
        }
        y = 0;
        x++;
    }

void colup_edge_clue_init(int **target_view, int ***possible_values, int N);
     //For colUp clues we only look at the bottom target views (target_view[n-1][x] and we look up (d is N - 1 - y)
    x = 0;
    y = 0;
    while (x < N)
    {
        while (y < N)
        {   //If clue is greater than one and less than N
            if ((target_view[N - 1][x] > 1) && (target_view[N - 1][x] < N))
            {
                possible_index = (N - target_view[y][0] + 2 + (N - 1 - y));
                z = possible_index;
                while (z < N)
                {
                    possible_values[z][y][x] = 0;
                    z++;
                }
            }
            z = 0;
            y++;
        }
        y = 0;
        x++;
    }

void colleft_edge_clue_init(int **target_view, int ***possible_values, int N);
    //For colLeft clues we only look at the left target views (target_view[y][0] and we look right (d is x)
    x = 0;
    y = 0;
    while (x < N)
    {
        while (y < N)
        {   //If clue is greater than one and less than N
            if ((target_view[y][0] > 1) && (target_view[y][0] < N))
            {
                possible_index = (N - target_view[y][0] + 2 + x);
                z = possible_index;
                while (z < N)
                {
                    possible_values[z][y][x] = 0;
                    z++;
                }
            }
            z = 0;
            y++;
        }
        y = 0;
        x++;
    }

void colright_edge_clue_init(int **target_view, int ***possible_values, int N);
     //For colRight clues we only look at the right target views (target_view[y][N-1] and we look left (d is N - 1 - x)
    x = 0;
    y = 0;
    while (x < N)
    {
        while (y < N)
        {   //If clue is greater than one and less than N
            if ((target_view[y][N - 1] > 1) && (target_view[y][N - 1] < N))
            {
                possible_index = (N - target_view[y][N - 1] + 2 + (N - 1 - x));
                z = possible_index;
                while (z < N)
                {
                    possible_values[z][y][x] = 0;
                    z++;
                }
            }
            z = 0;
            y++;
        }
        y = 0;
        x++;
    }

    //After running the entire board through possible_values algorithms, go back and check for N and 1 clues to set them as guaranteed values
  
void coldown_clue1_set(int **target_view, int ***possible_values, int N); 
    //For colDown clues we only look at the top target views (target_view[0][x] and we look down
    //We are only looking at edge clues so we only check the top row by setting y to 0 
    //We also only iterate x for one row
    x = 0;
    y = 0;
    while (x < N)
    {   //If clue is one
        if ((target_view[y][x] == 1))
        {
            //Set z to 0 and erase all values up to N - 1 (leave only largest value)
            z = 0;
            while (z < N - 1)
            {
                possible_values[z][y][x] = 0;
                z++;
            }
        }
        z = 0;
        x++;
    }



void colup_clue1_set(int **target_view, int ***possible_values, int N);
    //For colUp clues we only look at the bottom target views (target_view[N - 1][x] and we look up
    //We are only looking at edge clues so we only check the bottom row by setting y to N - 1
    //We also only iterate x for one row
    x = 0;
    y = N - 1;
    while (x < N)
    {     //If clue is one
          if ((target_view[y][x] == 1))
          {
              //Set z to 0 and erase all values up to N - 1 (leave only largest value)
              z = 0;
              while (z < N - 1)
             {
                 possible_values[z][y][x] = 0;
                 z++;
             }
        }
        z = 0;
        x++;
    }


void colleft_clue1_set(int **target_view, int ***possible_values, int N);
    //For colLeft clues we only look at the left target views (target_view[y][0] and we look left
    //We are only looking at edge clues so we only check the right column by setting x to 0
    x = 0;
    y = 0;
    while (y < N)
    {   //If clue is one
        if ((target_view[y][x] == 1))
        {
            //Set z to 0 and erase all values up to N - 1 (leave only largest value)
            z = 0;
            while (z < N - 1)
            {
                possible_values[z][y][x] = 0;
                z++;
            }
        }
        z = 0;
        y++;
    }
   
void colright_clue1_set(int **target_view, int ***possible_values, int N);
    //For colRight clues we only look at the right target views (target_view[y][N-1] and we look left
    //We are only looking at edge clues so we only check the right column by setting x to N - 1
    x = N - 1;
    y = 0
    while (y < N)
    {   //If clue is one
        if ((target_view[y][x] == 1))
        {
            //Set z to 0 and erase all values up to N - 1 (leave only largest value)
            z = 0;
            while (z < N - 1)
            {
                possible_values[z][y][x] = 0;
                z++;
            }
        }
        z = 0;
        y++;
    }


    //Finally if we encounter a clue of N we need to set the guaranteed values

void coldown_clueN_set(int **target_view, int ***possible_values, int N);
    //For colDown clues we only look at the top target views (target_view[0][x]) and we look down
    //We are only looking at edge clues so we only check the top column by setting y to 0
    x = 0;
    y = 0;
    while (x < N)
    {   //If clue is one
        if ((target_view[y][x] == N))
        {   
            //Iterate through the column
            while (y < N)
            {
                //Set z to 0 and erase all values up to N
                z = 0;
                while (z < N)
                {
                    possible_values[z][y][x] = 0;
                    z++;
                }
                //Then set the value of the row from 1 to N
                //z value is equal to y
                possible_values[y][x][y] = y + 1;
                y++;
            }
            //Reset x for each loop
            y = 0;
        }
        x++;
    }

void colup_clueN_set(int **target_view, int ***possible_values, int N);
    //For colUp clues we only look at the bottom target views (target_view[N - 1][x]) and we look up
    //We are only looking at edge clues so we only check the bottom column by setting y to N - 1
    x = 0;
    y = N - 1;
    while (x < N)
    {   //If clue is one
        if ((target_view[y][x] == N))
        {   
            //Iterate through the column in reverse
            while (y >= 0)
            {
                //Set z to 0 and erase all values up to N
                z = 0;
                while (z < N)
                {
                    possible_values[z][y][x] = 0;
                    z++;
                }
                //Then set the value of the row from 1 to N
                //z value is equal to y
                possible_values[y][x][y] = N - y;
                y--;
            }
            //Reset x for each loop
            y = N - 1;
        }
        x++;
    }

void colleft_clueN_set(int **target_view, int ***possible_values, int N);
    //For colLeft clues we only look at the left target views (target_view[y][0]) and we look right
    //We are only looking at edge clues so we only check the right column by setting x to 0
    x = 0;
    y = 0;
    while (y < N)
    {   //If clue is one
        if ((target_view[y][x] == N))
        {   
            //Iterate through the row
            while (x < N)
            {
                //Set z to 0 and erase all values up to N
                z = 0;
                while (z < N)
                {
                    possible_values[z][y][x] = 0;
                    z++;
                }
                //Then set the value of the row from 1 to N
                //z value is equal to x
                possible_values[x][x][y] = x + 1;
                x++;
            }
            //Reset x for each loop
            x = 0;
        }
        y++;
    }

void colright_clueN_set(int **target_view, int ***possible_values, int N);
    //For colRight clues we only look at the right target views (target_view[y][N-1]) and we look left
    //We are only looking at edge clues so we only check the right column by setting x to N - 1
    x = N - 1;
    y = 0;
    while (y < N)
    {   //If clue is one
        if ((target_view[y][x] == N))
        {   
            //Iterate through the row in reverse
            while (x >= 0)
            {
                //Set z to 0 and erase all values up to N
                z = 0;
                while (z < N)
                {
                    possible_values[z][y][x] = 0;
                    z++;
                }
                //Then set the value of the row from 1 to N
                //z value is equal to x
                possible_values[x][x][y] = N - x;
                x--;
            }
            //Reset x for each loop
            x = N - 1;
        }
        y++;
    }

//SPLIT OUT ALL THESE FUNCTIONS, DOES PUSH WORK!?


// This expression will allow us to set the possible values for any location on our board
//N is board size, c is the view and d is the distance from the clue starting at 0
//This only works for clues where 1 < c < N
//AKA all middle clues
N - c + 2 + d 


