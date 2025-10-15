


                                      // DESIGN FRAMEWORK:-(blueprint)
// 1 . DESIGN CONSOLE
// 2. TWO BOARDS : MAIN BOARD -> CONTAINING ALL NUMBERS AND MINES 
//                 VIEW BOARD -> CONTAINING WHAT WE WANNA PRESENT TO USER.

// HOW TO PLACE MINES => USER RAND() AND SRAND(TIME(0)) FUNCTIONS TO PLACE THE MINES RANDOMLY 
// RAND()=> EVERY TIME PLACES A NEW MINE 
// SRAND(TIME(0))=> JUST LIKE SHAKES A BAG EVERY SEC SO THAT RAND() FN ALWAYS PLACES A MINE AT RANDOM POSITION.

// 3. DESIGNING INSTRUCTIONS : TWO CHARACTERS- (r / f) row col
// 4. IF CHARCTER= r    =>  FOUND MINE "BOOM" AND  MAIN IMP => SHOW ALL MINES TO PLAYER(USER).
// 5. ELSE  REVEALING OTHER CELLS IF THAT CELL CHOSEN BY USER (POPPED BY USER) IS 0 
// 6. OR REVEALING ONLY THAT CELL IF THAT CELL CONTAINING NUMBERS FROM 1-8
        // CAN BE DONE USING RECUR. FN OR ITER. 🩻🩻🩻 (MOST LOGICAL PART)
// 7. IF CHARACTER= f => JUST FLAG THAT CELL (IF USER WANTS TO MARK A CELL IF IT'S SUSPICIOUS )
// 8. CHECKING  IF ALL  SAFE CELLS ARE POPPED  THEN WON and show board . 


                                     // 🧠 Concepts Used (overview):-
// - 2D Vectors for board representation  
// - Recursion for revealing connected empty cells  
// - Random mine placement  
// - Condition-based cell expansion  
// - Game loop and user input handling  




//header files => 
// 1. cstdlib-->
//  This header gives access to general-purpose functions like:
// rand() → generate a random number

// srand() → set a seed for random number generation

// abs(), atoi(), exit(), and more

// 2.ctime --> 
// This header handles date and time functions — and we use it mainly for:

// time(0) (or time(NULL)) → gives the current system time in seconds

// We use this as a changing seed for randomness — so the output is different each time you run your program.


#include <iostream>
#include<vector>
#include <cstdlib> // for rand() & srand ()
#include <ctime>// for time(0)
using namespace std;


    // generating custom positions for revealing a correct cell:- 
    void customPositions(vector<vector<char>> &main, vector<vector<char>> &view, int i,int j, int n,
                    vector<vector<bool>> &visited){
            if (i<0 || j<0 || i>=n || j>=n || main[i][j]=='9' || visited[i][j]==true) {
                return ;
            }

            visited[i][j]=true;
            view[i][j]=main[i][j];
            if (main[i][j]!='0'){
                return;
            }

            customPositions(main,view,i+1,j,n,visited);
            customPositions(main,view,i-1,j,n,visited);
            customPositions(main,view,i,j+1,n,visited);
            customPositions(main,view,i,j-1,n,visited);
                    }

    void showMines(vector<vector<char>> &mainboard, vector<vector<char>> &viewboard){
        int n=mainboard.size();
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (mainboard[i][j]=='9'){
                    cout<<"* ";
                }else{
                    cout<<viewboard[i][j]<<" ";
                }
            }cout<<endl;
        }
    }

    // if ch=r/f
    void revealOrFlag(vector<vector<char>> &mainboard , vector<vector<char>> &viewboard, int ROWS , int COLS,char ch){
    int n=mainboard.size();
    if (ROWS>n || COLS >n || ROWS<=0 || COLS<=0){
        return;
    }

    ROWS--;
    COLS--;
    if (ch=='r'){
        // int n=mainboard.size();
        viewboard[ROWS][COLS]=mainboard[ROWS][COLS];
        vector<vector<bool>> visited(n,vector<bool> (n,false));
        customPositions(mainboard,viewboard, ROWS, COLS,n, visited);
        //print
        for (int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<viewboard[i][j]<<" ";
            }cout<<endl;
        }
    }else{
        //f
        viewboard[ROWS][COLS]='F';
        for (int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<viewboard[i][j]<<" ";
            }cout<<endl;
        }
    }

}
int main(){
        
        cout<<" Welcome to the MINE SWEEPER GAME (~YMS)!!!"<<endl;
        cout<<" Rules:-"<<endl;
        cout<<"  There are 3 commands -> "<<endl;
        cout<<" 1.' r row col ' -> for revealing that row and column."<<endl;
        cout<<" If there will a number between 1 to 8 other couple of cells will be shown ,if mine -> <BOOM!!!> Game Over ."<<endl;
        cout<<" 2. 'f row col ' -> for putting a flag on any cell if you feel it is suspicious it has a mine. "<<endl;
        cout<<" 3. ' q ' -> for quitting the game (WHICH YOU SHOULDN'T!!!)"<<endl;
        cout<<endl;
        

        int n;
        int mines;
        cout<< "Let's Start!!!"<<endl;cout<<endl;
        cout<<"Enter the number of rows/cols of  which you wanna a grid (n*n) : ";
        cin>>n;
        cout<<endl;
        cout<<"Enter the the number of mines you need in your game : ";
        cin>>mines;
        cout<<endl;
        vector<vector<char>> ms_board(n,vector<char>(n,'0'));
        vector<vector<char>> view(n,vector<char>(n,'.'));


        for (int i=0;i<n;i++){
            for (int j=0;j< n ;j++){
                cout<< view[i][j]<<" ";
            }cout<<endl;
        }

        // placing mines:
        srand(time(0));
        int placed=0;
        while(placed<mines){
            int random_rows=rand()%n;
            int random_cols=rand()%n;
            if (ms_board[random_rows][random_cols]!='9'){
                ms_board[random_rows][random_cols]='9';
                placed++;
            }
        }

        //putting other numbers.
        
        for (int i=0;i< n ;i++){
            for (int j=0;j<n;j++){
                int count=0;
                if (ms_board[i][j]=='9') continue;

                if ((i-1)>=0 && ms_board[i-1][j]=='9'){
                    count++;
                }
                if ((i+1)<n && ms_board[i+1][j]=='9'){
                    count++;
                }
                if ((j-1)>=0 && ms_board[i][j-1]=='9'){
                    count++;
                }
                if ((j+1)<n && ms_board[1][j+1]=='9'){
                    count++;
                }
                if ((i-1)>=0 && (j-1)>=0  && ms_board[i-1][j-1]=='9'){
                    count++;
                }
                if ((i-1)>=0 && (j+1)<n &&  ms_board[i-1][j+1]=='9'){
                    count++;
                }
                if ((i+1)<n && (j-1)>=0 &&  ms_board[i+1][j-1]=='9'){
                    count++;
                }
                if ((i+1)<n && (j+1)<n && ms_board[i+1][j+1]=='9'){
                    count++;
                }

                ms_board[i][j]='0'+count;
            }
        }


        //commands
        for (int i=0;i<(n*n)-mines;i++){
            char ch;
            int ROWS;int COLS;
            cin>> ch;
            cin>> ROWS;cin>>COLS;
               //row and col are of 1 based indexing.
            if (ch=='r' || ch=='f'){
                
                if (ch=='r'&& ms_board[ROWS-1][COLS-1]=='9'){
                    cout<<"BOOM ! GAME OVER :("<<endl;
                    showMines(ms_board,view);
                    return 0;
                }

                revealOrFlag(ms_board,view ,ROWS, COLS, ch);
            }
            else if (ch=='q'){
                cout<<"Thanks for playing ,but now u are quitting the game !!! "<<endl;
                return 0;
            }else{
                cout<<"wrong input"<<endl;
                return 0;
            }

            //winning 
            int winningNo=0;
            bool allRevealed=true;
            for (int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if (view[i][j]!='.' && ms_board[i][j]=='9'){
                        allRevealed=false;
                        break;
                    }
                    if (view[i][j]!='.' && ms_board[i][j]!='9'){
                        winningNo++;
                    }
                }
                if (!allRevealed) break;
            }

            while(allRevealed && winningNo==(n*n)-mines){
                cout<<"whooohooooo U WON THE GAME !!!"<<endl;
                showMines(ms_board,view);
                return 0;
            }
        }
    return 0;
}