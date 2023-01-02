#include <fstream>
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cout << "please input 3 parameter! (filename, s1, s2)" << std::endl;
        return 0;
    }

    std::ifstream file(argv[1]);
    std::string   file_content;
    std::string   s1 = argv[2];
    std::string   s2 = argv[3];

    if (file.is_open())
    {
        file.seekg(0, std::ios::end);
        int size = file.tellg();
        file_content.resize(size);
        file.seekg(0, std::ios::beg);
        file.read(&file_content[0], size);

        std::cout << "------------- Before ----------------------" << std::endl;
        std::cout << file_content << std::endl;

        int loc_s1 = 0;
        int s1_size = s1.size();
        while ((loc_s1 = file_content.find(s1)) != -1)
        {
            file_content.erase(loc_s1, s1_size);
            file_content.insert(loc_s1, s2);
        }
        std::cout << "------------- After -----------------------" << std::endl;
        std::cout << file_content << std::endl;
    }
    else
    {
        std::cout << "cannot find file! " << std::endl;
    }
}
