#pragma once

#include "stdafx.h"
#include <istream>
#include <vector>
#include <stack>
#include<algorithm>
#include<queue>
using namespace std;


/// 链表结构
struct linkNode
{
	int num;
	linkNode *next;
};

class linkTest
{
public:
	linkNode* creatLink(int n);
	void show(linkNode* head);
	void deleteLink(linkNode* head);
	linkNode* reverseLink(linkNode* head);
	bool intersectionJudgment(linkNode* head1,linkNode* head2);    ////交点判断
	void createInterLink(linkNode* head1,linkNode* head2);
	void mergeLink(linkNode* head1,linkNode* head2);

	linkNode* creatLoopLink(int n1,int ind);

	bool linkLoopJudgement(linkNode *head);
	linkNode* getInterNode(linkNode *head);
	void linkDivision(linkNode *head,int n);
	

};


/// 贪心算法
class greedyAlgorith
{
public:

	/// 分糖果
	int divCandy(vector<int> children);
	void correction(vector<int>& vec,int start,int end);

	///摇摆序列

	int wiggleMaxLength(vector<int> num);

	///删除K个数值使得原来数值最小

	string removeKdigits(string num,int k);

	bool jumpNum1(vector<int>num);

	bool static mySort(pair<int,int>a,pair<int,int>b);

	void vecSort(vector<pair<int,int>>& vec);
	int minShot(vector<pair<int,int>> points);
};


typedef struct node
{
	struct node *lchild;
	struct node *rchild;
	int data;
}BiTreeNode,*BiTree;   //*BiTree的意思是给 struct node*起了个别名，叫BiTree，故BiTree为指向节点的指针

#define MAX 26
typedef struct Trie
{
	Trie *next[MAX];
	int v;   //  按需使用，本例子中表示从头到本字符组成的前缀出现的次数
	int cnt;  // 单词出现的次数
	bool flag;  // 该节点是否有单词
};

class BinTree
{
public:
	void createBiTree(BiTree &T);   //&的意思是传进来节点指针的引用，括号内等价于 BiTreeNode* &T,目的是让传递进来的指针发生改变
	void preTraverse(BiTree T);
	BiTree commonNode(BiTree A,BiTree B,BiTree root);

	/// 求满足根到叶节点路径和为sum 的所有路径
	void dfs(BiTree root,int sum);
	vector<vector<int>> pathSum(BiTree root,int sum);
	void flatten(BiTree root);

	void printLink(BiTree root);
	void levelOrderPrint(BiTree root);
	BiTree buildTree(vector<int> preorder,vector<int> inorder,int a =1);
	BiTree creatBST(vector<int>preorder,vector<int>inorder,int start,int end,int& index);
	BiTree creatBST0(vector<int>preorder,vector<int>inorder,int start,int end,int& index);

	/// 复制一颗二叉树
	void copyTree(BiTree root,BiTree& cpRoot);

	Trie* creatTrieNode();
	void insertTrie(char *str,Trie* root);
	int findTrie(char *str,Trie *root);
	void delTrie(Trie *T);


public:
	vector<vector<int>> pathVec;
	vector<int> path;
};



class Dynamic{
public:
	int climbStairs(int n);  //爬楼梯算法  每次只能一步或者两步，先走一步剩下n-1台阶，先走2步，剩下n-2台阶
	int rob(vector<int> num);  // 计算前n-1的最大，前n-2的最大
	int maxSubArray(vector<int> num);   //最大子串和
	int miniNumTotal(vector<vector<int>> triangle);   //三角形最小路径

	int maxlengthsub(vector<int> vec);

};