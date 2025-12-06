#include <iostream>
#include <vector>

using namespace std;

void wordLadder(string s, string t, int &steps, vector<string> &p);

int main()
{
    int steps=0;
    vector<string> path;

    wordLadder("genro", "iller", steps, path);

    //ASSERT_EQ(steps,30);
    if (steps != 30)
    {
        std::cout << "genro->iller: expected/correct value for steps is 30, actual value when testing " << steps << ".\n";
        return 1;
    }

    std::cout << "Passed" << endl;
}