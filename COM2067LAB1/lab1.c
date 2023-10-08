#include <stdio.h>
#include <stdlib.h>
#define MaxRow 40
#define MaxColumn 40
void CreateMaze(char Maze[][MaxColumn], int MazeRow, int MazeColumn);
void PrintMaze(char Maze[][MaxColumn], int MazeRow, int MazeColumn);
void BubbleSort(int ArrLength, int arr[], int *length);
void BubbleSortReverse(int ArrLength, int arr[]);
void BlobsCheckAlgorithm(char Maze[][MaxColumn], int CurrentRow, int CurrentColumn ,int MazeRow, int MazeColumn, int* BlobChecker, int* BlobLength);


int main(){
    int MazeRow, MazeColumn;
    char MazeArr[MaxRow][MaxColumn];
    scanf("%d %d", &MazeRow, &MazeColumn);
    int MazeFlagArr[MazeRow * MazeColumn];
    int BlobLengthArr[MazeRow * MazeColumn];
    for(int i = 0; i < MazeRow * MazeColumn; ++i){
        BlobLengthArr[i] = 0;
        MazeFlagArr[i] = 0;
    }
    CreateMaze(MazeArr, MazeRow, MazeColumn);
    int GroupCounter = 0;
    int count = 0;
    for(int i = 0; i < MazeRow; ++i){
        for(int j = 0; j < MazeColumn; ++j){
            BlobsCheckAlgorithm(MazeArr, i, j, MazeRow, MazeColumn, MazeFlagArr, &count);
            BlobLengthArr[GroupCounter++] = count;
            count = 0;
        }
    }
    int BlubCounter = 0;
    BubbleSort(MazeRow*MazeColumn, BlobLengthArr, &BlubCounter);
    BubbleSortReverse(BlubCounter, BlobLengthArr);
    printf("%d ", BlubCounter);
    for(int i = 0; i < BlubCounter; ++i){
        printf("%d ", BlobLengthArr[i]);
    }
    printf("\n");


    return 0;

}



void BubbleSort(int ArrLength, int arr[], int* length){
    //Takes THREE arguments as inputs, first one is ArrLength which defines the number of cells, second argument is for array, third one is length which defines the cells that are not '0' ZERO.
    //Bubble Sort algorithm is a traditional way to make numbers in order.
    //temp variable is placeholder for changing places of the numbers


    for(int i = 0; i < ArrLength - 1; ++i){
        for(int j = 0; j < ArrLength - i - 1; j++){
            if(arr[j] <= arr[j + 1]){
                int temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < ArrLength; ++i){
        if(arr[i] != 0){
            *length = *length + 1; 
        }
    }
}

void BubbleSortReverse(int ArrLength, int arr[]){
    //Takes two arguments as input arguments. First one is the length of the array which is named as ArrLength. arr variable defines the object which must be in order.

    for(int i = 0; i < ArrLength - 1; ++i){
        for(int j = 0; j < ArrLength - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void CreateMaze(char Maze[][MaxColumn], int MazeRow, int MazeColumn){
    int InputRow = 0, InputColumn = 0;
    for(int i = 0; i < MazeRow; ++i){
        for(int j = 0; j < MazeColumn; ++j){
            Maze[i][j] = '-';
        }
    }
    int flag = 1;
    scanf("%d", &InputRow);
    //takes input if flag is one, which means flag will be one as long as the condition is true.
    while(flag == 1){
        scanf("%d", &InputColumn);
        //for ending input, makes condition false.
        if(InputRow == -1 || InputColumn == -1){
            flag = 0;
        }
        else{
            Maze[InputRow][InputColumn] = '*';
        }
        scanf("%d", &InputRow);
    }
}


void PrintMaze(char Maze[][MaxColumn], int MazeRow, int MazeColumn){
    //visits every cell to print it with for loops
    for(int i = 0; i < MazeRow; i++){
        for(int j = 0; j < MazeColumn; j++){
            printf("%c", Maze[i][j]);
        }
        printf("\n");
    }
}

void BlobsCheckAlgorithm(char Maze[][MaxColumn], int CurrentRow, int CurrentColumn ,int MazeRow, int MazeColumn, int* BlobChecker, int* BlobLength){
    
    //It checks for cells that are not in the maze, if cell is not in maze, return for ending the recursion correctly.
    if(CurrentRow < 0 || CurrentRow >= MazeRow || CurrentColumn < 0 || CurrentColumn >= MazeColumn || Maze[CurrentRow][CurrentColumn] != '*' || BlobChecker[CurrentRow*MazeColumn + CurrentColumn] == 1){
        return;
    }
    BlobChecker[MazeColumn * CurrentRow + CurrentColumn] = 1;
    *BlobLength = *BlobLength + 1;
    BlobsCheckAlgorithm(Maze, CurrentRow+1, CurrentColumn, MazeRow, MazeColumn, BlobChecker, BlobLength);
    BlobsCheckAlgorithm(Maze, CurrentRow+1, CurrentColumn +1, MazeRow, MazeColumn, BlobChecker, BlobLength);
    BlobsCheckAlgorithm(Maze, CurrentRow+1, CurrentColumn - 1, MazeRow, MazeColumn, BlobChecker, BlobLength);
    BlobsCheckAlgorithm(Maze, CurrentRow, CurrentColumn -1, MazeRow, MazeColumn, BlobChecker, BlobLength);
    BlobsCheckAlgorithm(Maze, CurrentRow-1, CurrentColumn -1, MazeRow, MazeColumn, BlobChecker, BlobLength);
    BlobsCheckAlgorithm(Maze, CurrentRow-1, CurrentColumn, MazeRow, MazeColumn, BlobChecker, BlobLength);
    BlobsCheckAlgorithm(Maze, CurrentRow, CurrentColumn +1, MazeRow, MazeColumn, BlobChecker, BlobLength);
    BlobsCheckAlgorithm(Maze, CurrentRow-1, CurrentColumn+1, MazeRow, MazeColumn, BlobChecker, BlobLength);
}
