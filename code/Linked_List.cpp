#include <iostream>
using namespace std;

typedef char Datatype;
class Node
{
public:
	Datatype key;
	Node* next;
};

class linklist
{
public:
	linklist(); //����һ��������
	~linklist(); //���ٵ�����
	void creatlist(Datatype a[], int n);//β�巨
	void print();  //���������
	int getlen(); //�õ�����ĳ���
	bool isempty(); //�ж��Ƿ�Ϊ��
	Datatype getelm(int i); //��λ�ò���Ԫ��
	int locate(Datatype e); //��ֵ����Ԫ��λ��
	bool insert(Datatype elm, int i); //��ָ��λ�ò���Ԫ��
	bool Delete(int i); //ɾ��ָ��λ��Ԫ��

private:
	Node *head;
};

linklist::linklist()  //��ʼ��
{
	head = new Node;
	head->key = NULL;
	head->next = NULL;
}
linklist::~linklist() //ɾ�����н��
{
	Node *temp;
	head = head->next;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	delete head;
	cout << "�����ڴ����ͷ�" << endl;
}

void linklist::creatlist(Datatype a[], int n) 
{
	Node *tail = head;//ָ��β���
	for (int i = 0; i < n; i++)
	{
		Node *temp = new Node;
		temp->key = a[i];
		tail->next = temp;
		tail = temp;
	}
	tail->next = NULL;
}

void linklist::print()
{
	Node *p = head->next;
	cout << "��ǰ����Ϊ��";
	while (p != NULL) { cout << p->key<<' '; p = p->next; }
	cout << endl;
}
int linklist::getlen()
{
	Node *p = head->next;
	int i = 0;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

bool linklist::isempty()
{
	bool flag = true;
	if (head->next != NULL) { flag = false; }
	return flag;
}

Datatype linklist::getelm(int i)
{
	int j = 1;
	Node *p = head->next;
	while (i != j)
	{
		j++;
		p = p->next;
	}
	return p->key;
}
int linklist::locate(Datatype e)
{
	int i = 1;
	Node *p = head->next;
	while (p != NULL && p->key != e)
	{
		p = p->next;
		i++;
	}
	if (p == NULL) { return 0; }//0��ʾû���ҵ�
	else
		return i;
}

bool linklist::insert(Datatype elm, int i)
{
	if (i <= 0 || i > (*this).getlen()+1) { return false; }
	else
	{
		Node *newelm = new Node; //����һ���½��
		newelm->key = elm;

		int j = 1;
		Node *p = head->next;
		while (j != i-1)
		{
			j++;
			p = p->next;
		}
		newelm->next = p->next;
		p->next = newelm;
		return true;
	}
}

bool linklist::Delete(int i)
{
	if (i <= 0 || i > (*this).getlen()) { return false; }
	else
	{
		int j = 1;
		Node *p = head->next;
		while (j != i - 1)
		{
			j++;
			p = p->next;
		}
		Node *temp = p->next;
		p->next = temp->next;
		delete temp;
		return true;
	}

}

int main()
{
	linklist h;
	Datatype a[5] = { 'a','b','c','d','e' };
	int n = 5;
	h.creatlist(a, 5);
	h.print();
	cout << "��ǰ������Ϊ��" << h.getlen() << endl;
	if (h.isempty()) { cout << "��ǰ����״̬����" << endl; }
	else { cout << "��ǰ����״̬���ǿ�" << endl; }
	cout << "h������Ԫ��Ϊ��" << h.getelm(3) << endl;
	cout << "a��λ��Ϊ��" << h.locate('a') << endl;
	h.insert('f', 4);
	h.print();
	h.Delete(3);
	h.print();
	return 0;
}