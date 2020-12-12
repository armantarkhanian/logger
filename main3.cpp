#include <iostream>
#include <cstring>

using namespace std;

bool isDelimiter(char s) {
    return s == ' ' || s == ',' || s == '.' || s == '!' ||
        s == '?' || s == ':' || s == ';';
}

int main() {

    int count = 0, word_l;

    const int size_word = 20; //Максимальный размер слова
    const int count_words = 10; //Максимальное кол-во слов
    const int size_str = 80; //Максимальная длина строки
    char s[size_str];
    char words[count_words][size_word];

    cout << "Введите строку: ";
    cin.get(s, size_word);
    cout << endl;

    cout << "Введите размер слов, которые вы хотите вывести: ";
    cin >> word_l;
    cout << endl;


    char* ps = s; //pointer s
    char* pss = 0; //pointer start s - указатель на начало слова
    int size = 0;
    while (*ps != '\0') {
        //Пропускаем знаки препинания и пробелы
        while (*ps != '\0' && isDelimiter(*ps)) ++ps;

        //Подсчитываем длину найденного слова
        size = 0;
        pss = ps;
        while (*ps != '\0' && !isDelimiter(*ps)) {
            ++size;
            ++ps;
        }

        //Подсчитываем кол-во слов, длина которых = word_l и копируем в массив слов
        if (size == word_l) {
            strncpy(*(words + count), pss, word_l);
            ++count;
        }
    }

    for (int i = 0; i < count; ++i)
        cout << words[i] << endl;

}
