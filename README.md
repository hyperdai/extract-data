# 项目介绍

从文本中提取题目信息， 题目描述，题目答案，题目选项。

题目样例见“example”文件夹内

题目代码见“code"文件夹内

# 代码实现

以选择题为例，运行选择题.cpp文件，将选择题问题导入程序中，然后将执行提取出来的代码放入php代码内执行，php用的tp，执行操作即可插入。因为数据库不同，仅做参考。

生成的字符串，每个题之间用<>分割，题内用格式：`题目描述||题目答案||题目选项A||题目选项B……`