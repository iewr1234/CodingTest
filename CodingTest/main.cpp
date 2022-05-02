#include <iostream>
#include <cmath>

//연결리스트
typedef struct Node
{
	int data;
	Node* next;
} node;

Node* head;
Node* tail;
int nodeSize;

void Init()
{
	head = new Node;
	tail = new Node;
	head->next = tail;
	tail->next = tail;
	nodeSize = 0;
}

bool Insert(int value, Node* node)
{
	if (node == tail)
		return false;

	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = node->next;
	node->next = newNode;
	nodeSize++;
	std::cout << "삽입 : " << newNode->data << std::endl;
	return true;
}

Node* FindNode(int value)
{
	Node* temp = head->next;
	while (temp != tail)
	{
		if (temp->data == value)
		{
			return temp;
		}
		temp = temp->next;
	}
	return temp;
}

bool DeleteNode(Node* node)
{
	if (node == head || tail == node)
		return false;

	Node* preNode = head;
	Node* temp = head->next;

	while (temp != tail)
	{
		if (node == temp)
		{
			Node* deleteNode = node;
			preNode->next = deleteNode->next;
			std::cout << "삭제 : " << deleteNode->data << std::endl;
			delete deleteNode;
			nodeSize--;
			return true;
		}

		preNode = temp;
		temp = temp->next;
	}

	return false;
}

void PrintLinkedList()
{
	Node* temp = head->next;
	std::cout << "리스트 출력 : ";
	while (temp != tail)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
	std::cout << "리스트 크기 : " << nodeSize << std::endl;
}

//스택
char stack[5];
int top = -1;
int SIZE = 5;

int isFull()
{
	if (top >= SIZE - 1)
	{
		std::cout << "isFull" << std::endl;
		return 1;
	}

	return 0;
}

int isEmpty()
{
	if (top == -1)
	{
		std::cout << "isEmpty" << std::endl;
		return 1;
	}

	return 0;
}

void push(char data)
{
	if (!isFull())
	{
		top++;
		stack[top] = data;
	}
}

char pop()
{
	if (!isEmpty())
	{
		char temp = stack[top];
		top--;
		return temp;
	}
}

char peek()
{
	if (!isEmpty())
	{
		return stack[top];
	}
}

void print() {
	if (!isEmpty())
	{
		for (int i = 0; i <= top; i++)
		{
			std::cout << stack[i];
		}
		std::cout << std::endl;
	}
}

//피보나치
int Fibo(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}

	return Fibo(n - 1) + Fibo(n - 2);
}

//하노이
void Hanoi(int n, int start, int mid, int end)
{
	if (n == 1)
	{
		std::cout << start << "번 기둥에서 " << end << "번 기둥으로 옮김" << std::endl;
		return;
	}
	else
	{
		Hanoi(n - 1, start, end, mid);
		std::cout << start << "번 기둥에서 " << end << "번 기둥으로 옮김" << std::endl;
		Hanoi(n - 1, mid, start, end);
	}
}

int main()
{
	//피보나치 재귀
	int n = 0;
	std::cout << "n번째 피보나치수 : ";
	std::cin >> n;
	std::cout << Fibo(n) << std::endl;

	//하노이
	std::cout << "하노이 원반의 개수 : ";
	std::cin >> n;
	Hanoi(n, 1, 2, 3);

	//링크드 리스트에 대하여 설명하고 삽입, 삭제, 출력을 구현하라.
	// 참고 : https://happysalmon.tistory.com/74
	Init();
	Insert(10, head);
	Insert(100, FindNode(10));
	PrintLinkedList();
	DeleteNode(FindNode(10));
	PrintLinkedList();
	Insert(500, head);
	PrintLinkedList();

	//배열을 이용한 스택
	//참고 : https://minimin2.tistory.com/3
	print();
	push('1');
	push('2');
	push('3');
	print();
	pop();
	push('4');
	print();
	pop();
	pop();
	print();
}