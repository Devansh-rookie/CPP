// its also LeetCode- 208
#include<iostream>
#include<algorithm>
using namespace std;
class TrieNode{
    public:
        char val;
        TrieNode * children[26];
        bool isTerminal;
        TrieNode(char ch){
            val = ch;
            for(int i=0;i< 26;i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie {
public:
    TrieNode * root;

    Trie() {
        root = new TrieNode('\0');
    }
    
    void recursiveInsert(TrieNode * root, string word){
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        } // or length can be used as well
        // there instead of the array can can be sued as per convience
        // now check if the children have to be NULL or not;
        // here search if the child is there or not
        int index = word[0] - 'a'; // or i and &i passing by address can be done
        TrieNode * child;// for passing into the recursion
        if(root->children[index] != NULL){ // not null means that its present
            child = root->children[index];
        }
        else{// NULL means that the character wasn't present in the original searching
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        //recursive call

        recursiveInsert(child, word.substr(1));
    }

    void insert(string word) {
        recursiveInsert(root, word);
        return;
    }

    bool recSearch(TrieNode * root, string word){
        if(word.length() == 0 && root->isTerminal) return true;
        // checking the index here is key
        int index = word[0] - 'a';
        TrieNode * child;
        if(index<0) return false;
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else return false;
        // recursive call
        return recSearch(child, word.substr(1));// sub string starts from 1 and goes till the end
    }
    
    bool search(string word) {
        return recSearch(root, word);
    }

    bool recStartsWith(TrieNode * root, string prefix){
        //base case
        if(prefix.length()==0) return true;
        // check index very important
        int index = prefix[0] - 'a';
        TrieNode * child;
        if(root->children[index] != NULL){//  the current root which will help in recursion ofc
            child =  root->children[index];
        }
        else return false;
        // recursive call
        return recStartsWith(child, prefix.substr(1));
    }
    
    bool startsWith(string prefix) {
        return recStartsWith(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */