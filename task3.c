#include<stdio.h>
#define N 9
void print_grid(int grid[N][N]){
    for(int row=0;row<N;row++){
        for(int col=0;col<N;col++)
        {
            printf("%d",grid[row][col]);
        }
        printf("\n");
    }
}
int is_safe(int grid[N][N],int row,int col,int num){
    for(int x=0;x<N;x++){
        if(grid[row][x]==num){
            return 0;
        }
    }
    for(int x=0;x<N;x++){
        if(grid[x][col]==num){
            return 0;
        }
    }
    int start_row=row-row%3;
    int start_col=col-col%3;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++){
            if(grid[i+start_row][j+start_col]==num){
                return 0;
            }
        }
    }
    return 1;
}
int solve_sudoku(int grid[N][N])
{
    int row,col;
    int empty_found=0;
    for(row=0;row<N;row++){
        for(col=0;col<N;col++){
            if(grid[row][col]==0){
                empty_found=1;
                break;
            }
        }
        if(empty_found){
            break;
        }
    }
    if(!empty_found){
        return 1;
    }
    for(int num=1;num<=9;num++){
        if(is_safe(grid,row,col,num)){
            grid[row][col]=num;
            if(solve_sudoku(grid)){
                return 1;
            }
            grid[row][col]=0;
        }
    }
    return 0;
}
int main(){
    int grid[N][N]={
        {4,5,7,8,0,0,8,6,0},
        {5,6,8,9,0,3,0,0,0},
        {0,0,8,0,0,6,0,5,5},
        {0,0,0,7,4,0,5,2,5},
        {6,0,0,0,0,7,1,3,4},
        {6,8,0,0,3,4,4,2,1},
        {1,2,5,3,0,7,0,0,0},
        {4,3,1,4,6,0,0,5,0},
        {1,3,5,7,0,7,0,5,7}
        };
        if(solve_sudoku(grid)){
            printf("sudoku solved\n");
            print_grid(grid);
        } else{
            printf("no sudoku exist \n");
        }
        return 0;
}