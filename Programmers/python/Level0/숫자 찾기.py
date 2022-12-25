def solution(num: int, k: int) -> int:
    return str(num).index(str(k)) + 1 if str(k) in str(num) else -1