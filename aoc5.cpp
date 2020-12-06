#include <bits/stdc++.h>

using namespace std;

int main(){
    std::string line;
    int row_a = 0;
    int row_b = 0;
    int row = 0;

    int col_a = 0;
    int col_b = 0;
    int col = 0;

    int res = 0;

    int max_id = 0;
    int curr_id = 0;

    char seat_list[128][8];

    while (std::getline(std::cin, line))
    {   
        row_a = 0;
        row_b = 127;
        col_a = 0;
        col_b = 7;
        for(int i = 0; i < line.length(); i++){
            switch(line[i]){
                case 'F':
                    res = (row_b-(row_a-1))/2;
                    row_b = row_b - res;
                    if(i == 6){
                        row = row_b;
                    }
                    break;
                case 'B':
                    res = (row_b-(row_a+1))/2;
                    row_a = row_b - res;
                    if(i == 6){
                        row = row_a;
                    }
                    break;
                case 'L':
                    res = (col_b-(col_a-1))/2;
                    col_b = col_b - res;
                    if(i == 9){
                        col = col_b;
                    }
                    break;
                case 'R':
                    res = (col_b-(col_a+1))/2;
                    col_a = col_b - res;
                    if(i == 9){
                        col = col_a;
                    }
                    break;
            }
        }
        seat_list[row][col] = 'X';
        curr_id = row * 8 + col;
        if(curr_id > max_id){
            max_id = curr_id;
        }
    } 
    for(int r = 0; r < 128; r++){
        for(int c = 0; c < 8; c++){
            if(seat_list[r][c] != 'X'){
                seat_list[r][c] = 'O';
            }
            if(seat_list[r][c] == 'O' && seat_list[r][c-1] == 'X'){
                cout << (r*8+c) << endl;
            }
        }
    }
    return 0;
}