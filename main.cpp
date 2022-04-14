#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int const SIZE = 255;

enum STATE
{
    FIRST,
    SECOND,
    THIRD,
    TRANSLATE,
    TYPE
};

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        cerr << "#ERROR input....\n";
        return -1;
    }

    /*CREATE TABLE Verb
            (
    id Int not Null AUTO_INCREMENT,
            first Varchar(20),
            second Varchar(20),
            third Varchar(20),
            translate Varchar(40),
            type Varchar(10),
            CONSTRAINT PK PRIMARY KEY (id)
    ) default charset utf8;*/

    string temp;
    string src_file = argv[1];
    ifstream reader(src_file); // открываем файл для чтения
    string dest_file = argv[2];
    ofstream writer(dest_file, ios_base::out);
    string beg = "INSERT INTO Verb(first, second, third, translate, type) VALUES('";
    string  midle= "','";
    string end = "');";

    string query = beg;
    int state = FIRST;
    while (true)
    {

        if (getline(reader, temp))
        {

            if (temp.size())
            {
                //query = left + temp + midle + id_s + right;
                //cout << query  << endl;
                //writer << query << endl;
                query += temp;
                switch (state)
                {
                    case FIRST:
                    case SECOND:
                    case THIRD:
                    case TRANSLATE:
                        query += midle;
                        break;

                    case TYPE:
                        query += end;
                        break;

                    default:
                        break;
                }
                ++state;
            }
            else
            {
                cout << query  << endl;
                query = beg;
                state = FIRST;
            }

        }
        else
        {
            cout << query  << endl;
            break;
        }
    }
    reader.close();
    return 0;
}