#include <iostream>
#include <vector>

using namespace std;

void wordLadder(string s, string t, int &steps, vector<string> &p);

int main()
{
    int steps=0;
    vector<string> path;

    wordLadder("layer", "level", steps, path);

    //ASSERT_EQ(steps,3);
    if (steps != 3)
    {
        std::cout << "layer->level: expected/correct value for steps is 3, actual value when testing " << steps << ".\n";
        return 1;
    }

    std::cout << "Passed" << endl;
}