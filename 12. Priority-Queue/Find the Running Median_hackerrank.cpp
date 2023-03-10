#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'runningMedian' function below.
 *
 * The function is expected to return a DOUBLE_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

vector<double> runningMedian(vector<int> a) {
    priority_queue<int, vector<int>> q1;
    priority_queue<int, vector<int>, greater<int>> q2;   
    double median;
    vector<double> ans;
    
    for (int i = 0; i < a.size(); i++)
    {
        if (q1.empty() || q1.top() > a[i])
        {
            q1.push(a[i]);
        }
        else
        {
            q2.push(a[i]);
        }
        if (q1.size() > q2.size() + 1)
        {
            q2.push(q1.top());
            q1.pop();
        }
        else if (q2.size() > q1.size() + 1)
        {
            q1.push(q2.top());
            q2.pop();
        }
        if (q1.size() == q2.size())
        {
            median = (q1.top() + q2.top()) / 2.0;
            ans.push_back(median);
        }
        else if (q1.size() > q2.size())
        {
            median = q1.top() * 1.0;
            ans.push_back(median);
        }
        else if (q2.size() > q1.size())
        {
            median = q2.top() * 1.0;
            ans.push_back(median);
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_count_temp;
    getline(cin, a_count_temp);

    int a_count = stoi(ltrim(rtrim(a_count_temp)));

    vector<int> a(a_count);

    for (int i = 0; i < a_count; i++) {
        string a_item_temp;
        getline(cin, a_item_temp);

        int a_item = stoi(ltrim(rtrim(a_item_temp)));

        a[i] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
