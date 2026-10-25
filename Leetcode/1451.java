import java.util.*;

class Solution {
    public String arrangeWords(String text) {
        String[] words = text.toLowerCase().split(" ");
        List<Word> list = new ArrayList<>();

        for (int i = 0; i < words.length; i++) {
            list.add(new Word(words[i], i));
        }

        list.sort((a, b) -> {
            int cmp = Integer.compare(a.word.length(), b.word.length());
            return cmp != 0 ? cmp : Integer.compare(a.index, b.index);
        });

        StringJoiner sj = new StringJoiner(" ");
        for (Word word : list) {
            sj.add(word.word);
        }

        String result = sj.toString();
        return Character.toUpperCase(result.charAt(0))
                + result.substring(1);
    }

    static class Word {
        String word;
        int index;

        Word(String word, int index) {
            this.word = word;
            this.index = index;
        }
    }
}
