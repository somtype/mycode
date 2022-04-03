#include<iostream>
#include<queue>
using namespace std;
int main()
{
	priority_queue<int,vector<int>,greater<int>> q;
	for(int i=1;i<=5;i++)
	{
		q.push(i);
	}
	for(int i=1;i<=5;i++)
	{
		cout<<q.top();
		q.pop();
	}
	return 0;
}
