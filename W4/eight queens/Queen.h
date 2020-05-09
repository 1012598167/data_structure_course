//
// Created by mathskiller on 2018/10/13.
//

#ifndef EIGHT_QUEENS_QUEEN_H
#define EIGHT_QUEENS_QUEEN_H
const int Maxsize=10;

class Queen
{
public:

    Queen();
    int print[Maxsize][Maxsize];
    int pos[Maxsize];//表示第i的棋子放在第pos[i]列.
    int size; //表示皇后数量=8
    int result; // 存结果数目
    //row表示递归中当前放置第i行的皇后
    void DFS(int row);
};


#endif //EIGHT_QUEENS_QUEEN_H
