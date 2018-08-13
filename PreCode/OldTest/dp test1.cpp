class Node{
    int row;
    int column;
    int from_direction;
};
int min_path[max][max][4];
int has_edge[max][max][4];
int move_row[]={-1,0,1,0};
int move_column[]={0,-1,0,1};
Node walk(Node& n,int to){
    int from_direction=n.from_direction;
    if(to==1) from_direction=(from_direction+1)%4;
    if(to==2) from_direction=(from_direction+3)%4;
    return Node(n.row+move_row[from_direction],n.column+move_column[from_direction],from_direction);
}
bool can_go_to(Node& n,int from_direction){
    return has_edge[n.row][n.column][n.from_direction][from_direction];
}
int solve(int r1,int c1,int r2,int c2){
    queue<Node> q;
    memset(q,-1,sizeof(q));
    Node start(r1,c1,0);
    min_path[start.row][start.column][0]=0;
    min_path[start.row][start.column][1]=0;
    min_path[start.row][start.column][2]=0;
    min_path[start.row][start.column][3]=0;
    q.push(start);
    while(!q.empty()){
        Node n=q.front();
        q.pop();
        for(int i=0;i<3;i++){
            if(can_go_to(n,i)){
                Node temp=walk(n,i);
                if(min_path[temp.row][temp.column][i]>min_path[n.row][n.column][i]+1){
                min_path[temp.row][temp.column][i]-min_path[n.row][n.column][i]+1
                q.push(temp);
                }
            }
        }
    }
}