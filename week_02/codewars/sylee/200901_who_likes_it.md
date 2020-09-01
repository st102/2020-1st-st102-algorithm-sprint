# Who likes it?

## 문제설명

> 설명 중 `likes :: [String] -> String`라는 문구가 있는데 이게 무슨 뜻인지 잘 모르겠다.

## 나의 풀이 방법

 ```python
def likes(names):
    how_many = len(names)
    if how_many >= 4:
        return (
            "{}, {}".format(names[0], names[1])
            + " and "
            + "{} others like this".format(how_many - 2)
        )
    elif how_many == 3:
        return "{}, {} and {} like this".format(names[0], names[1], names[2])
    elif how_many == 2:
        return "{} and {} like this".format(names[0], names[1])
    return "{} likes this".format(names[0]) if how_many  else "no one likes this"
 ```

> 케이스별로 나누었다. 반환형식이 케이스별로 다 달라서 묶기가 어려웠던 것 같다.

> 이 방법 외에는 특별히 떠오르는 게 없었다.




## 다른 사람의 풀이 방법

```python
# Best Practices 1
def likes(names):
    n = len(names)
    return {
        0: 'no one likes this',
        1: '{} likes this', 
        2: '{} and {} like this', 
        3: '{}, {} and {} like this', 
        4: '{}, {} and {others} others like this'
    }[min(4, n)].format(*names[:3], others=n-2)
```

> 딕셔너리와 format을 이용해 풀었다.
>
> {others} 로 작성한뒤 others의 값을 설정 할 수 있다는 것을 알게 되었다.

> 이외에 추가적으로 볼만한 코드는 없는 것 같다. 



## 배운 점

>  `"".format()` 형식만 써왔는데 Best Practice처럼 `{딕셔너리}[].format()` 에서 딕셔너리 값을 format 형식에 맞추어 사용할 수 있는 것을 알게 되었다.

> `*names[:3]`를 사용하게 되면 출력시 `[` `]`를 없앨 수 있다.



>  ```python
>  def likes(names):
>    n = len(names)
>    return [
>        'no one likes this',
>        '{} likes this', 
>        '{} and {} like this', 
>        '{}, {} and {} like this', 
>        '{}, {} and {others} others like this'
>    ][min(4, n)].format(*names[:3], others=n-2)
>  ```
>
>  딕셔너리가 아니더라도 리스트와 인덱스를 이용할 수 도 있다.



## 반성할 점

> 특별히 반성 할 점은 생각나지 않는다.

## Action Item

> 이렇게 케이스별로 나누어져 있는 경우, if문으로 조건을 나누지 않고 딕셔너리나 리스트에 저장한뒤, 선택하는 방법도 있다. 