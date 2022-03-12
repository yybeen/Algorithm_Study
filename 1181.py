import sys

n = int(sys.stdin.readline())
lst = []

for i in range(n):
    lst.append(sys.stdin.readline().strip()) //strip:좌우 공백 제거
set_lst = set(lst) //set으로 변환하여 중복값제거
lst = list(set_lst)
lst.sort() //알파벳 순으로 정렬
lst.sort(key=len) // 길이순으로 정렬

for i in lst:
    print(i)