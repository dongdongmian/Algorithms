#include <iostream>
#include <malloc.h>
#include <stack>

using namespace std;

typedef struct tree{
    char data;
    struct tree *lchild;
    struct tree *rchild;
}TREE,*Tree;

Tree CreateTree(TREE *tree){  //base preorder cerate a tree
    char T;
    cin >> T;

    if(T != '#'){
        tree = new TREE;
        tree->lchild = NULL;
        tree->rchild = NULL;
        tree->data = T;

        tree->lchild=CreateTree(tree->lchild);
		tree->rchild=CreateTree(tree->rchild);

    }
    return tree;
}

void st_preorder(TREE *tree)
{
    stack<TREE*> s;
    TREE *p=tree;
    while(p!=NULL||!s.empty())  //while p!=NULL then there are some nodes don't be output
    {
        while(p!=NULL)      //print the lchild first
        {
            cout<<p->data<<" ";
            s.push(p);
            p=p->lchild;
        }
        if(!s.empty())      //there have not any lchild
        {
            p=s.top();
            s.pop();
            p=p->rchild;
        }
    }
}

void st_midorder(TREE *tree)
{
    stack<TREE*> s;
    TREE *p=tree;
    while(p!=NULL||!s.empty())
    {
        while(p!=NULL)
        {
            s.push(p);
            p=p->lchild;
        }
        if(!s.empty())
        {
            p=s.top();
            cout << p->data <<' ';
            s.pop();
            p=p->rchild;
        }
    }
}

void st_posorder(TREE *tree)
{
    stack<TREE*> s;
    TREE *cur;                      //current node
    TREE *pre=NULL;                 //the previous node
    s.push(tree);
    while(!s.empty())
    {
        cur=s.top();
        if((cur->lchild==NULL&&cur->rchild==NULL)||
           (pre!=NULL&&(pre==cur->lchild||pre==cur->rchild)))
        {
            cout<<cur->data<<" ";  //current node don't have child or it's child have been visit
            s.pop();
            pre=cur;
        }
        else
        {
            if(cur->rchild!=NULL)
                s.push(cur->rchild);
            if(cur->lchild!=NULL)
                s.push(cur->lchild);
        }
    }
}

int main()
{
    TREE *tree;
    tree = NULL;
    cout << "Please input a tree with a preorder:";

    tree = CreateTree(tree);
    cout << "st_preorder result:";
    st_preorder(tree);
    cout << endl;

    cout << "st_posorder result:";
    st_posorder(tree);
    cout << endl;

    cout << "st_midorder result:";
    st_midorder(tree);
    cout << endl;

    return 0;
}
