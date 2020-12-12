#include <iostream>
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
            if (word.size() == N) {
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

    int N; string str;
    cout << "Введите строку: "; getline(cin, str);
    cout << "Введите N: "; cin >> N;

    vector<string> words = getWords(N, str);

    cout << endl;
    cout << "Найдено " << words.size() << " слов(а) длины " << N << ": [";
    for (int i = 0; i < words.size(); i++){
        cout << " \"" << words[i] << "\" ";;
    }
    cout << "]"<< endl;
    cout << endl;
}
