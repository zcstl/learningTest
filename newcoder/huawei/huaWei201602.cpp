#include <iostream>
#include <utility> //pair
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<string, int> ER;
bool cmpZCS(const ER&, const ER&);

int main2()
{
    string sin;
    vector<ER> res;
    while(getline(cin, sin))
    {
        //if (sin==NULL)
        if (sin.size()==0)
        {
            //
        }
        int idx=sin.rfind('\\');
        sin=sin.substr(idx+1);
        int tag(0);//()赋初始值,只能初始化时用
        for (auto tmp=res.begin(); tmp<res.end(); ++tmp)
        {
            if (tmp->first==sin)
            {
                tag=1;
                ++tmp->second;
                break;
            }
        }
        if (tag==0)
        {
            ER tmp(sin,1);
            res.push_back(tmp);
            //cout<<tmp.first<<"ffrf"<<endl;
        }
    }
    //
    stable_sort(res.begin(), res.end(), cmpZCS);
    int i(1);
    //cout<<res.size()<<endl;
    for(auto tmp=res.begin();tmp<res.end()&&i<=8;++i, ++tmp)
    {
        int idx=tmp->first.rfind(' ');
        if (idx<=16)
            cout << tmp->first<<' '<<tmp->second<<endl;
        else
        {
            tmp->first.erase(0, idx-16);
            cout << tmp->first<<' '<<tmp->second<<endl;
        }
    }
}

bool cmpZCS(const ER& t1, const ER& t2)
{
    return t2.second<t1.second;//若写反了, 上机环境只输出一个,便检测到错误于是不再输出
}




/*
//别人写的比较好的实现
//先将所有的字符串存入哈希表，key为字符串，value为<出现顺序，出现次数>，顺序取相同的字符串的最小值，次数一直累加
//排序的话，利用set重写比较器，按次数降序，次数相同则按出现顺序排列
//插入过程利用hash时间复杂度可以认为是O(n)
//排序过程set的是红黑树，可以认为是O(nlgn) ,总的复杂度就是这个了
#include<iostream>
#include<unordered_map>
#include<set>
#include<string.h>
using namespace std;
struct info{//记录出现的顺序，和次数
    int rank;
    int count;
    info(int rank,int count){
        this->rank=rank;
        this->count=count;
    }
};
struct fullinfo{//一条完整的结果，字符串和次数
    string file;
    int rank;
    int count;
    fullinfo(string file,int rank,int count){
        this->file=file;
        this->rank=rank;
        this->count=count;
    }
};
struct classcomp {//set的比较器
  bool operator()(const struct fullinfo& f1,const struct fullinfo& f2){
        if(f1.count==f2.count)
            return f1.rank<f2.rank;
        return f1.count>f2.count;
    }
};
typedef struct info INFO;
typedef struct fullinfo FULLINFO;
int main(){
    unordered_map<string,INFO> record;
    unordered_map<string,INFO>::iterator it;
    unordered_map<string,INFO>::const_iterator itfind;
    set<FULLINFO,classcomp> ret;
    set<FULLINFO,classcomp>::iterator sit;
    string linestr;//一行输入
    string file;//文件名+行号
    int pos;//空格的位置
    int i=1;
    while(getline(cin,linestr)){
        if(linestr.length()==0)
            break;
        pos=linestr.rfind("\\");
        file=linestr.substr(pos+1);//拆分得到最后的filename和count
        itfind=record.find(file);//在map中查看是否已经有了该字符串，没有则插入，有则次数加1
        if(itfind==record.end()){
            INFO tmpi(i,1);
            record.insert(pair<string,INFO>(file,tmpi));
        }
        else{
            INFO tmpi(itfind->second.rank,itfind->second.count+1);
            record.erase(file);
            record.insert(pair<string,INFO>(file,tmpi));
        }
        i++;
    }
    for(it=record.begin();it!=record.end();it++){
        FULLINFO tmpfull(it->first,it->second.rank,it->second.count);//构建排序的set集合
        ret.insert(tmpfull);
    }
    for(i=0,sit=ret.begin();sit!=ret.end()&&i<8;++sit,++i){//最多输出8条记录，file少于16位
        if(file.find(" ")<=16){
            cout<<(*sit).file<<" "<<(*sit).count<<endl;
            }
        else{
            cout<<(*sit).file.substr(file.find(" ")-16)<<" "<<(*sit).count<<endl;
        }

    }
    return 0;
}

*/
/*
//能够正确运行, 但代码写的low
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

struct ER
{
    string fName;
    int rNumber;
    int times;
    ER():fName(""), rNumber(0), times(0){}
};

string getFileName(string);
vector<ER>::iterator findER(vector<ER>&, const ER&);
bool cmpER(const ER&, const ER&);
string getLast(const string&);

int main2()
{
    vector<ER> ins;
    string fn;
    int rown;
    while(cin >> fn >> rown)
    {
        ER arow;
        fn=getFileName(fn);
        arow.fName=fn;
        arow.rNumber=rown;
        ++arow.times;
        //string tmp(fn+" "+to_string(rown));
        vector<ER>::iterator tmp ;
        if ((tmp=findER(ins, arow))==ins.end())
            ins.insert(ins.end(), arow);
        else
           ++tmp->times;
    }
    sort(ins.begin(), ins.end(), cmpER);
    //auto 为ER
    int ot(1);
    for (auto tmp=ins.begin(); tmp<ins.end()&&ot<=8; ++ot, ++tmp)
        cout << getLast(tmp->fName) << " " << tmp->rNumber << " " << tmp->times << endl;
    return 0;
}


string getLast(const string& s)
{
    int lastNum(16);
    if (s.size()<=16)
        return s;
    string res;
    for (int i=s.size()-lastNum; i<s.size(); ++i)
        res=res+s[i];
    return res;
}

string getFileName(string s)
{
    int idx=s.find_last_of('\\');
    if (idx==-1)
        return nullptr;
    //cout<<idx<<endl;
    string res;
    for ( int i=idx+1; i<s.size(); ++i)
        res=res+s[i];
    return res;
}

vector<ER>::iterator findER(vector<ER>& ERS, const ER& aER)
{
    for (auto tmp = ERS.begin();tmp < ERS.end(); ++tmp)
    {
        if ((tmp->fName==aER.fName) && (tmp->rNumber==aER.rNumber))
        {
            //++tmp->tAmes;
            return tmp;
        }
    }
    return ERS.end();
}
bool cmpER(const ER& e1, const ER& e2)
{
    //if ((e1.fName<e2.fName)&&(e1.rNumber<e2.rNumber))
    if (e2.times<e1.times)
        return true;
    else
        return false;
}
*/




/*
//题意理解错了
#include <iostream>
#include <map>
#include <algorithm>  //sort
#include <string>
#include <string.h>  //strcpy strtok

using namespace std;

typedef pair<string, int> PAIR;
bool cmpByValue(const PAIR& p1, const PAIR& p2);

int main()
{
    string oneInput;
    //char tmp[1024];
    int rowN;
    //map采用红黑树实现, 是关联容器, begin()往往不是第一个插入的元素
    map<string, int> res;
    while(cin>>oneInput)
    {
        cin>>rowN;
        //to_string 把int转化为string的static方法
        ++res[oneInput+" "+to_string(rowN)];
    }
    //把容器元素放入vector, constructor
    vector<PAIR> resTmp(res.begin(),res.end());
    //sort这类排序模板函数的两个版本
    sort(resTmp.begin(),resTmp.end(),cmpByValue);
    //sort(resTmp.begin(),resTmp.end());
    char* f1(nullptr);
    char* f2(nullptr);
    for(auto i=resTmp.begin();i<resTmp.end();++i)
    {
        //string对象的c_str成员函数返回的是const char*
        char* tmp=(char*)malloc(1024*sizeof(char));
        strcpy(tmp,i->first.c_str());
        //strtok根据指定分隔符截断字符串返回第一个子段的char*, 随后使用NULL返回下一个子段
        f1=strtok(tmp," ");
        f2=strtok(NULL," ");
        cout<<f1<<" "<<f2<<" "<<i->second<<endl;
    }

}

bool cmpByValue(const PAIR& p1, const PAIR& p2)
{
    return p1.second<p2.second;
}
*/
