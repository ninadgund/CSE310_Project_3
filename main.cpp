
#include "util.h"
#include "GraphManager.h"

using namespace std;


// main
int main(int argc, char** argv)
{
    // Arguements read and verify
    if (argc < 4)
    {
        return EXIT_FAILURE;
    }

    // Edge data file
    string edgesFileName(argv[1]);
    // Dates data file
    string datesFileName(argv[2]);

    // Creating a graph manager object
    Module::GraphManager lGraphManager(datesFileName, edgesFileName);

    // Commands file
    string cmdsFileName(argv[3]);
    ifstream cmdsFile(cmdsFileName);
    if (!cmdsFile.is_open())
    {
        return EXIT_FAILURE;
    }

    string lstrStartGraphCmd = "start-graph ";
    string lstrOutDegreeCmd = "out-degree";
    string lstrDiameterCmd = "diameter";
    string lstrSCCCmd = "scc";
    string lstrEndGraphCmd = "end-graph";
    // Reading commands file line by line
    string line;
    int lineNo = 0;
    while (getline(cmdsFile, line))
    {
        line.erase( std::remove(line.begin(), line.end(), '\r'), line.end() );
        lineNo++;
        if(line.length() <= 1)
        {
            continue;
        }
        
        // Check the command type
        if (line.rfind(lstrStartGraphCmd, 0) == 0)
        {
            cout << "Command: " << line << "\n\n";
            line = line.substr(lstrStartGraphCmd.length());
            istringstream iss(line);
            // Read command input
            try
            {
                string token;
                if(!std::getline(iss, token, ' '))
                {
                    throw 1;
                }
                int lStartYear = stoi(token);
                if(!std::getline(iss, token, '\n'))
                {
                    throw 1;
                }
                int lEndYear = stoi(token);
                
                if (!lGraphManager.generateGraph(lStartYear, lEndYear))
                {
                    return EXIT_FAILURE;
                }
            }
            catch (...)
            {
                cout << "Command failed" << '\n';
            }
        }
        else if (line.rfind(lstrOutDegreeCmd, 0) == 0)
        {
            cout << "Command: " << line << "\n\n";
            try
            {
                lGraphManager.printOutDegree();
            }
            catch (...)
            {
                //  For failed Command, exception (integer for simplicity) is thrown
                cout << "Command failed" << '\n';
            }
        }
        else if (line.rfind(lstrDiameterCmd, 0) == 0)
        {
            cout << "Command: " << line << "\n\n";
            try
            {
                lGraphManager.printDiameter();
            }
            catch (...)
            {
                //  For failed Command, exception (integer for simplicity) is thrown
                cout << "Command failed" << '\n';
            }
        }
        else if (line.rfind(lstrSCCCmd, 0) == 0)
        {
            cout << "Command: " << line << "\n\n";
            try
            {
                lGraphManager.printSCC();
            }
            catch (...)
            {
                //  For failed Command, exception (integer for simplicity) is thrown
                cout << "Command failed" << '\n';
            }
        }
        else if (line.rfind(lstrEndGraphCmd, 0) == 0)
        {
            // Exit from reading commands and the program
            break;
        }
//            cout << endl;

    }
    cmdsFile.close();

    return 0;
}
