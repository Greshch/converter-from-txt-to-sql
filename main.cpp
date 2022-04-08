#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int const SIZE = 255;

int main(int argc, char** argv)
{
    if (argc < 4)
    {
        cerr << "#ERROR input....\n";
        return -1;
    }
    string temp;
    string src_file = argv[1];
    ifstream reader(src_file); // открываем файл для чтения
    string dest_file = argv[3];
    ofstream writer(dest_file, ios_base::out);
    string left = "INSERT INTO A2(text, les_id) VALUES('";
    string midle = "', ";
    string right = " );";
    string id_s= argv[2];

    string query;
    while (true)
    {
        if (getline(reader, temp))
        {
            if (temp.size())
            {
                query = left + temp + midle + id_s + right;
                //cout << query  << endl;
                writer << query << endl;
            }

        }
        else
        {
            break;
        }
    }
    reader.close();
    return 0;
}