#include<iostream>
#include<cstdio>
using namespace std;

class Heap
{
public:
	Heap(int Size=0)
	{
		arr = new int[Size];
		HeapSize = 0;
	}
	void push(int x)
	{
		int hole = ++ HeapSize;
		for(; hole > 1 && x < arr[hole/2]; hole /= 2)
			arr[hole] = arr[hole/2];
		arr[hole] = x;
	}
	void pop()
	{
		arr[1] = arr[HeapSize --];
		percolate(1);
	}
	int top()
	{
		return arr[1];
	}
private:
	int HeapSize;
	int *arr;
	void percolate(int hole)
	{
		int child;
		int tmp = arr[hole];
		
		for(; hole*2 <= HeapSize; hole = child)
		{
			child = hole * 2;
			if(child != HeapSize && arr[child+1] < arr[child])
				child ++;
			if(arr[child] < tmp)
				arr[hole] = arr[child];
			else break;
		}
		arr[hole] = tmp;
	}
};

int main()
{
	int n;
	scanf("%d",&n);
	
	Heap heap(n/2+1);				
	
	int tmp;
	int i;
	for(i = 0; i < n/2+1; i ++)				// Again,the first N/2+1 datas
	{
		scanf("%d",&tmp);
		heap.push(tmp);
	}
	
	for(i; i < n; i ++)
	{
		scanf("%d",&tmp);
		heap.push(tmp);
		heap.pop();
	}
	
	if(n % 2 == 0)							// even case
	{
		tmp = heap.top();
		heap.pop();
		printf("%.1lf\n",(double)(tmp*0.5)+(double)(heap.top()*0.5));
	}
	else
	{
		printf("%.1lf\n",(double)(heap.top()));
	}
}
