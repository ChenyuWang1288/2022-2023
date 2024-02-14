# Homework1--Crack following ciphertext

## 1. Caesar ciphertext

```FBUQIUUDSHOFJOEKHDQCUMYJXJXUIQCUAUOQDTKFBEQTJEBUQHDYDWYDPZK
FBUQIUUDSHOFJOEKHDQCUMYJXJXUIQCUAUOQDTKFBEQTJEBUQHDYDWYDPZK
```

Due to the lack of Caesaer offset, I wrote a program to try to test the total 25 cases, Here is the source code for this program

```java
import java.util.Scanner;

public class Crack_Caesar {
    private static final int MAXNUM = 200;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("input your cypher code:");
        String cypher = scanner.nextLine();
        char[] chars = cypher.toCharArray();
        char[] charsout = new char[MAXNUM];

        for(int i = 1; i <= 25; i++) {
            for(int j = 0; j < cypher.length(); j++) {
                if(chars[j] + i > 90) {
                    charsout[j] = (char) (chars[j] + i - 90 + 64);
                } 
                else charsout[j] = (char) (chars[j] + i);
            }
            String out = String.valueOf(charsout).toLowerCase();
            System.out.println(out);
        }

        scanner.close();
    }
}

```

the output is:

<img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20230313205825241.png" alt="image-20230313205825241" style="zoom:50%;" /> 

find the one with meaning:

```
PLEASE ENCRYPT YOUR NAME WITH THE SAME KEY AND UPLOAD TO LEARNINGINZJU
```

My name: `WANGCHENYU`

The offset: 16

The ciphertext of my name is: `MQDWSXUDOK`

## 2. Vignere

```
ktbueluegvitnthuexmonveggmrcgxptlyhhjaogchoemqchpdnetxupbqntietiabpsmaoncnwvoutiugtagmmqsxtvxaoniiogtagmbpsmtuvvihpstpdvcrxhokvhxotawswquunewcgxptlcrxtevtubvewcnwwsxfsnptswtagakvoyyak 
```

Suppose the length of the key is 2/3/4, break the text into n(the length of the key) parts, then use a program to test the frequency of each letters, Assume that one of the three letters with the highest frequency is `e`

Here is the program detect the top 3 letters with high frequency

```java
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
```

Then test all possible permutation of keys

The key is `cat` , the original content is

```
itisessentialtoseekoutenemyagentswhohavecometoconductespionageagainstyouandtobribethemtoserveyougivetheminstructionsandcareforthemthusdoubledagentsarerecruitedandusedsuntzutheartofwar (the Explicit text)

ktbueluegvitnthuexmonveggmrcgxptlyhhjaogchoemqchpdnetxupbqntietiabpsmaoncnwvoutiugtagmmqsxtvxaoniiogtagmbpsmtuvvihpstpdvcrxhokvhxotawswquunewcgxptlcrxtevtubvewcnwwsxfsnptswtagakvoyyak (the ciphertext)

catcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcatcat (The key after extension)
```

## 3. Unknown

```
MAL TIRRUEZF CR MAL RKZYIOL EX MAL OIY UAE RICF “MAL ACWALRM DYEUPLFWL CR ME DYEU MAIM UL IZL RKZZEKYFLF GH OHRMLZH”
```

`MAL` appears 4 times in this text, Inferring from its position in the text, assume it is `THE` in English.

| Cipher | Plain |
| :----: | :---: |
|   M    |   T   |
|   A    |   H   |
|   L    |   E   |

After re-replacement, the text:

<img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20230314113214662.png" alt="image-20230314113214662" style="zoom:50%;" />

`THIT` probably be `THAT`, refer:

| Cipher | Plain |
| :----: | :---: |
|   I    |   A   |

After re-replacement, the text:

<img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20230314113549703.png" alt="image-20230314113549703" style="zoom:50%;" />

`AZE` probably be `ARE`, refer:

| Cipher | Plain |
| :----: | :---: |
|   Z    |   R   |

After re-replacement, the text:

<img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20230314113725230.png" alt="image-20230314113725230" style="zoom:50%;" />

Notice that `CR` appears several times, and based on the location it appears, it is inferred that it is most likely `IS`

| Cipher | Plain |
| :----: | :---: |
|   C    |   I   |
|   R    |   S   |

After re-replacement, the text:

<img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20230314114503217.png" alt="image-20230314114503217" style="zoom:50%;" />

`SAIF` is `SAID` , `HIWHEST` is `HIGHEST`

| Cipher | Plain |
| :----: | :---: |
|   F    |   D   |
|   W    |   G   |

After re-replacement, the text:

<img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20230314114806273.png" alt="image-20230314114806273" style="zoom:50%;" />

From `SAID`, we can analyze that it is followed by a subordinate clause, so there must be a subject before `said`(HE/SHE/WHO)，`UHE` is `WHO`

| Cipher | Plain |
| :----: | :---: |
|   U    |   W   |
|   E    |   O   |



After re-replacement, the text:<img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20230314115349174.png" alt="image-20230314115349174" style="zoom:50%;" />

| Cipher | Plain |
| :----: | :---: |
|   T    |   P   |
|   X    |   F   |

After re-replacement, the text:

<img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20230314115606809.png" alt="image-20230314115606809" style="zoom:50%;" />

From the common words in English, we infer that`DYOWPEDGE` is `KNOWLEDGE`, `SKRROKYDED` is `SURROUNDED`

| Cipher | Plain |
| :----: | :---: |
|   D    |   K   |
|   Y    |   N   |
|   P    |   L   |
|   K    |   U   |

After re-replacement, the text:

<img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20230314120057960.png" alt="image-20230314120057960" style="zoom:50%;" />

Assume:

| Cipher | Plain |
| :----: | :---: |
|   O    |   M   |

After re-replacement, the text:

<img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20230314120228890.png" alt="image-20230314120228890" style="zoom:50%;" />

According to the meaning of the text, it is easy to infer that 

| Cipher | Plain |
| :----: | :---: |
|   H    |   Y   |
|   G    |   B   |

To conclude, the plain text is

```
THE PASSWORD IS THE SURNAME OF THE MAN WHO SAID "THE HIGHEST KNOWLEDGE IS TO KNOW THAT WE ARE SURROUNDED BY MYSTERY"
```

