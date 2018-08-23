//    二叉树的实现（C语言）
//    链表，递归实现
//    编译环境：visual studio code
//    操作系统：win7+
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef char Elementtype;      // 定义数据类型，可根据需要自行定制
typedef struct TreeNode *Node; // Node相当于 struct TreeNode *
typedef struct TreeNode
{
    Elementtype Element;
    Node left;  // 树节点的左子节点
    Node right; // 树节点的右子节点
} TREE, *PTREE;

// 函数申明
void CreateTree(PTREE *); // 树的先序创建函数
void PreOrderTree(PTREE); // 树的前序遍历函数
void InOrderTree(PTREE);  // 树的中序遍历函数

// 主函数
int main()
{
    PTREE Root;
    printf("请先序输入二叉树的节点数据(如：QWERT******)： ");
    CreateTree(&Root);

    printf("\n前序遍历结果为：");
    PreOrderTree(Root);

    printf("\n中序遍历结果为：");
    InOrderTree(Root);

    return 0;
}

// 定义树先序创建函数
void CreateTree(PTREE *Root)
{
    char val = 0;    // 用于下面存放数据
    val = getchar(); // 输入数据值
    // 如果输入'*'，则指向为空
    if (val == '*')
        (*Root) = NULL;
    // 如果输入非'*'，则给数据域赋值
    else
    {
        (*Root) = (PTREE)malloc(sizeof(TREE)); // 申请内存空间
        if ((*Root) == NULL)
        {
            printf("创建节点失败，无法分配可用内存...");
            exit(-1);
        }
        else
        {
            (*Root)->Element = val; // 给节点数据域赋值
            CreateTree(&(*Root)->left);
            CreateTree(&(*Root)->right);
        }
    }
}

// 树的前序遍历函数定义
void PreOrderTree(PTREE Root)
{
    if (Root == NULL)
    {
        return;
    }
    else
    {
        putchar(Root->Element);
        PreOrderTree(Root->left);
        PreOrderTree(Root->right);
    }
}

// 树的中序遍历函数定义
void InOrderTree(PTREE Root)
{
    if (Root == NULL)
    {
        return;
    }
    else
    {
        InOrderTree(Root->left);
        putchar(Root->Element);
        InOrderTree(Root->right);
    }
}