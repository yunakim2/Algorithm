## Counting Sort

***Counting Sort***

๐ ์ผ๋ฐ์ ์ผ๋ก O(NlonN) **Quick Sort**, **Merge Sort**๊ฐ ๊ฐ์ฅ ๋น ๋ฅด๋ค. O(n)์ **Counting Sort**๊ฐ ๋ ๋น ๋ฅธ ๋์์ ํ  ์ ์๋ค. ๊ทธ๋ฌ๋ ๋์ ์๋ฆฌ๋ฅผ ๋ณด๋ฉด ์ **Quick Sort**, **Merge Sort**์ ์ฌ์ฉํ๋์ง ์ ์ ์๋ค.

 **Counting Sort**๋ ๊ฐ ์ซ์๊ฐ ๋ช ๋ฒ ๋์ค๋์ง ์ธ์ด์ค๋ค. ๊ทธ๋ ๊ธฐ ๋๋ฌธ์, ๋ง์ฝ ์์ด์์ ๋ฌ๊ธ์์ด ํฐ ์๊ฐ ๋์ค๊ฒ ๋๋ฉด ๊ทธ ์ซ์๊น์ง์ ๋ฌด์๋ฏธํ ์๊ฐ์ ๋ญ๋นํ๊ฒ ๋๋ค.

<br>

***๋จ์ ***

๐ ์ผ๋ฐ์ ์ผ๋ก O(n)์ด๋ผ๋ ๋น ๋ฅธ ์๊ฐ์ ์๋ํ์ง๋ง, ๊ฐ์๊ธฐ ํ ์ซ์๊ฐ ์ปค์ง ๊ฒฝ์ฐ ๋ฌด์๋ฏธ์ ๋ฐ๋ณต์ผ๋ก ์๊ฐ์ ๋ญ๋นํ  ์ ์๋ค.

<br>

***์๊ฐ๋ณต์ก๋***

 N์ธ ๋ฐฐ์ด์ด ์๋ค. ๊ทธ๋ ๋ค๋ฉด N๋งํผ ๋ฐ๋ณตํ๋ฉด์ ๊ฐ ์ซ์์ ๊ฐ์๋ฅผ ์ธ์ด์ฃผ๊ณ  ๊ทธ ์ซ์๋งํผ ๋ฐ๋ณตํ๋ฉด์ ๋ค์ ์ถ๋ ฅ์ ํด์ฃผ๋ฉด ๋๋ค.

 ๊ทธ๋ ๊ธฐ ๋๋ฌธ์, **O(n)**์ ๋ณต์ก๋๋ฅผ ๊ฐ์ง๊ฒ ๋๋ค.

<br>

***๋ฐฉ๋ฒ***

1๏ธโฃ ๋ฐฐ์ด์ ์ต๋ ์๋ฅผ ๊ตฌํ๋ค.

2๏ธโฃ ๊ทธ ๋ฐฐ์ด์ ์ต๋ ์๊น์ง ๋ฐ๋ณต์ ์คํํ๋ฉฐ ๊ฐ ์ซ์๋ณ **Counting**์ ์คํํ๋ค.

3๏ธโฃ ์ดํ **Counting**์ ์คํํ๋งํผ ๋ฐฐ์ด์ ์๋กญ๊ฒ ์ ์ฅํด์ฃผ๊ณ  ์ถ๋ ฅํ๋ค.

<br>

***์์ค์ฝ๋(JAVA)***

```java
public static void main(String[] args) throws IOException {
  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

  int size = Integer.parseInt(br.readLine());
  int[] countingArray = new int[10001];

  int max = 0;
  int temp;
  for(int i = 0; i < size; i++) {
    temp = Integer.parseInt(br.readLine());
    countingArray[temp]++;
    if (temp > max) max = temp;
  }

  for(int i = 0; i <= max; i++) {
    for(int j = 0; j < countingArray[i]; j++) {
      bw.write( Integer.toString(i) + "\n");
    }
  }

  bw.flush();
  bw.close();
}
```



