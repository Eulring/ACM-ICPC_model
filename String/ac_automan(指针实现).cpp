#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <stack>
#include <map>
#include <queue>

#define CL(arr, val)    memset(arr, val, sizeof(arr))
#define REP(i, n)       for((i) = 0; (i) < (n); ++(i))
#define FOR(i, l, h)    for((i) = (l); (i) <= (h); ++(i))
#define FORD(i, h, l)   for((i) = (h); (i) >= (l); --(i))
#define L(x)    (x) << 1
#define R(x)    (x) << 1 | 1
#define MID(l, r)   (l + r) >> 1
#define Min(x, y)   (x) < (y) ? (x) : (y)
#define Max(x, y)   (x) < (y) ? (y) : (x)
#define E(x)        (1 << (x))
#define iabs(x)     (x) < 0 ? -(x) : (x)
#define OUT(x)  printf("%I64d\n", x)
#define Read()  freopen("data.in", "r", stdin)
#define Write() freopen("data.out", "w", stdout);

typedef long long ll;
const double eps = 1e-8;
const double pi = acos(-1.0);
const double inf = ~0u>>2;


using namespace std;

const int N = 10010;

struct Node {
    Node* fail;
    Node* next[26];
    int cnt;
    Node() {
        CL(next, NULL);
        fail = NULL;
        cnt = 0;
    }
};

class AC_automaton : public Node {
public:
    Node* root;
    int head, tail;
    void init() {root = new Node(); head = tail = 0;}
    void Insert(char* );
    void Build();
    int Search(char* );
}AC;

void AC_automaton::Insert(char* st) {
    Node* p = root;
    while(*st) {
        if(p->next[*st - 'a'] == NULL) 
            p->next[*st - 'a'] = new Node();
        p = p->next[*st - 'a'];  st++;
    }
    p->cnt++;
}

void AC_automaton::Build() {
    root->fail = NULL;
    deque<Node* > q;
    q.push_back(root);

    while(!q.empty()) {
        Node* tmp = q.front();
        Node* p = NULL;
        q.pop_front();

        for(int i = 0; i < 26; ++i) {
            if(tmp->next[i] != NULL) {
                if(tmp == root) tmp->next[i]->fail = root;
                else {
                    p = tmp->fail;
                    while(p != NULL) {
                        if(p->next[i] != NULL) {
                            tmp->next[i]->fail = p->next[i];
                            break;
                        }
                        p = p->fail;
                    }
                    if(p == NULL)   tmp->next[i]->fail = root;
                }
                q.push_back(tmp->next[i]);
            }
        }
    }
}

int AC_automaton::Search(char* st) {
    int res = 0, t;
    Node* p = root;
    while(*st) {
        t = *st - 'a';
        while(p->next[t] == NULL && p != root)    {p = p->fail;}

        p = (p->next[t] != NULL) ? p->next[t] : root;

        Node* tmp = p;
        while(tmp != root && tmp->cnt != -1) {
            res += tmp->cnt;
            tmp->cnt = -1;
            tmp = tmp->fail;
        }
        st++;
    }
    return res;
}

char ss[1000010];

int main() {
    int T, n;
    scanf("%d", &T);
    while(T--) {
        AC.init();
        scanf("%d", &n);
        while(n--)  {scanf("%s", ss); AC.Insert(ss);}
        AC.Build();
        scanf("%s", ss);
        printf("%d\n", AC.Search(ss));
    }
    return 0;
}