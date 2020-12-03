#include <bits/stdc++.h>

using namespace std;

vector<string> input_vector;

int main(){
    std::string line;
    while (std::getline(std::cin, line))
    {
        input_vector.push_back(line);
    } 
    u_int num_input = input_vector.size();
    u_int line_len = input_vector[10].length();

    u_int col = 0;
    u_int row = 0;

    u_int trees = 0;

    /* part 2 */

    vector<int> row_vector = {1, 1, 1, 1, 2};
    vector<int> col_vector = {1, 3, 5, 7, 1};
    u_int sum = 0;

    /* Part 2 */
    for(int it = 0; it < row_vector.size(); it++){
        col = 0;
        row = 0;
        /* Part 1 and 2 */
        for(int i = 0; i < num_input; i++){
            col += col_vector[it];
            row += row_vector[it];

            if(col > (line_len - 1)){
                col -= (line_len);
            }

            if(input_vector[row][col] == '#'){
                trees++;
            }

            if(row > num_input - row_vector[it] - 1){
                break;
            }
        }

        if(sum == 0){
            sum = trees;
        }else{
            sum *= trees;
        }
        trees = 0;
    }


    cout << sum << endl;

    return 0;
}