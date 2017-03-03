/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);



int main(int argc, string argv[])
{
                                   
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }
     
    // open log открываем файл для чтения 
    FILE* file = fopen("log.txt", "w"); 
    if (file == NULL) //если файла нет - ошибка
    {
        return 3;
    }   
   

    // greet user with instructions 
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win. провермяем выиграли ли
        if (won()) 
        {
            printf("ftw!\n");
            break;
        }    
        

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log . Закрытие файла
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences. очитска экрана консоли (подвигает)
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).   Заполняет массив цифрами опр образом
 */
void init(void)
{
  // TODO. Один раз инициализирует.
   int S = d*d-1;
   for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
                board[i][j] = S ;
                S--;
        }
    }  
    if (d%2 == 0)
    {
     board[d-1][d-3] = 1;
     board[d-1][d-2] = 2;
    }
    
    
}

/**
 * Prints the board in its current state. 
 */
void draw(void)
{
    // TODO. Каждый раз перерисовывает пятнашки поле хода.
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            /** if (board[i][j]== 95)
            {
                printf("%2c\t",(char)board[i][j]);
            }
            else
            {/
            */
            printf("%2d\t",board[i][j]);
            
        }
        printf("\n");    
    }            
                
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    int i_point=100;
    int j_point=100;
    int i_zero=100;
    int j_zero=100;
    
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == tile)
            {
                i_point = i;
                j_point = j;
            }
             else if (board[i][j] == 0)
            {
                i_zero = i;
                j_zero = j;
            }
        }
    } 
    
    if (i_point == i_zero || j_point == j_zero)
    {
        if (abs(i_point - i_zero) == 1 || abs(j_point - j_zero )== 1)
        {
            board[i_point][j_point] = 0;
            board[i_zero][j_zero] = tile;
            return true;
        }
    }
    // TODO двигаем пятнашки
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int array [d*d];
    int k=0;
    for (int i=0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
             array [k] =  board[i][j];
             k++;
        }
    }
    for (int i=0; i <d*d-2; i++)
    {
        if (array[i+1]<array[i])
        {
            return false;
        }
    }    
    return true;
}