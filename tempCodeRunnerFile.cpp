 #include <bits/stdc++.h>
 using namespace std;

 struct TrieNode{
    TrieNode * links[26];
    int countPrefix=0;
    int endsWith=0;

    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }

    TrieNode * get(char ch){
        return links[ch - 'a'];
    }
    void put(char ch, TrieNode * node){
        links[ch - 'a'] = node;
    }
    void increaseEnd(){
        endsWith++;
    }
    void increasePrefix(){
        countPrefix++;
    }
    void deleteEnd(){
        endsWith--;
    }
    void reducePrefix(){
        countPrefix--;
    }
    int getEnd(){
        return endsWith;
    }
    int getPrefix(){
        return countPrefix;
    }
 };

 class Trie{
    private:
    TrieNode * root;
    public:
    Trie(){
        root = new TrieNode(); 
    }

    void insert(string word){
        TrieNode * node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new TrieNode());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }
    int countWordsEqualTo(string &word){
        TrieNode * node = root;
        for(int i=0;i<word.length();i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->getEnd();
    }
    int countWordsStartingWith(string &word){
        TrieNode *node =root;
        for(int i=0;i<word.length();i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->getPrefix();
    }
    void erase(string &word){
        TrieNode * node = root;
        for(int i=0;i<word.length();i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                node->reducePrefix();
            }
            else{
                return;
            }
        }
        node->deleteEnd();
    }
 };

int main() {
  Trie T;
  T.insert("apple");
  T.insert("apple");
  T.insert("apps");
  T.insert("apps");
  string word1 = "apps";
  cout<<"Count Words Equal to "<< word1<<" "<<T.countWordsEqualTo(word1)<<endl;
  string word2 = "abc";
  cout<<"Count Words Equal to "<< word2<<" "<<T.countWordsEqualTo(word2)<<endl;
  string word3 = "ap";
  cout<<"Count Words Starting With "<<word3<<" "<<T.countWordsStartingWith(word3)
  <<endl;
  string word4 = "appl";
  cout<<"Count Words Starting With "<< word4<<" "<<T.countWordsStartingWith(word4)
  <<endl;
  T.erase(word1);
  cout<<"Count Words equal to "<< word1<<" "<<T.countWordsEqualTo(word1)<<endl;
  return 0;
}