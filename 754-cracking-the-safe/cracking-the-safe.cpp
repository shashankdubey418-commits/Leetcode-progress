class Solution {
public:
    unordered_set<string> visited;
    string ans;
    int n, k;

    void dfs(string node) {

        for (int i = 0; i < k; i++) {

            char digit = '0' + i;
            string edge = node + digit;

            if (visited.find(edge) == visited.end()) {

                visited.insert(edge);

                dfs(edge.substr(1));

                ans += digit;
            }
        }
    }

    string crackSafe(int n, int k) {
        this->n = n;
        this->k = k;

        visited.clear();
        ans.clear();

        string start(n - 1, '0');

        dfs(start);

        ans += start;

        return ans;
    }
};