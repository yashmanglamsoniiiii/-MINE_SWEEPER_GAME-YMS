


                                    // DESIGN FRAMEWORK:-(blueprint) ~"YMS"
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


                                            //CORRECT FUNCTION TO REVEAL CELLS
    void customPositions(vector<vector<char>> &main_board,vector<vector<char>> &view_board,int  i ,int j, int n,vector<vector<bool>> &visited){  // call by reference so that changes are saved
    // cases : all 4 dirn mei 9  , ya kisi ek dirn mei out of four , ya all clear, (baki ke like top right,etc....vo to aage wali recursive calls )
    //dont use bool visited -> this is just one true false for entire board
    //THEREFORE 2-D VECTOR FOR EACH CELL TO ENSURE WE DON'T REPEAT CELLS (TO AVOID INFINITY LOOP).

    //base case: out of bounds ,already visited or mine
    if (i<0 || j<0 || i>=n || j>=n || main_board[i][j]=='9' || visited[i][j]){  //visited is true for that cell
    return;
    } 
    // This prevents your code from ever even reaching invalid indices.
    //   So:
    //    i == n is not wrong in logic,--> uske phele it accessed main_board[i][j] or visited[i][j]
    //    but i >= n is safer in recursion because it catches all out-of-bound cases.


    // self works:-
    //1 . mark visited
    visited[i][j]=true;

    //2. reveal the cell
    view_board[i][j]=main_board[i][j];

    //3. if this cell is not empty (has no. 1-8 ) , don't expand further
    if (main_board[i][j]!='0'){
        return;
    }

    //recursive calls :assumptions (ye baki ke left, right ,up ,down , top-right, top-left, bottom -right, bottom -left reveal karega)
    customPositions(main_board,view_board,i+1,j,n,visited);//down
    customPositions(main_board,view_board,i-1,j,n,visited);//up
    customPositions(main_board,view_board,i,j+1,n,visited);//right
    customPositions(main_board,view_board,i,j-1,n,visited);//left
}



                         //TRIAL 2: wrong: THIS WON'T RUN JUST A BLUEPRINT HOW I THOUGHT AND REACHED TILL  CORRECT CODE 

                                      //ENOUGH CLOSE:-
void customPositionsTRIAL2(vector<vector<char>> &main_board,vector<vector<char>> &view_board,int  i ,int j, int n,vector<vector<bool>> &visited){  // call by reference so that changes are saved
    // cases : all 4 dirn mei 9  , ya kisi ek dirn mei out of four , ya all clear, (baki ke like top right,etc....vo to aage wali recursive calls )
    //dont use bool visited -> this is just one true false for entire board
    //THEREFORE 2-D VECTOR FOR EACH CELL TO ENSURE WE DON'T REPEAT CELLS (TO AVOID INFINITY LOOP).

    // base case:
    if (i==n || j==n || i<0 || j<0 || main_board[i][j]=='9' || visited [i][j]){// that cell is true then return too.
        return ;
    }

    //recursive calls (assumptions + self work):
    if (i<n && main_board[i+1][j]!='9'  && visited[i+1][j]!=true){
    customPositions(main_board,view_board,i+1,j,n,visited);
    view_board[i][j]=main_board[i][j];//value assign.
    visited[i][j]=true;
    // cout<<view_board[i][j]<<" ";//i don't wanna print specific cell, i wanna print whole board after this recur. fn.
    }

    if (i>=0  && main_board[i-1][j]!='9' &&  visited[i-1][j]!=true){
    customPositions(main_board,view_board,i-1,j,n,visited);
    view_board[i][j]=main_board[i][j];//value assign.
    visited[i][j]=true;
    // cout<<view_board[i][j]<<" ";
    }
    
    if (j<n && main_board[i][j+1]!='9' &&  visited[i][j+1]!=true){
    customPositions(main_board,view_board,i,j+1,n,visited);
    view_board[i][j]=main_board[i][j];//value assign.
    visited[i][j]=true;
    // cout<<view_board[i][j]<<" ";
    }

    if (j>=0 && main_board[i][j-1]!='9' &&  visited [i][j-1]!=true){
    customPositions(main_board,view_board,i,j-1,n,visited);
    view_board[i][j]=main_board[i][j];//value assign.
    visited[i][j] =true;
    // cout<<view_board[i][j]<<" ";
    }

}
                                      // ERRORS IN THIS CODE :-

//1 .  I am marking the cell as -> "visited[i][j] = true;"
// after making the recursive call.
// That means another direction could visit this same cell again before it’s marked → infinite recursion possible.

// ✅ Fix → mark visited immediately when entering the function.

//2.. Revealing the cell only after recursion

// You’re revealing (view_board[i][j] = main_board[i][j];) after recursion.
// That means the current cell might not appear revealed until much later.

// ✅ Fix → reveal immediately when visiting a cell.

                                    


                              // TRIAL 1:- wrong: COMPLETELY WRONG:-

// void customPositionsTRIAL1(vector<vector<char>> &v,int r, int c){
//     // using recursion.
//     if (v[r][c]=='9' || r==v.size() || c== v[0].size()){ return ;  //c==v.size( ) ->same .
//     }
//     //recursive call:
//     //we need to do (r,c+1),(r,c-1),(r+1.c), (r-1,c)   >> 4 recusive calls?
//     customPositions(v,r,c+1);
//     cout<<v[r][c];
//     customPositions(v,r,c-1);
//     cout<<v[r][c];
//     customPositions(v,r+1,c);
//     cout<<v[r][c];
//     customPositions(v,r-1,c);
//     cout<<v[r][c];

//     return ;
// }
    


   //if mine mila to boom
void showMines(vector<vector<char>> &mainBoard,vector<vector<char>> &viewBoard){

    for (int i=0;i<viewBoard.size();i++){
        for (int j=0;j<viewBoard[i].size();j++){
            if (mainBoard[i][j]=='9'){
                cout<<"* ";
            }else{
                cout<<viewBoard[i][j]<<" ";// kuch prev values bhi to hongi 
            }
        }cout<<endl;
    }

}



    // only called if character = r / f.
void revealOrFlag(vector<vector<char>> &mainBoard,vector<vector<char>> &viewBoard ,char c,int ROWS,int COLS){
    int n=mainBoard.size();
    //FOR 1-BASED INDEXING:-
    if (ROWS>n || COLS>n || ROWS<=0 || COLS<=0) {
        cout<< "Wrong input for rows and columns !!!!!! "<<endl;
        return ;
    }   //--> user se ek aur input maango
    ROWS--;
    COLS--; // FOR BOARDS' USAGE  HUM-1 BASED  , BOARD-0 BASED

    if (c=='r'){


        // CONDN 1 : IF r rows cols karne ke baad vo 9 YA mine nikla to boom  and all mines show karne ke baad game over >> 
        //IN MAIN FUNCTION  , REASON:-
        //code:
        // cout<<"BOOM !!! GAME OVER :(";
        // return ;
        // but main fn . mei loop hai to chalega. :(
        
        
        // WRITTEN IN MAIN FUNCTION :-
        // if (mainBoard[ROWS][COLS]=='9'){
        //     cout<<"BOOM !!! GAME OVER :("<<endl;
        //     showmines();
        //     return;
        // }
        
        //CONDN 2: HERE ALSO RANDOM NO. OF CELLS WILL BE DISPLAYED.AFTER THAT WITH VALUE EXCEPT 9 OR MINE.
        
        viewBoard[ROWS][COLS]=mainBoard[ROWS][COLS];  // putting that value (just like popping that cell).
        vector<vector<bool>> visited(n,vector<bool> (n,false));
        customPositions(mainBoard,viewBoard , ROWS,COLS,n,visited);
        //print the viewboard:
        for (int i=0;i< n;i++){
            for (int j=0;j<n;j++){
                cout<<viewBoard[i][j]<<" "; //viewBoard[ROWS][COLS] -> SAME CELL PRINTED
            }cout<<endl;
        }    
    }

    else {
        // we need user frienly 1 based indexing
        // viewBoard[ROWS-1][COLS-1]=  'F';         //char(70) typecasting.
        viewBoard[ROWS][COLS]=  'F';         //char(70) typecasting.
                        //0 based indexing.
    //displaying board after changes (AFTER PUTTING FLAG)
    for (int i=0;i<viewBoard.size();i++){
        for (int j=0;j<viewBoard[i].size();j++){
            cout<<viewBoard[i][j]<<" ";
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

        //creating mine sweeper board.

        vector<vector<char>> ms_board(n,vector<char>(n));

        //board display after inputs :-(hidden all)by dots. -> not correct and needed.
        // for(int i=0;i<ms_board.size();i++){
        //     for (int j=0;j<ms_board[i].size();j++){
        //         cout << "."<<" ";
        //     }cout<<endl;
        // }


        //creation of another board view which we will display after every move.
        vector<vector<char>> view(n,vector<char> (n,'.'));
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cout<<view[i][j]<<" ";  // for char board.  >> thoda easy to again and again display.
                // cout<<"."<<" ";   if int .
            }cout<<endl;
        }

        //creation of mines and numbers. >> use ch instead of int for flagging.
    

        //LOGIC :- NO.1 >> 9 JAHAN HO VAHAN VAHAN USKE AAS PASS NUMBERS DALO LIKE 1 OR 2. (BASICALLY EK EK TO SPECIFICALLY  CELL PAR JAA KAR.) 
                            // IF MANUAL BOARD TO EASY BUT NO. 2 IS THEN ALSO EASY.
                 //NO. 2>> MATRIX KO TRAVERSE IF 9 MILA TO  USKI SURR. MEI COUNT++ ; 
        
        //using logic 2:-

        // time(0) → returns current time (e.g., 1739455013)

        // srand() → seeds the random number generator with that time

        // rand() → generates a pseudo-random number based on that seed

        // Analogy:

        // Think of it like a lottery machine 🎲

        // srand(time(0)) → shakes the machine differently every second

        // rand() → picks a random ball out of it

        // If you didn’t use srand(time(0)), it would shake the same way every time → giving the same random numbers on every run 😅
        // EX:-          srand(10);             // set seed
        //               cout << rand() % 10;   // random number from 0–9

    //code for random mines.
  srand(time(0));  //without this code works fine but mines hamesha same jagah place hongi.
    int placed=0;
    while(placed<mines){
        int random_rows=rand()%n;//random rows
        int random_cols=rand()%n; // random cols

        if (ms_board[random_rows][random_cols]!='9'){//if not already a mine.
            ms_board[random_rows][random_cols]='9';
            placed++;
        }
    }


        //code for placing count on each cell.
        for (int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // int count=0;

                //skip the cell if the current cell is mine itself:-
                if (ms_board[i][j]=='9') continue;

                int count=0;//count banega hi nhi if mine hua cell to.

                //if ((i-1)!=-1)->
                // If there is a valid row above me (i.e., i-1 is not -1), then check if that cell has a mine.
                // So far it looks okay, right?
                // But the real problem is not logical correctness, it’s readability and potential confusion:

                // 1. It’s not the correct mathematical test for array bounds.
                // 2. It becomes confusing when combined with other conditions

                //if ((i-1)>=0)->(more correct)
                // “If there is a row above (i-1 is not negative), then check that cell.”

                //checking for all 8 directions:-
                if ((i-1)>=0 && ms_board[i-1][j]=='9'){  //i>0 is also correct ,same with others.
                    count++;
                }
                if ((j-1)>=0 && ms_board[i][j-1]=='9'){
                    count++;
                }
                if ((i+1)<n && ms_board[i+1][j]=='9'){
                    count++;
                }
                if ((j+1)<n && ms_board[i][j+1]=='9'){
                    count++;
                }
                if ((i-1)>=0 && (j-1)>=0 && ms_board[i-1][j-1]=='9'){
                    count++;
                } 
                if ((i-1)>=0 && (j+1)<n && ms_board[i-1][j+1]=='9'){
                    count++;
                } 
                if ((i+1)<n && (j-1)>=0 && ms_board[i+1][j-1]=='9'){
                    count++;
                } 
                if ((i+1)<n && (j+1)<n && ms_board[i+1][j+1]=='9'){
                    count++;
                } 

                //save the count into board and convert int to char 
                ms_board[i][j]=count+'0'; //ex: 4+'0'='4'
            }
        }


        // creation of commands + FUNCTIONALITY
        
        for(int i=0;i<=(n*n)-mines;i++){// for loop condition jab tak ki end na ho jae.
            cout<<endl;
            cout<<"  ENTER THE -CHARACTER- -ROW- -COL- (1-BASED INDEXING) :- "<<endl;
            char ch;
            cin>>ch;
            if (ch=='r' || ch=='f'){
                int ROWS,COLS;

                cin>> ROWS>>COLS;
                //proceed to next........ code
                //checking for mine 💣 firstly before REVEALING.
                if(ch=='r' && ms_board[ROWS-1][COLS-1]=='9'){
                    cout<<"BOOM !!! GAME OVER!!! :("<<endl;
                    showMines(ms_board,view);
                    return 0;
                }

                // REVEAL or FLAG cell (this fn handles printing)
                revealOrFlag(ms_board,view,ch,ROWS,COLS);

            }
            //NOT AS REQUIRED.
            // else if (ch=='f'){
            //     int ROWS,COLS;
            //     cin>> ROWS>>COLS;//local to 'else if' block.
            //     //proceed to next..............code.
            //     revealOrFlag(ms_board,view,ch,ROWS,COLS);
            // }
            else if (ch=='q'){
                // break the code and return  .....code.
                //so returning form main function aage ka nothing execute.
                cout<<"You are quitting the game!!! Thanks for playing ❤️❤️❤️:) "<<endl;
                return 0;

            }else{
                cout<< "Invalid input ."<<endl;
                // RETURNING FROM MAIN FUNCTION AAGE KA NOTHING EXECUTE.
                return 0;
            }
        

                                               //WINNING
                                        
                                        
                                        
            //agar sare cells reveal hogye to "." wale ek bhi cell nhi bachnege
            // int winningNo=0;
            // for (int i=0 ;i<n; i++){
            //     for (int j=0;j<n;j++){
            //         if (view[i][j]!='.' && ms_board[i][j]!='9'){ //view board is having all cells numbered and msboard wale jitne 9 hain vo bache hain
            //             winningNo++;
            //             // continue;//not as required.
                        
            //         }else{
            //             break; //optimization  so that full loop unnecessarily will not run.
            //             // it is not actually optimizing as it will only stop inner loop like for row 0 
            //             // but will again run for row 1 , row 2 ,etc......
            //         }
            //     }
            // } 
            //IF SIMPLY IF WALA PART AND WE DON'T WRITE THE ELSE PART ITS GOOD .

                      // ANOTHER VERSION:-
// int winningNo = 0;
// bool notFinished = false;

// for (int i = 0; i < n; i++) {
//     for (int j = 0; j < n; j++) {
//         if (view[i][j] != '.' && ms_board[i][j] != '9') {
//             winningNo++;
//         } else {
//             notFinished = true;
//             break;  // break inner loop
//         }
//     }
//     if (notFinished) break;  // break outer loop
// }



            // if (winningNo==(n*n)-mines){ //this means sare cells travel kar liye and no cell is having '.'
            //     // if winningNo ==n*n => we will never win

            //     // view[i][j] != '.' means this cell has been revealed.
            //     //  ms_board[i][j] != '9' means it’s a safe cell.
            //     // So winningNo counts how many safe cells have been revealed. ✅
            //     cout<<" YOU WON THE GAME WOOHOOOOOOOO!!!! "<<endl;
            // }




                                    // more better and optimized version:
            int winningNo=0;
            bool allRevealed=true;
            
            for (int i=0;i<n;i++){
                for (int j=0;j< n;j++){
                    if (ms_board[i][j]!='9' && view[i][j]=='.'){
                        allRevealed=false;
                        break;//stop checking this row as one unrevealed cell found.
                    }
                    if (ms_board[i][j]!='9' && view[i][j]!='.'){
                        winningNo++;
                    }
                }
                if (!allRevealed) break; // also break the outer loop.
            }
            

                //winning means all safe cells = total -mines = safe.

            if (allRevealed && winningNo==(n*n)-mines){ //this means sare cells travel kar liye and no cell is having '.'
                // if winningNo ==n*n => we will never win

                // view[i][j] != '.' means this cell has been revealed.
                //  ms_board[i][j] != '9' means it’s a safe cell.
                // So winningNo counts how many safe cells have been revealed. ✅
                cout<<" YOU WON THE GAME WOOHOOOOOOOO!!!! "<<endl;
                cout<< " This is the game board design U  chose :- "<<endl;
                showMines(ms_board,view);//reveal full board with mines.
                return 0 ; //varna aage bhi chalta rahega.(will continue further).
            }

        }
        
return 0;
}












