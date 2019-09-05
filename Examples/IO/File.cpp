#include <IO/File.hpp>
#include <iostream>

void FileTest()
{
    Alice::IO::File f ("C:\\AliceFileTest.txt");
    f.New();
    if(f.Exists())
    {
        f.Write("Hello World!");//12 bytes written
        s64 Size = f.Size();
        std::cout << "Size of file after writing: " << Size << std::endl;
        Alice::Collections::Generic::List<char> Content(Size);
        f.Read(Content);
        for(s64 i = 0; i < Size; i++)
            std::cout << Content[i];
        std::cout << std::endl;
        f.Delete();
    }
}