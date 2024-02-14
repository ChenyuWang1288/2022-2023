import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class Crack_Caesar {
    class LetterFrequency {
        int index;
        char l;
        int fre;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("input your cypher code:");
        String cypher = scanner.nextLine();
        int keyLength = scanner.nextInt();
        char[] chars = cypher.toCharArray();
        char t = 'a';
        // int fre[] = new int[26];
        ArrayList<LetterFrequency> letterFrequencies = new ArrayList<LetterFrequency>( new 
        Comparator<LetterFrequency>() {
                @Override
                public int compare(LetterFrequency o1, LetterFrequency o2) {
                    return o1.fre.compareTo(o2);
                }
            });

        for(int i = 0; i < 26; i++) {
            LetterFrequency temp = new LetterFrequency();
            temp.fre = 0;
            temp.index = i;
            temp.l = (char)('a' + i);
            letterFrequencies.add(temp);
        }
        for(int i = 0; i < chars.length; i++) {
            letterFrequencies.get((int)(chars[i] - 97)).index++;
        }
        Collections.sort(letterFrequencies);
        
        scanner.close();
    }
}
