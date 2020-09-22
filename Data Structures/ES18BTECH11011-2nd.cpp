#include<iostream>

using namespace std;

struct node
{
	int val;
	struct node *left;
	struct node *right;
	struct  node *parent;
};	//node containing which elements

struct node *nw(int x)
{
	struct node  *tem = (struct node *)malloc(sizeof(struct node));
    tem->val =  x;
    tem->left = NULL;
    tem->right = NULL;
    tem->parent = NULL; 	
    return tem;
}//new node being created

struct node *insert(struct node* node, int x)
{
	if (node == NULL)
	{
		return nw(x);
	}
	struct node *tmr;
	if(node->val > x)
	{
		tmr =  insert(node->left,x);
		node->left = tmr;
		tmr->parent = node; 
	}
	else if(node->val < x)
	{
		tmr = insert(node->right,x);		
		node->right = tmr;
		tmr->parent = node;
	}
	else
	{
		cout << " Dummy element entered"<<endl;
	}
	return node;
}//creating a tree
// Function that finds predecessor and successor of key in BST. 
void presuc(node* root, node*& suc, node*& pre, int x) 
{ 
	if (root == NULL) 
	{
		return;
	}	 
	while (root != NULL) 
	{  
		if (root->val == x) 
		{ 
			if (root->left) 
			{ 
				pre = root->left; 
				while (pre->right) 
				{
					pre = pre->right;
				}	 
			}
			if (root->right) 
			{ 
				suc = root->right; 
				while (suc->left) 
				{
					suc = suc->left;
				}	 
			}   
			return; 
		} 
		else if(root->val > x)
		{ 
			suc = root; 
			root = root->left; 
		} 
		else if (root->val < x) 
		{ 
			pre = root; 
			root = root->right; 
		}  
	} 
} 

int maxsubtree(struct node *node)//maximum of a rooted subtree
{
	if(node->right == NULL)
	{
		return node->val;
	}
	else 
	{
		return maxsubtree(node->right);
	}
}

int minsubtree(struct node *node)//minimum of a rooted subtree
{
	if(node->left == NULL)
	{
		return node->val;
	}
	else
	{
		return minsubtree(node->left);
	}
}

int  lcances(struct node *node,int x1,int x2)
{
	if(node == NULL)
	{
		return 0;
	}
	if((node->val  < x1) && (node->val < x2))
	{
		return lcances(node->right,x1,x2);
	}
	else if((node->val > x1) && (node->val > x2))
	{	
		return lcances(node->left,x1,x2);
	}
	else
	{
		return node->val;
	}
	
}//key value should passed for the function lcances()->val should be passed
int main()
{
	struct node *root = NULL;
	//int n;
	//printf("Enter the number of nodes in the tree: ");
	//cin >> n;
	int i=0;
	int tempo;
	cout<< "Input:" << endl;
	while(1)
	{
		if(i==0)
		{
			cin >> tempo; 
			root = insert(root,tempo);
		}
		else
		{
			cin >> tempo ;
			insert(root,tempo);
		}
		i = i + 1;
		if(getchar()=='\n')
		{
			break;
		}	
	}
	cout << "Functionality input:" <<endl;
	cout << "Enter functionality input or press two new lines to exit from function:" << endl;
	struct node *pr=NULL;
	struct node *sc=NULL;
	while(1)
	{
		char func;
		func = getchar();
		if(func =='M')
		{	
			int r;
			cin >> r;
			struct node *tmpo = NULL;
			tmpo = root;
			while(1)
			{
				if(tmpo->val == r)
				{
					break;
				}
				else if(tmpo->val > r)
				{
					tmpo = tmpo->left;
				}
				else if(tmpo->val < r)
				{
					tmpo = tmpo->right;
				}
			}
			cout << minsubtree(tmpo)<< " ";//to check if it is minimum or maxmimum in the subtree if left or right chikd does not exist then to print NULL
  			cout << maxsubtree(tmpo) << endl;		
		}
		else if(func == 'P')
		{
			int r;
			cin >> r;
			presuc(root,sc,pr,r);
			if(pr == NULL)
			{
				cout << "The key value entered is the least element";
			}
			else
			{
				cout << pr->val << endl;				
			}
		}
		else if(func == 'S')
		{
			int r;
			cin >> r;
			presuc(root,sc,pr,r);	
			if(sc == NULL)
			{
				cout << "The key value entered is the maximum element";
			}
			else
			{
				cout << sc->val << endl;				
			}
		}
		else if(func == 'C')
		{
			int r1,r2;
			cin >> r1;
			cin >> r2;
			struct node *rr;
			rr = root;
			int ans;
			ans = lcances(rr,r1,r2);
			cout << ans << endl;
		}
		else if(func == '\n')
		{
			char f2;
			f2 = getchar();
			if(f2 =='M')
			{	
				int r;
				cin >> r;
				struct node *tmpo = NULL;
				tmpo = root;
				while(1)
				{
					if(tmpo->val == r)
					{
						break;
					}
					else if(tmpo->val > r)
					{
						tmpo = tmpo->left;
					}
					else if(tmpo->val < r)
					{
						tmpo = tmpo->right;
					}
				}
				cout << minsubtree(tmpo)<< " ";//to check if it is minimum or maxmimum in the subtree if left or right chikd does not exist then to print NULL
  				cout << maxsubtree(tmpo) << endl;		
			}
			else if(f2 == 'P')
			{
				int r;
				cin >> r;
				presuc(root,sc,pr,r);
				if(pr == NULL)
				{
					cout << "The key value entered is the least element";
				}
				else
				{
					cout << pr->val << endl;				
				}
			}
			else if(f2 == 'S')
			{
				int r;
				cin >> r;
				presuc(root,sc,pr,r);	
				if(sc == NULL)
				{
					cout << "The key value entered is the maximum element";
				}
				else
				{
					cout << sc->val << endl;				
				}
			}
			else if(f2 == 'C')
			{
				int r1,r2;
				cin >> r1;
				cin >> r2;
				struct node *ee;
				ee = root;
				int ans;
				ans = lcances(ee,r1,r2);
				cout << ans << endl;
			}	
			else if(f2 == '\n')
			{
				break;
			}	
		}
	}
}