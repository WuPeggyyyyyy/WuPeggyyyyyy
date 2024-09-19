#include <iostream>
#include <string>
using namespace std;

int main(){
 
	int x; //名字的數量 
	int len=0; //名字的字串長度 
	int max=0; //最長名字（在空格前的部分）的長度
	int space[x];
	
	cout << "Input x(number of people):" << endl;
	cin >> x;
	cin.ignore();//忽略換行符 \n 

	string *name = new string[x];
    
	//依序輸入每個名字 
	for (int i = 0; i < x; i++){
    	cout << "Person" << i+1 << ": ";
        getline(cin, name[i]);
        len = name[i].length();
        //計算到空格之前的字母長度 
        for (int j = 0; j < len; j++){
            if (name[i][j] == ' '){
                space[i] = j; //記錄名字長度
                
                //判斷是否為前段名字最長的輸入
                if (j > max){
                    max = j;
                }
                break;
            }
        }
    }
	cout<<endl;
	
    //將名字重新打印出來 
	for(int i=0;i<x;i++){
		//在打出名字前用空格填充使名字對齊 
		for(int j=0;j<max-space[i];j++){
   
			cout<<" ";
		}
  
		cout<<name[i]<<endl;
  
	}
 
	delete [] name;
    
 	return 0;
   
}
