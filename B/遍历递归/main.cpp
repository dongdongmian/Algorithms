#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct tree{
    char data;
    struct tree *lchild;
    struct tree *rchild;
}TREE,*Tree;

void re_preorder(TREE *tree){   //DLR
    if(tree != NULL){
        cout << tree->data;
        re_preorder(tree->lchild);
        re_preorder(tree->rchild);
    }
}

void re_midorder(TREE *tree){   //LDR
    if(tree != NULL){
        re_midorder(tree->lchild);
        cout << tree->data;
        re_midorder(tree->rchild);
    }
}

void re_posorder(TREE *tree){      //LRD
    if(tree != NULL){
        re_posorder(tree->lchild);
        re_posorder(tree->rchild);
        cout << tree->data;
    }
}

void Create(TREE *tree){

}

Tree CreateTree(TREE *tree){  //base preorder cerate a tree
    char T;
    cin >> T;

    if(T != '#'){
        tree = new TREE;
        tree->lchild = NULL;
        tree->rchild = NULL;
        tree->data = T;

        //re_preorder(tree);
        //re_posorder(tree);
        //re_midorder(tree);

        tree->lchild=CreateTree(tree->lchild);
		tree->rchild=CreateTree(tree->rchild);

    }
    return tree;
}

int main()
{
    TREE *tree;
    tree = NULL;
    cout << "Please input a tree with a preorder:";

     tree = CreateTree(tree);
    cout << "re_preorder result:";
    re_preorder(tree);
    cout << endl;
    cout << "re_posorder result:";
    re_posorder(tree);
    cout << endl;
    cout << "re_midorder result:";
    re_midorder(tree);
    cout << endl;

   return 0;
}
