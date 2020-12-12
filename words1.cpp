#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> getWords(int N, string str) {
    vector<string> words;
    string word = "";
    
    for (auto x : str) {

        if ((x == '.') || (x == ',') || (x == '!') || (x == '?') || (x == '-') || (x == ':') || (x == ';')) {
            continue;
        }

        if (x == ' ') {
            if (word.length() == N) {
                words.push_back(word);
            }
            word = "";
            continue;
        } else {
            word = word + x;
        }
    }
    if (word.size() == N) {
        words.push_back(word);
    }    
    return words;
}

int main() {
    fstream textFile;
    int N;
    int Nstring;
    string str;
    vector<string> words;
    int testCounter = 1;
    textFile.open("input.txt", ios::in);

    if (textFile.is_open()) {
        while(getline(textFile, str)){            
            try {
                N = stoi(str.substr(2, 2));
            } catch(std::invalid_argument& e){
                N = 3;
            } catch(std::out_of_range& e){
                N = 3;
            }
            if (str.size() == 0 ) {
                continue;
            }
            string testString = str.substr(5, str.size()-1);            
            words = getWords(N, testString);
            
            cout << "Тест " << testCounter << ":" << endl;
            cout << "      Строка = \"" << testString << "\"" << endl;
            cout << "      N      = "   << N << endl;
            cout << "      Массив  = [";
            for (int i = 0; i < words.size(); i++){
                cout << " \"" << words[i] << "\" ";;
            }
            cout << "]"<< endl;
            cout << endl;

            testCounter++;
        }
        textFile.close();
    }

    cout << "Введите вашу строку: "; getline(cin, str);
    cout << "Введите N: "; cin >> N;
    words = getWords(N, str);

    cout << endl;
    cout << "Тест " << testCounter << ":" << endl;
    cout << "      Строка = \"" << str << "\"" << endl;
    cout << "      N      = "   << N << endl;
    cout << "      Массив  = [";
    for (int i = 0; i < words.size(); i++){
        cout << " \"" << words[i] << "\" ";;
    }
    cout << "]"<< endl;
    cout << endl;

    system("pause");
}
