#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
#include<algorithm>	
#define MAX  1000000
#define SIZE 26
using namespace std;

long int freq[SIZE];

struct node
{
	char p;
	struct node *next; 
};//structue node with character and link to next node

struct node *root = NULL;
struct node *tail = NULL;
void store(char x)//function to store charcter in linked list
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->p = x;
	temp->next = NULL;
	if(root == NULL)
	{
		root = temp;
	}
	else
	{
		struct node *nestemp;
		nestemp = root;
		while(nestemp->next != NULL)
		{
			nestemp = nestemp->next;
		}
		nestemp->next = temp;
	}

}
void store()
{
	cout << root->p;
	struct node *tpo;
	tpo = (struct node *)malloc(sizeof(struct node));
	tpo = NULL;
	tpo = root;
	while(tpo->next != NULL)
	{
		tpo = tpo->next;		
	}
	cout << " " << tpo->p << endl;//printing the function accoridng to the input funtion call of first and last character of the string
}

//unordered_map<char,int> freq;	
void printfreq()
{
	struct node *t;
	t = (struct node *)malloc(sizeof(struct node));
	t = NULL;
	t = root;
	if(t==NULL)//if store not performed before we print list is empty
	{
		cout << "List is empty as string is not stored" <<endl;
	}
	else
	{
		memset(freq,0,sizeof(freq));//initialise the set elements frequncy to zero
		for(t=root;;t=t->next)
		{
			freq[t->p - 'a'] = freq[t->p - 'a'] + 1;
			if(t->next==NULL)
			{
				break;
			}
		}
		t->next = NULL;
		t = root;	//setting for each character in frqeuncy array;
		for(t=root;;t=t->next)
		{
			if(freq[t->p - 'a'] != 0)
			{
				cout << t->p << " " << freq[t->p - 'a'] <<" ";
			}
			freq[t->p - 'a'] = 0;//updating frquency so that same character is not printed 
			if(t->next == NULL)
			{
				break;
			}
		}		
	}
 	cout << endl;	
}

void ascend()
{
	struct node *top;
	top = (struct node *)malloc(sizeof(struct node));
	top = NULL;
	top = root;
	unordered_map<char, long int> oc;
	if(top == NULL)//if store not performed before we print list is empty
	{
		cout <<"The list is empty as the string is not stored";
	}
	else
	{
		for(top=root;;top=top->next)
		{
			oc[top->p] = oc[top->p] + 1;
			if(top->next==NULL)
			{
				break;
			}
		}
		int size=oc.size();//oc to find the size to ascned and print the sorted order we use map and iterators
		unordered_map<char, long int>::iterator it;
		while(size--)
		{
			unsigned cmx = 0;
			char ag_mx;
			for(it = oc.begin();it!=oc.end();++it)
			{
				if((it->second > cmx) || (it->second == cmx  && it->first >	 ag_mx)) 
				{ 
         			ag_mx = it->first; 
     				cmx = it->second;
     			}
			}
			cout << ag_mx;
			oc.erase(ag_mx);
		}
		cout << endl;		
	}
	
}
void remove (long int t)//to remove a haracter which has occured more than t times
{
	struct node *t1;
	struct node *t2;
	t1 = (struct node *)malloc(sizeof(struct node));
	t2 = (struct node *)malloc(sizeof(struct node));
	t1 = root;
	t2 = root;
	long int i=0;
	long int count = 1;
	if(t1 != NULL)
	{
		while(t1 !=NULL)
		{
			count = 1;
			t2 = t1->next;
			while(t2 != NULL && t2->p == t1->p)
			{
				count = count + 1;
				t2 = t2->next;
			}
			if(count > t)
			{
				for(i=0;i<t;i++)
				{
					cout << t1->p;
				}
				//t1->next = t2->next;
				//t2->next = NULL;
				//free(t2);
			}
			else
			{
				for(i=0;i<count;i++)
				{
					cout << t1->p;
				}
			}
			t1 = t2;
		}		
	}
	else
	{
		cout << "List is empty as string is not stored" <<endl;
	}
}
void printlist()
{
	struct node *tp;
	tp = (struct node *)malloc(sizeof(struct node));
	tp = NULL;
	tp = root;
	while(tp != NULL)
	{
		cout << tp->p;
		tp = tp->next;		
	}
	cout << endl;
}

long int len_string(char *st)
{
	long int i=0;
	long int len=0;
	while(*st!='\0')
	{
		len = len + 1;
		st = st + 1;
	}
}//function for finding the length of the string

int main()
{
	cout << "Input\n";
	cout << "Enter the string:\n";
	char in[MAX];
	scanf("%s",in);
	long int ln;
	ln=strlen(in);
	int i=0;	
	for(i=0;i<MAX;i++)
	{
		if(in[i]>='A' && in[i]<='Z')
		{
			in[i] = in[i] + 32;///converting all the upper case to lower case
		}
	}
	cout << endl;
	cout << "Enter the input function to be performed	:" << endl;
	cout << "Enter 'S' to store" << endl;
	cout << "Enter 'P' to print each alphabet with duplicates"<< endl;
	cout << "Enter 'A' to ascend" << endl; 
	cout << "Enter 'R' to remove extra alphabet" << endl;
	cout << "Enter 'E' to exit from frunctionality input "<< endl;
	char x;
	while(1)
	{
		x = getchar();
		if(x=='S')
		{
			for(i=0;i<ln;i++)
			{
				store(in[i]);
			}
			store();
		}
		else if(x == 'P')
		{
			printfreq();
		}
		else if(x == 'A')
		{
			ascend();
		}	
		else if(x == 'R')
		{
			int t;
			cout << "Enter the frequency: ";
			cin >> t;
			remove(t);
			cout << endl;
		}
		else if(x =='\n')
		{
			char y;
			y = getchar();
			if(y == 'S')
			{
				for(i=0;i<ln;i++)
				{
					store(in[i]);
				}
				store();
			}
			else if(y == 'P')
			{
				printfreq();
			}
			else if(y == 'A')
			{
				ascend();
			}	
			else if(y == 'R')
			{
				int t;
				cout << "Enter the frequency: ";
				cin >> t;
				remove(t);
				cout << endl;
			}
			else if(y == '\n')
			{
				break;
			}
		}
	}

}