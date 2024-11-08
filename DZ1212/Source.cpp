#include <iostream>
#include <string>
using namespace std;

bool IsKPeriodic(const string& str, int K) {
    int n = str.size();

    // Если K <= 0 или длина строки не делится на K, сразу возвращаем false
    if (K <= 0 || n % K != 0) {
        return false;
    }

    // Получаем первую подстроку длиной K
    string pattern = str.substr(0, K);

    // Проверяем, состоит ли вся строка из повторений этой подстроки
    for (int i = K; i < n; i += K) {
        if (str.substr(i, K) != pattern) {
            return false;  // Если находим несоответствие, возвращаем false
        }
    }

    return true; // Если все проверки пройдены, строка является K-кратной
}

int main() {
    string str1 = "abcabcabcabc";
    int K1 = 3;
    cout << (IsKPeriodic(str1, K1) ? "true" : "false") << endl;  // Ожидаемый вывод: true

    string str2 = "abcdabcd";
    int K2 = 4;
    cout << (IsKPeriodic(str2, K2) ? "true" : "false") << endl;  // Ожидаемый вывод: true

    string str3 = "abcabcabc";
    int K3 = 4;
    cout << (IsKPeriodic(str3, K3) ? "true" : "false") << endl;  // Ожидаемый вывод: false

    return 0;
}
