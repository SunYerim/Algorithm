'''logic
	1. 전체 플레이어 수는 스테이지가 올라갈수록 줄어든다.
	2. for문 내에서, 해당 스테이지에 도달한 플레이어 수가 0명일때와 아닐때로 나누어서 실행
	3. value 기준으로 정렬 후 key 저장 (lambda 함수)'''

def solution(N, stages):
    answer = []
    
    #실패율
    ratio = {} #sorting위해 dictionary로 선언  
    # 전체 플레이어 수는 스테이지 지날수록 줄어든다
    allPlayer = len(stages)  # 스테이지에 도달한 플레이어의 수
     
    for i in range(1,N+1):
        if allPlayer == 0: # 스테이지에 도달한 플레이어 수가 0명일 때 
            ratio[i] = 0 # 실패율 0
        else:
            ratio[i] = stages.count(i)/allPlayer # 실패율
            allPlayer -= stages.count(i) # 현재 스테이지에 멈춘 숫자만큼 제외
        
    # value 기준으로 정렬 후 key 저장 (실패율 내림차순 정렬)
    answer = sorted(ratio, key=lambda x : ratio[x],reverse=True) 

    return answer