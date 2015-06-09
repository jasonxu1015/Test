// test.cpp : 定义控制台应用程序的入口点。
//

#include<stdlib.h>
#include <string>
#include <assert.h>
#include <stdio.h>
#include <iostream>
#include <map>
#include<vector>
#include <time.h>
using namespace std;
class A;

#define year_second (365*24*60*60)UL
#define MAX_LEN 10000


//hash begin***********************************************************************************************************
typedef struct _node
{
	char *name;
	char *desc;
	struct _node *next;
} node;

#define HASHSIZE 101
static node* hashtab[HASHSIZE];

void inithashtab()
{
	int i;
	for(i=0; i < HASHSIZE; i++)
		hashtab[i]=NULL;
}

unsigned int hashfun(char *s)
{
	unsigned int h=0;
	for(; *s; s++)
		h=*s+h*31;
	return h%HASHSIZE;
}

node* lookup(char *n)
{
	unsigned int hi=hashfun(n);
	node* np=hashtab[hi];
	for(; np!=NULL; np=np->next)
	{
		if(!strcmp(np->name,n))
			return np;
	}

	return NULL;
}

char* m_strdup(char *o)
{
	int l=strlen(o)+1;
	char *ns=(char*)malloc(l*sizeof(char));
	strcpy(ns,o);
	if(ns==NULL)
		return NULL;
	else
		return ns;
}

char* get(char* name)
{
	node* n=lookup(name);
	if(n==NULL)
		return NULL;
	else
		return n->desc;
}

int install(char* name,char* desc)
{
	unsigned int hi;
	node* np;
	if((np=lookup(name))==NULL)
	{
		hi=hashfun(name);
		np=(node*)malloc(sizeof(node));
		if(np==NULL)
			return 0;
		np->name=m_strdup(name);
		if(np->name==NULL) return 0;
		np->next=hashtab[hi];//现有的hashtab数组保存的是最近插入的节点地址，需要先保存在当前插入节点的next指针里面
		hashtab[hi]=np;
	}
	else
		free(np->desc);//如果已存在，则需要free掉原来的值，保存新值
	np->desc=m_strdup(desc);
	if(np->desc==NULL) return 0;

	return 1;
}

/* A pretty useless but good debugging function,
which simply displays the hashtable in (key.value) pairs
*/
void displaytable()
{
	int i;
	node *t;
	for(i=0; i < HASHSIZE; i++)
	{
		if(hashtab[i]==NULL)
			printf("()");
		else
		{
			t=hashtab[i];
			printf("(");
			for(; t!=NULL; t=t->next)
				printf("(%s.%s) ",t->name,t->desc);
			printf(".)");
		}
	}
}

void cleanup()
{
	int i;
	node *np,*t;
	for(i=0; i < HASHSIZE; i++)
	{
		if(hashtab[i]!=NULL)
		{
			np=hashtab[i];
			while(np!=NULL)
			{
				t=np->next;
				free(np->name);
				free(np->desc);
				free(np);
				np=t;
			}
		}
	}
}

//hash end***********************************************************************************************************


template<class T>

T xmin(T a, T b)
{
	return (a < b)?a:b;
}
void Bubble_Sort(int A[], int n);
void quick_sort(int s[], int l, int r);

class test1
{
	double a;
	float b;
	int c;
	char d;
};

char * GetString(char * dest, char * str)
{
	if (NULL == str || (0 == strlen(str)))
	{
		return NULL;
	}
	char *p = str;

	while(*p != '.' && '\0' != *p && (*p <'0' || *p >'9'))
		p ++;

	strncpy(dest, str, (p - str)/sizeof(char));
	memset(dest + (p - str)/sizeof(char), 0, 1);
	return dest;
}




class A
{

	public:
	int * pInt;
	public:
	int a;

public:


	void test(){cout<<"base"<<endl;}
	A():pInt(NULL)
	{
		a = 11811;
		cout<<"构造函数已调用"<<endl;
		pInt = new int[10];
		for (int i = 0; i < 10; i++)
		{
			pInt[i] = i;
		}
	}

	A(const  A &a)
	{

		pInt = new int[10];

		memcpy(pInt, a.pInt, 10 * sizeof(int));
		cout<<"拷贝构造函数已调用"<<endl;
	}

	A& operator = (const A & a)
	{
		cout<<"赋值函数已调用"<<endl;

		if (this == &a)
		{
			cout<<"自我复制"<<endl;
			return *this;
		}

		if (pInt)
		{
			cout<<"删除原有数据"<<endl;
			delete []pInt;
			pInt = NULL;
		}

		pInt = new int[10];
		memcpy(pInt, a.pInt, 10 * sizeof(int));
		
		return *this;

	}

	~A()
	{
		cout<<"析构函数已调用"<<endl;

		if (NULL != pInt)
		{
			delete [] pInt;
		}
	}

	void get()
	{
		for (int i = 0; i < 10; i++)
		{
			cout<<pInt[i]<<endl;
		}
	}

};

class B : public A
{
public:
	void test(){ a = 222; }
	B()
	{
		a = 33333;
	}

};




class Base
{
	// void  f(int){};
	// void f(double){};
	// void g(int a =10){};
	//virtual void g2(int b = 20){};

	//int a;
	//int b;
	int a;
	static int b;
};

void funabc(char v[] ){ 
	int b = sizeof(v);
	printf("%d", b);
int a = 234;}



//////////////////////////////////////////////////////////////////////////
#define DO_CAT3(a,b,c) a##b##c


#define REGISTER_XML_CLASS(key,driveclass) \
class driveclass##creator : public CCMTCreatorBase  \
{ \
public: \
	driveclass##creator(const char* szkey): CCMTCreatorBase(szkey){}; \
	virtual CBaseXML* Create() \
{ \
	return new driveclass; \
} \
}; \
	driveclass##creator DO_CAT3(driveclass,_,__LINE__)(key);

//////////////////////////////////////////////////////////////////////////

class MyClass
{
};

bool ShfsChkAcctIdFT( string sAcctId )
{

    if ( !strncmp(sAcctId.c_str() , "FTE" , 3) \
        || !strncmp(sAcctId.c_str() , "FTU" , 3)\
        || !strncmp(sAcctId.c_str() , "FTI" , 3) \
        || !strncmp(sAcctId.c_str() , "FTF" , 3)\
        || !strncmp(sAcctId.c_str(), "FTN" , 3) )
    {
        return true;
    }
    else
        return false;
}

#define Find(struc, e) (size_t)&(((struc*)0) ->e);
#define abc 12UL
struct  student
{
    int a;
    char b[20];
    double c;
};

struct SysRefData
{
    char m_szConnDBStr[80];	// 数据库连接串 没有结束符号 左对齐右补空
    char m_szQMGR[20];		// MQ管理器名称
    int  m_bRunFlag;		// FALSE:停止 TRUE:允许
    int  m_nOnlyIndex;		// 唯一索引 生成CMT报文de MSGID
    int  m_nTraceLevel;		// Trace信息等级
    int  m_nMaxProcessCount;// 最大进程数
    int	 m_nCMTProCount;	// CMT报文处理处理程序个数
    int  m_nCMTProOffset;	// CMT报文处理程序表项开始位置偏移
};



#define MIN(a, b) ((a) > (b)?(b): (a))

//string halfToFull(const string  str) 
//{ 
//	char * src = new char[str.length()+1]; 
//	memset(src,0,str.length()+1);
//	strcpy(src,str.c_str()); 
//
//	char* dest = new char[2 *	str.length()];
//	memset(dest,0,2*str.length()); 
//	int k =	0; 
//	for (int i = 0;i< str.length();i++) 
//	{ 
//		if (src[i]
//		<=127 && src[i]
//		> 32) {
//			dest[k] =
//				(char)163; 
//			dest[k+1] = (char)(src[i] +
//				128); 
//			k +=
//				2; 
//		}
//		else 
//		{
//			dest[k] =
//				src[i]; 
//			k++; 
//		}
//	}
//	string fullStr = string(dest);
//	return fullStr; 
//}
string ToDBS(const string str) {  
	string result = "";  
	unsigned char tmp; unsigned char tmp1;  
	for (unsigned int i = 0; i < str.length(); i++) {  
		tmp = str[i];  
		tmp1 = str[i + 1];  
		if (tmp == 163) {///第一个字节是163，标志着是全角字符  
			result += (unsigned char) str[i + 1] - 128;  
			i++;  
			continue;  
		} else if (tmp > 163) {//汉字  
			result += str.substr(i, 2);  
			i++;  
			continue;  
		} else if (tmp == 161 && tmp1 == 161) {///处理全角空格  
			result += "";  
			i++;  
		} else {  
			result += str.substr(i, 1); } 
	}
    return result;  
}  

//char * strcpy(char *strDest, const char *strSrc)
//{
//
//    if (NULL == strDest)
//    {
//        throw(1.0);
//    }
//
//    int i = 0;
//    for (; strSrc[i] != '\0'; i++)
//    {
//        strDest[i] = strSrc[i];
//    }
//    strDest[i] = '\0';
//    return strDest;
//}


//char * strcpy(char *strDest, const char *strSrc)
//{
//    if ((NULL == strDest) || (NULL == strSrc))
//    {
//        throw("err");
//    }
//    char *strDestCopy = strDest;
//    while((*strDest++ = *strSrc++) != '\0')
//        ;
//    return strDestCopy;
//}
void fun(int a, int b)
{
    a = b;
}

int max(int a, int b)
{
	return a > b?a:b;
}

class NetworkService
{
public:
	// 对外提供的唯一方法函数，用于获取唯一的对象指针
	static NetworkService* GetInstance()
	{
		if(m_pInstance == NULL)
		{
			m_pInstance = new NetworkService();
		}
		return m_pInstance;
	}

private:
	// 构造函数设置为私有，禁止用户另外创建对象
	NetworkService();
	static NetworkService* m_pInstance;

	// 实现私有内嵌类, 用于类NetworkService的对象资源的释放
	class Garbo
	{
	public:
		~Garbo()
		{
			if(NetworkService::m_pInstance)
			{
				delete m_pInstance;
			}
		}
	};
	// 程序运行结束时，系统会调用NetService的静态成员garbo的析构函数，
	// 该系够函数会删除NetService类的唯一实例
	static Garbo garbo;
};

char * strcpy(char * dest, const char * str)
{
	assert((NULL != dest) && (NULL != str));
	char * pTmpDest = dest;
	while('\0' != (*dest++ = *str++))
	{}
	return pTmpDest;	
}


class String
{
public:
	String();
	String(const char * pstr);
	~String();
	String(const String & other);
	String & operator = (const String & other);
	String & operator = (const char *pOther);

private:
	char * pBuf;
	int nLen;

};

String::String()
	:pBuf(NULL), nLen(0)
{
}

String::String(const char *pstr)
{
	if (NULL == pstr)
	{
		pBuf = new char[1];
		*pBuf = '\0';
	}
	else
	{
		nLen = strlen(pstr);
		pBuf = new char[nLen + 1];
		memset(pBuf, 0 ,sizeof(pBuf));
		strncpy(pBuf, pstr, nLen);
	}
}

String::~String()
{
	if (pBuf)
	{
		delete [] pBuf;
	}
	nLen = 0;
}

String::String(const String & strOther)
{
	nLen = strOther.nLen;
	pBuf = new char[nLen + 1];
	memset(pBuf, 0, sizeof(pBuf));
	strncpy(pBuf, strOther.pBuf, nLen);
}

String & String::operator=(const String & strOther)
{
	if (this == &strOther)
	{
		return *this;
	}
	nLen = strOther.nLen;
	if (pBuf)
	{
		delete [] pBuf;
	}

	pBuf = new char[nLen + 1];
	if (NULL == pBuf)
	{
		cerr << "error" << endl;
	}
	else
	{
		memset(pBuf, 0, sizeof(pBuf));
		strncpy(pBuf, strOther.pBuf, nLen);
	}
	return *this;
}

String & String::operator=(const char * pOther)
{
	nLen = strlen(pOther);
	if (pBuf)
	{
		delete [] pBuf;
	}
	pBuf = new char[nLen + 1];
	strcpy(pBuf, pOther);

	return *this;
}




class A1
{
};
class B1
{
public:
	B1() {}
	~B1() {}
};
class C1
{
public:
	C1() {}
	virtual ~C1() {};
	virtual void C11() {};

};
const char rstr[] = 
{
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  62,   0,   0,   0,  63, 
	52,  53,  54,  55,  56,  57,  58,  59,  60,  61,   0,   0,   0,   0,   0,   0, 
	0,   0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14, 
	15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,   0,   0,   0,   0,   0, 
	0,  26,  27,  28,  29,  30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40, 
	41,  42,  43,  44,  45,  46,  47,  48,  49,  50,  51,   0,   0,   0,   0,   0
};


void decode(const std::string& input,std::string& output)
{
	size_t i = 0;
	size_t l = input.size();

	output = "";
	while (i < l)
	{
		while (i < l && (input[i] == 13 || input[i] == 10))
			i++;
		if (i < l)
		{
			char b1 = (char)((rstr[(int)input[i]] << 2 & 0xfc) +
				(rstr[(int)input[i + 1]] >> 4 & 0x03));
			output += b1;
			if (input[i + 2] != '=')
			{
				char b2 = (char)((rstr[(int)input[i + 1]] << 4 & 0xf0) +
					(rstr[(int)input[i + 2]] >> 2 & 0x0f));
				output += b2;
			}
			if (input[i + 3] != '=')
			{
				char b3 = (char)((rstr[(int)input[i + 2]] << 6 & 0xc0) +
					rstr[(int)input[i + 3]]);
				output += b3;
			}
			i += 4;
		}
	}
}

string replace(string str,const string old_value, const string new_value)   
{
	string::size_type pos(string::npos);   
	pos=str.find(old_value);
	for (;pos!=string::npos;)
	{
		str.replace(pos, old_value.length(), new_value);   
		pos=str.find(old_value, pos+new_value.length());
	}
	return str;
}

class test
{
public:

	virtual ~test(void){}

public:
	long l;
	char c;
	int i;
	short s;
	static short ss;
};

short test::ss = 2;


void InsertSortArray(int arr[] , int n) 
{
	for(int i=1;i<n;i++)//循环从第二个数组元素开始，因为arr[0]作为最初已排序部分 
	{
		int temp=arr[i];//temp标记为未排序第一个元素 
		int j=i-1;
		while (j>=0 && arr[j]>temp)/*将temp与已排序元素从大到小比较，寻找temp应插入的位置*/
		{ 
			arr[j+1]=arr[j];  
			j--; 
		} 
		arr[j+1]=temp; 
	} 
} 



int binary_search(int * a, int len, int goal);


int binary_search(int* a, int len, int goal)
{
	int low = 0;
	int high = len - 1;
	while(low <= high)
	{
		int middle = (low + high)/2;
		if(a[middle] == goal)
			return middle;
		//在左半边
		else if(a[middle] > goal)
			high = middle - 1;
		//在右半边
		else
			low = middle + 1;
	}
	//没找到
	return -1;
}
void PrintArray(int* a, int n)
{
	cout << "Begin" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
	cout << "End" << endl;
}

int binary_search1(int s[], int n, int goal)
{
	int low = 0, high = n - 1;
	while(low < high)
	{
		int x = (high + low) / 2;
		if (s[x] == goal)
		{
			return x;
		}
		else if(s[x] < goal)
		{
			low = x + 1;
		}
		else
		{
			high = x-1;
		}
	}
	return -1;
}

class X
{
public:
	X( void ):j( 1 ),i( 1 + j ){};
	int get(){return j;};

protected:
	int i;
	int j;
};
bool CheckByteOrder (void)
{
	int i = 1; 
	return * ( char * )& i;
}



void LoopMove ( char *pStr, int steps )
{
	int n = strlen( pStr ) - steps;
	char tmp[MAX_LEN]; 
	memcpy( tmp, pStr + n, steps ); 
	memcpy(pStr + steps, pStr, n ); 
	memcpy(pStr, tmp, steps ); 
}

int checkSystem( )
{
	union check
	{
		int i;
		char ch;
	} c;
	c.i = 1;
	return (c.ch ==1);
}

char* Reverse(char* s)
{
	// p指向字符串头部
	char* p = s ;

	// q指向字符串尾部
	char* q = s ;
	while( *q )
		++q ;
	q -- ;

	// 交换并移动指针，直到p和q交叉
	while(q > p)
	{
		char t = *p ;
		*p++ = *q ;
		*q-- = t ;
	}

	return s ;
}
void fun( int a )
{
	printf( "%d", a%10 );
	a /= 10;
	if( a <=0 )return;
	fun( a );
}

void GetMemory(char **p, int nNum)
{
	*p = new char[nNum];
}
bool IsBigendian()

{

	unsigned short usData = 0x1122;

	unsigned char *pucData = (unsigned char*)&usData;

	return (*pucData == 0x22);

}

int AmtCompare(double dAmt1, double dAmt2)
{
	char szAmt1[19+1] = {0};
	char szAmt2[19+1] = {0};

	sprintf(szAmt1, "%18.2f", dAmt1);
	sprintf(szAmt2, "%18.2f", dAmt2);

	return strncmp(szAmt1, szAmt2, 18);
}


int main(int argc, char* argv[])
{

	//hash test begin********************************************************************************************************
	int i;
	char* names[]= {"name","address","phone","k101","k110"};
	char* descs[]= {"Sourav","Sinagor","26300788","Value1","Value2"};

	inithashtab();
	for(i=0; i < 5; i++)
		install(names[i],descs[i]);

	printf("Done");
	printf("If we didnt do anything wrong..""we should see %s\n",get("k110"));

	install("phone","9433120451");

	printf("Again if we go right, we have %s and %s",get("k101"),get("phone"));

	/*displaytable();*/
	cleanup();

	//hash test end**********************************************************************************************************
	
	//double a = 9999999999999999.99;
	//cout << a << endl;
	//char *pMem = NULL;
	//GetMemory(&pMem, 100);//
	//memset(pMem, 0, sizeof(100));
	//strcpy(pMem, "abc");
	//int iji = 789;
	//fun(iji);

	//char buf[MAX_LEN];
	//int u;
	////gets(buf);
	//bool badsf =CheckByteOrder();


	//char szSql[2048+1] = {0};



	
	//////////////////////////////////////////////////////////////////////////
	//char asf[] = "abcdefg";
	//LoopMove(asf, 3);


	//int i = 1;
	//char *p = (char *)&i;
	//printf("%d", *p);

	//int b[10] = {8, 0,1,  4,3,  5, 6, 2,7, 9};
	//InsertSortArray(b, 10);

	//int a[10] = {0, 1,2,  3,4,  5, 6, 7,8, 9};
	//int x = binary_search1(a, 10, 4);
	//
	//int adf = 3;
	//////////////////////////////////////////////////////////////////////////
	////生成大数组
	//srand((unsigned)time(NULL));
	//clock_t lBeginTime = clock();
	//const int nlen = 10000;
	//int a[nlen];
	//for (int i = 0; i < nlen; i++)
	//{
	//	a[i] = rand(); 
	//}
	//a[1000] = 1181;
	//clock_t lEndTime = clock();
	//double nSecond = (double)(lEndTime - lBeginTime) / CLOCKS_PER_SEC;
	//cout<<"生成数组用时" << nSecond << "秒"	<<endl;
	////PrintArray(a, nlen);
	//
	////排序测试
	//lBeginTime = clock();
	//InsertSortArray(a,nlen);
	////PrintArray(a, nlen);
	//lEndTime = clock();
	//nSecond = (double)(lEndTime - lBeginTime) / CLOCKS_PER_SEC;
	//cout<<"排序数组用时" << nSecond << "秒"	<<endl;

	////查找测试
	//lBeginTime = clock();
	//int pos = binary_search(b,10,5);
	//if (-1 == pos)
	//{
	//	cout << "没有找到数据" << endl;
	//}
	//else
	//{
	//	cout << "位置为" << pos <<endl;
	//}
	//
	////PrintArray(a, nlen);
	//lEndTime = clock();
	//nSecond = (double)(lEndTime - lBeginTime) / CLOCKS_PER_SEC;
	//cout<<"查找数组用时" << nSecond << "秒"	<<endl;
		

	//////////////////////////////////////////////////////////////////////////
	//long beginTime=clock();
	//long endTime=clock();  
	//cout<< endTime-beginTime<< endl;  
	// 

	//std::string str = "Meet the  new boss...";
	//std::hash<std::string> hash_fn;
	//std::size_t str_hash = hash_fn(str);

	//std::cout << str_hash << '\n';
	//////////////////////////////////////////////////////////////////////////
	system("pause");
	//map<int, map<int,int> > mm;



	//char str[] ="This is a sample string,just testing.";
	//char * pch;
	//printf ("Splitting string \"%s\" in tokens:\n",str);
	//pch = strtok (str," ");
	//while (pch != NULL)
	//{
	//	printf ("%s\n",pch);
	//	pch = strtok (NULL, " ,.");
	//}






	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
	//string a = "中国（银行abc），，";
	//string b = "中国(银行ａｂｃ）,,";

	//string c = ToDBS(a);
	//string d = ToDBS(b);
	//

	//if (c == d)
	//{
	//	printf("相等\n");
	//}
	//else
	//{
	//	printf("不等\n");
	//}

    //////////////////////////////////////////////////////////////////////////

    //char * a = "abc";
    //char * b = new char[10];
    //char *c = (char *)malloc(sizeof(char) * 10);
    //memset(c, 0, sizeof(c));
    //try
    //{
    //    //strcpy(b, a);
    //    strcpy(c, a);
    //}
    //catch(...)
    //{
    //    int a = 0;
    //}
    //int cb =3;
    //delete [] b;
    //b = NULL;

    //free(c);
    //c = NULL;


    //////////////////////////////////////////////////////////////////////////


    //const int n=10;
    //int a[n];
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    
    //int *p  = (int *)malloc(sizeof(int) * 10);
    //p[0] = 0;
    //p[1] = 1;
    //p[2] = 2;
    //p[3] = 3;
    //p[4] = 4;

    //printf("0x%08x, 0x%08x, 0x%08x\n\r", p+1, *(p+1), p[2]);

    //int q[10] = {0, 1, 2, 3, 4};
    //printf("0x%08x,0x%08x, 0x%08x\n\r", q+1, *(q+1), q[2]);

    //////////////////////////////////////////////////////////////////////////


    //////////////////////////////////////////////////////////////////////////

    //string strTest = "中文。";
    //int nLen = strlen(strTest.c_str());
    //int nSize = sizeof(strTest);

    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    //string a = "a";
    //string b = "b";
    //if (a.empty() && b.empty())
    //{
    //    int c = 1;
    //}



    //////////////////////////////////////////////////////////////////////////


    //////////////////////////////////////////////////////////////////////////
    //string a = "FT21";
    //bool b = ShfsChkAcctIdFT(a);


    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////

    //FILE*stream;
    //char msg[]="this is a test";
    //char buf[1024 * 500] = {0};
    //if((stream=fopen("C:\\Users\\Yang\\Desktop\\3129test","r+"))==NULL)
    //{
    //    fprintf(stderr,"Cannotopenoutputfile.\n");
    //    return 0;
    //}
    /////*write some data to thefile*/
    ////fwrite(msg,1,strlen(msg)+1,stream);
    /////*sizeof（char）=1seektothebeginningofthefile*/
    ////fseek(stream,0,SEEK_SET);
    ///*read the data and display it*/

    //fseek(stream, 0, SEEK_END);

    //// 得到当前指针位置, 即是文件的长度~
    //int nLen = ftell(stream);

    //// 文件指针恢复到文件头位置~
    //rewind(stream);
    //fread(buf,sizeof(char),nLen,stream);
    //printf("%s\n",buf);
    //fclose(stream);
    //////////////////////////////////////////////////////////////////////////


    //////////////////////////////////////////////////////////////////////////

    //SysRefData pData;
    //char* pOffset0 = (char*)&pData[0];
    //char* pOffset1 = (char*)&pData[1];
    //char* pOffset = (char*)&pData;

	//int a[5]={1,2,3,4,5};
	//int *ptr=(int *)(&a+1);
	//printf("%d,%d",*(a+1),*(ptr-1));
    /////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//string a = "abc";
//string b = "ab";
//size_t A = sizeof(a);
//size_t B = sizeof(b);
//size_t C = sizeof(string);
//
//size_t D = sizeof(MyClass);
//
//int saf = sizeof(Base);
//int sa = sizeof(int);
//
//char sfas[10];
//int sadsf = sizeof(sfas);
//funabc(sfas);
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////// 

//char * c = "abc";
//char c[] = "abc";
//*c = 't';
//*

	//int a[3];
	//a[0] = 0;
	//a[1] = 1;
	//a[2] = 2;


	//int x, y;
	//cin >> x>>y;
	//cout<<x<<" "<<y<<endl;

	//int (*pfun)(int, int) = max;
	//int x = 234, y = 456, z = 2;
	//int nResult = pfun(pfun(x, y), z);
	//cout << nResult << endl;

	//int v[2][10] = {{1,2,3,4,5,6,7,8,9,10}, {11,12,13,14,15,16,17,18,19,20}};

	//int (*p)[10] = v;

	//cout << *p;


	//int arr[] = {1,2,3,4,5};
	//int *p = (int*)(arr + 1);
	//int *q = (int*)(&arr + 1);

	//cout<<*p<<" "<<*q;

//int a[2][5] = {{1,2,3,4,5}, {6,7,8,9,10}};
//
//	int *p = (int*)(a + 1);
//	int *q = (int*)(&a + 1);
//
//	cout<<*p<<" "<<*q;
//
// 
// 


//A* a = new A();
//
//A b;
//
//b = *a;
//
//delete a;
//
//b.get();

//B b;
//b.test();

	//char * abcw = "sfdsafsa1wea";
	//char abcw[100] = {"sfdsafsa1wea"};
	//char * b = new char[100];
	//memset(b, 9, sizeof(b));
	//string c = GetString(b, abcw);
//////////////////////////////////////////////////////////////////////////


	return 0;
}



void Bubble_Sort(int A[], int n)
{
	int nTmp;
	int nFlag = 0;
	for (int i = 0; i < n - 1; i++)
	{
		nFlag = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				nTmp = A[j + 1];
				A[j + 1] = A[j];
				A[j] = nTmp;
				nFlag = 1;
			}
		}
		if (0 == nFlag)
			break;
	}
}


//快速排序
void quick_sort(int s[], int l, int r)
{
	if (l < r)
	{
		//Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
				j--;  
			if(i < j) 
				s[i++] = s[j];

			while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
				i++;  
			if(i < j) 
				s[j--] = s[i];
		}
		s[i] = x;
		quick_sort(s, l, i - 1); // 递归调用 
		quick_sort(s, i + 1, r);
	}
}

