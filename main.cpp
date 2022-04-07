#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int const SIZE = 255;

int main()
{
    string temp;
    ifstream reader("a5.txt"); // открываем файл для чтения
    string left = "INSERT INTO A2(text, id) VALUES('";
    string midle = "', ";
    string right = " );";
    int les_id = 5;
    string id_s= to_string(les_id);
    while (true)
    {
        if (getline(reader, temp))
        {
            if (temp.size())
            {
                cout << left + temp + midle + id_s + right  << endl;
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