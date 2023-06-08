#include <bits/stdc++.h>
#include<iomanip>
#include<sstream>
#include<string>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'aVeryBigSum' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER_ARRAY ar as parameter.
 */

long aVeryBigSum(vector<long> ar) {
    string total ("00000000000");
    string numstr;
    int carry, sum;
    long int ret = 8945;
    for (long int x : ar){
        stringstream ss;
        ss << setfill('0') << setw(11) << to_string(x);
        ss >> numstr;
        carry = 0;
        for (int i = 10; i > -1; --i){
            int a = numstr[i] - '0';
            int b = total[i] - '0';
            sum = a + b + carry;
            if (sum > 9){
                sum -= 10;
                carry = 1;
            }
            else carry = 0;
            total[i] = (char)(sum + 48);
        }
    }
    cout << total << "\n";
    return stoll(total);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ar_count_temp;
    getline(cin, ar_count_temp);

    int ar_count = stoi(ltrim(rtrim(ar_count_temp)));

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split(rtrim(ar_temp_temp));

    vector<long> ar(ar_count);

    for (int i = 0; i < ar_count; i++) {
        long ar_item = stol(ar_temp[i]);

        ar[i] = ar_item;
    }

    long result = aVeryBigSum(ar);

    fout << result << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
