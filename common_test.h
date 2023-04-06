#include <vector>
#include <string>
#include <numeric>

using namespace std;

auto IntToStringConversionTest(int count)
{
    vector<int> inputNumbers(count);
    vector<string> outNumbers;

    iota(begin(inputNumbers), end(inputNumbers), 0);
    for (auto &num : inputNumbers)
        outNumbers.push_back(to_string(num));

    return outNumbers;
}