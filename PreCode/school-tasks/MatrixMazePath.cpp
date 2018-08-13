#include <map>
#include <iostream>
using namespace std;
//int getPath(int[][] matrix_maze,int current_pos_x,int current_pos_y,int aimed_pos_x,int aimed_pos_y);

int getPath(int** matrix_maze,int width,int height,int current_pos_x,int current_pos_y,int aimed_pos_x,int aimed_pos_y){
    if(current_pos_x==aimed_pos_x&&current_pos_y==aimed_pos_y)
        return 1;

	int len_width = width;
	int len_heigh = height;

	matrix_maze[current_pos_y][current_pos_x] = 2;
	if (current_pos_x + 1 < len_width&&matrix_maze[current_pos_y][current_pos_x + 1] == 0) {
		matrix_maze[current_pos_y][current_pos_x] = getPath(matrix_maze,width,height, current_pos_x+1, current_pos_y, aimed_pos_x, aimed_pos_y);
		if (matrix_maze[current_pos_y][current_pos_x] == 1)
			return 1;
	}
	//matrix_maze[current_pos_y][current_pos_x] == 2;
	if (current_pos_y + 1 < len_heigh&&matrix_maze[current_pos_y + 1][current_pos_x] == 0) {
		matrix_maze[current_pos_y][current_pos_x] = getPath(matrix_maze,width,height, current_pos_x, 1+current_pos_y, aimed_pos_x, aimed_pos_y);
		if (matrix_maze[current_pos_y][current_pos_x] == 1)
			return 1;
	}
	//matrix_maze[current_pos_y][current_pos_x] == 2;
	if (current_pos_x - 1 >= 0 && matrix_maze[current_pos_y][current_pos_x - 1] == 0) {
		matrix_maze[current_pos_y][current_pos_x] = getPath(matrix_maze,width,height, current_pos_x-1, current_pos_y, aimed_pos_x, aimed_pos_y);
		if (matrix_maze[current_pos_y][current_pos_x] == 1)
			return 1;
	}
	//matrix_maze[current_pos_y][current_pos_x] == 2;
	if (current_pos_y - 1 >= 0 && matrix_maze[current_pos_y - 1][current_pos_x] == 0) {
		matrix_maze[current_pos_y][current_pos_x] = getPath(matrix_maze, width,height,current_pos_x, current_pos_y-1, aimed_pos_x, aimed_pos_y);
		if (matrix_maze[current_pos_y][current_pos_x] == 1)
			return 1;
	}
	return 2;//matrix_maze[current_pos_y][current_pos_x];

}
int tmain(){
    int width,height,start_x,start_y,end_x,end_y;
    cin>>width>>height;
    int** matrix_maze=new int*[height];//=new int[height][widht];
	for (int i = 0; i < width; i++)
		matrix_maze[i] = new int[width];
    for(int i=0;i<height;i++)
        for(int k=0;k<width;k++)
            cin>>matrix_maze[i][k];
    cin>>start_x>>start_y>>end_x>>end_y;
    //matrix_maze[start_y-1][start_x-1]=1;
    getPath(matrix_maze,width,height,start_x-1,start_y-1,end_x-1,end_y-1);
    matrix_maze[end_y-1][end_x-1]=1;
	for (int i = 0; i < height; i++)
		for (int k = 0; k < width; k++)
			if (matrix_maze[i][k] == 2)
				matrix_maze[i][k] = 0;
	for (int i = 0; i < height; i++) {
		for (int k = 0; k < width; k++){
			if(matrix_maze[i][k]==1)
			cout <<"¡ö";
			else if(matrix_maze[i][k]==0)
			cout <<" *";
			else if(matrix_maze[i][k]==-1)
			cout <<"¡õ";
		}
		cout << endl;
	}
	system("pause");
    return 0;
}
