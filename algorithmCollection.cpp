#pragma once
#include "stdafx.h"
#include <iostream>
#include <map>
#include "algorithmCollection.h"

using namespace std;

linkNode* linkTest::creatLink(int n)
{
	linkNode *head,*p,*q;
	head = new linkNode;
	head->next = NULL;
	q = head;
	for(int i = 1;i<=n;i++)
	{
		p = new linkNode;
		cout<<"请输入数值：";
		cin>>p->num;
		p->next = NULL;
		q->next = p;
		q = p;
	}
	
	return head;
}

void linkTest::show(linkNode* head)
{
	linkNode* tail;
	tail = head->next;
	while(tail!=NULL)
	{
		cout<<tail->num<<" ";
		tail = tail->next;
		//system("pause");
	}
	cout<<endl;
}

void linkTest::deleteLink(linkNode* head)
{
	if(head->next==NULL)
	{
		delete head;
		return;

	}
	linkNode *p,*q;
	p = head->next;
	
	q = p->next;
	while(p!=NULL)
	{
		delete p;
		//p = NULL;
		p = q;
		if(q!=NULL)
			q = q->next;
	}
	delete head;
	//head = NULL;
}

linkNode* linkTest::reverseLink(linkNode* head)
{
	linkNode *p,*q,*s;
	
	p = head->next;
	if(p==NULL || p->next == NULL)
		return head;
	q = p->next;
	s = q->next;
	p ->next = NULL;
	while(s!=NULL)
	{
		q->next = p;
		p = q;
		q = s;
		s = s->next;
	}
	q->next = p;
	head->next = q;
	return head;
}


void linkTest::createInterLink(linkNode* head1,linkNode* head2)
{
	linkNode *p,*q,*s;
	p = head1;
	for(int i = 0;i<5;i++)
	{
		p = p->next;
	}
	q = head2;
	for(int i = 0;i<2;i++)
	{
		q = q->next;
	}
	s = q->next;
	q->next = p;
	deleteLink(s);
}




bool linkTest::intersectionJudgment(linkNode* head1,linkNode* head2)
{
	// 1.哈希存储地址判断是否相交
	// 2.如果两个链表相交 则末尾节点相同，因此直接判断末尾节点是否一样就好

	// 方法一：
	/*map<linkNode*,int> mapNode;
	linkNode *p;
	p = head1->next;
	while(p!=NULL)
	{
		mapNode[p] = 1;
		p = p->next;
	}

	p = head2->next;
	while(p!=NULL)
	{
		if(mapNode.count(p)!=0)
		{
			return true;
		}
		p = p->next;
	}
	return false;*/


	///方法二
	linkNode *p,*q;
	p = head1->next;
	q = head2->next;
	while(p->next!=NULL)
	{
		p = p->next;
	}

	while(q->next!=NULL)
		q = q->next;
	if(p == q)
		return true;
	return false;
}

void linkTest::mergeLink(linkNode* head1,linkNode* head2)
{
	linkNode *p1,*p2,*q1,*q2;
	linkNode *p;
	p = head1;
	p1 = head1->next;
	p2 = head2->next;
	while(p1!=NULL && p2!=NULL)
	{
		if(p1->num > p2->num)
		{
			p->next = p2;
			p = p->next;
			p2 = p2->next;
		}
		else
		{
			p->next = p1;
			p = p->next;
			p1 = p1->next;
		}
	}
	if(p1!=NULL)
		p->next = p1;
	else
		p->next = p2;

	head2->next = NULL;
	//return head1;
}

linkNode* linkTest::creatLoopLink(int n,int ind)
{
	linkNode* head;
	head = new linkNode;
	linkNode *p,*q,*s;
	head ->next = NULL;
	q = head;
	for(int i = 0;i<n;i++)
	{
		p = new linkNode;
		cout<<"请输入数值：";
		cin>>p->num;
		p->next = NULL;
		q->next = p;
		q = p;
		if((i+1) == ind)
		{
			s = p;
		}
	}
	p->next = s;
	return head;
}

bool linkTest::linkLoopJudgement(linkNode *head)
{
	linkNode *f,*s;
	f = head;
	s = head;
	if(head->next == NULL)
		return false;
	s = s->next;
	f = f->next->next;
	while(s!=NULL && f!=NULL)
	{
		if(s == f)
		{
			cout<<s->num<<endl;
			return true;
		}
		s = s->next;
		if(f->next!=NULL && f->next->next!=NULL)
			f = f->next->next;
	}
	return false;
}

linkNode* linkTest::getInterNode(linkNode *head)
{
	linkNode *f,*s;
	if(head->next == NULL)
		return false;
	s = head->next;
	f = head->next->next;
	while(s!=NULL && f!=NULL)
	{
		if(s == f)
		{
			break;
		}
		s = s->next;
		if(f->next!=NULL && f->next->next!=NULL)
			f = f->next->next;
	}
	linkNode *p;
	p = head;
	while(p!=f)
	{
		p = p->next;
		f = f->next;
	}
	return p;
}

void linkTest::linkDivision(linkNode *head,int n)
{
	linkNode *p,*q;
	linkNode *resMaxHead,*resP;
	resMaxHead = NULL;
	resP = NULL;
	p = head;
	q = head->next;
	while(q!=NULL)
	{
		if(q->num<n)
		{
			p->next = q;
			p = q;
			q = q->next;
		}
		else
		{
			if(resMaxHead!=NULL)
			{
				resP->next = q;
				resP = q;
				q = q->next;
			}
			else
			{
				resMaxHead = q;
				resP = q;
				q = q->next;
			}
		}
	}
	p->next = resMaxHead;
	resP->next = NULL;

}
void greedyAlgorith::correction(vector<int>& vec,int start,int end)
{
	if(vec[end] == vec[end-1])
	{
		for(int i = end-1;i>start;i--)
		{
			vec[i]+=1;
		}
		if(vec[start] == vec[start+1])
		{
			vec[start]+=1;
		}
	}
	
}


int greedyAlgorith::divCandy(vector<int> children)
{
	vector<int> vec(children.size(),0);
	int index = 0;
	for(int i = 0;i<children.size();i++)
	{
		if(i == 0)
			vec[0] = 1;
		else
		{
			if(children[i]>children[i-1])
			{
				vec[i]=vec[i-1]+1;
				index = i;
			}
			else if(children[i] == children[i-1])
			{
				vec[i] = 1;
				index = i;
			}
			else
			{
				vec[i] = 1;
				correction(vec,index,i);
			}

		}
	}

	int min = 0;


	for(int i = 0;i<vec.size();i++)
	{
		cout<<vec[i]<<" ";
		min+=vec[i];
	}
	cout<<endl;
	return min;

}

int greedyAlgorith::wiggleMaxLength(vector<int> num)
{
	int up,down;
	up = 1;down = 1;
	if(num.size() == 1)
		return 1;
	else if(num.size() == 0)
		return 0;
	
	for(int i = 1;i<num.size();i++)
	{
		if(num[i]>num[i-1])
		{
			up = down+1;
		}
		else if(num[i]<num[i-1])
		{
			down = up + 1;
		}
	}
	return up>down ? up:down;
}


string greedyAlgorith::removeKdigits(string num,int k)
{
	stack<int> st;
	if(num.size()<=k)return "0";
	int ind = 1;
	st.push(0);
	while(k!=0)
	{
		if(ind == num.size())
		{
			for(int i = 0;i<st.size() && k!=0;i--)
			{
				int ind0 = st.top();
				num[ind0] = '#';
				st.pop();
				k--;
			}
		}
		else
		{
			if(st.size() == 0)
			{
				st.push(ind);
				ind+=1;
			}
			int ind0 = st.top();
			if(num[ind0] > num[ind])
			{
				num[ind0] = '#';
				k--;
				st.pop();
			}
			else
			{
				st.push(ind);
				ind+=1;
			}
		}
		
	}

	return num;
}


bool greedyAlgorith::jumpNum1(vector<int > num)
{
	int ind = 0;
	int maxlen = 0;
	int length = num.size();
	int indtemp = 0;
	int len = num[ind];
	while(true)
	{

		for(int i = ind;i<=ind+len;i++)
		{
			int step = num[i]+i;
			if(step >= length-1)
				return true;
			if(maxlen < step)
			{
				maxlen = step;
				indtemp = i;
			}
		}
		
		//maxlen = 0;
		ind = maxlen;
		len = num[ind];
		maxlen = 0;
		if(len==0)
			return false;


	}
}

bool greedyAlgorith::mySort(pair<int,int>a,pair<int,int>b)
{
	return a.first<b.first;
}

void greedyAlgorith::vecSort(vector<pair<int,int>>& vec)
{
	sort(vec.begin(),vec.end(),mySort);   ///需要引用#include<algorithm>

}

int greedyAlgorith::minShot(vector<pair<int,int>> points)
{
	int times = 1;
	vecSort(points);
	int right = points[0].second;
	for(int i = 1;i<points.size();i++)
	{
		int firstTmp = points[i].first;
		if(firstTmp > right)
		{
			times+=1;
			right = points[i].second;
		}
		else
		{
			//right = points[i].second < right ? points[i].second:right;
			right = min(points[i].second,right);
		}
	}
	return times;
}



void BinTree::createBiTree(BiTree &T)
{
	int temp = 0;
	cout<<"请输入数值：";
	cin>>temp;
	if(temp == 0)
	{
		T = NULL;
	}
	else
	{

		T = new BiTreeNode;
		T->data = temp;
		createBiTree(T->lchild);
		createBiTree(T->rchild);
	}
}

void BinTree::preTraverse(BiTree T)
{
	if(T)
	{
		cout<<T->data<<" ";
		preTraverse(T->lchild);
		preTraverse(T->rchild);
	}
}

BiTree BinTree::commonNode(BiTree A,BiTree B,BiTree root)
{
	if(root == NULL)
	{
		return NULL;
	}
	if(A->data == root->data || B->data == root->data)
		return root;

	BiTree left = commonNode(A,B,root->lchild);
	BiTree right = commonNode(A,B,root->rchild);

	if(left !=NULL && right!=NULL)
		return root;
	return left == NULL ? right:left;
}

void BinTree::dfs(BiTree root,int sum)
{
	if(root == NULL)
		return;
	sum -= root->data;
	path.push_back(root->data);
	if(sum == 0 && root->lchild == NULL && root->rchild == NULL)
		pathVec.push_back(path);
	dfs(root->lchild,sum);
	dfs(root->rchild,sum);
	path.pop_back();

}


vector<vector<int>> BinTree::pathSum(BiTree root,int sum)
{
	dfs(root,sum);
	return pathVec;
}


/// 将二叉树转换为单链表形式
void BinTree::flatten(BiTree root)
{
	if(root == NULL)
		return ;
	//BiTree T = root;
	flatten(root->lchild);
	flatten(root->rchild);
	BiTree left = root->lchild;
	BiTree right = root->rchild;
	BiTree pos = root;
	if(left!=NULL)
	{
		root->rchild = left;
		while(pos->rchild!=NULL)
		{
			pos = pos->rchild;
		}
	}
	if(right!=NULL)
	{
		pos->rchild = right;
	}

}

void BinTree::printLink(BiTree root)
{
	BiTree T = root;
	while(T!=NULL)
	{
		cout<<T->data<<" ";
		T = T->rchild;
	}
	cout<<endl;
}


void BinTree::levelOrderPrint(BiTree root)
{
	if(root==NULL)
		return;
	queue<BiTree> qu;
	if(root->lchild!=NULL)
		qu.push(root->lchild);
	if(root->rchild!=NULL)
		qu.push(root->rchild);
	cout<<root->data<<" ";
	while(qu.size()!=0)
	{
		BiTree s = qu.front();
		qu.pop();
		cout<<s->data<<" ";
		if(s->lchild!=NULL)
			qu.push(s->lchild);
		if(s->rchild!=NULL)
			qu.push(s->rchild);

	}
}

BiTree BinTree::buildTree(vector<int> preorder,vector<int> inorder,int a)
{
	if(preorder.size() == 0 || inorder.size() == 0)
		return NULL;
	if(preorder.size()!=inorder.size())
		return NULL;
	
	if(a == 1)
	{
		int index = 0;
		return creatBST(preorder,inorder,0,preorder.size()-1,index);
	}
	else
	{
		int index = preorder.size()-1;
		return creatBST0(preorder,inorder,0,preorder.size()-1,index);
	}
}

BiTree BinTree::creatBST0(vector<int>postorder,vector<int>inorder,int start,int end,int& index)
{
	int pos = index;
	for(int i = start;i<=end;i++)
	{
		if(inorder[i] == postorder[index])
		{
			pos = i;
			break;
		}
	}
	BiTree T = new BiTreeNode;
	T->data = postorder[index];

	if(pos+1<=end)
	{
		T->rchild = creatBST0(postorder,inorder,pos+1,end,--index);
	}
	else
	{
		T->rchild = NULL;
	}

	if(pos-1>=start)
	{
		T->lchild = creatBST0(postorder,inorder,start,pos-1,--index);
	}
	else
	{
		T->lchild = NULL;
	}
	return T;
}




BiTree BinTree::creatBST(vector<int>preorder,vector<int>inorder,int start,int end,int& index)
{
	int pos = start;
	for(int i = start;i<=end;i++)
	{
		if(inorder[i] == preorder[index])
		{
			pos = i;
			break;
		}
	}
	BiTree T = new BiTreeNode;
	T->data = preorder[index];
	if(start<=pos-1)
	{
		T->lchild = creatBST(preorder,inorder,start,pos-1,++index);
	}
	else
	{
		T->lchild = NULL;
	}

	if(end>=pos+1)
	{
		T->rchild = creatBST(preorder,inorder,pos+1,end,++index);

	}
	else
	{
		T->rchild = NULL;
	}
	return T;
}


void BinTree::copyTree(BiTree root,BiTree& cpRoot)
{
	if(root == NULL)
		return;
	BiTree T = new BiTreeNode;
	T->data = root->data;
	cpRoot = T;
	if(root->lchild == NULL)
		T->lchild = NULL;
	else
	{
		copyTree(root->lchild,cpRoot->lchild);
	}
	if(root->rchild == NULL)
		T->rchild = NULL;
	else
	{
		copyTree(root->rchild,cpRoot->rchild);
	}
}
Trie* BinTree::creatTrieNode()
{
	Trie *q = new Trie;
	for(int i = 0;i<26;i++)
	{
		q->next[i] = NULL;
	}
	q->cnt = 0;
	return q;
}

void BinTree::insertTrie(char *str,Trie* root)
{
	int len = strlen(str);
	Trie *p,*q;
	p = root;
	for(int i = 0;i<len;i++)
	{
		char c = str[i];
		int ind = c-'a';
		if(p->next[ind] == NULL)
		{
			q = creatTrieNode();
			p->next[ind] = q;
			p = q;
		}
		else
		{
			p = p->next[ind];
		}
	}
	p->cnt+=1;

}

////  查找字典树中 词的词频
int BinTree::findTrie(char *str,Trie *root)
{
	int len = strlen(str);
	Trie *p = root;
	for(int i = 0;i<len;i++)
	{
		int ind = str[i]-'a';
		if(p->next[ind] !=NULL)
		{
			p = p->next[ind];
		}
		else
			return -1;
	}
	return p->cnt;
}

void BinTree::delTrie(Trie *T)
{
	int i;
	if(T==NULL)
		return ;
	for(i=0;i<MAX;i++)
	{
		if(T->next[i]!=NULL)
			delTrie(T->next[i]);
	}
	delete T;
	return ;
}

///
int Dynamic::climbStairs(int n)
{
	if(n == 1)
		return 1;
	else if(n == 2)
		return 2;
	else
	{
		return climbStairs(n-1)+climbStairs(n-2);
	}
}

int Dynamic::rob(vector<int> num)
{
	if(num.size() == 0)return 0;
	if(num.size() == 1) return num[0];
	int a = num[0];
	int maxSum = max(num[0],num[1]);
	for(int i = 2;i<num.size();i++)
	{
		int temp = num[i]+a;
		a = maxSum;
		maxSum = max(maxSum,temp);
	}
	return maxSum;
}


int Dynamic::maxSubArray(vector<int> num)
{
	int maxSum = 0;
	int sum = 0;
	int start = 0,end = 0;
	int pos_i = 0,pos_j = 0;
	for(int i = 0;i<num.size();i++)
	{

		if(sum == 0 && num[i]>=0)
		{
			pos_i = i;
			pos_j = i;
		}

		sum += num[i];
		if(sum>maxSum)
		{
			maxSum = sum;
			pos_j = i;
			start = pos_i;
			end = pos_j;
		}
		if(sum<0)
		{
			sum = 0;

		}
		
	}
	cout<<start<<"\t"<<end;
	return maxSum;

}

int Dynamic::miniNumTotal(vector<vector<int>> triangle)
{
	vector<vector<int>> res;
	int len = triangle.size();
	if(len == 1)
	{
		return triangle[0][0];
	}
	res = triangle;
	for(int i = len-2;i>=0;i-- )
	{
		for(int j = 0;j<=i;j++)
		{
			res[i][j] = res[i][j]+min(res[i+1][j],res[i+1][j+1]);
		}
	}
	return res[0][0];
}

int Dynamic::maxlengthsub(vector<int> vec)
{
	int len = 0;
	
	int maxLen = 0;
	int maxIndex = 0;

	for(int i = 0;i<vec.size();i++)
	{
		if(i == 0)
		{
			
			maxLen = 1;
			len = 1;
			maxIndex = i;
		}
		else
		{
			if(vec[i]>vec[i-1])
			{
				
				len+=1;
				if(len > maxLen)
				{
					maxLen = len;
					maxIndex = i;
				}

			}
			else
			{
				
				len = 1;
			}
		}
	}
	cout<<"位置是："<<maxIndex<<endl;
	return maxLen;


}