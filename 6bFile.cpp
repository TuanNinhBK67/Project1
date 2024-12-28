#include<bits/stdc++.h>
#include<fstream>

using namespace std;

// Nếu số ký tự nằm trước ký tự
string decoding(string& input){
    string decode = "";
    int n = input.length();
    for(int i = 0; i < n; i++){
        string temp = "";
        while(isdigit(input[i])){
            temp += input[i];
            i++;
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

        while(i < n && isdigit(input[i])){
            temp += input[i];
            i++;
        }

        int count = stoi(temp);
        for(int j = 0; j < count; j++){
            decode += character;
        }
        i--;
    }
    return decode;
}

void writeFile(const string& filename,const string& data){
    ofstream outputFile(filename);

    if(outputFile){
        outputFile << data;
        outputFile.close();
    }
    else{
        cout << "Khong the ghi vao file";
    }
}

int main(){
    ifstream inputFile("input.txt");
    string data, line;
    if(inputFile){
        while(getline(inputFile, line)){
            data += line;
        }
        inputFile.close();
    }
    else{
        cout << "Khong the mo file";
    }
    string encode;
    if(isdigit(data[0])){
        encode = decoding(data);
    }
    else{
        encode = decoding2(data);
    }
    writeFile("output.txt", encode);
    
    return 0;
}