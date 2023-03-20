class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        //RUNTIME: 512- 545 MS
        //TIME COMPLEXITY: O(m * n), where m is the average length of a string and n is the number of strings.
        //With constants, time complexity would be (26 * 25 / 2 * m * n)
        //SPACE COMPLEXITY: O(m * n), where m is the average length of a string and n is the number of strings.

        std::array<std::unordered_set<std::string>, 26> begCharToSuffix;
        long long returnVal = 0;

        //Add the suffix of each string from our parameter ideas to begCharToSuffix
        for (int i = 0; i < ideas.size(); i++)
        {
            begCharToSuffix[ideas[i][0] - 'a'].emplace(ideas[i].substr(1));
        }

        //Iterate through all of thee characters and count the number of equal suffix values
        for (int i = 0; i < 25; i++)
        {
            for (int j = i + 1; j < 26; j++)
            {
                long long mutualChars = 0;

                for (auto suffix : begCharToSuffix[j])
                {
                    if (begCharToSuffix[i].count(suffix))
                    {
                    ++mutualChars;
                    }
                }

                //Since we know that two words are unique if they don't make a word that was already in the array,
                //we remove the mutual suffixes that two different characters share. Then, after doing this, we know
                //that we can multiply our result by two since the remaining suffixes (+ their original prefix letter)
                //don't exist in the original array which means that we can use both of them in either position. Ex:
                //if "coffee" and "donuts" are both unique, we could include "coffee donuts" and "donuts coffee" in our answer
                returnVal += 2LL * (begCharToSuffix[i].size() - mutualChars) * (begCharToSuffix[j].size() - mutualChars);
            }
        }

        return returnVal;
        
    }
};
