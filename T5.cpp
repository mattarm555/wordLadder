#include <iostream>
#include <vector>

using namespace std;

void wordLadder(string s, string t, int &steps, vector<string> &p);

int main()
{
    int steps=0;
    vector<string> path;

    wordLadder("world", "atlas", steps, path);

    //ASSERT_EQ(steps,13);
    if (steps != 13)
    {
        std::cout << "world->atlas: expected/correct value for steps is 13, actual value when testing " << steps << ".\n";
        return 1;
    }

    std::cout << "Passed" << endl;
}