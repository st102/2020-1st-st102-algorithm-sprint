ECHO가 설정되어 있습니다.
def solution(number):
    return sum(i for i in range(number) if(i%3==0 or i%5==0))