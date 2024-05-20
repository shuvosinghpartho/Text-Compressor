#include <bits/stdc++.h>
using namespace std;


class TreeNode
{
public:
    int data;
    char letter;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val, char c)
    {
        this->data = val;
        this->letter = c;
        this->left = NULL;
        this->right = NULL;
    }
};



class Compare
{
public:
    bool operator()(TreeNode *a, TreeNode *b)
    {
        if (a->data > b->data)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};



// Function to find the frequency of a character
vector<pair<int, char>> FrequencyDetc(string s)
{
    map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }
    vector<pair<int, char>> v;
    for (int i = 0; i < s.size(); i++)
    {
        if (mp[s[i]] != 0)
        {
            v.push_back(make_pair(mp[s[i]], s[i]));
            mp[s[i]] = 0;
        }
    }

    cout << endl
         << endl
         << "Displaying the frequency of the charecters:" << endl
         << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << "  " << v[i].second << endl;
    }

    return v;
}



// Tree build
TreeNode *buildTree(vector<pair<int, char>> &frq)
{
    priority_queue<TreeNode *, vector<TreeNode *>, Compare> q;

    for (int i = 0; i < frq.size(); i++)
    {
        q.push(new TreeNode(frq[i].first, frq[i].second));
    }
    // print(q);
    while (q.size() > 1)
    {
        TreeNode *left = q.top();
        q.pop();
        TreeNode *right = q.top();
        q.pop();

        TreeNode *nd = new TreeNode(left->data + right->data, '~');
        nd->left = left;
        nd->right = right;
        q.push(nd);
    }
    return q.top();
}



// encode
void encode(TreeNode *root, string s, map<char, string> &vtr)
{
    if (!root)
    {
        return;
    }
    if (root->letter != '~')
    {
        vtr[root->letter] = s;
        return;
    }
    else
    {
        encode(root->left, s + "0", vtr);
        encode(root->right, s + "1", vtr);
    }
}



// decode
string decode(TreeNode *Tree, string s, int &i)
{
    string str = "";

    while (i <= s.size())
    {
        if (Tree->letter != '~')
        {
            str += Tree->letter;
            return str;
        }

        else if (s[i] == '0')
        {
            if (Tree->left)
            {
                Tree = Tree->left;
                i++;
            }
            else
            {
                return str;
            }
        }
        else if (s[i] == '1')
        {
            if (Tree->right)
            {
                Tree = Tree->right;
                i++;
            }
            else
            {
                return str;
            }
        }
    }
    return "";
}




// main function
int main()
{
    string s;
    cout << endl
         << endl
         << "Enter the string: " << endl
         << endl
         << "- ";
    cin >> s;

    vector<pair<int, char>> frq = FrequencyDetc(s);

    // sort the heap in Ascending order
    sort(frq.begin(), frq.end());
    // Print the sorted heap
    cout << endl
         << endl
         << "Displaying the heap in sorted order:" << endl
         << endl;
    for (int i = 0; i < frq.size(); i++)
    {
        cout << frq[i].first << "  " << frq[i].second << endl;
    }
    cout << endl;

    map<char, string> vtr;
    TreeNode *Tree = buildTree(frq);
    encode(Tree, "", vtr);
    string res = "";

    
    cout << endl
         << "Displaying the ENCODED value of the characters:" << endl
         << endl;

    for (auto i : vtr)
    {
        cout << i.first << "  " << i.second << endl;
    }
    cout << endl
         << endl;

    for (auto i : s)
    {
        res += vtr[i];
    }

    cout << "ENCODED FORM:  "
         << res << endl
         << endl;

    string back = "";
    for (int i = 0; i < res.size();)
    {
        back += decode(Tree, res, i);
    }

    cout << "DECODED FORM:  "
         << back << endl
         << endl
         << endl;
}