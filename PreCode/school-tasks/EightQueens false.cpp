//EightQueens
#include <iostream>
using namespace std;
void placeQueens(int**,int,int,int);
void printMatrix(int**,int,int);
bool checkLines(int** matrix,int current_row,int width_pos,int width,int height);
bool checkRow(int** matrix,int current_row,int width_pos,int width,int height);
bool checkHeight(int** matrix,int current_row,int width_pos,int width,int height);
int main(){
   int** matrix=new int*[8];
   for(int i=0;i<8;i++){
         matrix[i]=new int[8];
         for(int k=0;k<8;k++)
            matrix[i][k]=0;
    }
   placeQueens(matrix,0,8,8);
   system("pause");
    return 0;
}
void placeQueens(int** matrix,int current_row,int height,int width){
    if(current_row==height){
        printMatrix(matrix,height,width);
        return;
    }
   for(int i=0;i<width;i++){
        if(checkRow(matrix,current_row,i,width,height)&&checkHeight(matrix,current_row,i,width,height)&&checkLines(matrix,current_row,i,width,height)){
            matrix[current_row][i]=1;
            placeQueens(matrix,current_row+1,height,width);
            matrix[current_row][i]=0;
        }
   }
}
bool checkLines(int** matrix,int current_row,int width_pos,int width,int height){
    int current_row_cp=current_row;
    int width_pos_cp=width_pos;
    while(width_pos_cp>=0&&current_row_cp>=0){
        if(matrix[current_row_cp][width_pos_cp]==1)
            return false;
        width_pos_cp--;
        current_row_cp--;
    }
    current_row_cp=current_row;
    width_pos_cp=width_pos;
    while(width_pos_cp>=0&&current_row_cp<height){
        if(matrix[current_row_cp][width_pos_cp]==1)
            return false;
        width_pos_cp--;
        current_row_cp++;
    }
    current_row_cp=current_row;
    width_pos_cp=width_pos;
    while(width_pos_cp<width&&current_row_cp>=0){
        if(matrix[current_row_cp][width_pos_cp]==1)
            return false;
        width_pos_cp++;
        current_row_cp--;
    }
    current_row_cp=current_row;
    width_pos_cp=width_pos;
    while(width_pos_cp<width&&current_row_cp<height){
        if(matrix[current_row_cp][width_pos_cp]==1)
            return false;
        width_pos_cp++;
        current_row_cp++;
    }
    return true;
}
bool checkRow(int** matrix,int current_row,int width_pos,int width,int height){
    for(int i=0;i<width;i++) {
        if(matrix[current_row][i]==1)
            return false;
    }
    return true;
}
bool checkHeight(int** matrix,int current_row,int width_pos,int width,int height){
    for(int i=0;i<height;i++) {
        if(matrix[i][width_pos]==1)
            return false;
    }
    return true;
}
void printMatrix(int** matrix,int height,int width){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;i++){
            if(matrix[i][j]==0)
                cout<<" *";
            else
                cout<<"口";
        }
        cout<<endl;
    }
}
