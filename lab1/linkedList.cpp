#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void solve1(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s, cur;
    vector<int> a;
    getline(cin, s);
    for(int i = 0; i <= s.length(); i++){
        if(i == s.length() || s[i] == ' '){
            a.push_back(stoi(cur));
            cur.clear();
        }
        else{
            cur += s[i];
        }
    }
    int ans = -1e9 - 7;
    const int N = a.size();
    for(int x = 1; x <= N; x++){
        int sum = 0;
        for(int i = 0; i < x; i++)
            sum += a[i];
        ans = max(ans, sum);
        for(int i = x; i < N; i++){
            sum = sum + a[i] - a[i - x];
            ans = max(ans, sum);
        }
    }
    cout << ans;
}

void solve2(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s, cur;
    vector<string> words;
    set<int> res;
    cin >> s;
    while(cin >> cur)
        words.push_back(cur);
    do{
        string t;
        for(auto &i: words)
            t += i;
        for(int i = 0; i + t.length() <= s.length(); i++)
            if(s.substr(i, t.length()) == t)
                res.insert(i);
    } while(next_permutation(words.begin(), words.end()));
    string t;
    for(auto &i: words)
        t += i;
    for(int i = 0; i + t.length() <= s.length(); i++)
        if(s.substr(i, t.length()) == t)
            res.insert(i);
    for(auto &i: res)
        cout << i << " ";
}

struct Node{
public:
    Node* next = nullptr;
    int value = 0;
public:
    Node(){
        next = nullptr;
        value = 0;
    }
};

class LinkedList{
public:
    Node *head = nullptr;
public:
    LinkedList(){
        head = nullptr;
    }
    void insert(Node &node){
        if(head == nullptr){
            head = &node;
        }
        else{
            Node *temp = head;
            while(temp->next != nullptr)
                temp = temp->next;
            temp->next = &node;
        }

    }
    void changeNodes(Node &x, Node &y){
        Node *temp = new Node();
        temp->value = y.value;
        temp->next = &x;
        x.next = y.next;
        y = *temp;
        if(head == &x)
            head = &y;
        else{
            Node *pa_ = head;
            while(pa_->next != &x)
                pa_ = pa_->next;
            pa_->next = &y;
        }
    }
};

void solve3(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    LinkedList a;
    int k;
    while(cin >> k){
        Node *node = new Node();
        node->value = k;
        a.insert(*node);
    }

    Node *pa = a.head;
    while(pa != nullptr && pa->next != nullptr){
        a.changeNodes(*pa, *pa->next);
        pa = pa->next;
    }
    pa = a.head;
    while(pa != nullptr){
        cout << pa->value << " ";
        pa = pa->next;
    }
}

int main(){
    //solve1();
    //solve2();
    solve3();
}