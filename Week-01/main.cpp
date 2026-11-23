#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void analyzeSourceCode(ifstream &in, ofstream &out)
{
    string line;
    int total = 0, nonEmpty = 0, empty = 0, characters = 0;

    out << "========== SOURCE CODE ANALYSIS ==========\n\n";

    while (getline(in, line))
    {
        total++;
        characters += line.length();

        bool blank = true;

        for (char c : line)
        {
            if (c != ' ' && c != '\t')
            {
                blank = false;
                break;
            }
        }

        if (blank)
            empty++;
        else
            nonEmpty++;

        out << "Line " << total << ": " << line << endl;
    }

    out << "\n========== STATISTICS ==========\n\n";

    out << "Total lines       : " << total << endl;
    out << "Non-empty lines   : " << nonEmpty << endl;
    out << "Empty lines       : " << empty << endl;
    out << "Total characters   : " << characters << endl;
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    if (!in)
    {
        cout << "Cannot open input.txt!";
        return 1;
    }

    analyzeSourceCode(in, out);

    in.close();
    out.close();

    cout << "Analysis completed! Check output.txt";

    return 0;
}
