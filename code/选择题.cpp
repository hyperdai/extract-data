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
        out<<m[i].answer;
        //out<<"题目选项";
        for(int j=0;m[i].choice[j].size()!=0;j++)
        {
            /*char a='A'+j;
            if(a!='A')
                out<<"        "
            out<<a<<":"*/
            out<<"||"<<m[i].choice[j];
        }
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
void choice(string messa,int i)
{
    while(isalpha(messa[i]))
    {
        char a=messa[i];
        string b;
        i++;
        if(messa[i]<0)
        {
            b=messa[i];
            b+=messa[i+1];
        }
        else
            b=messa[i];
        while(is_cha(b))
        {
            if(b[0]<0)
                i=i+2;
            else
                i++;
            if(messa[i]<0)
            {
               b=messa[i];
               b+=messa[i+1];
            }
            else
            b=messa[i];
        }
        while(i<messa.size()&&messa[i]!=a+1)
        {
            if(messa[i]!=' ')
            {
                if(messa[i]<0)
                {
                    p.choice[a-'A']+=messa[i];
                    p.choice[a-'A']+=messa[i+1];
                    i=i+2;
                }
                else
                {
                    p.choice[a-'A']+=messa[i];
                    i++;
                }
            }
            else
                i++;
        }
        int j=p.choice[a-'A'].size()-2;
        b=p.choice[a-'A'][j];
        b+=p.choice[a-'A'][j+1];
        while(is_cha(b))
        {
            p.choice[a-'A'].resize(j);
            j=j-2;
            b=p.choice[a-'A'][j];
            b+=p.choice[a-'A'][j+1];
        }
    }
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
        if(isalpha(messa[i]))
        {
            is_letter=0;
            choice(messa,i);
        }
        else if(isdigit(messa[i]))
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
        while(is_letter&&messa[i]!='\0')
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
                        if(messa[i]<0)
                            j++;
                        while(messa[j]==' ')
                            j++;
                        if(isalpha(messa[j]))
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
                    p.problem+="（";
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