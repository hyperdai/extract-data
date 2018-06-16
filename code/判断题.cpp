#include <bits/stdc++.h>
#define _xx ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long LL;
struct mes
{
    string problem,choice[30],answer,number;
};
vector<mes>m;
mes p;
int is_cha(string b)
{
    if(b=="，"||b=="。"||b=="；"||b=="："||b=="."||b==";"||b==","||b==":"||b=="、"||b==" ")
    return true;
    return false;
}
void println()
{
    string str;
    cout<<"请输入你想生成的文件名：";
    cin>>str;
    ofstream out(str);
    for(int i=0; i<m.size(); i++)
    {
        //out<<"题目描述："
        out<<m[i].problem<<"||";
        //out<<"题目答案："
        if(m[i].answer=="√")m[i].answer="A";
        else m[i].answer="B";
        out<<m[i].answer<<"||对||错";
        out<<"<>";
    }
    out.close();
}
void clear_mes(mes &p)
{
    p.problem.resize(0);
    p.answer.resize(0);
    for(int i=0;p.choice[i].size()!=0;i++)
        p.choice[i].resize(0);
}
int main()
{
    string messa,name;
    int is_pro=1,is_cho=0,is_dot=0,is_number=1,is_letter=1,t=0;
    cout<<"请输入你要读取的文件名："<<endl;
    cin>>name;
    ifstream myfile(name);
    while(getline(myfile,messa))
    {
        int i=0;
        string a;
        a=messa[i];
        if(a[0]<0)
            a+=messa[i+1];
        while(messa[i]!='\0'&&is_cha(a))
        {
           i++;
           if(messa[i]<0)
            i=i+2;
           a=messa[i];
           if(a[0]<0)
           a+=messa[i+1];
        }
        if(isdigit(messa[i]))
        {
            if(t!=0)
            {
                m.push_back(p);
                clear_mes(p);
            }
            string b;
            i++;
            while(isdigit(messa[i]))
            i++;
            b=messa[i];
            i++;
            if(b[0]<0)
            {
                b+=messa[i];
                i++;
            }
            is_letter=1;
            is_pro=1;
        }
        while(messa[i]!='\0')
        {
            if(is_pro)
            {
                string a;
                while(messa[i]!='\0')
                {
                    if(messa[i+1]!='\0')
                    {
                        a=messa[i];
                        a+=messa[i+1];
                    }
                    if((a=="（"||messa[i]=='('))
                    {
                        int j=i+1;
                        string b;
                        if(messa[i]<0)
                            j++;
                        while(messa[j]==' ')
                            j++;
                        b=messa[j];
                        b+=messa[j+1];
                        if(b=="√"||b=="×")
                            break;
                    }
                    if(messa[i]!=' ')
                    {
                        if(messa[i]<0)
                        {
                            p.problem+=messa[i];
                            p.problem+=messa[i+1];
                            i=i+2;
                        }
                        else
                        {
                            p.problem+=messa[i];
                            i++;
                        }
                    }
                    else
                        i++;
                }
                if(a=="（"||messa[i]=='(')
                {
                    if(messa[i]<0)
                    i++;
                    i++;
                    while(messa[i]!='\0'&&(a!="）"&&messa[i]!=')'))
                    {
                        if(messa[i]!=' ')
                        {
                            if(messa[i]<0)
                            {
                                p.answer+=messa[i];
                                p.answer+=messa[i+1];
                                i=i+2;
                            }
                            else
                            {
                                p.answer+=messa[i];
                                i++;
                            }
                        }
                        else
                        i++;
                        if(messa[i+1]!='\0')
                        {
                            a=messa[i];
                            a+=messa[i+1];
                        }
                    }
                    i++;
                    if(messa[i]<0)
                        i++;
                }
                while(messa[i]!='\0')
                {
                    if(messa[i]!=' ')
                    {
                        if(messa[i]<0)
                        {
                            p.problem+=messa[i];
                            p.problem+=messa[i+1];
                            i=i+2;
                        }
                        else
                        {
                            p.problem+=messa[i];
                            i++;
                        }
                    }
                    else
                        i++;
                }
            }
        }
        t++;
    }
    m.push_back(p);
    myfile.close();
    println();
    return 0;
}