#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

//function for sprite: pass in number 1-8, or bomb, depending on how many objects surrounding it is bombs
class board{
public:
    int rows;
    int columns;
    //int total;
    //vector <int> cells;

    board(){};
    board(int rows, int columns){ this -> rows = rows; this -> columns = columns;}

};

struct cells{
    int address = 0;
    int color = 0; /// 0 blank; 1 black; 2 white
    vector <int> flip = {}; ///adjacent values of opposite color
    vector <int> turntiles = {};
    vector <int> validflip = {}; ///adjacent values that are valid to flip

    cells(){};
    cells(int a, int b, vector <int> c, vector <int> d, vector <int> e){this ->address = a; this -> color = b; this -> flip = c; this ->turntiles =d;this ->validflip =e;} // this -> isFlag = c ; this -> adjacent =d ; this -> num = n; this -> tnum = t; this ->checked_blank = e;}
};

vector <cells> boardlist;
board boardy(8,8);


void pushfunc(board board){
    for (int e = 0 ; e < 64 ; e++){

        cells cell(e, 0, {0}, {}, {});
        boardlist.push_back(cell);
    }
    boardlist[27].color =2; boardlist[28].color =1;boardlist[35].color =1; boardlist[36].color =2;
}

bool isadjacent(int click, vector<cells> list, int turn){ ///updates adjacent positions "flip"
    list[click].flip.clear(); list[click].flip.push_back(0);  ///i hope this works !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    if (turn % 2 ==1) {
        if (click == 0){
            if (list[click+1].color == 2){boardlist[click].flip.push_back(5);}
            if (list[click+8].color == 2){boardlist[click].flip.push_back(7);}
            if (list[click+9].color == 2){boardlist[click].flip.push_back(8);}
            if (list[click+1].color == 2 || list[click+8].color == 2 || list[click+9].color == 2) {return true;}
        }
        else if (click == 7){
            if (list[click-1].color == 2){boardlist[click].flip.push_back(4);}
            if (list[click+7].color == 2){boardlist[click].flip.push_back(6);}
            if (list[click+8].color == 2){boardlist[click].flip.push_back(7);}
            if (list[click-1].color == 2 || list[click+7].color == 2 || list[click+8].color == 2) {return true;}
        }
        else if (click == 56){
            if (list[click-8].color == 2){boardlist[click].flip.push_back(2);}
            if (list[click-7].color == 2){boardlist[click].flip.push_back(3);}
            if (list[click+1].color == 2){boardlist[click].flip.push_back(4);}
            if (list[click-8].color == 2 || list[click-7].color == 2 || list[click+1].color == 2) {return true;}
        }
        else if (click == 63){
            if (list[click-9].color == 2){boardlist[click].flip.push_back(1);}
            if (list[click-8].color == 2){boardlist[click].flip.push_back(2);}
            if (list[click-1].color == 2){boardlist[click].flip.push_back(4);}
            if (list[click-1].color == 2 || list[click-8].color == 2 || list[click-9].color == 2) {return true;}
        } ///corner cases
        else if ( 0 < click && click < 7){
            if (list[click-1].color == 2){boardlist[click].flip.push_back(4);}
            if (list[click+7].color == 2){boardlist[click].flip.push_back(6);}
            if (list[click+8].color == 2){boardlist[click].flip.push_back(7);}
            if (list[click+9].color == 2){boardlist[click].flip.push_back(8);}
            if (list[click+1].color == 2){boardlist[click].flip.push_back(5);}
            if (list[click-1].color == 2 || list[click+8].color == 2 || list[click+9].color == 2 || list[click+7].color == 2|| list[click+1].color == 2) {return true;}
        }
        else if ( 56 < click && click < 63){
            if (list[click-1].color == 2){boardlist[click].flip.push_back(4);}
            if (list[click-9].color == 2){boardlist[click].flip.push_back(1);}
            if (list[click-8].color == 2){boardlist[click].flip.push_back(2);}
            if (list[click-7].color == 2){boardlist[click].flip.push_back(3);}
            if (list[click+1].color == 2){boardlist[click].flip.push_back(5);}
            if (list[click-1].color == 2 || list[click-8].color == 2 || list[click-9].color == 2 || list[click-7].color == 2|| list[click+1].color == 2) {return true;}
        }
        else if( click== 8 || click== 16 ||click== 24 ||click== 32 ||click== 40 || click == 48 ){ ///lhs
            if (list[click-8].color == 2){boardlist[click].flip.push_back(2);}
            if (list[click-7].color == 2){boardlist[click].flip.push_back(3);}
            if (list[click+1].color == 2){boardlist[click].flip.push_back(5);}
            if (list[click+9].color == 2){boardlist[click].flip.push_back(8);}
            if (list[click+8].color == 2){boardlist[click].flip.push_back(7);}
            if (list[click-8].color == 2 || list[click-7].color == 2 || list[click+1].color == 2 || list[click+9].color == 2|| list[click+8].color == 2) {return true;}
        }
        else if( click== 15 || click== 23 ||click== 31 ||click== 39 ||click== 47 || click == 55 ){
            if (list[click-8].color == 2){boardlist[click].flip.push_back(2);}
            if (list[click-9].color == 2){boardlist[click].flip.push_back(1);}
            if (list[click-1].color == 2){boardlist[click].flip.push_back(4);}
            if (list[click+7].color == 2){boardlist[click].flip.push_back(6);}
            if (list[click+8].color == 2){boardlist[click].flip.push_back(7);}
            if (list[click-8].color == 2 || list[click-9].color == 2 || list[click-1].color == 2 || list[click+7].color == 2|| list[click+8].color == 2) {return true;}
        }

        else{
                if (list[click + 1].color == 2) { boardlist[click].flip.push_back(5); }
                if (list[click + 8].color == 2) { boardlist[click].flip.push_back(7); }
                if (list[click + 9].color == 2) { boardlist[click].flip.push_back(8); }
                if (list[click - 1].color == 2) { boardlist[click].flip.push_back(4); }
                if (list[click + 7].color == 2) { boardlist[click].flip.push_back(6); }
                if (list[click - 9].color == 2) { boardlist[click].flip.push_back(1); }
                if (list[click - 8].color == 2) { boardlist[click].flip.push_back(2); }
                if (list[click - 7].color == 2) { boardlist[click].flip.push_back(3); }

            if(list[click-9].color == 2 || list[click-8].color == 2 || list[click-7].color == 2 || list[click-1].color == 2 || list[click+1].color == 2 ||
                    list[click+7].color == 2 || list[click+8].color == 2 || list[click+9].color == 2){

                return true;
            }
        }
        return false;
    }

    else if (turn % 2 ==0) {
        if (click == 1) {
            if (list[click + 1].color == 1) { boardlist[click].flip.push_back(5); }
            if (list[click + 8].color == 1) { boardlist[click].flip.push_back(7); }
            if (list[click + 9].color == 1) { boardlist[click].flip.push_back(8); }
            if (list[click + 1].color == 1 || list[click + 8].color == 1 || list[click + 9].color == 1) { return true; }
        } else if (click == 7) {
            if (list[click - 1].color == 1) { boardlist[click].flip.push_back(4); }
            if (list[click + 7].color == 1) { boardlist[click].flip.push_back(6); }
            if (list[click + 8].color == 1) { boardlist[click].flip.push_back(7); }
            if (list[click - 1].color == 1 || list[click + 7].color == 1 || list[click + 8].color == 1) { return true; }
        } else if (click == 56) {
            if (list[click - 8].color == 1) { boardlist[click].flip.push_back(2); }
            if (list[click - 7].color == 1) { boardlist[click].flip.push_back(3); }
            if (list[click + 1].color == 1) { boardlist[click].flip.push_back(4); }
            if (list[click - 8].color == 1 || list[click - 7].color == 1 || list[click + 1].color == 1) { return true; }
        } else if (click == 63) {
            if (list[click - 9].color == 1) { boardlist[click].flip.push_back(1); }
            if (list[click - 8].color == 1) { boardlist[click].flip.push_back(2); }
            if (list[click - 1].color == 1) { boardlist[click].flip.push_back(4); }
            if (list[click - 1].color == 1 || list[click - 8].color == 1 || list[click - 9].color == 1) { return true; }
        } ///corner cases
        else if (0 < click && click < 7) {
            if (list[click - 1].color == 1) { boardlist[click].flip.push_back(4); }
            if (list[click + 7].color == 1) { boardlist[click].flip.push_back(6); }
            if (list[click + 8].color == 1) { boardlist[click].flip.push_back(7); }
            if (list[click + 9].color == 1) { boardlist[click].flip.push_back(8); }
            if (list[click + 1].color == 1) { boardlist[click].flip.push_back(5); }
            if (list[click - 1].color == 1 || list[click + 8].color == 1 || list[click + 9].color == 1 ||
                list[click + 7].color == 1 || list[click + 1].color == 1) { return true; }
        } else if (56 < click && click < 63) {
            if (list[click - 1].color == 1) { boardlist[click].flip.push_back(4); }
            if (list[click - 9].color == 1) { boardlist[click].flip.push_back(1); }
            if (list[click - 8].color == 1) { boardlist[click].flip.push_back(2); }
            if (list[click - 7].color == 1) { boardlist[click].flip.push_back(3); }
            if (list[click + 1].color == 1) { boardlist[click].flip.push_back(5); }
            if (list[click - 1].color == 1 || list[click - 8].color == 1 || list[click - 9].color == 1 ||
                list[click - 7].color == 1 || list[click + 1].color == 1) { return true; }
        } else if (click == 8 || click == 16 || click == 24 || click == 32 || click == 40 || click == 48) { ///lhs
            if (list[click - 8].color == 1) { boardlist[click].flip.push_back(2); }
            if (list[click - 7].color == 1) { boardlist[click].flip.push_back(3); }
            if (list[click + 1].color == 1) { boardlist[click].flip.push_back(5); }
            if (list[click + 9].color == 1) { boardlist[click].flip.push_back(8); }
            if (list[click + 8].color == 1) { boardlist[click].flip.push_back(7); }
            if (list[click - 8].color == 1 || list[click - 7].color == 1 || list[click + 1].color == 1 ||
                list[click + 9].color == 1 || list[click + 8].color == 1) { return true; }
        }
        else if (click == 15 || click == 23 || click == 31 || click == 39 || click == 47 || click == 55) {
            if (list[click - 8].color == 1) { boardlist[click].flip.push_back(2); }
            if (list[click - 9].color == 1) { boardlist[click].flip.push_back(1); }
            if (list[click - 1].color == 1) { boardlist[click].flip.push_back(4); }
            if (list[click + 7].color == 1) { boardlist[click].flip.push_back(6); }
            if (list[click + 8].color == 1) { boardlist[click].flip.push_back(7); }
            if (list[click - 8].color == 1 || list[click - 9].color == 1 || list[click - 1].color == 1 ||
                list[click + 7].color == 1 || list[click + 8].color == 1) { return true; }
        }
        else {
            if (list[click + 1].color == 1) { boardlist[click].flip.push_back(5); }
            if (list[click + 8].color == 1) { boardlist[click].flip.push_back(7); }
            if (list[click + 9].color == 1) { boardlist[click].flip.push_back(8); }
            if (list[click - 1].color == 1) { boardlist[click].flip.push_back(4); }
            if (list[click + 7].color == 1) { boardlist[click].flip.push_back(6); }
            if (list[click - 9].color == 1) { boardlist[click].flip.push_back(1); }
            if (list[click - 8].color == 1) { boardlist[click].flip.push_back(2); }
            if (list[click - 7].color == 1) { boardlist[click].flip.push_back(3); }

            if (list[click - 9].color == 1 || list[click - 8].color == 1 || list[click - 7].color == 1 ||
                list[click - 1].color == 1 || list[click + 1].color == 1 ||
                list[click + 7].color == 1 || list[click + 8].color == 1 || list[click + 9].color == 1) {

                return true;
            }
        }
        }
        return false;
    }


/*void isadjacent(int click, vector<cells> list, int turn){ ///updates adjacent positions "flip"
    if (turn % 2 ==1) {
        if (click == 1){
            if (list[click+1].color == 2){boardlist[click].flip.push_back(5);}
            if (list[click+8].color == 2){boardlist[click].flip.push_back(7);}
            if (list[click+9].color == 2){boardlist[click].flip.push_back(8);}
            //if (list[click+1].color == 2 || list[click+8].color == 2 || list[click+9].color == 2) {return true;}
        }
        else if (click == 7){
            if (list[click-1].color == 2){boardlist[click].flip.push_back(4);}
            if (list[click+7].color == 2){boardlist[click].flip.push_back(6);}
            if (list[click+8].color == 2){boardlist[click].flip.push_back(7);}
        }
        else if (click == 56){
            if (list[click-8].color == 2){boardlist[click].flip.push_back(2);}
            if (list[click-7].color == 2){boardlist[click].flip.push_back(3);}
            if (list[click+1].color == 2){boardlist[click].flip.push_back(4);}
        }
        else if (click == 63){
            if (list[click-9].color == 2){boardlist[click].flip.push_back(1);}
            if (list[click-8].color == 2){boardlist[click].flip.push_back(2);}
            if (list[click-1].color == 2){boardlist[click].flip.push_back(4);}
        } ///corner cases
        else if ( 0 < click && click < 7){
            if (list[click-1].color == 2){boardlist[click].flip.push_back(4);}
            if (list[click+7].color == 2){boardlist[click].flip.push_back(6);}
            if (list[click+8].color == 2){boardlist[click].flip.push_back(7);}
            if (list[click+9].color == 2){boardlist[click].flip.push_back(8);}
            if (list[click+1].color == 2){boardlist[click].flip.push_back(5);}
        }
        else if ( 56 < click && click < 63){
            if (list[click-1].color == 2){boardlist[click].flip.push_back(4);}
            if (list[click-9].color == 2){boardlist[click].flip.push_back(1);}
            if (list[click-8].color == 2){boardlist[click].flip.push_back(2);}
            if (list[click-7].color == 2){boardlist[click].flip.push_back(3);}
            if (list[click+1].color == 2){boardlist[click].flip.push_back(5);}
        else if( click== 8 || click== 16 ||click== 24 ||click== 32 ||click== 40 || click == 48 ){ ///lhs
            if (list[click-8].color == 2){boardlist[click].flip.push_back(2);}
            if (list[click-7].color == 2){boardlist[click].flip.push_back(3);}
            if (list[click+1].color == 2){boardlist[click].flip.push_back(5);}
            if (list[click+9].color == 2){boardlist[click].flip.push_back(8);}
            if (list[click+8].color == 2){boardlist[click].flip.push_back(7);}}

        else if( click== 15 || click== 23 ||click== 31 ||click== 39 ||click== 47 || click == 55 ){
            if (list[click-8].color == 2){boardlist[click].flip.push_back(2);}
            if (list[click-9].color == 2){boardlist[click].flip.push_back(1);}
            if (list[click-1].color == 2){boardlist[click].flip.push_back(4);}
            if (list[click+7].color == 2){boardlist[click].flip.push_back(6);}
            if (list[click+8].color == 2){boardlist[click].flip.push_back(7);}}

        else{
            if (list[click+1].color == 2){boardlist[click].flip.push_back(5);}
            if (list[click+8].color == 2){boardlist[click].flip.push_back(7);}
            if (list[click+9].color == 2){boardlist[click].flip.push_back(8);}
            if (list[click-1].color == 2){boardlist[click].flip.push_back(4);}
            if (list[click+7].color == 2){boardlist[click].flip.push_back(6);}
            if (list[click-9].color == 2){boardlist[click].flip.push_back(1);}
            if (list[click-8].color == 2){boardlist[click].flip.push_back(2);}
            if (list[click-7].color == 2){boardlist[click].flip.push_back(3);}

            }
        }
    }

    else if (turn % 2 ==0) {
        if (click == 1) {
            if (list[click + 1].color == 1) { boardlist[click].flip.push_back(5); }
            if (list[click + 8].color == 1) { boardlist[click].flip.push_back(7); }
            if (list[click + 9].color == 1) { boardlist[click].flip.push_back(8); }
        } else if (click == 7) {
            if (list[click - 1].color == 1) { boardlist[click].flip.push_back(4); }
            if (list[click + 7].color == 1) { boardlist[click].flip.push_back(6); }
            if (list[click + 8].color == 1) { boardlist[click].flip.push_back(7); }
        } else if (click == 56) {
            if (list[click - 8].color == 1) { boardlist[click].flip.push_back(2); }
            if (list[click - 7].color == 1) { boardlist[click].flip.push_back(3); }
            if (list[click + 1].color == 1) { boardlist[click].flip.push_back(4); }
        } else if (click == 63) {
            if (list[click - 9].color == 1) { boardlist[click].flip.push_back(1); }
            if (list[click - 8].color == 1) { boardlist[click].flip.push_back(2); }
            if (list[click - 1].color == 1) { boardlist[click].flip.push_back(4); }
        } ///corner cases
        else if (0 < click && click < 7) {
            if (list[click - 1].color == 1) { boardlist[click].flip.push_back(4); }
            if (list[click + 7].color == 1) { boardlist[click].flip.push_back(6); }
            if (list[click + 8].color == 1) { boardlist[click].flip.push_back(7); }
            if (list[click + 9].color == 1) { boardlist[click].flip.push_back(8); }
            if (list[click + 1].color == 1) { boardlist[click].flip.push_back(5); }
        } else if (56 < click && click < 63) {
            if (list[click - 1].color == 1) { boardlist[click].flip.push_back(4); }
            if (list[click - 9].color == 1) { boardlist[click].flip.push_back(1); }
            if (list[click - 8].color == 1) { boardlist[click].flip.push_back(2); }
            if (list[click - 7].color == 1) { boardlist[click].flip.push_back(3); }
            if (list[click + 1].color == 1) { boardlist[click].flip.push_back(5); }
        } else if (click == 8 || click == 16 || click == 24 || click == 32 || click == 40 || click == 48) { ///lhs
            if (list[click - 8].color == 1) { boardlist[click].flip.push_back(2); }
            if (list[click - 7].color == 1) { boardlist[click].flip.push_back(3); }
            if (list[click + 1].color == 1) { boardlist[click].flip.push_back(5); }
            if (list[click + 9].color == 1) { boardlist[click].flip.push_back(8); }
            if (list[click + 8].color == 1) { boardlist[click].flip.push_back(7); }
        } else if (click == 15 || click == 23 || click == 31 || click == 39 || click == 47 || click == 55) {
            if (list[click - 8].color == 1) { boardlist[click].flip.push_back(2); }
            if (list[click - 9].color == 1) { boardlist[click].flip.push_back(1); }
            if (list[click - 1].color == 1) { boardlist[click].flip.push_back(4); }
            if (list[click + 7].color == 1) { boardlist[click].flip.push_back(6); }
            if (list[click + 8].color == 1) { boardlist[click].flip.push_back(7); }
        } else {
            if (list[click + 1].color == 1) { boardlist[click].flip.push_back(5); }
            if (list[click + 8].color == 1) { boardlist[click].flip.push_back(7); }
            if (list[click + 9].color == 1) { boardlist[click].flip.push_back(8); }
            if (list[click - 1].color == 1) { boardlist[click].flip.push_back(4); }
            if (list[click + 7].color == 1) { boardlist[click].flip.push_back(6); }
            if (list[click - 9].color == 1) { boardlist[click].flip.push_back(1); }
            if (list[click - 8].color == 1) { boardlist[click].flip.push_back(2); }
            if (list[click - 7].color == 1) { boardlist[click].flip.push_back(3); }
            }
        }
    }



*/

/*
bool isvalid(int click, int turn) {
    int x = click % 8;

    if (boardlist[click].flip.empty()) {
        cout << "false ";
        return false;
    }

    int flipSize = boardlist[click].flip.size();
    for (int v = 0; v < flipSize; v++) {
        int flipValue = boardlist[click].flip[v];

        if (flipValue == 4 || flipValue == 5) { // Leftward or Right
            int tilecheck = (flipValue == 4) ? click - 1 : click + 1;

            for (int h = 0; h < 8 - abs(x - (click % 8)); h++) {
                if ((boardlist[tilecheck].color == 2 && turn % 2 == 1) ||
                    (boardlist[tilecheck].color == 1 && turn % 2 == 0)) {
                    cout << "valid ";
                    return true;
                } else if (boardlist[tilecheck].color == 0) {
                    break;
                }

                tilecheck = (flipValue == 4) ? tilecheck - 1 : tilecheck + 1;
            }
        } else if (flipValue == 2 || flipValue == 7) { // Up or Down
            int tilecheck = (flipValue == 2) ? click - 8 : click + 8;

            for (int h = 0; h < 8 - abs((click / 8) - (tilecheck / 8)); h++) {
                if ((boardlist[tilecheck].color == 2 && turn % 2 == 1) ||
                    (boardlist[tilecheck].color == 1 && turn % 2 == 0)) {
                    cout << "valid ";
                    return true;
                } else if (boardlist[tilecheck].color == 0) {
                    break;
                }

                tilecheck = (flipValue == 2) ? tilecheck - 8 : tilecheck + 8;
            }
        }
    }

    cout << "false ";
    return false;
}
*/

bool validFlip(int click, int turn) {///updates adjacent positions that are valid fr "validflip"
    boardlist[click].validflip.clear();
    //cout << "FUNCTION ";
    /*int x = click % 8; int y = click /8;
    int lower; int higher;
    if (x < y){lower = x; higher = y;} else {lower = y; higher = x;}*/
    int turn_check;
    if (turn % 2 == 1 ){turn_check = 1;}
    else {turn_check = 2;}
    if (boardlist[click].flip.size() == 1) {
        return false;
    }
    else {
        for (int v = 1; v < boardlist[click].flip.size() + 1; v++) {
            int x = click % 8; int y = click /8;
            int lower; int higher;
            if (x < y){lower = x; higher = y;} else {lower = y; higher = x;}


            int flip = boardlist[click].flip[v];
            if (flip == 4){
                int check = click - 2;
                int validturn = 0;
                for (int h = 0; h < x - 1; h ++) {
                    if (boardlist[check].color == turn_check){
                        validturn += 1; break;
                    }
                    check -= 1;
                }
                if (validturn > 0){
                    boardlist[click].validflip.push_back(4);
                }}

            if (flip == 5){
                int check = click +2;
                int validturn = 0;
                for (int h = 0; h < 7 - 1 - x; h ++) {
                    if (boardlist[check].color == turn_check){
                        validturn += 1; break;
                    }
                    check += 1;
                }
                if (validturn > 0){
                    boardlist[click].validflip.push_back(5);
                }
            }

            if (flip == 7){
                int check = click +16;
                int validturn = 0;
                for (int h = 0; h < 7 -1 - y; h ++) {
                    if (boardlist[check].color == turn_check){
                        validturn += 1; break;
                    }
                    check += 8;
                }
                if (validturn > 0){
                    boardlist[click].validflip.push_back(7);
                }
            }
            if (flip == 2){
                int check = click - 16;
                int validturn = 0;
                for (int h = 0; h < y -1; h ++) {
                    if (boardlist[check].color == turn_check){
                        validturn += 1; break;
                    }
                    check -= 8;
                }
                if (validturn > 0){
                    boardlist[click].validflip.push_back(2);
                }
            }
            if(flip == 1){
                int check = click - 18;
                int validturn = 0;
                for (int h = 0; h < lower - 1; h ++) {
                    if (boardlist[check].color == turn_check){
                        validturn += 1; break;
                    }
                    check -= 9;
                }
                if (validturn > 0){
                    boardlist[click].validflip.push_back(1);
                }
            }
            if(flip == 3){
                x = 7-x; int iter;
                if (x < 7) { iter = x;} else { iter = y;}
                int check = click - 14;
                int validturn = 0;
                for (int h = 0; h < iter - 1; h ++) {
                    if (boardlist[check].color == turn_check){
                        validturn += 1; break;
                    }
                    check -= 7;
                }
                if (validturn > 0){
                    boardlist[click].validflip.push_back(3);
                }}
            if(flip == 6){
                y = 7-y; int iter;
                if (x < 7) { iter = x;} else { iter = y;}
                int check = click +14;
                int validturn = 0;
                for (int h = 0; h < iter - 1; h ++) {
                    if (boardlist[check].color == turn_check){
                        validturn += 1; break;
                    }
                    check += 7;
                }
                if (validturn > 0){
                    boardlist[click].validflip.push_back(6);
                }
            }
            if(flip == 8){
                y = 7-y;x = 7-x;
                int iter;
                if (x < 7) { iter = x;} else { iter = y;}
                int check = click +18;
                int validturn = 0;
                for (int h = 0; h < iter - 1; h ++) {
                    if (boardlist[check].color == turn_check){
                        validturn += 1; break;
                    }
                    check += 9;
                }
                if (validturn > 0){
                    boardlist[click].validflip.push_back(8);
                }
            }


            /*else if (turn % 2 == 0){
                if (flip == 4){
                    int check = click - 2;
                    int validturn = 0;
                    for (int h = 0; h < x - 1; h ++) {
                        if (boardlist[check].color == 2){
                            validturn += 1; break;
                        }
                        check -= 1;
                    }
                    if (validturn > 0){
                        boardlist[click].validflip.push_back(4);
                    }}

                if (flip == 5){
                    int check = click +2;
                    int validturn = 0;
                    for (int h = 0; h < 7 - 1 - x; h ++) {
                        if (boardlist[check].color == 2){
                            validturn += 1; break;
                        }
                        check += 1;
                    }
                    if (validturn > 0){
                        boardlist[click].validflip.push_back(5);
                    }
                }
            }*/

        }

    }
    if (boardlist[click].validflip.size() > 0){
        return true;}
}

bool gamecontinue(int turn){
    for (int click = 0; click < 64 ; click ++ ){
        if (boardlist[click].color == 0){

    if (isadjacent(click, boardlist, turn)){
        if (validFlip(click, turn)){
            return true;
        }
    }}}
    cout << "GAME OVER GAME OVER" ;
    return false;
}





bool isvalid(int click, int turn){ ///updates list of positions to be flipped

    int is_true = 0;

    if (boardlist[click].flip.size() == 1){cout << "firstFLIP" << boardlist[click].flip[0] ; return false;}


    ///NOTE TO ME
    ///IN THE FUTURE
    ///GO THRO AND FIX THE REST OF THE FLIPS LIKE
    ///I DID FOR NUMBER 4
    ///THE IS TRUE IS UPDATING TOO SOON BASED ON BASICALLY IF THERE IS AN ADJACENT VALUE AT ALL
    ///RATHER THAN STARTING BY CHECKING THE ONE AFTER THE ADJACENT

    else {
        for (int v = 0; v < boardlist[click].validflip.size() ; v++) {
            int x = click % 8; int y = click /8;
            int flip = boardlist[click].validflip[v];

            if (flip == 4) { ///leftward

                if (turn % 2 == 1) {///black piece turn
                    int tilecheck = click - 1;
                    int turns = 0;
                    for (int h = x; h > 0; h--) {
                        if (boardlist[tilecheck].color == 2) {
                            tilecheck -= 1;
                            turns += 1;
                        } else if (boardlist[tilecheck].color == 1) {
                            int number = click;
                            for (int i = 0; i < turns; i++) {
                                if (x > 1){
                                if (boardlist[number -2].color == 1) { is_true += 1; }
                                boardlist[click].turntiles.push_back(number - 1);
                                number -= 1;
                                //if (boardlist[number].color == 1) { is_true += 1; }
                            }}
                        }
                    }
                } else if (turn % 2 == 0) {
                    int tilecheck = click - 1;
                    int turns = 0;
                    for (int h = x; h > 0; h--) {
                        if (boardlist[tilecheck].color == 1) {
                            tilecheck -= 1;
                            turns += 1;
                        } else if (boardlist[tilecheck].color == 2) {
                            int number = click;
                            for (int i = 0; i < turns; i++) {if (x > 1){
                                if (boardlist[number -2].color == 2) { is_true += 1; }
                                boardlist[click].turntiles.push_back(number - 1);
                                number -= 1;
                            }}
                        }
                        //is_true += 1;}
                    }
                }
            } else if (flip == 5) { ///right
                if (turn % 2 == 1) {///black piece turn
                    int tilecheck = click + 1;
                    int turns = 0;
                    for (int h = x; h < 7; h++) {
                        if (boardlist[tilecheck].color == 2) {
                            tilecheck += 1;
                            turns += 1;
                        } else if (boardlist[tilecheck].color == 1) {
                            int number = click;
                            for (int i = 0; i < turns; i++) {
                                if ( x < 6){
                                if (boardlist[number +2].color == 1) { is_true += 1; }
                                boardlist[click].turntiles.push_back(number + 1);
                                number += 1;
                            }}
                        }
                    }
                } else if (turn % 2 == 0) {
                    int tilecheck = click + 1;
                    int turns = 0;
                    for (int h = x; h < 7; h++) {
                        if (boardlist[tilecheck].color == 1) {
                            tilecheck += 1;
                            turns += 1;
                        } else if (boardlist[tilecheck].color == 2) {
                            int number = click;
                            for (int i = 0; i < turns; i++) {if ( x < 6){
                                if (boardlist[number +2].color == 2) { is_true += 1; }
                                boardlist[click].turntiles.push_back(number + 1);
                                number += 1;
                            }}
                        }
                    }
                }
            } else if (flip == 2) { ///up
                int tilecheck = click - 8;
                int turns = 0;
                if (turn % 2 == 1) {///black piece turn
                    for (int h = y; h > 0; h--) {
                        if (boardlist[tilecheck].color == 2) {
                            tilecheck -= 8;
                            turns += 1;
                        } else if (boardlist[tilecheck].color == 1) {
                            int number = click;
                            for (int i = 0; i < turns; i++) { if (y >1){

                                if (boardlist[number -16].color == 1) { is_true += 1; }
                                boardlist[click].turntiles.push_back(number - 8);
                                number -= 8;
                            }
                        }}
                    }
                } else if (turn % 2 == 0) {

                    for (int h = y; h > 0; h--) {
                        if (boardlist[tilecheck].color == 1) {
                            tilecheck -= 8;
                            turns += 1;
                        } else if (boardlist[tilecheck].color == 2) {
                            int number = click;
                            for (int i = 0; i < turns; i++) { if (y >1){
                                if (boardlist[number -16].color == 2) { is_true += 1; }
                                boardlist[click].turntiles.push_back(number - 8);
                                number -= 8;
                                if (boardlist[number].color == 2) { is_true += 1; }
                            }
                        }}
                    }
                }
            } else if (flip == 7) { ///down

                if (turn % 2 == 1) {///black piece turn
                    int tilecheck = click + 8;
                    int turns = 0;
                    for (int h = y; h < 7; h++) {
                        if (boardlist[tilecheck].color == 2) {
                            tilecheck += 8;
                            turns += 1;
                        } else if (boardlist[tilecheck].color == 1) {
                            int number = click;
                            for (int i = 0; i < turns; i++) {
                                if (y < 6){
                                if (boardlist[number +16].color == 1) { is_true += 1; }
                                boardlist[click].turntiles.push_back(number + 8);
                                number += 8;
                            }
                        }}
                    }
                    //return false;
                } else if (turn % 2 == 0) {
                    int tilecheck = click + 8;
                    int turns = 0;
                    for (int h = y; h < 7; h++) {
                        if (boardlist[tilecheck].color == 1) {
                            tilecheck += 8;
                            turns += 1;
                        } else if (boardlist[tilecheck].color == 2) {
                            int number = click;
                            for (int i = 0; i < turns; i++) {
                                if (y < 6){
                                if (boardlist[number +16].color == 2) { is_true += 1; }
                                boardlist[click].turntiles.push_back(number + 8);
                                number += 8;
                            }
                        }}
                    }
                    //return false;
                }
            } else if (flip == 1) { ///topleft
                int iteration;
                if (y > x) { iteration = x; } else { iteration = y; }

                if (turn % 2 == 1) {///black piece turn
                    int tilecheck = click - 9;
                    int turns = 0;
                    for (int h = 0; h < iteration; h++) {
                        if (boardlist[tilecheck].color == 2) {
                            tilecheck -= 9;
                            turns += 1;
                        } else if (boardlist[tilecheck].color == 1) {
                            int number = click;
                            for (int i = 0; i < turns; i++) {
                                if (boardlist[number - 18].color == 1) { is_true += 1; }
                                boardlist[click].turntiles.push_back(number - 9);
                                number -= 9;
                            }
                        }
                    }
                    // return false;
                } else if (turn % 2 == 0) {
                    int tilecheck = click - 9;
                    int turns = 0;
                    for (int h = 0; h < iteration; h++) {
                        if (boardlist[tilecheck].color == 1) {
                            tilecheck -= 9;
                            turns += 1;
                        } else if (boardlist[tilecheck].color == 2) {
                            int number = click;
                            for (int i = 0; i < turns; i++) {
                                if (iteration > 1){
                                    if (boardlist[number-18].color == 2) { is_true += 1; }
                                boardlist[click].turntiles.push_back(number - 9);number -=9;
                            }}
                        }
                        //return false;
                    }
                }
            } else if (flip == 3) { ///topright
                x = 7 - x;
                int iteration;
                if (y > x) { iteration = x; } else { iteration = y; }
                int turns = 0;

                if (turn % 2 == 1) {///black piece turn
                    int tilecheck = click - 7;
                    for (int h = 0; h < iteration; h++) {
                        if (boardlist[tilecheck].color == 2) {
                            tilecheck -= 7;
                            turns += 1;
                        } else if (boardlist[tilecheck].color == 1) {
                            int number = click;
                            for (int i = 0; i < turns; i++) {
                                if (iteration >1) {
                                    if (click > 14 && boardlist[number - 14].color == 1) { is_true += 1; }
                                    boardlist[click].turntiles.push_back(number - 7);
                                    number -= 7;
                                }
                            }
                        }
                    }
                } else if (turn % 2 == 0) {
                    int tilecheck = click - 7;
                    for (int h = 0; h < iteration; h++) {
                        if (boardlist[tilecheck].color == 1) {
                            tilecheck -= 7;
                            turns += 1;
                        } else if (boardlist[tilecheck].color == 2) {
                            int number = click;
                            for (int i = 0; i < turns; i++) {
                                if (iteration >1) {
                                    if (click > 14 && boardlist[number - 14].color == 2) { is_true += 1; }
                                    boardlist[click].turntiles.push_back(number - 7);
                                    number -= 7;

                                }
                            }
                        }
                    }
                }
            }else if (flip == 6) { ///bottomleft
                y = 7 - y;
                int iteration;
                if (y > x) { iteration = x; } else { iteration = y; }
                int turns = 0;
                if (turn % 2 == 1) {///black piece turn
                    int tilecheck = click + 7;
                    for (int h = 0; h < iteration; h++) {
                        if (boardlist[tilecheck].color == 2) {
                            tilecheck += 7;
                            turns += 1;
                        } else if (boardlist[tilecheck].color == 1) {
                            int number = click;
                            for (int i = 0; i < turns; i++) {
                                boardlist[click].turntiles.push_back(number + 7);
                                number += 7;
                        }}
                    }
                } else if (turn % 2 == 0) {
                    int tilecheck = click + 7;
                    for (int h = 0; h < iteration; h++) {
                        if (boardlist[tilecheck].color == 1) {
                            tilecheck += 7;
                            turns += 1;
                        } else if (boardlist[tilecheck].color == 2) {
                            int number = click;
                            for (int i = 0; i < turns; i++) {
                                boardlist[click].turntiles.push_back(number + 7);
                                number += 7;
                        }}

                    }
                }
            } else if (flip == 8) { ///bottomright //CODE IT !!!!!1
                x = 7 - x;
                y = 7 - y;
                int iteration;
                int turns = 0;
                if (y > x) { iteration = x; } else { iteration = y; }

                if (turn % 2 == 1) {///black piece turn
                    int tilecheck = click + 9;
                    for (int h = 0; h < iteration; h++) {
                        if (boardlist[tilecheck].color == 2) {
                            tilecheck += 9;
                            turns += 1;
                        } else if (boardlist[tilecheck].color == 1) {
                            int number = click;
                            for (int i = 0; i < turns; i++) {
                                boardlist[click].turntiles.push_back(number + 9);
                                number += 9;
                            }
                        }
                    }
                } else if (turn % 2 == 0) {
                    int tilecheck = click + 9;
                    for (int h = 0; h < iteration; h++) {
                        if (boardlist[tilecheck].color == 1) {
                            tilecheck += 9;
                            turns += 1;
                        } else if (boardlist[tilecheck].color == 2) {
                            int number = click;
                            for (int i = 0; i < turns; i++) {
                                boardlist[click].turntiles.push_back(number +9);
                                number += 9;
                        } }
                    }
                }
            }

        }}
        if (boardlist[click].turntiles.size() > 0) {
            //cout << "__size__" << boardlist[click].turntiles.size() << "       ";
            return true;
        }
        else{ (boardlist[click].turntiles.clear());
            return false;}
        }





int white_turn(int turn){ //returns random valid position
    ///is adjacent and valid flip
    vector <int> validPositions ;
    for (int i = 0; i < 64 ; i++){
        if (boardlist[i].color == 0){
            if (isadjacent(i, boardlist, turn) && validFlip(i, turn) && isvalid(i, turn)){
                validPositions.push_back(i);
            }
        }
    }
    int returnIndex = rand() % validPositions.size();
    return validPositions[returnIndex];
}





        void drawvalid(int click) { ///updates a list of positions to flip according to clicked cell "turntiles"

        }

        vector<int> blankCells; // vector of addresses of all the blank tiles adjacent


        void DrawSquare(board boardy, vector<cells> boardlist) { //, int a){
            for (int a = 0; a < 64; a++) {
                if (boardlist[a].color == 0) {
                    //cout << boardlist[a].address << endl;
                    Sprite blank;
                    Texture blankt;
                    blankt.loadFromFile("blank50.png");
                    blank.setTexture(blankt);
                    int posx = (a) % 64;
                    posx *= 50;
                    int posy = (a) / 64;
                    posy *= 50;
                    blank.setPosition(posx, posy);
                    //gameWindow.draw(boardlist[a].num);
                } else if (boardlist[a].color == 1) {
                    //cout << boardlist[a].address << endl;
                    Sprite blank;
                    Texture blankt;
                    blankt.loadFromFile("blacktile50.png");
                    blank.setTexture(blankt);
                    int posx = (a) % 64;
                    posx *= 50;
                    int posy = (a) / 64;
                    posy *= 50;
                    blank.setPosition(posx, posy);
                    //gameWindow.draw(boardlist[a].num);
                } else if (boardlist[a].color == 2) {
                    //cout << boardlist[a].address << endl;
                    Sprite blank;
                    Texture blankt;
                    blankt.loadFromFile("whitetile50.png");
                    blank.setTexture(blankt);
                    int posx = (a) % 64;
                    posx *= 50;
                    int posy = (a) / 64;
                    posy *= 50;
                    blank.setPosition(posx, posy);
                    //gameWindow.draw(boardlist[a].num);
                }
            }
        }

        Sprite assignbase(board
                          boardy, vector<int>
                          bombcells, int
                          e) {
            Sprite number;
            Texture tbomb;
            tbomb.loadFromFile("tile_revealed.png");
            number.setTexture(tbomb);
            int posxx = (e) % boardy.columns;
            posxx *= 32;
            int posyy = (e) / boardy.columns;
            posyy *= 32;
            number.setPosition(posxx, posyy);
            return number;
            //gameWindow.draw(number);

            //DrawSquare(boardy, bombcells);
            //boardlist[e].num.setTexture(boardlist[e].tnum);
            //gameWindow.draw(boardlist[e].num);
        }
