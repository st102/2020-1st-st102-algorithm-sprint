# {알파벳 찾기}

## 문제 설명
모든 알파벳들이 입력된 단어에서 몇번째에 위치하는지 출력하는 문제

## 나의 풀이 방법
알파벳을 담은 char 형 배열을 만들고, foreach문을 돌며 String.indexOf(char) 메소드를 통해 몇번째 위치하는지 찾아서 출력한다.
```kotlin
val bufferedReader = BufferedReader(InputStreamReader(`in`))
val s = bufferedReader.readLine()
val alphabet = arrayOf(
    'a', 'b', 'c', 'd', 'e',
    'f', 'g', 'h', 'i', 'j',
    'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r', 's', 't',
    'u', 'v', 'w', 'x', 'y', 'z'
)
alphabet.forEach {
    stringBuilder.append("${s.indexOf(it)} ")
}
println(stringBuilder)
```

## 다른 사람의 풀이 방법
아스키코드에서 97을 빼서 배열의 인덱스로 접근하는 방법. 시간 복잡도 측면으로 봤을 대 해당방법은 O(문자열의 길이)이고 내 방법은 최악의 경우 O(26*문자열의 길이)이다...
```kotlin
for(i=0; i<strlen(s); i++){

         if(arr[s[i]-97]==-1) //만약 (아스키코드-97)가 -1(처음나온경우)라면

             arr[s[i]-97]=i; //알파벳이 나온 위치를 넣기

    }
```

## 배운 점
- 아스키코드에 익숙해지면 사용할 수 있는 경우가 많아진다. 

## 반성할 점
- c에서는 아스키코드로 접근해서 해결한 경험이 많은데, JVM환경에서 뭔가 접근하려니 어색하게 느껴졌다. 아스키코드를 잘 사용해보자..

## Action Item
- 아스키코드에 익숙해지기