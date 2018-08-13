#include <iostream>

using namespace std;
//void placeQueens(int**,int,int,int);
//void printMatrix(int**,int,int);
//bool checkLines(int** matrix,int current_row,int width_pos,int width,int height);
//bool checkRow(int** matrix,int current_row,int width_pos,int width,int height);
//bool checkHeight(int** matrix,int current_row,int width_pos,int width,int height);
//
void printMatrix(int** matrix,int height,int width){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if (matrix[i][j] == 0) {
                cout << " .";
            }
            else {
                cout << " *";
            }
            //cout << matrix[i][j];
        }
        cout<<endl;
    }
    cout << "---------------------------------------------------" << endl;
}
// bool checkLines(int** matrix,int current_row,int width_pos,int width,int height){
//     int current_row_cp=current_row;
//     int width_pos_cp=width_pos;
//     while(width_pos_cp>=0&&current_row_cp>=0){
//         if(matrix[current_row_cp][width_pos_cp]==1)
//             return false;
//         width_pos_cp--;
//         current_row_cp--;
//     }
//     current_row_cp=current_row;
//     width_pos_cp=width_pos;
//     while(width_pos_cp>=0&&current_row_cp<height){
//         if(matrix[current_row_cp][width_pos_cp]==1)
//             return false;
//         width_pos_cp--;
//         current_row_cp++;
//     }
//     current_row_cp=current_row;
//     width_pos_cp=width_pos;
//     while(width_pos_cp<width&&current_row_cp>=0){
//         if(matrix[current_row_cp][width_pos_cp]==1)
//             return false;
//         width_pos_cp++;
//         current_row_cp--;
//     }
//     current_row_cp=current_row;
//     width_pos_cp=width_pos;
//     while(width_pos_cp<width&&current_row_cp<height){
//         if(matrix[current_row_cp][width_pos_cp]==1)
//             return false;
//         width_pos_cp++;
//         current_row_cp++;
//     }
//     return true;
// }
// bool checkRow(int** matrix,int current_row,int width_pos,int width,int height){
//     for(int i=0;i<width;i++) {
//         if(matrix[current_row][i]==1)
//             return false;
//     }
//     return true;
// }
// bool checkHeight(int** matrix,int current_row,int width_pos,int width,int height){
//     for(int i=0;i<height;i++) {
//         if(matrix[i][width_pos]==1)
//             return false;
//     }
//     return true;
// }

// void placeQueens(int** matrix,int current_row,int height,int width){
//    //  if(current_row==height){
//    //      printMatrix(matrix,height,width);
//    //      return;
//    //  }
//    // for(int i=0;i<width;i++){
//    //      if(checkRow(matrix,current_row,i,width,height)&&checkHeight(matrix,current_row,i,width,height)&&checkLines(matrix,current_row,i,width,height)){
//    //          matrix[current_row][i]=1;
//    //          placeQueens(matrix,current_row+1,height,width);
//    //          matrix[current_row][i]=0;
//    //      }
//    // }
//     for(int m=0;m<width;m++){
//         for(int y=0;y<height;y++){
//             for(int x=m;x<width;x++){
//                 if(checkHeight(matrix,y,x,width,height)&&checkLines(matrix,y,x,width,height)&&checkRow(matrix,y,x,width,height)){
//                     matrix[y][x]=1;
//                 }
//             }
//         }
//     }
// }

int main() {
    int** matrix = new int*[8];
    for (int i = 0; i < 8; i++) {
        matrix[i] = new int[8];
        for (int k = 0; k < 8; k++)
            matrix[i][k] = 0;
    }
    int width=8;
    int height=8;
    for(int r0=0;r0<width;r0++){
     matrix[0][r0]=1;
     for(int r1=0;r1<width;r1++){
       if(checkHeight(matrix,1,r1,width,height)&&checkLines(matrix,1,r1,width,height)&&checkRow(matrix,1,r1,width,height)){
        matrix[1][r1]=1;
        for(int r2=0;r2<width;r2++){
         if(checkHeight(matrix,2,r2,width,height)&&checkLines(matrix,2,r2,width,height)&&checkRow(matrix,2,r2,width,height)){
            matrix[2][r2]=1;
            for(int r3=0;r3<width;r3++){
             if(checkHeight(matrix,3,r3,width,height)&&checkLines(matrix,3,r3,width,height)&&checkRow(matrix,3,r3,width,height)){
                matrix[3][r3]=1;
                for(int r4=0;r4<width;r4++){
                 if(checkHeight(matrix,4,r4,width,height)&&checkLines(matrix,4,r4,width,height)&&checkRow(matrix,4,r4,width,height)){
                     matrix[4][r4]=1;
                     for(int r5=0;r5<width;r5++){
                         if(checkHeight(matrix,5,r5,width,height)&&checkLines(matrix,5,r5,width,height)&&checkRow(matrix,5,r5,width,height)){
                             matrix[5][r5]=1;
                             for(int r6=0;r6<width;r6++){
                                 if(checkHeight(matrix,6,r6,width,height)&&checkLines(matrix,6,r6,width,height)&&checkRow(matrix,6,r6,width,height)){
                                     matrix[6][r6]=1;
                                     for(int r7=0;r7<width;r7++){
                                       if(checkHeight(matrix,7,r7,width,height)&&checkLines(matrix,7,r7,width,height)&&checkRow(matrix,7,r7,width,height)){
                                           matrix[7][r7]=1;
                                           printMatrix(matrix,8,8);
                                           matrix[7][r7]=0;
                                       }
                                   }
                                   matrix[6][r6]=0;
                                 }
                             }
                             matrix[5][r5]=0;
                         }
                     }
                     matrix[4][r4]=0;
                 }
             }
             matrix[3][r3]=0;
         }
     }
     matrix[2][r2]=0;
 }
}
matrix[1][r1]=0;
}
}
matrix[0][r0]=0;
}
    //placeQueens(matrix, 0, 8, 8);
system("pause");
return 0;
}