#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class Sqlist :public vector<T>
{
public:
	//size,empty,clear,erase�Ƚӿڿ���ֱ����
	void creat(T a[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			(*this).push_back(a[i]);
		}
	}
	void print()
	{
		for (int i = 0; i < (*this).size(); i++)cout << (*this)[i] << ' ';
		cout << endl;
	}
	int locelm(T elm)
	{
		int i = 0;
		while ((*this)[i] != elm)
		{
			i++;
		}
		return i;
	}
	
};

int main()
{
	char a[5] = { 'a','b','c','d','e' };
	Sqlist <char> L;
	L.creat(a, 5);
	L.print();
	cout << "˳�����Ϊ: " << L.size() << endl;
	if (L.empty())cout << "��ǰ״̬Ϊ����" << endl;
	else cout<< "��ǰ״̬Ϊ���ǿ�" << endl;
	cout << "������Ԫ��Ϊ:" << L[2] << endl;
	cout << "aԪ�ص�λ��Ϊ��" << L.locelm('a') << endl;
	L.insert(L.begin()+3,'f');
	cout << "��������Ϊ��"; L.print();cout << endl;
	L.erase(L.begin()+2);
	cout << "��������Ϊ��"; L.print(); cout << endl;
	L.clear();
	return 0;
}