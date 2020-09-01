#include <string>
using namespace std;
class hashNode {
    friend class hashMap;
    string keyword;
    string *values;
    int valuesSize;
    int currSize;
    public:
        hashNode();
        hashNode(string s);
        hashNode(string s, string v);
        void addValue(string v);
        void dblArray();
        string getRandValue();
};