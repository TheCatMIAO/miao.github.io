/*************************************************************************
	> File Name: binary_search_tree.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 19 Dec 2020 09:59:15 AM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define KEY(r) (r ? r->key : 0)
typedef struct Node{
    int key;
    struct Node *lchild,*rchild;
}Node;

Node *getNewNode(int key){
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    return p;
}

void clear(Node *root){
    if(root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

int search(Node *root, int key){
    if(root == NULL) return 0;
    if(root->key == key) return 1;
    if(key < root->key) return search(root->lchild, key);
    else return search(root->rchild, key);
}


//详见博客分析,这里的root是最底层的root，可以用temp代替
//这个版本使用getNewNode
//就是使用root也没关系
Node *insert(Node *root, int key){
    if(root == NULL){
        //root = (Node*)malloc(sizeof(Node));
        //root->key = key;
        //root->lchild = root->rchild = NULL;
        //return root;
        //-------
        //root = getNewNode(key);
        //return root;
        //-------
        return getNewNode(key);
    }
    if(key == root->key) return root;
    if(key < root->key) root->lchild = insert(root->lchild, key);//特别重要的一步
    else  root->rchild = insert(root->rchild, key);
    return root;
}

//找当前节点的右下，是当前节点，在使用的时候需要把根的左孩子传过来
Node *findPre(Node *root){
    if(root->rchild == NULL) return root;
    findPre(root->rchild);
}

Node *erase(Node *root, int key){
    if(root == NULL) return NULL;
    if(key < root->key) erase(root->lchild, key);
    else if(key > root->key) erase(root->rchild, key);
    else {
        if(root->lchild == NULL||root->rchild == NULL){
            root = root->lchild ? root->lchild : root->rchild;
            return root;
        }else{
            Node *pre = findPre(root->lchild);
            root->key = pre->key;
            erase(root->lchild, pre->key);
        }
    }
}

void output_tree(Node *root){
    if(root == NULL) return ;
    output_tree(root->lchild);
    printf("(c:%d, l:%d, r:%d)\n", KEY(root), KEY(root->lchild), KEY(root->rchild));
    output_tree(root->rchild);
}

int main(){
    int op;
    int val;
    Node *root = NULL;
    while(~scanf("%d %d", &op, &val)){
        switch (op){
            case 0:
                printf("search %d ok? %d\n", val, search(root, val));
                break;
            case 1:
                root = insert(root, val);//这里一定要写root，因为没有&不会改变里面的值
                break;
            case 2:
                root = erase(root, val);
                break;
        }
        if(op){
            output_tree(root);
            printf("----------------\n");
        }

    }
    return 0;
}
