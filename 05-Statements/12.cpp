#include <iostream>

using std::cin, std::cout, std::endl;

int main() {
    char ch, pre_ch = '\0';
    int a_cnt = 0, e_cnt = 0, i_cnt = 0, o_cnt = 0, u_cnt = 0,
        space_cnt = 0, t_cnt = 0, n_cnt = 0,
        ff_cnt = 0, fl_cnt = 0, fi_cnt = 0;
    while (cin >> std::noskipws >> ch) {  // std::noskipws 统计符号
        switch (ch) {
            case 'a':
            case 'A':
                ++a_cnt;
                break;
            case 'e':
            case 'E':
                ++e_cnt;
                break;
            case 'i':
                if (pre_ch == 'f')
                    ++fi_cnt;
            case 'I':
                ++i_cnt;
                break;
            case 'o':
            case 'O':
                ++o_cnt;
                break;
            case 'u':
            case 'U':
                ++u_cnt;
                break;
            case ' ':
                ++space_cnt;
                break;
            case '\t':
                ++t_cnt;
                break;
            case '\n':
                ++n_cnt;
                break;
            case 'f':
                if (pre_ch == 'f')
                    ++ff_cnt;
                break;
            case 'l':
                if (pre_ch == 'f')
                    ++fl_cnt;
                break;
            default:
                break;
        }
        pre_ch = ch;
    }
    cout << "Number of vowel a: " << a_cnt << endl
         << "Number of vowel e: " << e_cnt << endl
         << "Number of vowel i: " << i_cnt << endl
         << "Number of vowel o: " << o_cnt << endl
         << "Number of vowel u: " << u_cnt << endl
         << "Number of vowel space: " << space_cnt << endl
         << "Number of vowel tab: " << t_cnt << endl
         << "Number of vowel new line: " << n_cnt << endl;
    return 0;
}