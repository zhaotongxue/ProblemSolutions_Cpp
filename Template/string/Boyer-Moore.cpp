#include <cstring>
#include <string>
class BoyerMoore {
  private:
    int *right;
    std::string pat;

  public:
    BoyerMoore(std::string pat);
    int search(std::string txt);
    ~BoyerMoore();
};
BoyerMoore::BoyerMoore(std::string pat) {
    this->pat = pat;
    int M = pat.length();
    int R = 256;
    right = new int[R];
    std::memset(right, -1, R);
    for (int i = 0; i < M; i++) {
        right[pat.at(i)] = i;
    }
}
int BoyerMoore::search(std::string txt) {
    int N = txt.length();
    int M = this->pat.length();
    int skip = 0;
    for (int i = 0; i <= N - M; i += skip) {
        skip = 0;
        for (int j = M - 1; j >= 0; j--) {
            if (this->pat.at(j) != txt.at(i + j)) {
                skip = j - right[txt.at(i + j)];
                if (skip < 1)
                    skip = 1;
                break;
            }
        }
        if (!skip)
            return i;
    }
    return -1;
}
BoyerMoore::~BoyerMoore() {
    delete[] right;
}