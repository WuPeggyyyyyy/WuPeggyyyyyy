#include <iostream>
#include <cstdlib>  // for malloc, free
using namespace std;

int main() {
    int x, y;
    cout << "Input x (number of strings) and y (maximum string length): " << endl;
    cin >> x >> y;

	// 使用 malloc 動態分配記憶體
    char **name = (char**)malloc(x * sizeof(char*));  // 分配指標陣列
    for (int i = 0; i < x; i++) {
        name[i] = (char*)malloc((y + 1) * sizeof(char));  // 為每個字串分配記憶體 (+1 是為了存放 '\0')
    }

    // 儲存每個字串的實際長度
    int *size = (int*)malloc(x * sizeof(int));  // 分配大小陣列 

    // 清空輸入緩衝區(通常是換行符 \n)，避免 cin 和 getline 的衝突
    cin.ignore();

    // 讓使用者輸入字串
    for (int i = 0; i < x; i++) {
        cout << "Input string " << i + 1 << ": ";
        string temp;
        getline(cin, temp); //getline()會從 cin 讀取資料，直到遇到換行符 \n 或文件結尾（EOF） 

        // 確保輸入的字串長度不超過 y
        while (temp.size() > y) {
            cout << "String cannot exceed " << y << " letters. Please try again: ";
            getline(cin, temp);
        }

        // 複製字串到動態分配的 char 陣列
        size[i] = temp.size();
        for (int j = 0; j < temp.size(); j++) {
            name[i][j] = temp[j];
        }
        name[i][temp.size()] = '\0';  // 字串結尾放置 \0，結尾標記 
    }

    // 根據字串的首字母使用bubble sort排序
    for (int i = 0; i < x - 1; i++) {
        for (int j = 0; j < x - 1 - i; j++) {
            if (name[j][0] > name[j + 1][0]) {
                // 交換字串
                char *temp = name[j];
                name[j] = name[j + 1];
                name[j + 1] = temp;
            }
        }
    }

    // 輸出排序後的字串
    cout << "After sorting by the first letter:\n";
    for (int i = 0; i < x; i++) {
        cout << name[i] << endl;
    }

    // 釋放動態記憶體
    free(size);
    for (int i = 0; i < x; i++) {
        free(name[i]);
    }
    free(name);

    return 0;
}

