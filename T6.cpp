#include <iostream>
#include <vector>

using namespace std;

void wordLadder(string s, string t, int &steps, vector<string> &p);

int main()
{
    int steps=0;
    vector<string> path;

    wordLadder("aloof", "aloft", steps, path);

    //ASSERT_EQ(steps,0);
    if (steps != 0)
    {
        std::cout << "aloof->aloft: expected/correct value for steps is 0, actual value when testing " << steps << ".\n";
        return 1;
    }

    std::cout << "Passed" << endl;
}