#include <iostream>
#include <string>
using namespace std;

bool IsKPeriodic(const string& str, int K) {
    int n = str.size();

    // ���� K <= 0 ��� ����� ������ �� ������� �� K, ����� ���������� false
    if (K <= 0 || n % K != 0) {
        return false;
    }

    // �������� ������ ��������� ������ K
    string pattern = str.substr(0, K);

    // ���������, ������� �� ��� ������ �� ���������� ���� ���������
    for (int i = K; i < n; i += K) {
        if (str.substr(i, K) != pattern) {
            return false;  // ���� ������� ��������������, ���������� false
        }
    }

    return true; // ���� ��� �������� ��������, ������ �������� K-�������
}

int main() {
    string str1 = "abcabcabcabc";
    int K1 = 3;
    cout << (IsKPeriodic(str1, K1) ? "true" : "false") << endl;  // ��������� �����: true

    string str2 = "abcdabcd";
    int K2 = 4;
    cout << (IsKPeriodic(str2, K2) ? "true" : "false") << endl;  // ��������� �����: true

    string str3 = "abcabcabc";
    int K3 = 4;
    cout << (IsKPeriodic(str3, K3) ? "true" : "false") << endl;  // ��������� �����: false

    return 0;
}
