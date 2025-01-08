#include<bits/stdc++.h>

using namespace std;

// Nếu số ký tự nằm trước ký tự
string decoding(string& input){
    string decode = "";
    int n = input.length();
    for(int i = 0; i < n; i++){
        string temp = "";

        if (input[i] == ' ') {
            decode += ' ';
            continue;
        }

        while(i < n && isdigit(input[i])){
            temp += input[i];
            i++;
        }

        if (i >= n || !isalpha(input[i]) || (i + 1 < n && isalpha(input[i + 1]))) {
            return "Dau vao bi loi";
        }

        int count = stoi(temp);
        char character = input[i];

        for(int j = 0; j < count; j++){
            decode += character;
        }
    }
    return decode;
}

// Nếu số ký tự nằm sau ký tự 
string decoding2(string& input){
    string decode = "";
    int n = input.length();

    for(int i = 0; i < n; i++){
        char character = input[i];
        i++;
        string temp = "";

        if (character == ' ') {
            decode += ' ';
            continue;
        }

        while(i < n && isdigit(input[i])){
            temp += input[i];
            i++;
        }

        if(temp.empty() || i > n){
            return "Dau vao bi loi";
        }

        int count = stoi(temp);
        for(int j = 0; j < count; j++){
            decode += character;
        }
        i--;
    }
    return decode;
}

int main(){
    cout << "Nhap chuoi can giai ma: ";
    string input;
    getline(cin, input);
    cout << "Sau khi giai ma: ";
    if(isdigit(input[0])) cout << decoding(input);
    else cout << decoding2(input);
    return 0;
}