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
void Display(node* root);
int min(node* root);
node* Delete(node* root,int data);

int main()
{
	node* root=NULL;
	int n,r;

	while(1){
	   cout<<"\n\nPress : \n 1 to insert a new node\n 2 to delete an node\n 3 to display all the nodes\n 4 to quit";
       cout<<"\nYour Response : ";
	   cin>>r;
	   if( (root==NULL)  &&  (r==2||r==3) )
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

		   case 3: Display(root);
				   break;

		   case 4: exit(0);

		   default: cout<<"\nInvalid entry"<<endl;
	    }

    }

	return 0;
}

node* Create(int data)
{
	node* newNode=new node();
	newNode->info=data;
	newNode->lc=NULL;
	newNode->rc=NULL;
	return newNode;
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

void Display(node* root)
{
	if(root==NULL)
		return;
	Display(root->lc);
	cout<<"\t"<<root->info;
	Display(root->rc);
}

int min(node* root)
{
	if(root->lc==NULL)
		return root->info;
	else return min(root->lc);

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
