#include <iostream>
#include <string>
using namespace std;

int main(){
    string octal_str, binary_str = "";
    
    cin >> octal_str;
    for(int i = 0; i < octal_str.size(); i++){
        switch (octal_str[i]){
            case '0':
                if(i == 0){
                    binary_str += "0";
                    break;
                }
                else{
                    binary_str += "000";
                    break;
                }
            case '1':
                if(i == 0){
                    binary_str += "1";
                    break;
                }
                else{
                    binary_str += "001";
                    break;
                }
            case '2':
                if(i == 0){
                    binary_str += "10";
                    break;
                }
                else{
                    binary_str += "010";
                    break;
                }
            case '3':
                if(i == 0){
                    binary_str += "11";
                    break;
                }
                else{
                    binary_str += "011";
                    break;
                }
            case '4':
                binary_str += "100";
                break;
            case '5':
                binary_str += "101";
                break;
            case '6':
                binary_str += "110";
                break;
            case '7':
                binary_str += "111";
                break;
        }
    }
    cout << binary_str;
    return 0;
}