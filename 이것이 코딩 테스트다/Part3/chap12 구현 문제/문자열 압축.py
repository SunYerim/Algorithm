def solution(s):
    answer = len(s)
    standard_arr = ""
    # 첫 글자부터 기준점 늘려가면서 비교 글자 확인
    for i in range(1, (len(s) // 2) + 1):
        new_str = ""
        standard_str = s[0:i]
        count = 1
        # standard_arr이랑 i개 단위만큼 문자열 끝까지 비교 시작 (new_str)...
        for j in range (i, len(s), i):
            # 동일하면 count 증가시킴
            if (standard_arr == s[j:j+i]):
                count += 1
            # 안 동일한 경우를 만나게 된다면 ? ..
            else:
                # 동일한 경우 모두 만나고 안 동일한 문자열 만남
                if (count >= 2):
                    new_str += str(count) + standard_arr
                # standard_arr 기준 문자열 뒤 바로 반복 안 되는 경우 (count = 1)
                else:
                    new_str += standard_arr # 반복 안 된 것임
                # 작업 후 상태 초기화
                # 뒷부분에 반복되는 문자열 또 있는지 ?
                standard_arr = s[j:j+i]
                count = 1
         # 나머지 뒤에 문자열 붙여주기
        if (count >= 2):
            new_str += str(count) + standard_arr
        else:
            new_str += standard_arr   
        
        answer = min(len(s), len(new_str))
    return answer

    '''왜 testcase 전체 통과가 안 되는거야.....'''