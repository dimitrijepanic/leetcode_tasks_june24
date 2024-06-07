package replace_words;

import java.util.List;

public class solution {
    class Trie{
        Trie[] letters = new Trie[26];
        boolean isWord;

    
        void add(String s){
            Trie root = this;

            for(char c: s.toCharArray()){
                if(root.letters[c - 'a'] == null) 
                    root.letters[c - 'a'] = new Trie();
                root = root.letters[c - 'a'];
            }
            root.isWord = true;
        }

        String get(String s){
            Trie root = this;
            StringBuilder sb = new StringBuilder();
            for(char c: s.toCharArray()){
                if(root.isWord) break;
                if(root.letters[c - 'a'] == null) return "";
                sb.append(c);
                root = root.letters[c - 'a'];
            }

            return sb.toString();
        }
    }

    public String replaceWords(List<String> dictionary, String sentence) {
        Trie root = new Trie();

        for(String s: dictionary) root.add(s);

        StringBuilder sb = new StringBuilder();
        StringBuilder curr = new StringBuilder();
        for(char c: sentence.toCharArray()){
            if(c == ' ') {
                String s = root.get(curr.toString());
                if(s == "") sb.append(curr.toString());
                else sb.append(s);
                sb.append(' ');
                curr = new StringBuilder();
            }
            else curr.append(c);
        }

        String s = root.get(curr.toString());
        if(s == "") sb.append(curr.toString());
            else sb.append(s);

        return sb.toString();
    }

    
}