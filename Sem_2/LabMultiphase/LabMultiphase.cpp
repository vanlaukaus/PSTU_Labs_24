#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
using namespace std;
using namespace filesystem;

vector<int> readnum(const path& file)
{
    ifstream fin(file);
    vector<int> numbers;
    int num;
    while (fin >> num)
    {
        numbers.push_back(num);
    }
    return numbers;
}
void writenum(const path& file, const vector<int>& numbers)
{
    ofstream fout(file);
    for (int num : numbers)
    {
        fout << num << ' ';
    }
}
vector<vector<int>> splitruns(const vector<int>& numbers)
{
    vector<vector<int>> runs;
    if (numbers.empty()) return runs;

    vector<int> currentRun = { numbers[0] };
    for (size_t i = 1; i < numbers.size(); ++i)
    {
        if (numbers[i] >= numbers[i - 1])
        {
            currentRun.push_back(numbers[i]);
        }
        else
        {
            runs.push_back(currentRun);
            currentRun = { numbers[i] };
        }
    }
    runs.push_back(currentRun);
    return runs;
}
vector<int> mergetwo(const vector<int>& a, const vector<int>& b)
{
    vector<int> result;
    size_t i = 0, j = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[j])
        {
            result.push_back(a[i++]);
        }
        else
        {
            result.push_back(b[j++]);
        }
    }

    while (i < a.size()) result.push_back(a[i++]);
    while (j < b.size()) result.push_back(b[j++]);

    return result;
}
void mphsort(const path& input, const path& output)
{
    vector<int> numbers = readnum(input);
    if (numbers.empty()) return;

    vector<vector<int>> runs = splitruns(numbers);

    while (runs.size() > 1)
    {
        vector<vector<int>> newRuns;

        for (size_t i = 0; i < runs.size(); i += 2)
        {
            if (i + 1 < runs.size())
            {
                newRuns.push_back(mergetwo(runs[i], runs[i + 1]));
            }
            else
            {
                newRuns.push_back(runs[i]);
            }
        }

        runs = newRuns;
    }

    if (!runs.empty())
    {
        writenum(output, runs[0]);
    }
}
int main()
{
    path input = "input.txt";
    path output = "output.txt";
    cout << "Input: \n";
    writenum(input, { 22, 629, 414, 281, 892, 861, 249, 982, 742, 61, 310, 866, 708, 967, 961, 24, 547, 267, 389, 971, 494, 311, 755, 343, 70, 121, 170, 688, 243, 258, 534, 463, 804, 100, 747, 595, 591, 552, 549, 304, 221, 714, 439, 608, 860, 238, 535, 274, 111, 529 });

    vector<int> before = readnum(input);
    for (int num : before) cout << num << ' ';
    cout << '\n';

    mphsort(input, output);
    cout << "Output: \n";
    vector<int> after = readnum(output);
    for (int num : after) cout << num << ' ';
    cout << '\n';

    return 0;
}