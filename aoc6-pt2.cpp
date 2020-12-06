#include <bits/stdc++.h>

using namespace std;


int main(){
    int sum = 0;
    int it = 0;
    int sum_nf = 0;

    vector<vector<char>> set_vec;

    /* Debug */
    int sum_prev = 0;


    std::string line;
    while (std::getline(std::cin, line))
    {
        if(line == ""){
            sum_prev = sum;

            if(it == 1){
                sum += set_vec[it-1].size();
            }else{
                for(int k = 0; k < set_vec[0].size(); k++){
                    for(int j = 1; j < it; j++){
                        if(find(set_vec[j].begin(), set_vec[j].end(), set_vec[0][k]) != set_vec[j].end()){
                            sum_nf++;
                        }
                    }
                    if(sum_nf == set_vec.size()-1){
                    sum ++;
                    }
                    sum_nf = 0;
                }
            }

            set_vec.clear();
            sum_nf = 0;
            it = 0;
            continue;
        }


        vector<char> temp;
        set_vec.push_back(temp);

        for(int i = 0; i < line.length(); i++){
            set_vec[it].push_back(line[i]);
        }
        it++;
    } 


    if(cin.eof()){
        if(it == 1){
            sum += set_vec[it-1].size();
        }else{
            for(int k = 0; k < set_vec[0].size(); k++){
                for(int j = 1; j < it; j++){
                    if(find(set_vec[j].begin(), set_vec[j].end(), set_vec[0][k]) != set_vec[j].end()){
                        sum_nf++;
                    }
                }

                if(sum_nf == set_vec.size()-1){
                    sum ++;
                }
                sum_nf = 0;
            }
        }
    }

    cout << sum << endl;    

    return 0;
}