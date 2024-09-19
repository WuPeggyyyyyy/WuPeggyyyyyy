#include <iostream>
#include <string>
using namespace std;

int main() {
    int x, y;
    cout << "Input x (number of strings) and y (maximum string length): " << endl;
    cin >> x >> y;

    // �ʺA���t�G���}�C�Ӧs��r��
    char **name = new char*[x];  
    for (int i = 0; i < x; i++) {
        name[i] = new char[y + 1];  // +1 �O���F�� \0
    }

    // �x�s�C�Ӧr�ꪺ��ڪ���
    int *size = new int[x];

    // �M�ſ�J�w�İ�(�q�`�O����� \n)�A�קK cin �M getline ���Ĭ�
    cin.ignore();

    // ���ϥΪ̿�J�r��
    for (int i = 0; i < x; i++) {
        cout << "Input string " << i + 1 << ": ";
        string temp;
        getline(cin, temp); //getline()�|�q cin Ū����ơA����J�촫��� \n �Τ�󵲧��]EOF�^ 

        // �T�O��J���r����פ��W�L y
        while (temp.size() > y) {
            cout << "String cannot exceed " << y << " letters. Please try again: ";
            getline(cin, temp);
        }

        // �ƻs�r���ʺA���t�� char �}�C
        size[i] = temp.size();
        for (int j = 0; j < temp.size(); j++) {
            name[i][j] = temp[j];
        }
        name[i][temp.size()] = '\0';  // �r�굲����m \0�A�����аO 
    }

    // �ھڦr�ꪺ���r���ϥ�bubble sort�Ƨ�
    for (int i = 0; i < x - 1; i++) {
        for (int j = 0; j < x - 1 - i; j++) {
            if (name[j][0] > name[j + 1][0]) {
                // �洫�r��
                char *temp = name[j];
                name[j] = name[j + 1];
                name[j + 1] = temp;
            }
        }
    }

    // ��X�Ƨǫ᪺�r��
    cout << "After sorting by the first letter:\n";
    for (int i = 0; i < x; i++) {
        cout << name[i] << endl;
    }

    // ����ʺA�O����
    delete[] size;
    for (int i = 0; i < x; i++) {
        delete[] name[i];
    }
    delete[] name;

    return 0;
}

