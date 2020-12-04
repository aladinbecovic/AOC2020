#include <bits/stdc++.h>

using namespace std;

vector<string> input_vector;

vector<string> must_contain ={"byr:", "iyr:", "eyr:", "hgt:", "hcl:", "ecl:", "pid:"};

int main(){
    string line;
    string passport;

    int target_num = must_contain.size();
    int occ = 0;
    int sum = 0;

    while (std::getline(std::cin, line))
    {
        if(line == ""){
            if(occ == target_num){ 
                sum++;
            }
            occ = 0;
        }else{
            for(int i = 0; i < target_num; i++){
                if(line.find(must_contain[i]) != string::npos){
                    occ++;
                }
            }
        }
    }
    if(cin.eof()){
        if(occ == target_num){ 
            sum++;
        }
    }

    cout << sum << endl;

    return 0;
}