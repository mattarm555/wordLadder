#include <iostream>
#include <vector>

using namespace std;

void wordLadder(string s, string t, int &steps, vector<string> &p);

int main()
{
    int steps=0;
    vector<string> path;

    wordLadder("stale", "tales", steps, path);

    //ASSERT_EQ(steps,8);
    if (steps != 8)
    {
        std::cout << "stale->tales: expected/correct value for steps is 8, actual value when testing " << steps << ".\n";
        return 1;
    }

    std::cout << "Passed" << endl;
}