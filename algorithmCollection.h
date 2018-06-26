#pragma once

#include "stdafx.h"
#include <istream>
#include <vector>
#include <stack>
#include<algorithm>
#include<queue>
using namespace std;


/// ����ṹ
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
	bool intersectionJudgment(linkNode* head1,linkNode* head2);    ////�����ж�
	void createInterLink(linkNode* head1,linkNode* head2);
	void mergeLink(linkNode* head1,linkNode* head2);

	linkNode* creatLoopLink(int n1,int ind);

	bool linkLoopJudgement(linkNode *head);
	linkNode* getInterNode(linkNode *head);
	void linkDivision(linkNode *head,int n);
	

};


/// ̰���㷨
class greedyAlgorith
{
public:

	/// ���ǹ�
	int divCandy(vector<int> children);
	void correction(vector<int>& vec,int start,int end);

	///ҡ������

	int wiggleMaxLength(vector<int> num);

	///ɾ��K����ֵʹ��ԭ����ֵ��С

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
}BiTreeNode,*BiTree;   //*BiTree����˼�Ǹ� struct node*���˸���������BiTree����BiTreeΪָ��ڵ��ָ��

#define MAX 26
typedef struct Trie
{
	Trie *next[MAX];
	int v;   //  ����ʹ�ã��������б�ʾ��ͷ�����ַ���ɵ�ǰ׺���ֵĴ���
	int cnt;  // ���ʳ��ֵĴ���
	bool flag;  // �ýڵ��Ƿ��е���
};

class BinTree
{
public:
	void createBiTree(BiTree &T);   //&����˼�Ǵ������ڵ�ָ������ã������ڵȼ��� BiTreeNode* &T,Ŀ�����ô��ݽ�����ָ�뷢���ı�
	void preTraverse(BiTree T);
	BiTree commonNode(BiTree A,BiTree B,BiTree root);

	/// ���������Ҷ�ڵ�·����Ϊsum ������·��
	void dfs(BiTree root,int sum);
	vector<vector<int>> pathSum(BiTree root,int sum);
	void flatten(BiTree root);

	void printLink(BiTree root);
	void levelOrderPrint(BiTree root);
	BiTree buildTree(vector<int> preorder,vector<int> inorder,int a =1);
	BiTree creatBST(vector<int>preorder,vector<int>inorder,int start,int end,int& index);
	BiTree creatBST0(vector<int>preorder,vector<int>inorder,int start,int end,int& index);

	/// ����һ�Ŷ�����
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
	int climbStairs(int n);  //��¥���㷨  ÿ��ֻ��һ����������������һ��ʣ��n-1̨�ף�����2����ʣ��n-2̨��
	int rob(vector<int> num);  // ����ǰn-1�����ǰn-2�����
	int maxSubArray(vector<int> num);   //����Ӵ���
	int miniNumTotal(vector<vector<int>> triangle);   //��������С·��

	int maxlengthsub(vector<int> vec);

};