// DataStruct.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "algorithmCollection.h"

vector<vector<int>> subsets(vector<int>& nums) {
	int length=nums.size();
	sort(nums.begin(),nums.end());
	vector<vector<int> > result;
	for(int i=0;i<1<<length;i++)
	{
		cout<<length<<endl;
		int n = 1<<length;
		cout<<"数值："<<n<<endl;
		vector<int> tmp;
		//计算i中有那几位为1
		for(int j=0;j<length;j++)
		{
			//判断i中第j位是否为1
			if(i&1<<j)
			{
				tmp.push_back(nums[j]);
			}
		}
		result.push_back(tmp);
	}
	return result;
}

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	


	linkTest lk;
	greedyAlgorith ga;
	BinTree bi;
	/*BiTree root;
	bi.createBiTree(root);
	bi.preTraverse(root);
	cout<<endl;
	bi.levelOrderPrint(root);

	*/
	Dynamic dy;

	string s;
	Trie *root = bi.creatTrieNode();

	for(int i = 0;i<5;i++)
	{
		cout<<"请输入字符串：";
		cin>>s;
		bi.insertTrie((char*)s.c_str(),root);
	}
	int strCnt = bi.findTrie("asdr",root);
	cout<<"词串的个数是："<<strCnt<<endl;
	bi.delTrie(root);
	system("pause");





	vector<int> dyVec;
	dyVec.push_back(1);
	dyVec.push_back(3);
	dyVec.push_back(4);
	dyVec.push_back(5);
	dyVec.push_back(3);
	dyVec.push_back(7);
	dyVec.push_back(9);
	int mm = dy.maxlengthsub(dyVec);
	cout<<mm<<endl;
	system("pause");




	BiTree T;
	vector<int> vPre;
	vector<int> vIn;
	vector<int> vPost;
	vPre.push_back(1);
	vPre.push_back(2);
	vPre.push_back(3);
	vPre.push_back(4);
	vPre.push_back(5);
	vPre.push_back(6);
	vPre.push_back(7);
	vPre.push_back(8);
	vPre.push_back(9);
	vPre.push_back(10);
	vPre.push_back(11);

	vIn.push_back(4);
	vIn.push_back(3);
	vIn.push_back(5);
	vIn.push_back(2);
	vIn.push_back(7);
	vIn.push_back(6);
	vIn.push_back(8);
	vIn.push_back(1);
	vIn.push_back(10);
	vIn.push_back(9);
	vIn.push_back(11);

	vPost.push_back(4);
	vPost.push_back(5);
	vPost.push_back(3);
	vPost.push_back(7);
	vPost.push_back(8);
	vPost.push_back(6);
	vPost.push_back(2);
	vPost.push_back(10);
	vPost.push_back(11);
	vPost.push_back(9);
	vPost.push_back(1);


	cout<<endl;

	//T = bi.buildTree(vPre,vIn);
	T = bi.buildTree(vPost,vIn,0);
	bi.levelOrderPrint(T);
	cout<<endl;

	BiTree T1;
	bi.copyTree(T,T1);
	cout<<endl;
	bi.preTraverse(T1);
	cout<<endl;


	system("pause");





	/*vector<pair<int,int>> points;
	points.push_back(make_pair(1,6));
	points.push_back(make_pair(4,8));
	points.push_back(make_pair(8,16));
	points.push_back(make_pair(1,4));
	points.push_back(make_pair(6,10));
	//points.push_back(make_pair(18,20));
	points.push_back(make_pair(12,16));
	points.push_back(make_pair(6,16));
	
	ga.vecSort(points);
	cout<<"排序后结果："<<endl;
	for(int i = 0;i<points.size();i++)
	{

		cout<<points[i].first<<" "<<points[i].second<<endl;
	}

	int times = ga.minShot(points);
	cout<<"最少射击次数为："<<times<<endl;*/

	

	vector<int> numt; 
	numt.push_back(1);
	numt.push_back(2);
	numt.push_back(3);
	numt.push_back(4);
	vector<vector<int>> vecRes = subsets(numt);
	for(int i = 0;i<vecRes.size();i++)
	{
		
			for(int j = 0;j<vecRes[i].size();j++)
			{
				cout<<vecRes[i][j]<<" ";
			}
			cout<<endl;
	}


	system("pause");
	///跳跃游戏
	/*vector<int> num0;
	num0.push_back(3);
	num0.push_back(5);
	num0.push_back(1);
	num0.push_back(0);
	num0.push_back(4);
	//num.push_back(3);
	cout<<ga.jumpNum1(num0)<<endl;
	system("pause");
	*/
	
	/*linkNode *head1;
	head1 = lk.creatLink(5);
	lk.show(head1);
	
	linkNode *head2;
	head2 = lk.creatLink(5);
	lk.show(head2);

	lk.mergeLink(head1,head2);
	lk.show(head1);

	lk.show(head2);

	lk.deleteLink(head1);
	lk.deleteLink(head2);*/

	/*linkNode *head;
	head = lk.creatLoopLink(6,2);
	//lk.show(head);
	cout<<lk.linkLoopJudgement(head)<<endl;

	linkNode *res;
	res = lk.getInterNode(head);
	cout<<"环的入口："<<res->num<<endl;


	linkNode *head1;
	head1 = lk.creatLink(6);
	lk.linkDivision(head1,5);
	lk.show(head1);
	*/
	

	vector<int> num;
	//[1,17,5,10,13,15,10,5,16,8]
	num.push_back(1);
	num.push_back(17);
	num.push_back(5);
	num.push_back(10);
	num.push_back(13);
	num.push_back(15);
	num.push_back(10);
	num.push_back(5);
	num.push_back(16);
	num.push_back(8);
	
	int res1 = ga.wiggleMaxLength(num);
	cout<<res1<<endl;


	
	cout<<"1432219   "<<ga.removeKdigits("1432219",3)<<endl;
	cout<<"10200   "<<ga.removeKdigits("10200",1)<<endl;
	cout<<"10200   "<<ga.removeKdigits("10200",2)<<endl;
	cout<<"111111   "<<ga.removeKdigits("111111",2)<<endl;
	cout<<"1234567890   "<<ga.removeKdigits("1234567890",9)<<endl;
	cout<<"123456789   "<<ga.removeKdigits("123456789",8)<<endl;
	cout<<"10   "<<ga.removeKdigits("10",1)<<endl;


	
	vector<int> children;
	children.push_back(3);
	children.push_back(5);
	children.push_back(10);
	children.push_back(9);
	//children.push_back(4);
	//children.push_back(3);
	//children.push_back();
	for(int i = 0;i<children.size();i++)
		cout<<children[i]<<" ";
	cout<<endl;
	cout<<"最少需要糖的个数："<<ga.divCandy(children)<<endl;
	return 0;
}

