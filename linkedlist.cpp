#include<iostream>
using namespace std;
class node
{
	public:
		 node *next;
		 int data;
};
class list1
{
	public:
		node *head;
		node *tail;
	list1()
	{
		head=NULL;
		tail=NULL;
	}
	void create()
	{
		int n;
		cout<<"How many node entered:";
		cin>>n;
		node *tmp;
		
		for(int i=0;i<n;i++)
		{
			tmp=new node;
			cin>>tmp->data;
			tmp->next=NULL;
			if(head==NULL)
			{
				head=tmp;
				tail=tmp;
			}
			else
			{
				tail->next=tmp;
				tail=tmp;
			}
		}
	}
	void display()
	{
		node *tmp1;
		tmp1=head;
		while(tmp1->next!=NULL)
		{
			cout<<tmp1->data<<" ";
			tmp1=tmp1->next;
		}
		cout<<tmp1->data;
	}
	void insert()
	{
		int pos;
		node *tmp;
		tmp=new node;
		cout<<"Enter position:";
		cin>>pos;
	    cout<<"please node entered:";
		cin>>tmp->data;
		tmp->next=NULL;
		int count=1;
		node *temp1,*prev;
		temp1=head;
		if(pos==1)
		{
			tmp->next=head;
			head=tmp;
		}
		else
		{
			while(pos!=count)
			{
				prev=temp1;
				temp1=temp1->next;
				count++;
			}
			if(temp1->next!=NULL)
			{
				tmp->next=temp1;
				prev->next=tmp;
			
			}
			else
			{
				temp1->next=tmp;
				tmp->next=NULL;
				tail=tmp;
			}
			
		}
	}
	void delet()
	{
		int pos;
		node *tmp;
		tmp=new node;
		cout<<endl;
		cout<<"Enter position:";
		cin>>pos;
	    
		tmp->next=NULL;
		int count=1;
		node *prev;
		tmp=head;
		if(pos==1)
		{
			head=tmp->next;
			delete tmp;
		}
		else
		{
			while(pos!=count)
			{
				prev=tmp;
				tmp=tmp->next;
				count++;
			}
			if(tmp->next!=NULL)
			{
				prev->next=tmp->next;
				delete tmp;
			
			}
			else
			{
				prev->next=NULL;
				tail=prev;
				delete tmp;
			}
			
		}
	}
	
	
};
int main()
{
	list1 l;
	l.create();
	l.display();
	cout<<endl;
	l.insert();
	cout<<"After Inseting:"<<endl;
	l.display();
	l.delet();
	cout<<"After Deleting:"<<endl;
	l.display();
	
}
