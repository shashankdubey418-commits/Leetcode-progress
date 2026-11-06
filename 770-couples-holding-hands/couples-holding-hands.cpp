class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int swaps = 0;

        unordered_map<int, int> pos;

        // Store the current position of every person
        for (int i = 0; i < n; i++) {
            pos[row[i]] = i;
        }

        for (int i = 0; i < n; i += 2) {

            int person = row[i];

            // Find the partner
            int partner = person ^ 1;

            // Check whether partner is already beside them
            if (row[i + 1] != partner) {

                int partnerPos = pos[partner];

                // Person currently sitting in the next seat
                int other = row[i + 1];

                // Swap the two people
                swap(row[i + 1], row[partnerPos]);

                // Update positions
                pos[partner] = i + 1;
                pos[other] = partnerPos;

                swaps++;
            }
        }

        return swaps;
    }
};