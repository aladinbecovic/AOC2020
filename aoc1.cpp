#include <bits/stdc++.h>

using namespace std;


int main(){
    std::string line;
    vector<int> input_vector;

    while (std::getline(std::cin, line))
    {
        std::cout << line << std::endl;
        input_vector.push_back(stoi(line));
    } 


    u_int num_input = input_vector.size();
    
    /* Part 1 */
    for(int i = 0; i < num_input; i++){
        for(int j = i + 1; j < num_input; j++){
            if(input_vector[i] + input_vector[j] == 2020){
                cout << input_vector[i] * input_vector[j] << endl;
                break;
            }
        }
    }

    /* Part 2 */
    for(int i = 0; i <= num_input; i++){
        for(int j = i + 1; j <= num_input; j++){
            for(int k = j + 1; k <= num_input; k++){
                if(input_vector[i] + input_vector[j] + input_vector[k] == 2020){
                    cout << input_vector[i] * input_vector[j] * input_vector[k] << endl;
                    break;
                }
            }
        }
    }

    return 0;
}

// g++ -std=c++11 -O2 -Wall template.cpp -o template