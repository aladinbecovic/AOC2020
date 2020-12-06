#include <bits/stdc++.h>

using namespace std;


int main(){
    set<int> answer_set;
    int sum = 0;

    vector<set<int>> set_vec;

    std::string line;
    while (std::getline(std::cin, line))
    {
        if(line == ""){
            sum += answer_set.size();
            answer_set.clear();
        }

        for(int i = 0; i < line.length(); i++){
            answer_set.insert(line[i]);
        }
    } 

    if(cin.eof()){
        sum += answer_set.size();
    }

    cout << sum << endl;

    return 0;
}