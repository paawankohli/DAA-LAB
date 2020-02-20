#include<stdlib.h>
#include<stdio.h>

int opcount=0;//initialize the opcount variable

struct node
{
    int val;
    struct node*left, *right;
};

typedef struct node* NODE;

NODE root=NULL;

NODE create()
{
    NODE p;
    int x;
    printf("Enter data(-1 for no data):");
    scanf("%d",&x);
    
    if(x==-1)
        return NULL;
    
    p=(NODE)malloc(sizeof(struct node));
    p->val=x;
    
    printf("Enter left child of %d:\n",x);
    p->left=create();
 
    printf("Enter right child of %d:\n",x);
    p->right=create();
    
    return p;
}


unsigned int binarytree_count_recursive(NODE root)
{
    opcount++;
    unsigned int count = 1;
    if(root!=NULL)
    {
        return binarytree_count_recursive(root->left)+binarytree_count_recursive(root->right)+1;
    }
    else 
        return 0;
}
 
int binarytree_count(NODE p)
{
    int count = 0;
    if (p != NULL) 
    {
        count = binarytree_count_recursive(p);
    }
    return count;
}


int main()
{
    int choice, ele;

            printf("TREEE CREAATIONNN\n");
            root=create();
            //break;

            printf("Number of nodes in binary tree: %d\n", binarytree_count(root));
            printf("The opcount is %d\n", opcount);
            return 0;

}