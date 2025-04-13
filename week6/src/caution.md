String **&** String::operator=(String str2)

为什么要是引用？因为要返回一个实实在在的对象，不能返回一个副本。

例如语句 (str1=str2) =str3;

这里就要求前面括号返回一个实在的东西，不能是一个虚的“副本”之类的东西。


ostream &String::operator<<(outstream &output, const String &str)

{	output<<"("<<str.r<<str.i<<")"<<endl;

    return output;

}
