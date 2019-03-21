#include<iostream>
#include<queue>

using namespace std;

struct node{
	int info;
	node* lc;
	node* rc;
};

node* Create(int data);
node* Insert(node* root,int data);
node* Delete(node* root,int data);
int max(node* root);
int min(node* root);
int height(node* root);
bool Search(node* root, int data);
void InOrderDisplay(node* root);
void LevelOrderDisplay(node* root);

int main()
{
	node* root=NULL;
	int n,r;

	while(1){
	   cout<<"\n\nPress : \n 1 to insert a new node\n 2 to delete an node\n 3 to display nodes in IN-ORDER\n 4 to display nodes in  LEVEL-ORDER";
	   cout<<"\n 5 to display root node, height, max. and min. nodes of tree\n 6 to Search for a node\n 7 to quit"<<endl;
       cout<<"\nYour Response : ";
	   cin>>r;
	   if( (root==NULL) && (  (r==2)||(r==3)||(r==4)||(r==5)||(r==6)  ) )
	   {
		   cout<<"\nError !   Tree is empty. Insert some nodes first"<<endl;
		   continue ;
	   }
	   switch(r){
		   case 1: cout<<"\n\tEnter the value of new node : "; cin>>n;
				   cout<<"\n\tNode Inserted"<<endl;
				   root=Insert(root,n);
				   break;

		   case 2: cout<<"\nEnter the value of node to be deleted : "; cin>>n;
				   cout<<"\n\tNode Deleted"<<endl;
				   root=Delete(root,n);
			       break;

		   case 3: InOrderDisplay(root);
				   break;

		   case 4: LevelOrderDisplay(root);
				   break;

		   case 5: 	cout<<"\n\t Root = "<<root->info;
					cout<<"\n\t Height of Tree = "<<height(root);
					cout<<"\n\t Max. Value = "<<max(root);
					cout<<"\n\t Min. Value = "<<min(root);
				   break;

		   case 6: cout<<"\n\tEnter a number to search :  ";
				   cin>>n;
				   if(Search(root,n))
						cout<<"\n\tFound";
				   else
						cout<<"\n\tNot Found";
		   case 7: exit(0);

		   default: cout<<"\nInvalid entry"<<endl;
	    }

    }

	return 0;
}

void LevelOrderDisplay(node* root)
{
	if(root==NULL)
		return;
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node* current=q.front();
		cout<<"\t"<<current->info;
		if(current->lc!=NULL)q.push(current->lc);
		if(current->rc!=NULL)q.push(current->rc);
		q.pop();
	}
	return;
}

void InOrderDisplay(node* root)
{
	if(root==NULL)
		return;
	InOrderDisplay(root->lc);
	cout<<"\t"<<root->info;
	InOrderDisplay(root->rc);
}

int height(node* root)
{
	if(root==NULL)
		return -1;
	else
	{
		int l=height(root->lc);
		int r=height(root->rc);
		if(l>r)
			return l+1;
		else return r+1;
	}
}

int max(node* root)
{
	if(root->rc==NULL)
		return root->info;
	else return max(root->rc);

}
int min(node* root)
{
	if(root->lc==NULL)
		return root->info;
	else return min(root->lc);

}

node* Insert(node* root,int data)
{
	if(root==NULL)
	{
		root=Create(data);
	}
	else if(root->info>=data)
		root->lc=Insert(root->lc,data);
	else
		root->rc=Insert(root->rc,data);
	return root;
}



node* Delete(node* root,int data)
{
	if(root==NULL) return root;
	else if(data<root->info)  root->lc=Delete(root->lc,data);
	else if(data>root->info)  root->rc=Delete(root->rc,data);
	else
	{
		// No Child, i.e. leaf node
		if(root->lc==NULL && root->rc==NULL)
		{
			node* temp=root;
			delete temp; root=NULL;
		}
		// One Child
		else if(root->lc==NULL)
		{
			node* temp=root;
			root=root->rc;
			delete temp;
		}
		else if(root->rc==NULL)
		{
			node* temp=root;
			root=root->lc;
			delete temp;
		}
		// Two Children
		else
		{
			int data;
			data=min(root->rc);
			root->info=data;
			root->rc=Delete(root->rc,data);
		}

	}

	return root;
}



bool Search(node* root,int data)
{
	if(root==NULL)
		return false;
	else if(root->info==data)
		return true;
	else if(root->info>=data)
		return Search(root->lc,data);
	else
		return Search(root->rc,data);
}

node* Create(int data)
{
	node* newNode=new node();
	newNode->info=data;
	newNode->lc=NULL;
	newNode->rc=NULL;
	return newNode;
}
