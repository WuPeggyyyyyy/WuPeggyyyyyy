#include <iostream>
#include <string>
using namespace std;

int main(){
 
	int x; //�W�r���ƶq 
	int len=0; //�W�r���r����� 
	int max=0; //�̪��W�r�]�b�Ů�e�������^������
	int space[x];
	
	cout << "Input x(number of people):" << endl;
	cin >> x;
	cin.ignore();//��������� \n 

	string *name = new string[x];
    
	//�̧ǿ�J�C�ӦW�r 
	for (int i = 0; i < x; i++){
    	cout << "Person" << i+1 << ": ";
        getline(cin, name[i]);
        len = name[i].length();
        //�p���Ů椧�e���r������ 
        for (int j = 0; j < len; j++){
            if (name[i][j] == ' '){
                space[i] = j; //�O���W�r����
                
                //�P�_�O�_���e�q�W�r�̪�����J
                if (j > max){
                    max = j;
                }
                break;
            }
        }
    }
	cout<<endl;
	
    //�N�W�r���s���L�X�� 
	for(int i=0;i<x;i++){
		//�b���X�W�r�e�ΪŮ��R�ϦW�r��� 
		for(int j=0;j<max-space[i];j++){
   
			cout<<" ";
		}
  
		cout<<name[i]<<endl;
  
	}
 
	delete [] name;
    
 	return 0;
   
}
