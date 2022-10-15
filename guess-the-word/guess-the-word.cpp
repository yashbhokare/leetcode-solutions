/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for(int i=0;i<30;i++){
            string guessWord = wordlist[wordlist.size()/2];
            int guessCount = master.guess(guessWord);
            if(guessCount==6) break;
            wordlist = compareTheCount(guessWord,guessCount,wordlist);
        }
    }
    
    vector<string> compareTheCount(string guessWord,int guessCount,vector<string> wordlist){
        vector<string> newWordList;
        for(int i=0;i<wordlist.size();i++){
            string currentWord = wordlist[i];
            int counter = 0;
            for(int j=0;j<currentWord.size();j++){
                if(guessWord[j] == currentWord[j]) counter++;
            }
            if(counter == guessCount) newWordList.push_back(currentWord);
        }
        return newWordList;
    }
};