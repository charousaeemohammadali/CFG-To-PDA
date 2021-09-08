#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

class CFG_PDA
{
public:
    char input_Filename[50];

    void cfgToPDA()
    {
        ifstream inputfile;
        char Fileline[50];
        inputfile.open(input_Filename);
        while (!inputfile.eof())
        {
            char A;
            char a;
            char X[20];
            inputfile.getline(Fileline, 50);
            int i = 0;
            int j = 0;
            bool b = 0;
            int q = 0;
            for (i = 0; i < strlen(Fileline); i++)
            {
                if ((Fileline[i] > 64 && Fileline[i] < 91) && b == 0)
                {
                    A = Fileline[i];
                    b = 1;
                }
                else if ((Fileline[i] > 64 && Fileline[i] < 91) && b == 1)
                {
                    X[j++] = Fileline[i];
                    X[j] = NULL;
                }
                else if ((Fileline[i] > 96 && Fileline[i] < 123) && b == 1)
                    a = Fileline[i];
                else if ((Fileline[i] == '$') && b == 1)
                {
                    a = Fileline[i];
                    X[j++] = Fileline[i];
                    X[j] = NULL;
                    q = 1;
                }
            }
            cout << "0   " << a << "    " << A << "    " << q << "    " << X << "\n";
        }
    }
    //----------------
    void pdaToCFG()
    {
        ifstream inputfile;
        char Fileline[50];
        inputfile.open(input_Filename);
        int statNo = 0;
        int final = 0;
        int lineIndex = 0;
        while (!inputfile.eof())
        {
            lineIndex++;
            if (lineIndex == 1)
            {
                inputfile.getline(Fileline, 50);
                statNo = Fileline[0];
            }
            else if (lineIndex == 2)
            {
                inputfile.getline(Fileline, 50);
                final = Fileline[0];
            }
            else
            {
                char A;
                char a;
                char X[20];
                inputfile.getline(Fileline, 50);
                int i = 0;
                int j = 0;
                int b = 0;
                int q = 0;

                for (i = 0; i < strlen(Fileline); i++)
                {
                    if ((Fileline[i] > 64 && Fileline[i] < 91) && b == 1)
                    {
                        A = Fileline[i];
                        b++;
                    }
                    else if ((Fileline[i] > 64 && Fileline[i] < 91) && b == 2)
                    {
                        X[j++] = Fileline[i];
                        X[j] = NULL;
                    }
                    else if ((Fileline[i] > 96 && Fileline[i] < 123) && b == 0)
                    {
                        a = Fileline[i];
                        b++;
                    }
                    else if ((Fileline[i] == '$') && b == 0)
                    {
                        a = Fileline[i];
                        X[j] = NULL;
                        b++;
                    }


                }
                cout << A << "    " << a << X << "\n";
            }
        }
    }

};

void main(void)
{

    char filename[50];
    CFG_PDA  myClass;

    cout << "For converting PDA to CFG enter number 1\n";
    cout << "For converting CFG to PDA enter number 2 : ";
    int num = 0;
    cin >> num;
    cout << "Enter input file name: ";
    cin >> myClass.input_Filename;

    //strcpy(myClass.input_Filename,"e:\in2.txt");
    if (num == 2)
    {
        myClass.cfgToPDA();
    }
    else if (num == 1)
        myClass.pdaToCFG();

    getch();
}
