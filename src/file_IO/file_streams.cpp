#include <iostream>
#include <fstream>

void test01()
{
    // open file
    std::ifstream infile;
    infile.open("/home/hsk/Documents/cpp_stl/file_IO/source.txt",std::ios::in);
    if(!infile)
    {
        std::cout<<"open file failed!"<<std::endl;
        return;
    }

    std::ofstream outfile;
    outfile.open("/home/hsk/Documents/cpp_stl/file_IO/target.txt",std::ios::app);//std::ios::app 追加
    if(!outfile)
    {
        std::cout<<"open file failed!"<<std::endl;
        return;
    }
    
    // read file
    char ch;
    while(infile.get(ch))
    {
        std::cout<<ch;
        outfile.put(ch);//写入数据
    }
    std::cout<<std::endl;

    // close file
    infile.close();
    outfile.close();

}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}
