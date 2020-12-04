#include <bits/stdc++.h>

using namespace std;

vector<string> input_vector;

vector<string> eye_clr = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
vector<string> must_contain ={"byr:", "iyr:", "eyr:", "hgt:", "hcl:", "ecl:", "pid:"};

vector<regex> reg_vec= {regex("(byr:)(\\d{4})"),
                        regex("(iyr:)(\\d{4})"),
                        regex("(eyr:)(\\d{4})"),
                        regex("(hgt:)(\\d{2,3})(cm|in)"),
                        regex("hcl:#[a-f0-9]{6}"),
                        regex("(ecl:)(\\w{3})"),
                        regex("pid:\\d{9}")};



int main(){
    string line;
    string passport;
    smatch m;

    int sti = 0;

    int target_num = must_contain.size();
    int occ = 0;
    int sum = 0;
    int sum2 = 0;
    int matches = 0;

    while (std::getline(std::cin, line))
    {
        if(line == ""){
            if(occ == target_num){ 
                sum++;
            }
            if(matches == target_num){
                sum2++;
            }
            matches = 0;
            occ = 0;
        }else{
            for(int i = 0; i < target_num; i++){
                if(line.find(must_contain[i]) != string::npos){
                    occ++;
                    if(regex_search(line, m, reg_vec[i])){
                        if(i >= 0 && i < 3){
                                sti = stoi(m.str(2));
                            if(i == 0){
                                if(sti >= 1920 && sti <=2002){
                                    matches++;
                                }
                            }else if(i == 1){
                                if(sti >= 2010 && sti <=2020){
                                    matches++;
                                }
                            }else{
                                if(sti >= 2020 && sti <=2030){
                                    matches++;
                                }
                            }
                        }else if(i == 3){
                            sti = stoi(m.str(2));
                            if(m.str(3) == "cm"){
                                if(sti >= 150 && sti <= 193){
                                    matches++;
                                }
                            }else{
                                if(sti >= 59 && sti <= 76){
                                    matches++;
                                }
                            }                           
                        }else if(i == 4){
                            matches++;
                        }else if(i == 5){
                            for(int ec = 0; ec < eye_clr.size(); ec++){
                                if(eye_clr[ec] == m.str(2)){
                                    matches++;
                                    break;
                                }
                            }
                        }else{
                            matches++;
                        }
                    }
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
    cout << sum2 << endl;

    return 0;
}