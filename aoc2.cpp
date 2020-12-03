#include <bits/stdc++.h>

using namespace std;


int main(){

    char col, dash, find_char;
    int v1, v2;
    string str;
    int sum;

    std::string line;
    while (std::getline(std::cin, line))
    {
        stringstream ss(line);
        ss >> v1 >> dash >> v2 >> find_char >> col >> str;
        //cout << v1 << v2 << find_char<< str << endl;  
        
        /* Part 1 */
/*
        int occ = 0;
        for(int i = 0; i < str.length(); i++){
            if(str[i] == find_char){
                occ++;
            }
        }
        if(occ >= v1 && occ <= v2){
            sum++;
        }
*/

        /* Part 2 */
        if(!(str[v1-1] == find_char) == (str[v2-1] == find_char)){
            sum++;
        }
    }

    cout << sum << endl; 

    return 0;
}