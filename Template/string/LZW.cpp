#include <cstring>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
class LZW {
  private:
    int R = 256;
    int L = 4096;
    int W = 12;
    std::map<std::string, int> st;
    std::map<int, std::string> ts;
    std::vector<int> res;

  public:
    LZW(/* args */);
    ~LZW();
    void compress(std::string);
    void expand();
    void printcode();
};
LZW::LZW(/* args */) {}

LZW::~LZW() {}

void LZW::compress(std::string str) {
    std::string p;
    char c;
    int idx = 0;
    for (; idx < R; idx++) {
        st[std::string(1, (char)idx)] = idx;
    }
    idx++;
    for (int i = 0; i < str.length(); i++) {
        c = str.at(i);
        if (st.count(p + std::string(1, c))) {
            p += std::string(1, c);
        } else {
            // std::cout<<p<<":"<<st[p]<<std::endl;
            res.push_back(st[p]);
            st[p + std::string(1, c)] = idx++;
            p = std::string(1, c);
        }
    }
    if (p.length() > 0) {
        res.push_back(st[p]);
    }
}
void LZW::printcode() {
    for (int i = 0; i < this->res.size(); i++)
        std::cout << res[i] << " ";
}
void LZW::expand() {
    std::map<int, std::string> mt;
    int idx = 0;
    for (; idx < R; idx++) {
        mt[idx] = std::string(1, (char)idx);
    }
    idx++;
    int codeword = res[0];
    std::string val = mt[codeword];
    for (int i = 1; i < res.size(); i++) {
        std::cout<<val;
        codeword = res[i];
        // if (codeword == R)
        //     break;
        std::string s = mt[codeword];
        if (idx == codeword)
            s = val + val.at(0);
        if (idx < L)
            mt[idx++] = val + s.at(0);
        val = s;
    }
}
int main(int argc, char const *argv[]) {
    std::string str = "ABRACADABRABRABRA";
    LZW lzw;
    lzw.compress(str);
    lzw.printcode();
    lzw.expand();

    return 0;
}
