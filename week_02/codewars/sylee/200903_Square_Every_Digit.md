# Squared Every Digit

## ��������

> ������ �Է¹޾� ���ڸ��� ������ ���� ��� 

## ���� Ǯ�� ���

 ```python
def square_digits(num):
    return int("".join(str(int(x) ** 2) for x in str(num)))
 ```

> ó�� Ǯ���̴�. �� ����� ������.



```python
def square_digits(num):
    return int("".join(str(x ** 2) for x in map(int, str(num))))
```

> map�� �̿��Ͽ� Ǯ��Ҵ�.



```python
def square_digits(num):
    list_square = [int(x) ** 2 for x in str(num)]
    return int(("{}" * len(list_square)).format(*list_square))
```

> *args�� �̿��� Ǯ�� ���Ҵ�.




## �ٸ� ����� Ǯ�� ���

```python
# Best Practices 1
def square_digits(num):
    ret = ""
    for x in str(num):
        ret += str(int(x)**2)
    return int(ret)
```

> �� Ǯ�̸� ���ڵ��ϸ� �� Ǯ�̿� ����.



```python
# Best Practices 2
def square_digits(num):
    return int(''.join([str(n * n) for n in map(int, str(num))]))
```

> ���� `x ** 2`�� ��µ�, `x * x`�� �� ���� ���� �� ����. 

> ���⼭ ���� ����Ʈ `[ ]` �� �� �ʿ䰡 ���� �� ����. 
>
> �ڿ� `))]))`�̷� ������ �����µ� ������ �������� ���� ���������� �ϳ��� �� ���̴°� ���� �� ����.



## ��� ��

>  Ư���� ������.



## �ݼ��� ��

> Ư���� ������.



## Action Item

> �����ϸ� �б⽬�� �ڵ� �����(����Ѻκ��̶�)