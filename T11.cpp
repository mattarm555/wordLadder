#include <iostream>
#include <vector>

using namespace std;

void wordLadder(string s, string t, int &steps, vector<string> &p);

int main()
{
    int steps=0;
    vector<string> path;

    wordLadder("crawl", "prowl", steps, path);

    //ASSERT_EQ(steps,4);
    if (steps != 4)
    {
        std::cout << "crawl->prowl: expected/correct value for steps is 4, actual value when testing " << steps << ".\n";
        return 1;
    }

    std::cout << "Passed" << endl;
}