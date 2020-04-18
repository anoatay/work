#include<iostream>
using namespace std;
struct node{
	
	int data;
	node* left;
	node* right;
};
node* nnode(int data)
{
	node* temp = new node();
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
node* ctu(int pre[],int* pi,int low,int high,int size)
{
	if(*pi>=size||low>high)
		return NULL;
	node* root = nnode(pre[*pi]);
	*pi = *pi + 1;
	if(low==high)
		return root;
	int i;
	for(i=low;i<=high;i++)
	if(pre[i]>root->data)
		break;
	root->left=ctu(pre,pi,*pi,i-1,size);
	root->right=ctu(pre,pi,i,high,size);
	return root;
}
node* ctree(int pre[],int size)

{
	int pi=0;
	return ctu(pre,&pi,0,size-1,size);
	
}
void preorder(node* root)
{
	if(root)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);	
	}
}
void inorder(node* root)
{
	if(root){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
node* treemin(node* root)
{
	while(root->left!=NULL)
	{
		root=root->left;
	}
	return root;
}
node* suc(node* root, node* n)
{
	if(n->right!=NULL)
		return treemin(n->right);
	node* succ= NULL;
	while(root!=NULL)
	{
		if(n->data<root->data)
		{
			succ=root;
			root=root->left;
			
		}
		else if(n->data>root->data)
			root=root->right;
		else 
			break;
	}
	return succ;
	
}
node* insert(node* root, int val)
{
	if(root==NULL)
		return nnode(val);
	if(val< root->data)
		root->left=insert(root->left,val);
	else
		root->right=insert(root->right,val);
	return root;
	
}
node* search(node* x,int item)
{
	if(x==NULL||item==x->data)
		return x;
	if(item<x->data)
		return search(x->left,item);
	else
		return search(x->right,item);
}
int main()
{
	int pre[]={10,5,1,7,30,40,50};
	int size=sizeof(pre)/sizeof(pre[0]);
	node*root=ctree(pre,size);
	//node* y;
	//y= search(root,5);
	
	node* h;
	h= insert(root,8);
	preorder(root);
	
	
	return 0;
}
