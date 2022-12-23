'''파이썬 최대공약수/최소공배수 함수 ==> gcd / lcm'''
import math

def solution(denum1, num1, denum2, num2):
    bunmo = num1 * num2
    bunja = denum1 * num2 + denum2 * num1
    
    #최대공약수
    gcd_value = math.gcd(bunmo, bunja)
    
    answer = [bunja / gcd_value, bunmo /gcd_value]
    return answer;